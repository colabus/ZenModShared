modded class RepairEpoxy extends RecipeBase
{
	ref static const array<string> REPAIRABLE =
	{
		"CarRadiator",
		"Canteen",
		"WorkingBoots_",
		"CombatBoots_",
		"HikingBootsLow_",
		"JungleBoots_",
		"MilitaryBoots_",
		"TTSKOBoots",
		"Glasses",
		"Pot",
		"Shovel"
	};

	override bool CanDo(ItemBase ingredients[], PlayerBase player) // Final check for recipe's validity
	{
		ItemBase item1;
		Class.CastTo(item1, ingredients[0]);
		ItemBase item2;
		Class.CastTo(item2, ingredients[1]);

		// Don't allow epoxy to repair a plate if it isn't full
		if (item2.GetType().Contains("PlateCarrier") && item1.GetQuantity() < 100)
		{
			return false;
		}

		foreach(string s : REPAIRABLE)
		{
			if (item2.GetType().Contains(s))
				return true;
		}

		return super.CanDo(ingredients, player);
	}

	override void Do(ItemBase ingredients[], PlayerBase player, array<ItemBase> results, float specialty_weight) // Gets called upon recipe's completion
	{
		ItemBase item1;
		Class.CastTo(item1, ingredients[0]);
		ItemBase item2;
		Class.CastTo(item2, ingredients[1]);

		// Reduce epoxy to zero if used on a plate carrier
		if (item2.GetType().Contains("PlateCarrier"))
		{
			item1.SetQuantity(0);
		}

		float quantity = item1.GetQuantity();
		super.Do(ingredients, player, results, specialty_weight);

		// If we just repaired an item that isn't usually repairable from epoxy then the epoxy quantity won't have changed - change it here.
		if (item1.GetQuantity() == quantity)
		{
			item1.AddQuantity(-25);
		}
	}
};

// Sewing kits
modded class PatchItem extends RecipeBase
{
	override bool CanDo(ItemBase ingredients[], PlayerBase player)//final check for recipe's validity
	{
		ItemBase item1;
		Class.CastTo(item1, ingredients[0]);
		ItemBase item2;
		Class.CastTo(item2, ingredients[1]);

		// Don't allow epoxy to repair a plate if it isn't full
		if (item2.GetType().Contains("PlateCarrierVest") && item1.GetQuantity() < 100)
			return false;

		return super.CanDo(ingredients, player);
	}

	override void Do(ItemBase ingredients[], PlayerBase player, array<ItemBase> results, float specialty_weight)//gets called upon recipe's completion
	{
		ItemBase item1;
		Class.CastTo(item1, ingredients[0]);
		ItemBase item2;
		Class.CastTo(item2, ingredients[1]);

		// Don't allow leather kits to repair vests if it isn't full
		if (item2.GetType().Contains("PlateCarrierVest"))
		{
			item1.SetQuantity(0);
		}

		super.Do(ingredients, player, results, specialty_weight);
	}
};