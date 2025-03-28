modded class ActionLowerFlag
{
	// Don't allow lowering flags unless you're near the base 
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		TerritoryFlag totem = TerritoryFlag.Cast(target.GetObject());
		if (!totem)
		{
			return false;
		}
		
		float state = totem.GetAnimationPhase("flag_mast");
		if ( totem.FindAttachmentBySlotName("Material_FPole_Flag") && state < 1)
		{
			return vector.Distance(totem.GetPosition(), player.GetPosition()) < 2.0;
		}

		return false;
	}
}