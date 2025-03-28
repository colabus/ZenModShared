modded class Animal_CanisLupus
{
	static const vector BUNKER_AREA = "571.013184 0 1128.119141";
	static const float BUNKER_HEIGHT = 533.0;

	float m_BunkerCheckTimer = 0;

	// If any wolves/hyenas fall under the map at the Bunker, kill em.
	override bool ModCommandHandlerBefore(float pDt, int pCurrentCommandID, bool pCurrentCommandFinished)
	{
		if (IsAlive())
		{
			m_BunkerCheckTimer += pDt;

			if (m_BunkerCheckTimer > 60)
			{
				m_BunkerCheckTimer = 0;

				// Zero height coords
				vector pos = GetPosition();
				pos[1] = 0;

				if (vector.Distance(pos, BUNKER_AREA) < 150)
				{
					float height = GetPosition()[1];
					if (height < BUNKER_HEIGHT)
					{
						SetHealth(0);
					}
				}
			}
		}

		return super.ModCommandHandlerBefore(pDt, pCurrentCommandID, pCurrentCommandFinished);
	}
}