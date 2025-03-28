modded class ActionWringClothesCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousRepeat(UATimeSpent.WASH_HANDS / 2.0);
	}
};

modded class ActionWringClothes
{
	override void OnFinishProgressServer(ActionData action_data)
	{
		float wetness = action_data.m_MainItem.GetWet();
		float wet_change;

		if (wetness >= GameConstants.STATE_DRENCHED)
		{
			wet_change = Math.RandomFloat(GameConstants.STATE_SOAKING_WET, GameConstants.STATE_DRENCHED);
		}
		else if (wetness >= GameConstants.STATE_SOAKING_WET)
		{
			wet_change = Math.RandomFloat(GameConstants.STATE_WET, GameConstants.STATE_SOAKING_WET);
		}
		else if (wetness >= GameConstants.STATE_WET)
		{
			wet_change = Math.RandomFloat(GameConstants.STATE_DAMP, GameConstants.STATE_WET);
		}

		wet_change /= 2.0;

		action_data.m_MainItem.SetWet(wet_change);
		action_data.m_Player.GetSoftSkillsManager().AddSpecialty(m_SpecialtyWeight);
	}
};