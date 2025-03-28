modded class GasMask_Filter
{
	override void InitItemVariables()
	{
		super.InitItemVariables();
		can_this_be_combined = true;
	}

	/*override void OnCombine(ItemBase other_item)
	{
		super.OnCombine(other_item);

		if (other_item.GetQuantity() <= 0)
			other_item.SetHealth(0);
	}*/
}