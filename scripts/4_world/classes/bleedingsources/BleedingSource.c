/*
modded class BleedingSource
{
	Particle m_BloodDripsParticle;
	ref BloodDrips m_BloodDrips;

	void BleedingSource(PlayerBase player, int bit, string bone, vector orientation, vector offset, int max_time, float flow_modifier, string particle_name)
	{
		if (GetGame().IsClient() || !GetGame().IsMultiplayer())
		{
			float chance = 0.01;
			if (vector.Distance(player.m_LastBleedPosition, player.GetPosition()) < 1.0)
				chance = 0;

			if (Math.RandomFloat01() < chance)
				CreateBloodDrips();
		}
	}

	void ~BleedingSource()
	{
		if (m_BloodDripsParticle)
			RemoveParticleSplat();
	}

	void CreateBloodDrips()
	{
		if (m_Player.IsAI())
			return; // Don't create blood drops for AI

		vector pos = m_Player.GetPosition();
		m_BloodDrips = new BloodDrips();
		SEffectManager.PlayInWorld(m_BloodDrips, "0 0 0");
		m_BloodDripsParticle = m_BloodDrips.GetParticle();
		m_Player.AddChild(m_BloodDripsParticle, -1, true);
		m_BloodDripsParticle.ScaleParticleParam(EmitorParam.BIRTH_RATE, m_FlowModifier);
		m_Player.m_LastBleedPosition = pos;
	}

	void RemoveParticleSplat()
	{
		if (m_BloodDrips)
			delete m_BloodDrips;
	}
};
*/