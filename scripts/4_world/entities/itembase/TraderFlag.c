modded class TerritoryFlagKit
{
	override bool PlacementCanBeRotated()
	{
		return true;
	}
};

class TraderFlagKit extends KitBase
{
	override bool PlacementCanBeRotated()
	{
		return true;
	}

	override bool DoPlacingHeightCheck()
	{
		return true;
	}

	override float HeightCheckOverride()
	{
		return 11.3;
	}

	override bool CanReceiveAttachment(EntityAI attachment, int slotId)
	{
		if (!super.CanReceiveAttachment(attachment, slotId))
			return false;

		ItemBase att = ItemBase.Cast(GetInventory().FindAttachment(slotId));
		if (att)
			return false;

		return true;
	}

	//================================================================
	// ADVANCED PLACEMENT
	//================================================================			

	override void OnPlacementComplete(Man player, vector position = "0 0 0", vector orientation = "0 0 0")
	{
		super.OnPlacementComplete(player, position, orientation);

		if (GetGame().IsDedicatedServer())
		{
			//Create TerritoryFlag
			TerritoryFlag totem = TerritoryFlag.Cast(GetGame().CreateObjectEx("TraderFlag", GetPosition(), ECE_PLACE_ON_SURFACE));
			totem.SetPosition(position);
			totem.SetOrientation(orientation);

			//make the kit invisible, so it can be destroyed from deploy UA when action ends
			HideAllSelections();

			SetIsDeploySound(true);
		}
	}
}

class TraderFlag extends TerritoryFlag
{
	override string GetConstructionKitType()
	{
		return "TraderFlagKit";
	}

	override bool CanDisplayAttachmentCategory(string category_name)
	{
		if (category_name == "Flag" && GetConstruction().IsPartConstructed("pole"))
			return GetInventory().AttachmentCount() == 0;

		return false;
	}

	override void SetActions()
	{
		// Only allow raising the flag.
		AddAction(ActionRaiseFlag);
	}

	override void SetRefresherActive(bool state)
	{
		m_RefresherActive = false;
	};

	override bool OnStoreLoad(ParamsReadContext ctx, int version)
	{
		if (!super.OnStoreLoad(ctx, version))
			return false;

		// Always set flag to max remaining time!
		m_RefresherTimeRemaining = GetCEApi().GetCEGlobalInt("FlagRefreshMaxDuration");
		m_RefresherActive = false;
		CheckLoadedVariables(m_RefresherTimeRemaining);
		AnimateFlag(1 - GetRefresherTime01());

		return true;
	}
};