modded class PowerGenerator
{
	override void EEOnCECreate()
	{
		super.EEOnCECreate();
		this.SetLifetime(3600);
	}

	override void StartLoopSound()
	{
		super.StartLoopSound();

		if (GetGame().IsClient() || !GetGame().IsMultiplayer())
		{
			if (GetCompEM().IsWorking())
			{
				if (m_EngineLoop)
				{
					m_EngineLoop.SetSoundVolume(m_EngineLoop.GetSoundVolume() / 2); // Make power generator quieter
				}
			}
		}
	}
};