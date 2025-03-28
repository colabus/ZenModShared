modded class SharpWoodenStick
{
	override bool IsRefresherSignalingViable()
	{
		EntityAI attached = FindAttachmentBySlotName("ingredient");
		return !IsRuined() && attached != NULL && attached.GetType() == "ZenHumanSkull";
	}

	override void EEItemAttached(EntityAI item, string slot_name)
	{
		super.EEItemAttached(item, slot_name);

		if (GetGame().IsDedicatedServer())
		{
			if (item != NULL && item.GetType() == "ZenHumanSkull")
			{
				SetLifetimeMax(1209600);
			}
		}
	}

	override void EEItemDetached(EntityAI item, string slot_name)
	{
		super.EEItemDetached(item, slot_name);

		if (GetGame().IsDedicatedServer())
		{
			if (item != NULL && item.GetType() == "ZenHumanSkull")
			{
				SetLifetimeMax(14400);
			}
		}
	}

	override void SetActions()
	{
		super.SetActions();

		AddAction(ActionTogglePlaceObject);
		AddAction(ActionPlaceObject);
	}
}