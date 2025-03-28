class ZenMissionZombiesTrigger extends Trigger
{
	bool m_ShouldSpawn;
	bool m_AggroZombies;
	int m_TriggerLifetimeSecs;
	int m_ZombieCount;
	int m_ZombieSpawnRadius;
	ref TStringArray m_ZombieTypes;
	ref Timer m_TriggerStopTimer;

	void SetupZenMissionZombiesTrigger(int crashLifetime, int triggerRadius, int zombieCount, array<string> zedTypes, int spawnRadius, bool aggro = true)
	{
		ZenModLogger.Log("SetupZenMissionZombiesTrigger @ " + GetPosition() + " life=" + crashLifetime + " radius=" + triggerRadius + " zedCount=" + zombieCount, "triggers");

		SetCollisionSphere(triggerRadius);

		m_ShouldSpawn = true;
		m_TriggerLifetimeSecs = crashLifetime;
		m_ZombieCount = zombieCount;
		m_ZombieSpawnRadius = spawnRadius;
		m_AggroZombies = aggro;
		m_ZombieTypes = new TStringArray;
		m_TriggerStopTimer = new Timer();
		m_TriggerStopTimer.Run(m_TriggerLifetimeSecs, this, "StopSpawn", NULL, false);

		foreach (string zType : zedTypes)
		{
			m_ZombieTypes.Insert(zType);
		}
	}

	void ~ZenMissionZombiesTrigger()
	{
		ZenModLogger.Log("SetupZenMissionZombiesTrigger @ " + GetPosition() + " - ~DESTROY()", "triggers");

		if (m_TriggerStopTimer)
		{
			if (m_TriggerStopTimer.IsRunning())
				m_TriggerStopTimer.Stop();

			delete m_TriggerStopTimer;
		}
	}

	void StopSpawn()
	{
		ZenModLogger.Log("SetupZenMissionZombiesTrigger @ " + GetPosition() + " - StopSpawn()", "triggers");

		m_ZombieTypes.Clear();
		if (m_TriggerStopTimer && m_TriggerStopTimer.IsRunning())
			m_TriggerStopTimer.Stop();

		m_ShouldSpawn = false;
		SetLifetime(3);
	}

	override void OnEnter(Object obj)
	{
		if (!obj.IsMan() || !GetGame().IsDedicatedServer() || !m_ShouldSpawn)
			return;

		PlayerBase player = PlayerBase.Cast(obj);
		if (!player || !player.GetIdentity())
			return;

		ZenModLogger.Log("SetupZenMissionZombiesTrigger @ " + GetPosition() + " - OnEnter() - " + player.GetIdentity().GetName() + "/" + player.GetIdentity().GetPlainId(), "triggers");
		SpawnRandomZombies();
	};

	void SpawnRandomZombies()
	{
		if (!m_ZombieTypes)
			return;

		vector spawnPos;
		for (int i = 0; i < m_ZombieCount; i++)
		{
			spawnPos = GetPosition();
			spawnPos[0] = spawnPos[0] + Math.RandomFloatInclusive(m_ZombieSpawnRadius * -1, m_ZombieSpawnRadius);
			spawnPos[2] = spawnPos[2] + Math.RandomFloatInclusive(m_ZombieSpawnRadius * -1, m_ZombieSpawnRadius);
			spawnPos[1] = GetGame().SurfaceY(spawnPos[0], spawnPos[2]);

			string randomZed = m_ZombieTypes.GetRandomElement();
			ZombieBase zed = ZombieBase.Cast(GetGame().CreateObjectEx(randomZed, spawnPos, ECE_PLACE_ON_SURFACE|ECE_INITAI|ECE_SETUP|ECE_EQUIP));
			if (!zed)
			{
				ZenModLogger.Log("SetupZenMissionZombiesTrigger @ " + GetPosition() + " - FAILED TO CREATE ZOMBIE - " + randomZed, "triggers");
				continue;
			}

			zed.SetLifetime(3600); // Set lifetime to 1 hour
			zed.SetPosition(spawnPos); // Ensure it's on the ground
			zed.m_IsMissionZombie = true; // Make it so this zombie kills cars

			// Trigger aggro state
			if (m_AggroZombies)
			{
				DayZInfectedCommandMove moveCommandZ = zed.GetCommand_Move();
				if (moveCommandZ)
					moveCommandZ.SetIdleState(2);
			}
		}

		// Trigger no longer needed - TODO: Necessary?
		StopSpawn();
	}
};