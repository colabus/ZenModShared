/*class Zen_BarrelRecipe extends RecipeBase   // Our example recipe which uses primary ingredient - our custom item MagicHammer to turn any other secondary ingredient ( all ItemBase items ) into stones. 
{
	override void Init()
	{
		int recipeMakeCost = 99;
		int recipeResourceCost = 10;
		string makeItem = "Nail";
		string resourceItem = "MetalPlate";

		m_Name = "Craft Barrel";	// action name in game
		m_IsInstaRecipe = false;	// should this recipe be performed instantly without animation
		m_AnimationLength = 1;		// animation length in relative time units
		m_Specialty = 0;			// softskills modifier. value > 0 for roughness, value < 0 for precision

		//conditions
		m_MinDamageIngredient[0] = -1;	//-1 = disable check
		m_MaxDamageIngredient[0] = -1;	//-1 = disable check
		m_MinQuantityIngredient[0] = recipeMakeCost;	//quantity required for primary ingredient
		m_MaxQuantityIngredient[0] = -1;//-1 = disable check

		m_MinDamageIngredient[1] = -1;	//-1 = disable check
		m_MaxDamageIngredient[1] = -1;	//-1 = disable check
		m_MinQuantityIngredient[1] = recipeResourceCost;	//quantity required for secondary ingredient
		m_MaxQuantityIngredient[1] = -1;//-1 = disable check

		//ingredient 1  
		InsertIngredient(0, makeItem);	// primary ingredient

		m_IngredientAddHealth[0] = -1;	// -1 = do nothing
		m_IngredientSetHealth[0] = -1; 	// -1 = do nothing
		m_IngredientAddQuantity[0] = -recipeMakeCost;// -1 = do nothing
		m_IngredientDestroy[0] = false;
		m_IngredientUseSoftSkills[0] = false;	// set 'true' to allow modification of the values by softskills on this ingredient

		//ingredient 2	
		InsertIngredient(1, resourceItem); //  secondary ingredient

		m_IngredientAddHealth[1] = -1;	// -1 = do nothing
		m_IngredientSetHealth[1] = -1; 	// -1 = do nothing
		m_IngredientAddQuantity[1] = -recipeResourceCost;// -1 = do nothing
		m_IngredientDestroy[1] = false;		// destroy secondary ingredient
		m_IngredientUseSoftSkills[1] = false;	// set 'true' to allow modification of the values by softskills on this ingredient
	}

	// Spawn random barrel
	override void Do(ItemBase ingredients[], PlayerBase player, array<ItemBase> results, float specialty_weight)//gets called upon recipe's completion
	{
		array<string> barrelTypes = { "Barrel_Blue", "Barrel_Green", "Barrel_Red", "Barrel_Yellow" };
		GetGame().CreateObjectEx(barrelTypes.GetRandomElement(), player.GetPosition(), ECE_PLACE_ON_SURFACE);
	}
}*/