class Zen_CraftableMap extends ItemBase
{
	//! Called upon object creation
	override void EEInit()
	{
		if (GetGame().IsDedicatedServer())
		{
			GetInventory().CreateAttachment("Zen_MapPin_Red");
			GetInventory().CreateAttachment("Zen_MapPin_Green");
			GetInventory().CreateAttachment("Zen_MapPin_Blue");
		}
	}

	override bool CanPutInCargo(EntityAI parent)
	{
		return true;
	}

	override bool CanPutIntoHands(EntityAI parent)
	{
		return true;
	}

	override bool IsRefresherSignalingViable()
	{
		return !IsRuined();
	}

	override void SetActions()
	{
		super.SetActions();

		AddAction(ActionTogglePlaceObject);
		AddAction(ActionPlaceObject);
	}
}

class Zen_CraftableMapKit extends ItemBase
{
	void Zen_CraftableMapKit()
	{
		SetAnimationPhase("placing", 1);
		SetAnimationPhase("triggered", 1);
		SetAnimationPhase("inventory", 0);
	}

	bool HasMapAttached()
	{
		return FindAttachmentBySlotName("map") != NULL;
	}

	override void OnPlacementComplete(Man player, vector position = "0 0 0", vector orientation = "0 0 0")
	{
		super.OnPlacementComplete(player, position, orientation);

		DeleteSafe();
	}

	override void SetActions()
	{
		super.SetActions();

		AddAction(ActionTogglePlaceObject);
		AddAction(ActionPlaceObject);
	}
}

class Zen_MapPin_Base extends ItemBase
{
	override bool IsRefresherSignalingViable()
	{
		return !IsRuined();
	}

	override void SetActions()
	{
		super.SetActions();

		AddAction(ActionTogglePlaceObject);
		AddAction(ActionPlaceObject);
	}

	override void OnPlacementComplete(Man player, vector position = "0 0 0", vector orientation = "0 0 0")
	{
		super.OnPlacementComplete(player, position, orientation);

		SetLifetimeMax(604800);
		SetLifetime(604800);
	}
}

class Zen_MapPin_Red extends Zen_MapPin_Base {};
class Zen_MapPin_Blue extends Zen_MapPin_Base {};
class Zen_MapPin_Green extends Zen_MapPin_Base {};