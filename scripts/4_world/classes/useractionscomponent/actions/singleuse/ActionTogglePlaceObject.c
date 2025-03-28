modded class ActionTogglePlaceObject
{
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		if (item != NULL && item.Type() == Zen_CraftableMapKit)
		{
			Zen_CraftableMapKit kit = Zen_CraftableMapKit.Cast(item);
			if (kit)
			{
				return kit.HasMapAttached();
			}
		}
		
		return super.ActionCondition(player, target, item);
	}
}