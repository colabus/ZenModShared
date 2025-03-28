modded class ActionUnrestrainSelfCB
{
	override void CreateActionComponent()
	{
		float time = DEFAULT_STRUGGLE_TIME;

		if (m_ActionData.m_MainItem.ConfigIsExisting("StruggleLength"))
		{
			time = m_ActionData.m_MainItem.ConfigGetFloat("StruggleLength");
		}

		m_ActionData.m_ActionComponent = new CAContinuousTime(time * 10);
	}
}