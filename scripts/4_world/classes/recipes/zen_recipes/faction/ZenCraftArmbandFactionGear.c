class ZenCraftArmbandFactionGear extends RecipeBase
{
	override void Init()
	{
		m_Name = "Convert to faction";

		m_IsInstaRecipe = false;//should this recipe be performed instantly without animation
		m_AnimationLength = 2;//animation length in relative time units
		m_Specialty = 0.02;// value > 0 for roughness, value < 0 for precision

		//conditions
		m_MinDamageIngredient[0] = -1;//-1 = disable check
		m_MaxDamageIngredient[0] = 3;//-1 = disable check

		m_MinQuantityIngredient[0] = -1;//-1 = disable check
		m_MaxQuantityIngredient[0] = -1;//-1 = disable check

		m_MinDamageIngredient[1] = -1;//-1 = disable check
		m_MaxDamageIngredient[1] = 3;//-1 = disable check

		m_MinQuantityIngredient[1] = -1;//-1 = disable check
		m_MaxQuantityIngredient[1] = -1;//-1 = disable check
		//----------------------------------------------------------------------------------------------------------------------

		//INGREDIENTS
		//ingredient 1
		InsertIngredient(0, "Armband_ColorBase");//you can insert multiple ingredients this way

		m_IngredientAddHealth[0] = -10;// 0 = do nothing
		m_IngredientSetHealth[0] = -1; // -1 = do nothing
		m_IngredientAddQuantity[0] = 0;// 0 = do nothing
		m_IngredientDestroy[0] = false;//true = destroy, false = do nothing
		m_IngredientUseSoftSkills[0] = false;// set 'true' to allow modification of the values by softskills on this ingredient

		//ingredient 2
		InsertIngredient(1, "Inventory_Base");

		m_IngredientAddHealth[1] = 0;// 0 = do nothing
		m_IngredientSetHealth[1] = -1; // -1 = do nothing
		m_IngredientAddQuantity[1] = -1;// 0 = do nothing
		m_IngredientDestroy[1] = false;// false = do nothing
		m_IngredientUseSoftSkills[1] = false;// set 'true' to allow modification of the values by softskills on this ingredient
		//----------------------------------------------------------------------------------------------------------------------
	}

	override bool CanDo(ItemBase ingredients[], PlayerBase player)//final check for recipe's validity
	{
		// Player needs to belong to the faction of the armband
		if (!ingredients[0].GetType().Contains(player.GetMyFactionID()))
			return false;

		// Item can't have already been converted
		if (ingredients[1].GetType().Contains(player.GetMyFactionID()))
			return false;

		// Item we plan to spawn needs to exist in CfgVehicles
		if (!GetGame().ConfigIsExisting("CfgVehicles " + GetFactionCfg(ingredients)))
		{
			return false;
		}

		return true;
	}

	string GetFactionCfg(ItemBase ingredients[])
	{
		string cfgToFind = ingredients[1].GetType();
		string faction = ingredients[0].GetType();
		faction.Replace("Armband_", "");
		cfgToFind.Replace("Zen_", "");
		cfgToFind.Replace("Spur_", "Spur-");

		// Remove everything after first underscore
		if (cfgToFind.IndexOf("_") > -1)
		{
			cfgToFind = cfgToFind.Substring(0, cfgToFind.IndexOf("_"));
			cfgToFind.Replace("Spur-", "Spur_");

			//ZenFunctions.DebugMessage("NEW CFG: " + cfgToFind);
		}

		cfgToFind = cfgToFind + "_" + faction;
		return cfgToFind;
	}

	override void Do(ItemBase ingredients[], PlayerBase player, array<ItemBase> results, float specialty_weight)
	{
		//ZenFunctions.DebugMessage("CONVERT TO: " + GetFactionCfg(ingredients));

		string itemToSpawn = GetFactionCfg(ingredients);
		ItemBase convertedItem = ItemBase.Cast(GetGame().CreateObjectEx(itemToSpawn, ingredients[1].GetPosition(), ECE_PLACE_ON_SURFACE));
		if (convertedItem)
		{
			ZenFunctions.MoveInventory(ingredients[1], convertedItem);
			convertedItem.SetOrientation(ingredients[1].GetOrientation());
			convertedItem.SetHealth(ingredients[1].GetHealth());

			// Set lifetime here so we don't need Types entry
			convertedItem.SetLifetime(14440);
			convertedItem.SetLifetimeMax(14440);
		}
		else 
		{
			ZenFunctions.SendPlayerMessage(player, "Error! Failed to spawn faction item - email admin@hardcoredayz.com to get this fixed");
		}
	}
};