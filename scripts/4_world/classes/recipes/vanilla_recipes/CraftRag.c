modded class CraftRag
{	
	override bool CanDo(ItemBase ingredients[], PlayerBase player)
	{
		if (ingredients[1].IsInherited(Flag_Base))
		{
			InventoryLocation il = new InventoryLocation;
			ingredients[1].GetInventory().GetCurrentInventoryLocation(il);
			InventoryLocationType type = il.GetType();

			if (type == InventoryLocationType.ATTACHMENT)
				return false;
		}

		return super.CanDo(ingredients, player);
	}
}