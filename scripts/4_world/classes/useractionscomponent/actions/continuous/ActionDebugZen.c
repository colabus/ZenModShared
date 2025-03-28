class ActionDebugZenCB : ActionContinuousBaseCB
{
	protected const float TIME_BETWEEN_MATERIAL_DROPS_DEFAULT = 1;

	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(TIME_BETWEEN_MATERIAL_DROPS_DEFAULT);
	}
};

class ActionDebugZen : ActionContinuousBase
{
	void ActionDebugZen()
	{
		m_CallbackClass = ActionDebugZenCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_INTERACT;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_HIGH;
	}

	override void CreateConditionComponents()
	{
		m_ConditionTarget = new CCTCursor(UAMaxDistances.DEFAULT);
		m_ConditionItem = new CCINone;
	}

	override string GetText()
	{
		return "Debug test...";
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		Object targetObject = target.GetObject();
		SendChat(player, "Object type: " + targetObject.GetType() + " | Model: " + targetObject.GetModelName());
		return true;
	}

	override void OnFinishProgressServer(ActionData action_data)
	{
		PlayerBase player = action_data.m_Player;
		GetGame().CreateObjectEx("Paper", player.GetPosition(), ECE_PLACE_ON_SURFACE);
	}

	void SendChat(PlayerBase player, string message)
	{
		Param1<string> Msgparam;
		PlayerIdentity playerIdentity = player.GetIdentity();
		Msgparam = new Param1<string>(message);
		GetGame().RPCSingleParam(player, ERPCs.RPC_USER_ACTION_MESSAGE, Msgparam, true, playerIdentity);
	}
};