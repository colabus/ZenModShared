/*
modded class UndergroundStash
{
	// If winter, convert to WinterStash
	#ifdef WINTER
	override void EEInit()
	{
		super.EEInit();

		if (!GetGame().IsDedicatedServer() || GetType() != "UndergroundStash") // Only convert vanilla stashes, not modded ones
			return;

		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(ShapeshifterMorph, 1000, false);
	}

	void ShapeshifterMorph()
	{
		WinterStash stash = WinterStash.Cast(GetGame().CreateObject("WinterStash", GetPosition(), ECE_PLACE_ON_SURFACE));
		stash.SetPosition(GetPosition());
		stash.SetOrientation(GetOrientation());
		stash.PlaceOnGround();

		stash.SetLifetimeMax(GetLifetimeMax());
		stash.SetLifetime(GetLifetime());

		ZenFunctions.MoveInventory(this, stash);

		ZMPrint("[UndergroundStash] Turned " + GetType() + " into WinterStash");
	}
	#endif

	override void PlaceOnGround()
	{
		// Place on surface properly
		vector pos = GetPosition();
		pos[1] = GetGame().SurfaceY(pos[0], pos[2]);
		pos[1] = pos[1] + 0.24;
		SetPosition(pos);

		// Align to ground 
		vector transform[4];
		GetTransform(transform);
		vector ground_position, ground_dir; 
		int component;
		DayZPhysics.RaycastRV(transform[3], transform[3] + transform[1] * -100, ground_position, ground_dir, component, null, null, null, false, true);
		vector surface_normal = GetGame().SurfaceGetNormal(ground_position[0], ground_position[2]);
		vector local_ori = GetDirection();
		transform[0] = surface_normal * local_ori;
		transform[1] = surface_normal;
		transform[2] = surface_normal * (local_ori * vector.Up);
		SetTransform(transform);
		Update();
	}
}

#ifndef WINTER
class WinterStash extends UndergroundStash 
{
	// If summer, convert to UndergroundStash
	override void EEInit()
	{
		super.EEInit();

		if (!GetGame().IsDedicatedServer())
			return;

		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(ShapeshifterMorph, 1000, false);
	}

	void ShapeshifterMorph()
	{
		UndergroundStash stash = UndergroundStash.Cast(GetGame().CreateObject("UndergroundStash", GetPosition(), ECE_PLACE_ON_SURFACE));
		stash.SetPosition(GetPosition());
		stash.SetOrientation(GetOrientation());
		stash.PlaceOnGround();

		stash.SetLifetimeMax(GetLifetimeMax());
		stash.SetLifetime(GetLifetime());

		ZenFunctions.MoveInventory(this, stash);

		ZMPrint("[UndergroundStash] Turned " + GetType() + " into UndergroundStash");
	}
};
#endif
*/