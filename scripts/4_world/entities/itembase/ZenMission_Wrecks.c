class ZenMission_Wreck_C130J extends House
{
	protected bool m_PlayCrashSound;
	Particle m_ParticleFx;

	void ZenMission_Wreck_C130J()
	{
		RegisterNetSyncVariableBoolSignal("m_PlayCrashSound");

		if (GetGame().IsClient())
		{
			m_ParticleFx = Particle.PlayOnObject(ParticleList.SMOKING_HELI_WRECK, this, Vector(5, -1, -2));
		}

		if (GetGame().IsDedicatedServer())
		{
			GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(ServerTriggerCrashSound, 250);
		}
	}

	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
		
		if (m_PlayCrashSound)
		{
			PlayCrashSound();
		}
	}

	void ServerTriggerCrashSound()
	{
		m_PlayCrashSound = true;
		SetSynchDirty();
	}

	void PlayCrashSound()
	{
		SEffectManager.PlaySoundOnObject("Landmine_Explosion_SoundSet", this);
		SEffectManager.PlaySoundOnObject("Landmine_Explosion_Tail_SoundSet", this);
	}

	override void EEDelete(EntityAI parent)
	{
		super.EEDelete(parent);

		if (GetGame().IsClient())
		{
			if (m_ParticleFx) m_ParticleFx.Stop();
		}
	};
};

class ZenMission_Wreck_Heli extends House
{
	protected bool m_PlayCrashSound;
	Particle m_ParticleFx;

	void ZenMission_Wreck_Heli()
	{
		RegisterNetSyncVariableBoolSignal("m_PlayCrashSound");

		if (GetGame().IsClient())
		{
			m_ParticleFx = Particle.PlayOnObject(ParticleList.SMOKING_HELI_WRECK, this, Vector(-0.5, 0, -1.0));
		}

		if (GetGame().IsDedicatedServer())
		{
			GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(ServerTriggerCrashSound, 250);
		}
	}

	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
		
		if (m_PlayCrashSound)
		{
			PlayCrashSound();
		}
	}

	void ServerTriggerCrashSound()
	{
		m_PlayCrashSound = true;
		SetSynchDirty();
	}

	void PlayCrashSound()
	{
		SEffectManager.PlaySoundOnObject("Landmine_Explosion_SoundSet", this);
		SEffectManager.PlaySoundOnObject("Landmine_Explosion_Tail_SoundSet", this);
	}

	override void EEDelete(EntityAI parent)
	{
		super.EEDelete(parent);

		if (GetGame().IsClient())
		{
			if (m_ParticleFx) m_ParticleFx.Stop();
		}
	};
};

class ZenMission_Wreck_Hummer extends House
{
	protected bool m_PlayCrashSound;
	Particle m_ParticleFx;

	void ZenMission_Wreck_Hummer()
	{
		RegisterNetSyncVariableBoolSignal("m_PlayCrashSound");

		if (GetGame().IsClient())
		{
			m_ParticleFx = Particle.PlayOnObject(ParticleList.SMOKING_HELI_WRECK, this, Vector(0, 0, 0));
		}

		if (GetGame().IsDedicatedServer())
		{
			GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(ServerTriggerCrashSound, 250);
		}
	}

	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
		
		if (m_PlayCrashSound)
		{
			PlayCrashSound();
		}
	}

	void ServerTriggerCrashSound()
	{
		m_PlayCrashSound = true;
		SetSynchDirty();
	}

	void PlayCrashSound()
	{
		SEffectManager.PlaySoundOnObject("Landmine_Explosion_SoundSet", this);
		SEffectManager.PlaySoundOnObject("Landmine_Explosion_Tail_SoundSet", this);
	}

	override void EEDelete(EntityAI parent)
	{
		super.EEDelete(parent);

		if (GetGame().IsClient())
		{
			if (m_ParticleFx) m_ParticleFx.Stop();
		}
	};
};
