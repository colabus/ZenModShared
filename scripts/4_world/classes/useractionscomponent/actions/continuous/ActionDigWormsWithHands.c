class ActionDigWormsWithHandsCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.DIG_WORMS * 2);
	}
};

class ActionDigWormsWithHands : ActionContinuousBase
{
	void ActionDigWormsWithHands()
	{
		m_CallbackClass = ActionDigWormsWithHandsCB;
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_MEDIUM;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_CRAFTING;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH;
		m_FullBody = true;
		m_Text = "#dig_up_worms";
	}

	override void CreateConditionComponents()
	{
		m_ConditionTarget = new CCTSurface(UAMaxDistances.DEFAULT);
		m_ConditionItem = new CCINone;
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		if (item)
			return false;

		// Don't allow on Winter Livonia or Namalsk
		#ifdef WINTER
		return false;
		#endif

		if (player.IsPlacingLocal())
			return false;

		// Check if player is standing on terrain
		vector plr_pos = player.GetPosition();
		float height = GetGame().SurfaceY(plr_pos[0], plr_pos[2]);
		height = plr_pos[1] - height;

		if (height > 0.4)
			return false; // Player is not standing on ground

		if (GetGame().IsDedicatedServer())
			return true;

		if (ZenFunctions.GetCameraPitch() > -80)
			return false;

		if (target)
		{
			string surface_type;
			vector position;
			position = target.GetCursorHitPos();

			GetGame().SurfaceGetType(position[0], position[2], surface_type);

			if (GetGame().IsSurfaceFertile(surface_type) && surface_type == "en_soil")
			{
				return true;
			}
		}

		return false;
	}

	override bool ActionConditionContinue(ActionData action_data)
	{
		return true;
	}

	override bool HasTarget()
	{
		return true;
	}

	override void OnFinishProgressServer(ActionData action_data)
	{
		if (Math.RandomFloat01() < 0.2)
		{
			ItemBase stone;
			Class.CastTo(stone, GetGame().CreateObjectEx("SmallStone", action_data.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE));
			stone.SetHealth(Math.RandomFloatInclusive(10, 25));
			action_data.m_Player.GetSoftSkillsManager().AddSpecialty(m_SpecialtyWeight);
			ZenFunctions.SendPlayerMessage(action_data.m_Player, "No worms here, but I did find a stone...");
			return;
		}

		if (Math.RandomFloat01() < 0.5)
		{
			ZenFunctions.SendPlayerMessage(action_data.m_Player, "Damn... I didn't find anything");
			return;
		}

		ItemBase worms;
		Class.CastTo(worms, GetGame().CreateObjectEx("Worm", action_data.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE));
		worms.SetQuantity(10, false);
		worms.SetHealth(1);
		action_data.m_Player.GetSoftSkillsManager().AddSpecialty(m_SpecialtyWeight);

		ItemBase gloves = ItemBase.Cast(action_data.m_Player.FindAttachmentBySlotName("Gloves"));
		if (gloves && !gloves.IsDamageDestroyed())
		{
			gloves.DecreaseHealth("", "", 10);
		}
		else
		{
			int rand = Math.RandomIntInclusive(0, 9);
			if (rand == 0 && !action_data.m_Player.GetBleedingManagerServer().AttemptAddBleedingSourceBySelection("LeftForeArmRoll"))
			{
				action_data.m_Player.GetBleedingManagerServer().AttemptAddBleedingSourceBySelection("RightForeArmRoll");
			}
			else if (rand == 1 && !action_data.m_Player.GetBleedingManagerServer().AttemptAddBleedingSourceBySelection("RightForeArmRoll"))
			{
				action_data.m_Player.GetBleedingManagerServer().AttemptAddBleedingSourceBySelection("LeftForeArmRoll");
			}

			if (action_data.m_Player.GetBleedingManagerServer().m_BleedingSources.Count() > 0)
				action_data.m_Player.GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_PAIN_LIGHT);
		}
	}
};