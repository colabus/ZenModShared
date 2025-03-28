class ActionSkinChickenWithHandsCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.SKIN * 5);
	}
};

class ActionSkinChickenWithHands : ActionContinuousBase
{
	void ActionSkinChickenWithHands()
	{
		m_CallbackClass = ActionSkinChickenWithHandsCB;
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_MEDIUM;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_CRAFTING;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH;
		m_FullBody = true;
		m_Text = "#skin";
	}

	override void CreateConditionComponents()
	{
		m_ConditionTarget = new CCTDummy();
		m_ConditionItem = new CCINotPresent;
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		if (item != NULL)
			return false;

		DeadChicken_ColorBase targetChicken = DeadChicken_ColorBase.Cast(target.GetObject());
		if (!targetChicken || targetChicken.IsRuined() || targetChicken.IsSkinned())
			return false;

		if (vector.Distance(player.GetPosition(), targetChicken.GetPosition()) > 1)
			return false;

		return true;
	}

	override void OnFinishProgressServer(ActionData action_data)
	{
		/*
		// Get chicken
		EntityAI chicken = EntityAI.Cast(action_data.m_Target.GetObject());
		if (!chicken)
			return;

		// Spawn meats
		ChickenBreastMeat meat1 = ChickenBreastMeat.Cast(GetGame().CreateObjectEx("ChickenBreastMeat", chicken.GetPosition() + "0.1 0 0", ECE_PLACE_ON_SURFACE));
		ChickenBreastMeat meat2 = ChickenBreastMeat.Cast(GetGame().CreateObjectEx("ChickenBreastMeat", chicken.GetPosition() + "0 0 0.1", ECE_PLACE_ON_SURFACE));
		Bone bone = Bone.Cast(GetGame().CreateObjectEx("Bone", chicken.GetPosition(), ECE_PLACE_ON_SURFACE));
		ChickenFeather feather = ChickenFeather.Cast(GetGame().CreateObjectEx("ChickenFeather", chicken.GetPosition() + "0.05 0 0", ECE_PLACE_ON_SURFACE));

		// Set meat quality
		meat1.SetQuantity(Math.RandomFloat(25, meat1.GetQuantityMax() * 0.75));
		meat2.SetQuantity(Math.RandomFloat(25, meat2.GetQuantityMax() * 0.75));
		bone.SetHealth(Math.RandomIntInclusive(0, 10));
		bone.SetQuantity(1);
		feather.SetQuantity(Math.RandomIntInclusive(5, 12));

		// Update player hands
		PlayerBase player = action_data.m_Player;
		PluginLifespan module_lifespan = PluginLifespan.Cast(GetPlugin(PluginLifespan));
		module_lifespan.UpdateBloodyHandsVisibility(player, true);

		// Delete chicken
		chicken.DeleteSafe();
		*/
	}
}