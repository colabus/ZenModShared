modded class ActionCheckPulseTarget: ActionContinuousBase
{
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		PlayerBase ntarget = PlayerBase.Cast(target.GetObject());
		if (ntarget && ntarget.IsAlive() && ntarget.IsUnconscious())
		{
			return true;
		}
		
		return false;
	}
}