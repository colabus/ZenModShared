modded class ActionBuildPart
{
	override void OnStartClient(ActionData action_data)
	{
		super.OnStartClient(action_data);

		if (action_data.m_MainItem && action_data.m_MainItem.Type() == Hatchet)
		{
			Hatchet hatchet = Hatchet.Cast(action_data.m_MainItem);
			if (hatchet)
				hatchet.SetBackwards(true);
		}
	}

	override void OnEndClient(ActionData action_data)
	{
		super.OnEndClient(action_data);

		if (action_data.m_MainItem && action_data.m_MainItem.Type() == Hatchet)
		{
			Hatchet hatchet = Hatchet.Cast(action_data.m_MainItem);
			if (hatchet)
				hatchet.SetBackwards(false);
		}
	}
}
