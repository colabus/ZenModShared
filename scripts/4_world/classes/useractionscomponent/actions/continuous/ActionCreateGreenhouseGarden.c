modded class ActionCreateGreenhouseGardenPlotCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		float time_spent = UATimeSpent.DIG_GARDEN * 4.0;

		if (m_ActionData.m_MainItem.KindOf("Knife"))
			time_spent = time_spent * 1.2;

		m_ActionData.m_ActionComponent = new CAContinuousTime(time_spent);
	}
};

modded class ActionCreateGreenhouseGardenPlot
{
	override bool SetupAction(PlayerBase player, ActionTarget target, ItemBase item, out ActionData action_data, Param extra_data = NULL)
	{
		if (super.SetupAction(player, target, item, action_data, extra_data))
		{
			if (item)
			{
				SetDiggingAnimation(item);
			}

			return true;
		}

		return false;
	}

	void SetDiggingAnimation(ItemBase item)
	{
		if (item.KindOf("Knife") || item.KindOf("Screwdriver"))
		{
			m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DEPLOY_1HD;
			m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
		}
		else
		{
			m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DIGMANIPULATE;
			m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;
		}
	}
}