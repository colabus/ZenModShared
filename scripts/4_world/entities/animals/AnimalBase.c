modded class AnimalBase
{
	bool m_MissionAnimal = false;

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

		if (ammo == "Arrow_Bolt_Virus")
		{
			float health = this.GetHealth() - 240;
			if (health < 0)
				health = 0;
			this.SetHealth(health);
		}

		if (speedCoef >= 80 && (ammo == "Arrow_Bolt" || ammo == "Arrow_Bolt_Virus"))
		{
			string type = "Crossbow_ArrowBolt";
			Ammunition_Base bolt = Ammunition_Base.Cast(GetGame().CreateObjectEx(type, this.GetPosition(), ECE_PLACE_ON_SURFACE));

			if (bolt)
			{
				bolt.ServerSetAmmoCount(1);
				if (Math.RandomFloat01() < 0.1)
					bolt.SetHealth("", "", 0);
				else
					bolt.SetHealth("", "", 20);
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
					if (m_MissionAnimal)
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
						objectToDamage = EntityAI.Cast(source.FindAttachmentBySlotName(ZombieBase.CAR_PARTS.GetRandomElement()));
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

	override bool CanBeTargetedByAI(EntityAI ai)
	{
		if (this.GetType().Contains("Animal_CanisPestis") || this.GetType().Contains("bear_blood"))
		{
			return !ai.IsZombie() && super.CanBeTargetedByAI(ai);
		}

		return super.CanBeTargetedByAI(ai);
	}
}