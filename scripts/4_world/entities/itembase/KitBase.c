modded class KitBase
{
	override void AssembleKit()
	{
		// Don't do this (vanilla) - it allows you to turn damaged rope to pristine. Instead, create rope when crafted and copy over health.
		/*if (!IsHologram())
		{
			Rope rope = Rope.Cast(GetInventory().CreateAttachment("Rope"));
		}*/
	}

	override void CreateRope(Rope rope)
	{
		if (!rope)
			return;
		
		InventoryLocation targetLoc = rope.GetTargetLocation();
		if (targetLoc && targetLoc.GetType() != InventoryLocationType.GROUND)
			return;
		
		EntityAI newRope = EntityAI.Cast(GetGame().CreateObjectEx(rope.GetType(), GetPosition(), ECE_PLACE_ON_SURFACE));
		if (newRope)
			MiscGameplayFunctions.TransferItemProperties(rope, newRope);
		
		rope.Delete();
	}
}