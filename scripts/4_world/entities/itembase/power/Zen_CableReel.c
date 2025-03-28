class Zen_CableReel extends ItemBase
{
	bool m_ForceIntoHands;

	static const string SEL_CORD_FOLDED 			= "cord_folded";
	static const string SEL_CORD_PLUGGED 			= "cord_plugged";
	
	void Zen_CableReel () 
	{
		m_ForceIntoHands = false;
		SetAllowDamage(false);
	}
	
	override bool IsElectricAppliance()
	{
		return true;
	}
	
	void ForceIntoHandsNow( PlayerBase player ) 
	{
		m_ForceIntoHands = true;
		player.LocalTakeEntityToHands(this); // Local, because ForceIntoHandsNow is executed on both, Client and Server
		m_ForceIntoHands = false;
	}
	
	override bool CanPutInCargo( EntityAI parent )
	{
		return !GetCompEM().IsPlugged();
	}

	override bool CanPutIntoHands ( EntityAI player ) 
	{
		return !GetCompEM().IsPlugged();
	}
	
	override bool CanRemoveFromHands( EntityAI player ) 
	{
		return true;
	}

	//================================================================
	// ADVANCED PLACEMENT
	//================================================================
	
	override void OnPlacementStarted(Man player)
	{
		super.OnPlacementStarted(player);

		array<string> selections = {
			SEL_CORD_PLUGGED,
			SEL_CORD_FOLDED
		};
		
		PlayerBase playerPB = PlayerBase.Cast(player);
		foreach (string selection : selections)
		{		
			if (GetGame().IsMultiplayer() && GetGame().IsServer())
				playerPB.GetHologramServer().SetSelectionToRefresh(selection);		
			else
				playerPB.GetHologramLocal().SetSelectionToRefresh(selection);
		}
	}

	override void SetActions()
	{
		super.SetActions();
		RemoveAction(ActionTakeItemToHands);
		
		AddAction(ActionPlugIn);
		AddAction(ActionPlugTargetIntoThis);
		AddAction(ActionTogglePlaceObject);
		AddAction(ActionPlaceObject);
	}
}