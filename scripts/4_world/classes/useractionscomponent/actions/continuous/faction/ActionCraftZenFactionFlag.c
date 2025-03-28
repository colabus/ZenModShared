class ActionZenFactionCB: ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.BANDAGE);
	}
}

class ActionCraftZenFactionFlag: ActionContinuousBase
{
	static const float CONSUME_CAN = 20.0;

	void ActionCraftZenFactionFlag()
	{
		m_CallbackClass 	= ActionZenFactionCB;
		m_CommandUID 		= DayZPlayerConstants.CMD_ACTIONFB_CRAFTING;
		m_FullBody 			= true;
		m_StanceMask 		= DayZPlayerConstants.STANCEMASK_CROUCH;
		m_SpecialtyWeight 	= UASoftSkillsWeight.PRECISE_LOW;
		m_Text 				= "Craft faction flag";
	}
	
	override void CreateConditionComponents()  
	{		
		m_ConditionItem 	= new CCINonRuined();
		m_ConditionTarget	= new CCTNonRuined(UAMaxDistances.DEFAULT);
	}
	
	override bool HasTarget()	
	{
		return true;
	}
	
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		//ZenFunctions.DebugMessage("factionID=" + player.GetMyFactionID());
		if (player.GetMyFactionID() == "NONE" || player.GetMyFactionID() == "NOT_RECEIVED")
			return false;

		Spraycan_ColorBase spraycan = Spraycan_ColorBase.Cast(item);
		if (!spraycan || spraycan.GetQuantity() < CONSUME_CAN)
			return false;

		ItemBase targetItem = ItemBase.Cast(target.GetObject());
		if (!targetItem)
			return false;

		return targetItem.IsKindOf("Flag_Base") && !targetItem.GetType().Contains(player.GetMyFactionID());
	}
	
	override void OnFinishProgressServer(ActionData action_data)
	{
		Spraycan_ColorBase spraycan = Spraycan_ColorBase.Cast(action_data.m_MainItem);
		if (!spraycan)
		{
			ZenError(action_data.m_Player, "No spraycan");
			return;
		}

		Flag_Base oldFlag = Flag_Base.Cast(action_data.m_Target.GetObject());
		if (!oldFlag)
		{
			ZenError(action_data.m_Player, "No old flag");
			return;
		}

		Flag_Base newFlag = Flag_Base.Cast(action_data.m_Player.SpawnEntityOnGroundPos("Flag_" + action_data.m_Player.GetMyFactionID(), oldFlag.GetPosition()));
		if (!newFlag)
		{
			ZenError(action_data.m_Player, "No new flag");
			return;
		}

		spraycan.SetQuantity(spraycan.GetQuantity() - CONSUME_CAN);
		newFlag.SetHealth(oldFlag.GetHealth());
		newFlag.SetWet(oldFlag.GetWet());
		newFlag.SetLifetime(14400);
		newFlag.SetLifetimeMax(14400);
		oldFlag.DeleteSafe();
	}

	void ZenError(PlayerBase player, string msg)
	{
		ZenFunctions.SendPlayerMessage(player, "Something went wrong - please email admin@hardcoredayz.com to let Zen know. Error: " + msg);
	}

	override string GetSoundCategory(ActionData action_data)
	{
		return "Zen_SprayPaint";
	}
}
