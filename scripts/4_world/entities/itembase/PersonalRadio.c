modded class PersonalRadio
{
	private bool m_IsTurnedOn = false;

	override void OnWorkStart()
	{
		super.OnWorkStart();
		m_IsTurnedOn = true;
	}

	override void OnWorkStop()
	{
		super.OnWorkStop();
		m_IsTurnedOn = false;
	}

	override void OnStoreSave(ParamsWriteContext ctx)
	{
		super.OnStoreSave(ctx);
		ctx.Write(m_IsTurnedOn);
	}

	override void OnWork(float consumed_energy)
	{
		super.OnWork(consumed_energy);
		if (GetGame().IsDedicatedServer()) // Slowly degrade radio over time when in use
		{
			this.SetHealth(this.GetHealth() - GetZenModConfig().DamageRadio);
		}
	}

	override void SoundTurnedOnNoiseStart() // Override loop so it doesn't keep looping.
	{
		if (!GetGame().IsDedicatedServer())
			SEffectManager.PlaySoundOnObject("personalradio_staticnoise_SoundSet", this);
	}

	override bool OnStoreLoad(ParamsReadContext ctx, int version)
	{
		if (!super.OnStoreLoad(ctx, version))
			return false;

		if (!ctx.Read(m_IsTurnedOn))
		{
			m_IsTurnedOn = false;
			return false;
		}

		return true;
	}

	override void EEInit()
	{
		super.EEInit();
		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(CheckRestartTurnOn, 1000, false);
	}

	void CheckRestartTurnOn()
	{
		if (m_IsTurnedOn)
		{
			if (HasEnergyManager() && GetCompEM() && !GetCompEM().IsWorking())
			{
				GetCompEM().SwitchOn();
			}
		}
	}
};