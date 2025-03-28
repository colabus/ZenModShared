modded class PluginRecipesManagerBase extends PluginBase
{
	override void RegisterRecipies()
	{
		super.RegisterRecipies(); // Calling base RegisterRecipies()

		// Add vanilla crafting modifications
		UnregisterRecipe("CraftWoodenCrate"); // Remove vanilla wooden crate
		RegisterRecipe(new VanillaCrateRecipe); // Add new vanilla crate recipe
		//RegisterRecipe(new Zen_BarrelRecipe); // Moved to Work Bench

		// Custom recipes
		RegisterRecipe(new CatShirtRecipe);
		RegisterRecipe(new Zen_PaintMichBlackRecipe);
		RegisterRecipe(new CraftRopeBurlapRecipe);

		// Dog house
		RegisterRecipe(new Zen_DogHouseRecipe);

		// Painting
		RegisterRecipe(new Zen_PaintRecipes);
		RegisterRecipe(new Zen_PaintCamoRecipes);
		RegisterRecipe(new Zen_PaintCrossbowBlackRecipe);
		//RegisterRecipe(new Zen_PaintCrossbowGreenRecipe);
		RegisterRecipe(new Zen_PaintGreenMosinCamoRecipe);
		RegisterRecipe(new Zen_PaintBlackMosinCamoRecipe);
		RegisterRecipe(new Zen_PaintVehiclesBlack);
		RegisterRecipe(new Zen_PaintVehiclesGreen);
		
		// Water pouch
		RegisterRecipe(new ZenWaterPouchRecipe);

		// Factions 
		RegisterRecipe(new ZenCraftArmbandFactionGear);

		// Winter camo net ghillie
		RegisterRecipe(new Craft_Zen_WinterCamoNet_Bushrag);
		RegisterRecipe(new Craft_Zen_WinterCamoNet_GhillieAtt);
		RegisterRecipe(new Craft_Zen_WinterCamoNet_Hood);
		RegisterRecipe(new Craft_Zen_WinterCamoNet_Suit);
		RegisterRecipe(new Craft_Zen_WinterCamoNet_Top);

		// Map wall
		RegisterRecipe(new CraftZenMapWallKit);

		// Worm guts 
		RegisterRecipe(new CraftBaitFromGutsRecipe);
	}
};