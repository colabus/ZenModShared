modded class CraftArmbandFlag
{
	override bool CanDo(ItemBase ingredients[], PlayerBase player)
	{
		InventoryLocation il = new InventoryLocation;
		ingredients[0].GetInventory().GetCurrentInventoryLocation(il);
		InventoryLocationType type = il.GetType();

		if (type == InventoryLocationType.ATTACHMENT)
			return false;

		return ingredients[0].IsEmpty();
	}
}
