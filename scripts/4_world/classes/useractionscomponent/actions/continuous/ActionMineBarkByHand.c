class ActionMineBarkByHandCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(10);
	}
};

class ActionMineBarkByHand : ActionContinuousBase
{
	ref static const array<string> TREES_ALLOWED =
	{
		"treehard_t_piceaabies_2d_dark",
		"treehard_t_piceaabies_2s_dark",
		"treehard_t_piceaabies_3d_dark",
		"treehard_t_piceaabies_2d",
		"treehard_t_piceaabies_3d",
		"treehard_t_fagussylvatica_3d"
	};

	void ActionMineBarkByHand()
	{
		m_CallbackClass = ActionMineBarkByHandCB;
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

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		if (player.GetBrokenLegs() == eBrokenLegs.BROKEN_LEGS || item)
			return false;

		Object targetObject = target.GetObject();
		WoodBase wood = WoodBase.Cast(targetObject);

		if (!wood)
			return false;

		if (!targetObject || !targetObject.IsTree() || !targetObject.IsCuttable())
			return false;

		string objType = targetObject.GetType();
		objType.ToLower();

		if (wood.GetBarkType() == "Bark_Birch")
			return true;

		foreach (string s : TREES_ALLOWED)
		{
			if (s == objType)
				return true;
		}
		
		return false;
	}

	override void OnFinishProgressServer(ActionData action_data)
	{
		// Attempt to create bark in player hands, if not possible just drop it onto the ground
		Object targetObject = action_data.m_Target.GetObject();
		WoodBase wood = WoodBase.Cast(targetObject);

		ItemBase woodItem = ItemBase.Cast(action_data.m_Player.GetHumanInventory().CreateInHands(wood.GetBarkType()));
		if (!woodItem)
		{
			woodItem = ItemBase.Cast(GetGame().CreateObjectEx(wood.GetBarkType(), action_data.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE));
		}

		if (woodItem)
		{
			woodItem.SetHealth(Math.RandomIntInclusive(0, 10));
		}
		else
		{
			// No bark was created - don't bleed!
			return;
		}

		// Update player hands
		PlayerBase player = action_data.m_Player;
		PluginLifespan module_lifespan = PluginLifespan.Cast(GetPlugin(PluginLifespan));
		module_lifespan.UpdateBloodyHandsVisibility(player, true);
		DamagePlayersHands(action_data.m_Player);
	}

	override void OnActionInfoUpdate(PlayerBase player, ActionTarget target, ItemBase item)
	{
		m_Text = "#harvest" + " " + GetYieldName(player, target, item);
	}

	string GetYieldName(PlayerBase player, ActionTarget target, ItemBase item)
	{
		Object targetObject = target.GetObject();
		WoodBase wood = WoodBase.Cast(targetObject);

		if (wood)
		{
			return MiscGameplayFunctions.GetItemDisplayName(wood.GetBarkType());
		}

		return "ERROR";
	}

	void DamagePlayersHands(PlayerBase player)
	{
		ItemBase gloves = ItemBase.Cast(player.FindAttachmentBySlotName("Gloves"));
		if (gloves && !gloves.IsDamageDestroyed())
		{
			gloves.DecreaseHealth("", "", 10);
		}
		else
		{
			int rand = Math.RandomIntInclusive(0, 1);
			if (rand == 0 && !player.GetBleedingManagerServer().AttemptAddBleedingSourceBySelection("LeftForeArmRoll"))
			{
				player.GetBleedingManagerServer().AttemptAddBleedingSourceBySelection("RightForeArmRoll");
			}
			else if (rand == 1 && !player.GetBleedingManagerServer().AttemptAddBleedingSourceBySelection("RightForeArmRoll"))
			{
				player.GetBleedingManagerServer().AttemptAddBleedingSourceBySelection("LeftForeArmRoll");
			}

			if (player.GetBleedingManagerServer().m_BleedingSources.Count() > 0)
				player.GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_PAIN_LIGHT);
		}
	}
};