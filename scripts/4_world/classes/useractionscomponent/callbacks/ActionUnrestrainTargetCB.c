modded class ActionUnrestrainTargetCB
{
	override void CreateActionComponent()
	{
		float time = ObtainUnrestrainTime();

		if (time <= 0)
		{
			time = DEFAULT_UNRESTRAIN_TIME;
		}

		if (m_ActionData.m_Player.IsQuickRestrain())
		{
			time = DEBUG_QUICK_UNRESTRAIN_TIME;
		}

		m_ActionData.m_ActionComponent = new CAContinuousTime(time * 2);
	}
}