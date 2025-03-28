class CatShirtRecipe extends RecipeBase
{
	override void Init()
	{
		string useItem = "Zen_Shirt_HunterCat";
		string onItem = "Zen_Shirt_PharaohCat";
		string resultItem = "Zen_Shirt_BothCat";

		m_Name = "Make kitty best friends shirt";	// action name in game
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

	override void Do(ItemBase ingredients[], PlayerBase player, array<ItemBase> results, float specialty_weight)//gets called upon recipe's completion
	{
		if ((ingredients[0] && ingredients[0].GetInventory().GetCargo().GetItemCount() > 0) || (ingredients[1] && ingredients[1].GetInventory().GetCargo().GetItemCount() > 0))
		{
			player.Zen_SendMessage("The shirts must be empty before I combine them!");
			return;
		}

		ItemBase shirt = ItemBase.Cast(GetGame().CreateObjectEx("Zen_Shirt_BothCat", player.GetPosition(), ECE_PLACE_ON_SURFACE));
		GetGame().ObjectDelete(ingredients[0]);
		GetGame().ObjectDelete(ingredients[1]);
	}
}