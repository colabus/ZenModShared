class Zen_PaintRecipes extends RecipeBase
{
	static ref TStringArray m_Paintables = 
	{ 
		"Mosin9130",
		"AK74",
		"AK101",
		"Mag_AKM_Drum75Rnd",
		"AK_FoldingBttstck",
		"AK_PlasticBttstck",
		"AK_RailHndgrd",
		"AKS74U",
		"AK_WoodBttstck",
		"AK74_WoodBttstck",
		"AK_WoodHndgrd",
		"M4A1_Green",
		"M4_RISHndgrd",
		"FirefighterAxe",
		"CZ527",
		"Winchester70",
		"SawedoffMosin9130",
		"HuntingKnife",
		"AK_Bayonet",
		"M9A1_Bayonet"
	};

	override void Init()
	{
		int cost = 25;
		m_Name = "Paint";

		m_IsInstaRecipe = false;//should this recipe be performed instantly without animation
		m_AnimationLength = 2;//animation length in relative time units
		m_Specialty = 0.02;// value > 0 for roughness, value < 0 for precision

		//conditions
		m_MinDamageIngredient[0] = -1;//-1 = disable check
		m_MaxDamageIngredient[0] = 3;//-1 = disable check

		m_MinQuantityIngredient[0] = cost;//-1 = disable check
		m_MaxQuantityIngredient[0] = -1;//-1 = disable check

		m_MinDamageIngredient[1] = -1;//-1 = disable check
		m_MaxDamageIngredient[1] = 3;//-1 = disable check

		m_MinQuantityIngredient[1] = -1;//-1 = disable check
		m_MaxQuantityIngredient[1] = -1;//-1 = disable check
		//----------------------------------------------------------------------------------------------------------------------

		//INGREDIENTS
		//ingredient 1
		InsertIngredient(0, "Spraycan_Black");//you can insert multiple ingredients this way
		InsertIngredient(0, "Spraycan_Green");

		m_IngredientAddHealth[0] = 0;// 0 = do nothing
		m_IngredientSetHealth[0] = -1; // -1 = do nothing
		m_IngredientAddQuantity[0] = -cost;// 0 = do nothing
		m_IngredientDestroy[0] = false;//true = destroy, false = do nothing
		m_IngredientUseSoftSkills[0] = false;// set 'true' to allow modification of the values by softskills on this ingredient

		//ingredient 2
		for (int i = 0; i < m_Paintables.Count(); i++)
		{
			InsertIngredient(1, m_Paintables.Get(i));
		}

		//InsertIngredient(1, "Weapon_Base");//you can insert multiple ingredients this way
		//InsertIngredient(1, "Inventory_Base");
		//InsertIngredient(1, "ToolBase");
		//InsertIngredient(1, "ButtstockBase");

		m_IngredientAddHealth[1] = 0;// 0 = do nothing
		m_IngredientSetHealth[1] = -1; // -1 = do nothing
		m_IngredientAddQuantity[1] = -1;// 0 = do nothing
		m_IngredientDestroy[1] = false;// false = do nothing
		m_IngredientUseSoftSkills[1] = false;// set 'true' to allow modification of the values by softskills on this ingredient
		//----------------------------------------------------------------------------------------------------------------------
	}

	override bool CanDo(ItemBase ingredients[], PlayerBase player)//final check for recipe's validity
	{
		if (ingredients[0].GetType().Contains("Black"))
		{
			m_Name = "Paint Black";
		}
		else
		if (ingredients[0].GetType().Contains("Green"))
		{
			m_Name = "Paint Green";
		}

		return true;
	}

	override void Do(ItemBase ingredients[], PlayerBase player, array<ItemBase> results, float specialty_weight)//gets called upon recipe's completion
	{
		string cfgToFind = ingredients[1].GetType();
		cfgToFind.Replace("_Black", "");
		cfgToFind.Replace("_Green", "");
		cfgToFind.Replace("_Camo", "");

		string colorType = "";
		if (ingredients[0].GetType().Contains("Black"))
			colorType = "_Black";
		else
		if (ingredients[0].GetType().Contains("Green"))
			colorType = "_Green";
		
		ItemBase paintedItem = ItemBase.Cast(GetGame().CreateObjectEx(cfgToFind + colorType, ingredients[1].GetPosition(), ECE_PLACE_ON_SURFACE));
		if (paintedItem)
		{
			paintedItem.SetOrientation(ingredients[1].GetOrientation());
			paintedItem.SetHealth(ingredients[1].GetHealth());
			paintedItem.SetLifetime(14400);	
			ZenFunctions.MoveInventory(ingredients[1], paintedItem);
			paintedItem.PlaceOnSurface();
		}
	}

	override string GetSoundCategory(int ingredientIndex, ItemBase item)
	{
		return "Zen_SprayPaint";
	}
};