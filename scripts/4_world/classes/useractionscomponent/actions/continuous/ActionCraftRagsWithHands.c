class ActionCraftRagsWithHandsCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(12);
	}
};

class ActionCraftRagsWithHands : ActionContinuousBase
{
	void ActionCraftRagsWithHands()
	{
		m_CallbackClass = ActionCraftRagsWithHandsCB;
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_MEDIUM;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_CRAFTING;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH;
		m_FullBody = true;
		m_Text = "#STR_CraftRag0";
	}

	override void CreateConditionComponents()
	{
		m_ConditionTarget = new CCTNonRuined;
		m_ConditionItem = new CCINone;
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		ItemBase targetItem = ItemBase.Cast(target.GetObject());

		if (!targetItem || item)
			return false;

		return targetItem.ConfigGetFloat("ragQuantity") > 0 && targetItem.IsEmpty();
	}

	override void OnFinishProgressServer(ActionData action_data)
	{
		// Get item
		Inventory_Base targetItem = Inventory_Base.Cast(action_data.m_Target.GetObject());

		if (!targetItem)
			return;

		// Spawn rag
		ItemBase rags = ItemBase.Cast(GetGame().CreateObjectEx("Rag", targetItem.GetPosition(), ECE_PLACE_ON_SURFACE));

		// Set rag quality
		rags.SetQuantity(1);
		rags.SetHealth(Math.RandomIntInclusive(0, 2));

		// Delete target clothing item
		targetItem.DeleteSafe();
	}

	override string GetSoundCategory(ActionData action_data)
	{
		return "Zen_CraftRag";
	}
};