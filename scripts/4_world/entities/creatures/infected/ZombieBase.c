modded class ZombieBase
{
	static const ref array<string> CAR_PARTS = { "SparkPlug", "TruckRadiator", "GlowPlug", "CarBattery", "TruckBattery", "CarRadiator" };

	bool m_IsMissionZombie = false;

	#ifdef SERVER
	// Detect vehicle crushing
	bool m_VehicleHitSuspended = false;

	// Resets the flag to allow vehicle hits on zombies to count
	void ResetVehicleHit()
	{
		m_VehicleHitSuspended = false;
	}

	override void EEHitBy(TotalDamageResult damageResult, int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos, float speedCoef)
	{
		super.EEHitBy(damageResult, damageType, source, component, dmgZone, ammo, modelPos, speedCoef);

		// Check for baseball bat 
		if (source && source.GetType().Contains("BaseballBat"))
		{
			if (dmgZone == "LeftLeg" || dmgZone == "RightLeg" || dmgZone == "LeftFoot" || dmgZone == "RightFoot")
			{
				float chance = 0.1;
				if (source.GetType() == "NailedBaseballBat" || source.GetType() == "BarbedBaseballBat")
				{
					chance = 0.9;
				}

				if (Math.RandomFloat01() < chance)
				{
					StartCommand_Crawl(0);
				}
			}
		}

		// Check for vehicle hit
		if (source && ammo == "TransportHit" && !m_VehicleHitSuspended)
		{
			m_VehicleHitSuspended = true;
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(ResetVehicleHit, Math.RandomInt(1000, 2000), false);

			CarScript theCar = CarScript.Cast(source);
			if (theCar && !theCar.GetType().Contains("Vodnik"))
			{
				float speed = theCar.GetSpeedometer();

				if (speed > 10)
				{
					EntityAI objectToDamage;
					if (m_IsMissionZombie)
					{
						objectToDamage = EntityAI.Cast(source.FindAttachmentBySlotName("SparkPlug"));
						if (!objectToDamage)
							objectToDamage = EntityAI.Cast(source.FindAttachmentBySlotName("GlowPlug"));
						if (!objectToDamage)
							objectToDamage = EntityAI.Cast(source.FindAttachmentBySlotName("CarBattery"));
						if (!objectToDamage)
							objectToDamage = EntityAI.Cast(source.FindAttachmentBySlotName("TruckBattery"));

						if (objectToDamage)
							objectToDamage.DecreaseHealth(objectToDamage.GetMaxHealth() + 1, false);
					}
					else
					{
						objectToDamage = EntityAI.Cast(source.FindAttachmentBySlotName(CAR_PARTS.GetRandomElement()));
						if (objectToDamage)
						{
							float maxRadiatorHealth = objectToDamage.GetMaxHealth();
							float healthToDecreaseFromSpeed = (speed / 1000) * 2.5;
							float healthQuantityToDecrease = healthToDecreaseFromSpeed * maxRadiatorHealth;
							objectToDamage.DecreaseHealth(healthQuantityToDecrease, false);
							theCar.SynchCrashLightSound(true);
						}
					}
				}
			}
		}
	}

	override bool ChaseAttackLogic(int pCurrentCommandID, DayZInfectedInputController pInputController, float pDt)
	{
		// always update target - it can be destroyed		
		m_ActualTarget = pInputController.GetTargetEntity();

		//! Allow attacking players in car if door is open
		bool carVulnerable = false;
		PlayerBase pb = PlayerBase.Cast(m_ActualTarget);
		if (pb && pb.GetCommand_Vehicle() && vector.Distance(GetPosition(), pb.GetPosition()) <= 2)
		{
			if (!PlayerVehicleVulnerable(pb))
				return false;

			carVulnerable = true;
		}

		if (m_ActualTarget == NULL)
			return false;

		vector targetPos = m_ActualTarget.GetPosition();
		if (!CanAttackToPosition(targetPos))
		{
			if (!carVulnerable)
				return false;
			else
			{
				if (vector.Distance(GetPosition(), targetPos) > 2)
					return false;
			}
		}

		float targetDist = vector.Distance(targetPos, this.GetPosition());
		int pitch = GetAttackPitch(m_ActualTarget);

		m_ActualAttackType = GetDayZInfectedType().ChooseAttack(DayZInfectedAttackGroupType.CHASE, targetDist, pitch);

		if (!m_ActualAttackType && carVulnerable && m_ActualTarget.IsMan())
		{
			int attackType = Math.RandomIntInclusive(0, 1);
			m_ActualAttackType = GetDayZInfectedType().ChooseAttack(DayZInfectedAttackGroupType.CHASE, 1, 0);	// pAttackType, float pTargetDistance, int pPitch	
			StartCommand_Attack(m_ActualTarget, attackType, 1);
		}
		else
		if (m_ActualAttackType)
		{
			Object target = DayZPlayerUtils.GetMeleeTarget(this.GetPosition(), this.GetDirection(), TARGET_CONE_ANGLE_CHASE, m_ActualAttackType.m_Distance, -1.0, 2.0, this, m_TargetableObjects, m_AllTargetObjects);
			//! target is outside the targeting cone; skip attack
			if (m_ActualTarget != target && !carVulnerable)
			{
				m_AllTargetObjects.Clear();
				return false;
			}

			StartCommand_Attack(m_ActualTarget, m_ActualAttackType.m_Type, m_ActualAttackType.m_Subtype);
			m_AttackCooldownTime = m_ActualAttackType.m_Cooldown;
			return true;
		}

		return false;
	}

	override bool FightAttackLogic(int pCurrentCommandID, DayZInfectedInputController pInputController, float pDt)
	{
		// always update target - it can be destroyed		
		m_ActualTarget = pInputController.GetTargetEntity();

		//! do not attack players in vehicle - hotfix
		bool carVulnerable = false;
		PlayerBase pb = PlayerBase.Cast(m_ActualTarget);
		if (pb && pb.GetCommand_Vehicle() && vector.Distance(GetPosition(), pb.GetPosition()) <= 2)
		{
			if (!PlayerVehicleVulnerable(pb))
				return false;

			carVulnerable = true;
		}

		if (m_AttackCooldownTime > 0)
		{
			m_AttackCooldownTime -= pDt * GameConstants.AI_ATTACKSPEED;
			return false;
		}

		if (m_ActualTarget == NULL)
			return false;

		vector targetPos = m_ActualTarget.GetPosition();
		float targetDist = vector.Distance(targetPos, this.GetPosition());
		int pitch = GetAttackPitch(m_ActualTarget);

		if (!CanAttackToPosition(targetPos))
		{
			return false;
		}

		m_ActualAttackType = GetDayZInfectedType().ChooseAttack(DayZInfectedAttackGroupType.FIGHT, targetDist, pitch);

		if (m_ActualAttackType)
		{
			Object target = DayZPlayerUtils.GetMeleeTarget(this.GetPosition(), this.GetDirection(), TARGET_CONE_ANGLE_FIGHT, m_ActualAttackType.m_Distance, -1.0, 2.0, this, m_TargetableObjects, m_AllTargetObjects);
			//! target is outside the targeting cone; skip attack
			if (m_ActualTarget != target && !carVulnerable)
			{
				m_AllTargetObjects.Clear();
				return false;
			}

			StartCommand_Attack(m_ActualTarget, m_ActualAttackType.m_Type, m_ActualAttackType.m_Subtype);
			m_AttackCooldownTime = m_ActualAttackType.m_Cooldown;
			return true;
		}

		return false;
	}

	bool PlayerVehicleVulnerable(PlayerBase pb)
	{
		CarScript car = null;
		if (Class.CastTo(car, pb.GetCommand_Vehicle().GetTransport()))
		{
			if (car.GetSpeedometer() >= 10)
				return false;

			int crewIdx = car.CrewMemberIndex(pb);
			if (crewIdx >= 0 && crewIdx <= 3 && (car.GetCarDoorsState(car.GetDoorInvSlotNameFromSeatPos(crewIdx)) == CarDoorState.DOORS_MISSING || car.GetCarDoorsState(car.GetDoorInvSlotNameFromSeatPos(crewIdx)) == CarDoorState.DOORS_OPEN))
			{
				return true;
			}
		};

		return false;
	}

	/*override bool ModCommandHandlerBefore(float pDt, int pCurrentCommandID, bool pCurrentCommandFinished)
	{
		bool superMod = super.ModCommandHandlerBefore(pDt, pCurrentCommandID, pCurrentCommandFinished);

		//! TODO: ONLY IF VERY DARK
		if (GetGame().GetWorld().IsNight())
		{
			GetInputController().OverrideMovementSpeed(true, 3);
			if (GetHealth01("","") > 0.1)
			{
				SetHealth01("", "", 0.1);
				ZenFunctions.DebugMessage("HP=" + GetHealth());
			}
		}

		return superMod;
	}*/
	#endif
};
