modded class RepairWithTape
{
	override bool CanDo(ItemBase ingredients[], PlayerBase player)
	{
		if (super.CanDo(ingredients, player)) // Disable tape being used to repair clothing
		{
			return !ingredients[0].IsKindOf("Clothing") && !ingredients[1].IsKindOf("Clothing");
		}

		return false;
	}
}