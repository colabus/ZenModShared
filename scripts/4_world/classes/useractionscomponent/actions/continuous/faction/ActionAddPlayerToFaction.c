class ActionAddPlayerToFaction : ActionContinuousBase
{
	void ActionAddPlayerToFaction()
	{
		m_CallbackClass = ActionZenFactionCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_OPENITEM;
		m_CommandUIDProne = DayZPlayerConstants.CMD_ACTIONFB_OPENITEM;
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_LOW;
		m_Text = "Add to faction";
	}

	override void CreateConditionComponents()  
	{
		m_ConditionTarget 	= new CCTMan(UAMaxDistances.DEFAULT);
		m_ConditionItem		= new CCINonRuined;
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		if (GetGame().ConfigGetInt("CfgVehicles " + item.GetType() + " isFaction") != 1)
			return false;

		if (!item.GetType().Contains(player.GetMyFactionID()))
			return false;

		return true;
	}

	override void OnFinishProgressServer(ActionData action_data)
	{
		if (!action_data.m_Player.GetIdentity())
			return;

		PlayerBase targetPlayer = PlayerBase.Cast(action_data.m_Target.GetObject());
		if (!targetPlayer || !targetPlayer.GetIdentity())
			return;

		ZenFaction playerFaction = GetZenFactionGearConfig().GetPlayerFaction(action_data.m_Player.GetIdentity().GetPlainId());
		if (!playerFaction)
			return;

		if (playerFaction.LeaderID != action_data.m_Player.GetIdentity().GetPlainId())
		{
			ExpansionNotification(new StringLocaliser("FACTION", "FACTION"), "Only the Faction Leader can invite new players!").Error(action_data.m_Player.GetIdentity());
			return;
		}

		ZenFaction playerTargetFaction = GetZenFactionGearConfig().GetPlayerFaction(targetPlayer.GetIdentity().GetPlainId());
		if (playerTargetFaction)
		{
			ExpansionNotification(new StringLocaliser("FACTION", "FACTION"), "That player is already in a Faction!").Error(action_data.m_Player.GetIdentity());
			return;
		}

		playerFaction.MemberIDs.Insert(targetPlayer.GetIdentity().GetPlainId());
		GetZenFactionGearConfig().Save();
		targetPlayer.SetMyFactionID(playerFaction.FactionID);

		ExpansionNotification(new StringLocaliser("FACTION", "FACTION"), "That player is now part of your faction.").Error(action_data.m_Player.GetIdentity());
	}
};