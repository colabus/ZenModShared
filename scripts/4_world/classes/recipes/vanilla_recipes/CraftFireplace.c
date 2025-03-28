modded class CraftFireplace
{
	override void Init()
	{
		super.Init();

		// Damage fireplace ingredients over time if player repeatedly makes a fire
		m_IngredientAddHealth[0] = -10;
		m_IngredientAddHealth[1] = -10;
	}

	override void Do(ItemBase ingredients[], PlayerBase player, array<ItemBase> results, float specialty_weight)//gets called upon recipe's completion
	{
		super.Do(ingredients, player, results, specialty_weight);

		ItemBase result = ItemBase.Cast(results.Get(0));
		if (result)
		{
			result.SetLifetimeMax(28800);
			result.SetLifetime(28800);
		}
	}
}