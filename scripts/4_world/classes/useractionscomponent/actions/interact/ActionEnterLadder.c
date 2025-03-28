modded class ActionEnterLadder
{
	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINotPresent;
		m_ConditionTarget = new CCTCursor;
	}
}