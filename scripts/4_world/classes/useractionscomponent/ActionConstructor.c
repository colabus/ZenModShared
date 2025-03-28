modded class ActionConstructor
{
	override void RegisterActions(TTypenameArray actions)
	{
		super.RegisterActions(actions);
		actions.Insert(ActionMineBarkByHand);
		actions.Insert(ActionDigWormsWithHands);
		actions.Insert(ActionCraftRagsWithHands);
		actions.Insert(ActionSkinChickenWithHands);
		actions.Insert(ActionZenUnfoldMap);
		actions.Insert(ActionZenFoldMap);
		actions.Insert(ActionZenSitByFire);
		actions.Insert(ActionZenLieByFire);

		// Factions 
		actions.Insert(ActionCraftZenFactionFlag);
		actions.Insert(ActionAddPlayerToFaction);
		actions.Insert(ActionRemovePlayerFromFaction);
	}
}
