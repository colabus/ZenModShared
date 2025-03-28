/*class InfectedWolfSpawnTimer
{
	protected ref Timer m_ZenWolfSpawnTimer;
	protected string m_LastPlayerID = "";
	protected static ref InfectedWolfSpawnTimer m_WolfSpawnInstance;

	static InfectedWolfSpawnTimer GetInstance()
	{
		if (!m_WolfSpawnInstance)
		{
			m_WolfSpawnInstance = new InfectedWolfSpawnTimer();
		}

		return m_WolfSpawnInstance;
	}

	static void ClearInstance()
	{
		m_WolfSpawnInstance = null;
	}

	void ZenInfectedWolfSpawn()
	{
		m_ZenWolfSpawnTimer = new Timer();
		m_ZenWolfSpawnTimer.Run((GetZenModConfig().InfectedWolfSpawnTime + Math.RandomIntInclusive(0, 60)) * 60, this, "SpawnWolfNearRandomPlayer", NULL, true);
	}

	void SpawnWolfNearRandomPlayer()
	{
		// 50% chance to spawn a wolf on someone
		if (Math.RandomIntInclusive(1, 2) == 2)
		{
			return;
		}

		vector spawnPoint = GetRandomSpawnPoint();

		if (!spawnPoint || (spawnPoint[0] == -1 && spawnPoint[1] == -1 && spawnPoint[2] == -1))
		{
			return;
		}

		// This code is taken from CheckUnderRoof() in DayZ/Environment.c
		float hitFraction;
		vector hitPosition, hitNormal;
		vector to = spawnPoint + "0 25 0";
		Object hitObject;
		PhxInteractionLayers collisionLayerMask = PhxInteractionLayers.ITEM_LARGE | PhxInteractionLayers.BUILDING | PhxInteractionLayers.VEHICLE;

		// Do some fancy DayZ 3D math to see if a roof is above us
		bool isInside = DayZPhysics.RayCastBullet(spawnPoint, to, collisionLayerMask, null, hitObject, hitPosition, hitNormal, hitFraction);

		// Spawn wolf only if it's not inside a structure or object - if it is, try one more time and then give up.
		if (!isInside)
		{
			GetGame().CreateObject("Animal_CanisPestis", spawnPoint, false, true, true);
		}
		else
		{
			spawnPoint = GetRandomSpawnPoint();
			isInside = DayZPhysics.RayCastBullet(spawnPoint, to, collisionLayerMask, null, hitObject, hitPosition, hitNormal, hitFraction);
			if (!isInside)
			{
				GetGame().CreateObject("Animal_CanisPestis", spawnPoint, false, true, true);
			}
		}

		vector xyzRand;
		int count = 0;

		int maxCount = 0;
		array<Man> players = new array<Man>;
		g_Game.GetWorld().GetPlayerList(players);
		for (int x = 0; x < players.Count(); x++)
		{
			if (vector.Distance(players.Get(x).GetPosition(), spawnPoint) < 50)
				maxCount += Math.RandomIntInclusive(1, 2); // Add 1-2 wolves for every player within 50m of each other
		}

		for (int i = 0; i < maxCount; i++) // TODO: Config this - And make it only happen down south? Or limit to 1 spawn up north?
		{
			if (Math.RandomFloat01() < GetZenModConfig().ExtraWolfChance)
			{
				continue;
			}

			xyzRand = spawnPoint;
			xyzRand[0] = xyzRand[0] + Math.RandomFloatInclusive(-5, 5);
			xyzRand[2] = xyzRand[2] + Math.RandomFloatInclusive(-5, 5);
			xyzRand[1] = GetGame().SurfaceY(xyzRand[0], xyzRand[2]); // change to find surface

			isInside = DayZPhysics.RayCastBullet(xyzRand, to, collisionLayerMask, null, hitObject, hitPosition, hitNormal, hitFraction);

			if (!isInside)
			{
				GetGame().CreateObject("Animal_CanisPestis", spawnPoint, false, true, true);
				count++;
			}
			else
			{
				i--; // Keep looping until they all spawn
			}
		}

		ZenModLogger.Log("[InfectedWolf] Random wolf spawned at " + spawnPoint + " (+" + count + " extras)");
	}

	vector GetRandomSpawnPoint()
	{
		// Get a random player
		array<Man> players = new array<Man>;
		g_Game.GetWorld().GetPlayerList(players);
		Man poorBastard = players.GetRandomElement();
		vector xyzRand;

		if (!poorBastard)
		{
			xyzRand[0] = -1;
			xyzRand[1] = -1;
			xyzRand[2] = -1;
			return xyzRand;
		}

		// Spawn a wolf near them
		xyzRand = poorBastard.GetPosition();

		int randomX = Math.RandomFloatInclusive(-300, 300);
		int randomY = Math.RandomFloatInclusive(-300, 300);

		if (randomX < 0)
			randomX -= 50;
		else
			randomX += 50;

		if (randomY < 0)
			randomY -= 50;
		else
			randomY += 50;

		xyzRand[0] = xyzRand[0] + randomX; // Minimum range 100-250m, maximum range -250 - +250m on top of that
		xyzRand[2] = xyzRand[2] + randomY;
		xyzRand[1] = GetGame().SurfaceY(xyzRand[0], xyzRand[2]); // change to find surface

		PlayerBase player = PlayerBase.Cast(poorBastard);
		if (player)
		{
			if (player.GetIdentity().GetPlainId() == m_LastPlayerID)
			{
				xyzRand[0] = -1;
				xyzRand[1] = -1;
				xyzRand[2] = -1;
				m_LastPlayerID = "";
				return xyzRand;
			}

			m_LastPlayerID = player.GetIdentity().GetPlainId();
		}

		return xyzRand;
	}
};*/