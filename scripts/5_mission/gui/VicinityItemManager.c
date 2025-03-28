// This is for stopping the player from picking up items outside a car while inside it
modded class VicinityItemManager
{
	//Zen_PlayerInCar() = ZenModPack.pbo

	override bool ExcludeFromContainer_Phase1(Object actor_in_radius)
	{
		if (Zen_PlayerInCar())
			return true;

		return super.ExcludeFromContainer_Phase1(actor_in_radius);
	}

	override bool ExcludeFromContainer_Phase2(Object object_in_radius)
	{
		if (Zen_PlayerInCar())
			return true;

		return super.ExcludeFromContainer_Phase2(object_in_radius);
	}

	override bool ExcludeFromContainer_Phase3(Object object_in_cone)
	{
		if (Zen_PlayerInCar() && !object_in_cone.IsKindOf("CarScript"))
			return true;

		return super.ExcludeFromContainer_Phase3(object_in_cone);
	}
}