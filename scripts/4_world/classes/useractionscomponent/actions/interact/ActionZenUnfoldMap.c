class ActionZenUnfoldMapCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(1);
	}
};

class ActionZenUnfoldMap : ActionContinuousBase
{
	void ActionZenUnfoldMap()
	{
		m_CallbackClass = ActionZenUnfoldMapCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_OPENITEM;
		m_CommandUIDProne = DayZPlayerConstants.CMD_ACTIONFB_OPENITEM;
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_LOW;
		m_Text = "Unfold Map";
	}

	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNone;
	}

	override bool HasTarget()
	{
		return false;
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		if (player.m_hac || player.IsMapOpen())
		{
			return false;
		}

		return true;
	}

	override void OnFinishProgressServer(ActionData action_data)
	{
		super.OnFinishProgressServer(action_data);

		action_data.m_Player.GetHumanInventory().ReplaceItemWithNew(InventoryMode.SERVER, new ReplaceJunkLambda(action_data.m_MainItem, "ZenMapUnfolded", action_data.m_MainItem.GetHealth()));
	}
};

class ActionZenFoldMap : ActionContinuousBase
{
	void ActionZenFoldMap()
	{
		m_CallbackClass = ActionZenUnfoldMapCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_OPENITEM;
		m_CommandUIDProne = DayZPlayerConstants.CMD_ACTIONFB_OPENITEM;
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_LOW;
		m_Text = "Fold Map";
	}

	override void CreateConditionComponents()
	{
		m_ConditionItem 	= new CCINonRuined();
		m_ConditionTarget 	= new CCTNone();
	}

	override bool HasTarget()
	{
		return false;
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		return true;
	}

	override void OnFinishProgressServer(ActionData action_data)
	{
		super.OnFinishProgressServer(action_data);

		action_data.m_Player.GetHumanInventory().ReplaceItemWithNew(InventoryMode.SERVER, new ReplaceJunkLambda(action_data.m_MainItem, "ChernarusMap", action_data.m_MainItem.GetHealth()));
	}
};