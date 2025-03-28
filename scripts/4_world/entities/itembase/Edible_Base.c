modded class Edible_Base
{
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionAttach);
	}

	/*
	protected Particle m_SteamParticle;
	static const float STEAM_SIZE = 0.5;

	override void UpdateVisuals()
	{
		super.UpdateVisuals();
		
		if (GetGame() && GetGame().IsClient())
		{
			if (GetTemperature() >= 70 && !m_SteamParticle)
			{
				m_SteamParticle = ParticleManager.GetInstance().PlayOnObject(ParticleList.COOKING_BOILING_DONE, this);
			} 
			else 
			if (GetTemperature() < 70 && m_SteamParticle)
			{
				m_SteamParticle.Stop();
			}

			if (m_SteamParticle)
			{
				float tempPercent = GetTemperature() / 100;
				if (tempPercent < 0.1)
					tempPercent = 0.1;

				m_SteamParticle.ScaleParticleParamFromOriginal(EmitorParam.SIZE, tempPercent * STEAM_SIZE);
			}
		}
	}
	*/
}