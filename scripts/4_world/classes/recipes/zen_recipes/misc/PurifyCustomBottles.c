modded class PurifyWater extends RecipeBase
{	
	override void Init()
	{
		super.Init();

		// custom items
		InsertIngredient(1,"Empty_BeerBottle");
		InsertIngredient(1,"Empty_SodaCan_ColorBase");
		InsertIngredient(1,"Empty_Vodka");
	}

	override bool CanDo(ItemBase ingredients[], PlayerBase player)//final check for recipe's validity
	{
		return ingredients[1].GetQuantity() > 0;
	}

	override void Do(ItemBase ingredients[], PlayerBase player,array<ItemBase> results, float specialty_weight)//gets called upon recipe's completion
	{
		ItemBase ingredient2 = ingredients[1];
		ingredient2.RemoveAllAgents();
		ingredient2.SetCleanness(1);
	}
};
