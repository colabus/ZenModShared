/*class CombineGasMaskFilters extends RecipeBase
{
	override void Init()
	{
		string useItem		= "GasMask_Filter";
		string onItem		= "GasMask_Filter";

		m_Name = "#layout_icon_combine";	// action name in game
		m_IsInstaRecipe = false;	// should this recipe be performed instantly without animation
		m_AnimationLength = 1;		// animation length in relative time units
		m_Specialty = 0;			// softskills modifier. value > 0 for roughness, value < 0 for precision
		
		//conditions
		m_MinDamageIngredient[0] = -1;	//-1 = disable check
		m_MaxDamageIngredient[0] = 3;	//-1 = disable check
		m_MinQuantityIngredient[0] = -1;	//quantity required for primary ingredient
		m_MaxQuantityIngredient[0] = -1;//-1 = disable check
		
		m_MinDamageIngredient[1] = -1;	//-1 = disable check
		m_MaxDamageIngredient[1] = 3;	//-1 = disable check
		m_MinQuantityIngredient[1] = -1;	//quantity required for secondary ingredient
		m_MaxQuantityIngredient[1] = -1;//-1 = disable check
		
		//ingredient 1  
		InsertIngredient(0,useItem);	// primary ingredient
		
		m_IngredientAddHealth[0] = -1;	// -1 = do nothing
		m_IngredientSetHealth[0] = -1; 	// -1 = do nothing
		m_IngredientAddQuantity[0] = -1;// -1 = do nothing
		m_IngredientDestroy[0] = false;
		m_IngredientUseSoftSkills[0] = false;	// set 'true' to allow modification of the values by softskills on this ingredient
		
		//ingredient 2	
		InsertIngredient(1,onItem); //  secondary ingredient
		
		m_IngredientAddHealth[1] = -1;	// -1 = do nothing
		m_IngredientSetHealth[1] = -1; 	// -1 = do nothing
		m_IngredientAddQuantity[1] = -1;// -1 = do nothing
		m_IngredientDestroy[1] = false;		// destroy secondary ingredient
		m_IngredientUseSoftSkills[1] = false;	// set 'true' to allow modification of the values by softskills on this ingredient
	}

	override bool CanDo(ItemBase ingredients[], PlayerBase player)//final check for recipe's validity
	{
		ItemBase ingredient1 = ingredients[0];
		ItemBase ingredient2 = ingredients[1];

		if (ingredient1.GetQuantity() > 0 || ingredient2.GetQuantity() > 0)
		{
			if (ingredient1.GetQuantity() < ingredient1.GetQuantityMax() || ingredient2.GetQuantity() < ingredient2.GetQuantityMax())
				return true;
		}
		
		return false;
	}

	override void Do(ItemBase ingredients[], PlayerBase player, array<ItemBase> results, float specialty_weight)//gets called upon recipe's completion
	{
		ItemBase sourceFilter;
		ItemBase targetFilter;

		if (ingredients[0].GetQuantity() > ingredients[1].GetQuantity())
		{
			sourceFilter = ingredients[0];
			targetFilter = ingredients[1];
		}
		else
		{
			sourceFilter = ingredients[1];
			targetFilter = ingredients[0];
		}

		// Calculate the quantity to transfer
		float transferQty = Math.Min(sourceFilter.GetQuantity(), targetFilter.GetQuantityMax() - targetFilter.GetQuantity());

		// Transfer the quantity
		if (transferQty > 0)
		{
			// Transfer filters
			targetFilter.AddQuantity(transferQty);
			sourceFilter.AddQuantity(-transferQty);

			// Damage filters by 5%
			targetFilter.AddHealth((targetFilter.GetMaxHealth() * 0.1) * -1);
			sourceFilter.AddHealth((sourceFilter.GetMaxHealth() * 0.1) * -1);
		}
	}
}*/