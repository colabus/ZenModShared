class Zen_PaintVehiclesBlack extends RecipeBase
{
	static ref TStringArray m_Paintables = 
	{ 
		"CivSedanDoors_Driver",
		"CivSedanDoors_CoDriver",
		"CivSedanDoors_BackLeft",
		"CivSedanDoors_BackRight",
		"CivSedanHood",
		"CivSedanTrunk",
		"Hatchback_02_Door_1_1",
		"Hatchback_02_Door_2_1",
		"Hatchback_02_Door_1_2",
		"Hatchback_02_Door_2_2",
		"Hatchback_02_Hood",
		"Hatchback_02_Trunk",
	};

	override void Init()
	{
		int cost = 25;
		m_Name = "Paint Black";

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

		//result1
		AddResult("");//add results here

		m_ResultSetFullQuantity[0] = true;//true = set full quantity, false = do nothing
		m_ResultSetQuantity[0] = -1;//-1 = do nothing
		m_ResultSetHealth[0] = -1;//-1 = do nothing
		m_ResultInheritsHealth[0] = -1;// (value) == -1 means do nothing; a (value) >= 0 means this result will inherit health from ingredient number (value);(value) == -2 means this result will inherit health from all ingredients averaged(result_health = combined_health_of_ingredients / number_of_ingredients)
		m_ResultInheritsColor[0] = -1;// (value) == -1 means do nothing; a (value) >= 0 means this result classname will be a composite of the name provided in AddResult method and config value "color" of ingredient (value)
		m_ResultToInventory[0] = -2;//(value) == -2 spawn result on the ground;(value) == -1 place anywhere in the players inventory, (value) >= 0 means switch position with ingredient number(value)
		m_ResultUseSoftSkills[0] = false;// set 'true' to allow modification of the values by softskills on this result
		m_ResultReplacesIngredient[0] = -1;// value == -1 means do nothing; a value >= 0 means this result will transfer item propertiesvariables, attachments etc.. from an ingredient value
	}

	override void Do(ItemBase ingredients[], PlayerBase player, array<ItemBase> results, float specialty_weight)//gets called upon recipe's completion
	{
		string cfgToFind = ingredients[1].GetType();
		cfgToFind.Replace("_WineRust", "");
		cfgToFind.Replace("_Wine", "");
		cfgToFind.Replace("_BlackRust", "");
		cfgToFind.Replace("_Black", "");
		cfgToFind.Replace("_WhiteRust", "");
		cfgToFind.Replace("_White", "");
		cfgToFind.Replace("_BlueRust", "");
		cfgToFind.Replace("_Blue", "");
		cfgToFind.Replace("_GreenRust", "");

		string colorType = "_Black";
		
		ItemBase paintedItem = ItemBase.Cast(GetGame().CreateObjectEx(cfgToFind + colorType, ingredients[1].GetPosition(), ECE_PLACE_ON_SURFACE));
		if (paintedItem)
		{
			paintedItem.SetOrientation(ingredients[1].GetOrientation());
			paintedItem.SetHealth(ingredients[1].GetHealth());
			ingredients[1].DeleteSafe();
		}
	}

	override string GetSoundCategory(int ingredientIndex, ItemBase item)
	{
		return "Zen_SprayPaint";
	}
};