modded class ActionAttachExplosivesTrigger : ActionContinuousBase
{
	override void OnFinishProgressServer(ActionData action_data)
	{
		ExplosivesBase explosive = ExplosivesBase.Cast(action_data.m_Target.GetObject());
		if (!explosive)
			return;

		if (!explosive.GetType().Contains("Plastic_Explosive"))
		{
			super.OnFinishProgressServer(action_data);
			return;
		}

		vector pos = explosive.GetPosition();
		vector ori = explosive.GetOrientation();

		super.OnFinishProgressServer(action_data);

		// This places explosive back where it was instead of on ground as vanilla does
		explosive.SetPosition(pos);
		explosive.SetOrientation(ori);
		explosive.SetSynchDirty();
	}
};