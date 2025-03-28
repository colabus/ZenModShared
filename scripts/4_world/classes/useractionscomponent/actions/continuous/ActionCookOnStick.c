modded class ActionCookOnStick
{
	override void OnStartServer(ActionData action_data)
	{
		super.OnStartServer(action_data);

		// Generate noise
		FireplaceBase fireplace_target = FireplaceBase.Cast(action_data.m_Target.GetObject());
		if (fireplace_target)
		{
			fireplace_target.MakeCookingNoise();
		}
	}

	override void OnEndServer(ActionData action_data)
	{
		super.OnEndServer(action_data);

		if (action_data.m_MainItem)
		{
			action_data.m_MainItem.SetHealth(action_data.m_MainItem.GetHealth() - 10);
		}

		// Generate noise
		FireplaceBase fireplace_target = FireplaceBase.Cast(action_data.m_Target.GetObject());
		if (fireplace_target)
		{
			fireplace_target.MakeCookingNoise();
		}
	}
}