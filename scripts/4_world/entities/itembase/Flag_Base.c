modded class Flag_Base
{
	override bool IsTakeable()
	{
		return super.IsTakeable() && CanTakeThisFlag();
	}

	override bool CanPutInCargo(EntityAI parent)
	{
		return super.CanPutInCargo(parent) && CanTakeThisFlag();
	}

	override bool CanPutIntoHands(EntityAI parent)
	{
		return super.CanPutIntoHands(parent) && CanTakeThisFlag();
	}

	// If isonpole, cant take
	bool CanTakeThisFlag()
	{
		if (!GetGame().IsClient())
			return true;

		PlayerBase pb = PlayerBase.Cast(GetGame().GetPlayer());
		if (!pb)
			return true;

		InventoryLocation il = new InventoryLocation;
		GetInventory().GetCurrentInventoryLocation(il);
		InventoryLocationType type = il.GetType();

		if (type == InventoryLocationType.ATTACHMENT)
			return pb.IsInsideOwnTerritory();

		return true;
	}

	override void SetActions()
	{
		super.SetActions();

		AddAction(ActionAddPlayerToFaction);
		AddAction(ActionRemovePlayerFromFaction);
	}
}