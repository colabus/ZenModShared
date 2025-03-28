/*class ZenBloodTestReport
{
	// This code is adapted from Lucian's Medical Attention Mod
	static void DisplayReport(ActionBase action, PlayerBase player, PlayerBase target)
	{
		EStatLevels immunityLevel = target.GetImmunityLevel();
		string immunityLevelStr;
		switch (immunityLevel)
		{
		case EStatLevels.GREAT: immunityLevelStr = "VERY HIGH"; break;
		case EStatLevels.HIGH: immunityLevelStr = "HIGH"; break;
		case EStatLevels.MEDIUM: immunityLevelStr = "MEDIUM"; break;
		case EStatLevels.LOW: immunityLevelStr = "LOW"; break;
		case EStatLevels.CRITICAL: immunityLevelStr = "CRITICAL"; break;
		}

		if (target.GetSingleAgentCountNormalized(VirusAgents.VIRUS) > 0)
		{
			immunityLevelStr = "CRITICAL";
		}

		action.SendMessageToClient(player, player.GetIdentity().GetName() + "'s Blood Test Report:");
		action.SendMessageToClient(player, "Immunity Level: " + immunityLevelStr);
		action.SendMessageToClient(player, "Cholera: " + (target.GetSingleAgentCountNormalized(eAgents.CHOLERA) * 100).ToString() + "%");
		action.SendMessageToClient(player, "Salmonella: " + (target.GetSingleAgentCountNormalized(eAgents.SALMONELLA) * 100).ToString() + "%");
		action.SendMessageToClient(player, "Influenza: " + (target.GetSingleAgentCountNormalized(eAgents.INFLUENZA) * 100).ToString() + "%");
		action.SendMessageToClient(player, "Food Poison: " + (target.GetSingleAgentCountNormalized(eAgents.FOOD_POISON) * 100).ToString() + "%");
		action.SendMessageToClient(player, "Chemical Poison: " + (target.GetSingleAgentCountNormalized(eAgents.CHEMICAL_POISON) * 100).ToString() + "%");
		action.SendMessageToClient(player, "Wound Infection: " + (target.GetSingleAgentCountNormalized(eAgents.WOUND_AGENT) * 100).ToString() + "%");
		action.SendMessageToClient(player, "Zombie Virus Infection: " + (target.GetSingleAgentCountNormalized(VirusAgents.VIRUS) * 100).ToString() + "%");

		string recommendedTreatment = "";
		int virusCount = 0;

		if (target.GetSingleAgentCountNormalized(eAgents.CHOLERA) > 0 || target.GetSingleAgentCountNormalized(eAgents.INFLUENZA))
		{
			recommendedTreatment = "Take vitamins and antibiotics regularly. Use IV fluids to speed up immune system recovery.";
			virusCount++;
		}

		if (target.GetSingleAgentCountNormalized(eAgents.SALMONELLA) > 0 || target.GetSingleAgentCountNormalized(eAgents.FOOD_POISON) > 0)
		{
			recommendedTreatment = "Take charcoal tablets and antibiotics regularly. Use IV fluids to speed up immune system recovery.";
			virusCount++;
		}

		if (target.GetSingleAgentCountNormalized(eAgents.CHEMICAL_POISON) > 0)
		{
			recommendedTreatment = "Take a PO-X antidote as soon as possible.";
			virusCount++;
		}

		if (target.GetSingleAgentCountNormalized(VirusAgents.VIRUS) > 0)
		{
			recommendedTreatment = "Take a virus cure as soon as possible. To make one you need a blood bag, a petridish, a microscope with a battery, an infected brain and an empty syringe.";
			virusCount++;
		}

		if (target.GetSingleAgentCountNormalized(eAgents.WOUND_AGENT) > 0)
		{
			recommendedTreatment = "Take antibiotics regularly and disinfect wounds with alcohol or iodine.";
			virusCount++;
		}

		if (recommendedTreatment != "")
		{
			if (virusCount >= 2)
			{
				GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(SendTreatment, 1000, false, player, "RECOMMENDED TREATMENT: Multiple viruses detected. Priority: " + recommendedTreatment);
			}
			else
			{
				GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(SendTreatment, 1000, false, player, "RECOMMENDED TREATMENT: " + recommendedTreatment);
			}
		}
	}

	static void SendTreatment(PlayerBase player, string msg)
	{
		player.Zen_SendMessage(msg);
	}
}

modded class ActionTestBloodSelf
{
	override void OnFinishProgressServer(ActionData action_data)
	{
		super.OnFinishProgressServer(action_data);
		ZenBloodTestReport.DisplayReport(this, action_data.m_Player, action_data.m_Player);
	}
}

modded class ActionTestBloodTarget
{
	override void OnFinishProgressServer(ActionData action_data)
	{
		super.OnFinishProgressServer(action_data);
		PlayerBase ntarget = PlayerBase.Cast(action_data.m_Target.GetObject());
		ZenBloodTestReport.DisplayReport(this, action_data.m_Player, ntarget);
	}
}
*/