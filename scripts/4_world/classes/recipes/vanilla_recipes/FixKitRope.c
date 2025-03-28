modded class CraftFenceKit
{	
	override void Do(ItemBase ingredients[], PlayerBase player,array<ItemBase> results, float specialty_weight)//gets called upon recipe's completion
	{
		super.Do(ingredients, player, results, specialty_weight);

		ItemBase fence_kit = results[0];
		Rope rope = Rope.Cast(fence_kit.GetInventory().CreateAttachment("Rope"));
		MiscGameplayFunctions.TransferItemProperties(ingredients[0], rope);
	}
}

modded class CraftWatchtowerKit extends RecipeBase
{	
	override void Do(ItemBase ingredients[], PlayerBase player,array<ItemBase> results, float specialty_weight)//gets called upon recipe's completion
	{
		super.Do(ingredients, player, results, specialty_weight);

		ItemBase fence_kit = results[0];
		Rope rope = Rope.Cast(fence_kit.GetInventory().CreateAttachment("Rope"));
		MiscGameplayFunctions.TransferItemProperties(ingredients[0],rope);
	}
}

modded class CraftShelterKit extends RecipeBase
{	
	override void Do(ItemBase ingredients[], PlayerBase player,array<ItemBase> results, float specialty_weight)//gets called upon recipe's completion
	{
		super.Do(ingredients, player, results, specialty_weight);

		ItemBase fence_kit = results[0];
		Rope rope = Rope.Cast(fence_kit.GetInventory().CreateAttachment("Rope"));
		MiscGameplayFunctions.TransferItemProperties(ingredients[0],rope);
	}
}

modded class CraftTerritoryFlagKit extends RecipeBase
{
	override void Do(ItemBase ingredients[], PlayerBase player,array<ItemBase> results, float specialty_weight)//gets called upon recipe's completion
	{
		super.Do(ingredients, player, results, specialty_weight);

		ItemBase fence_kit = results[0];
		Rope rope = Rope.Cast(fence_kit.GetInventory().CreateAttachment("Rope"));
		MiscGameplayFunctions.TransferItemProperties(ingredients[0],rope);
	}
}
