modded class PlayerBase
{
	//! ATTACK PLAYERS IN CARS 
	override bool CanBeTargetedByAI(EntityAI ai)
    {
        if (IsInVehicle())
        {
            if (GetCommand_Vehicle())
            {
	            HumanCommandVehicle vehicleCommander = GetCommand_Vehicle();

	            if (vehicleCommander)
	            {
	                Transport transport = vehicleCommander.GetTransport();

	                if (transport)
	                {
	                    CarScript theCar = CarScript.Cast(transport);

	                    int carCrewIndex = theCar.CrewMemberIndex(this);

                        if (theCar.GetCarDoorsState(theCar.GetDoorInvSlotNameFromSeatPos(carCrewIndex)) != CarDoorState.DOORS_CLOSED)
                        {
                            return true;
                        }
                        else
                        {
                            return false;
                        }
	                }
	            }
            }
        }

		return super.CanBeTargetedByAI(ai);
    };

	//! FIX VANILLA SHAVING 
	override bool CanShave()
	{
		if (m_CharactersHead.GetBeardIndex() > -1)
			return super.CanShave() && IsMale();

		return false;
	}

	//! FACTION
	protected string m_MyFactionID = "NONE";

	string GetMyFactionID()
	{
		return m_MyFactionID;
	}

	void SetMyFactionID(string faction)
	{
		m_MyFactionID = faction;

		if (GetGame().IsDedicatedServer() && GetIdentity())
		{
			SyncFaction();
			ZMPrint("Sent faction ID of " + faction + " to " + GetIdentity().GetPlainId());
		}
	}

	void SyncFaction()
	{
		RPCSingleParam(ZenFactionERPC.FACTION_SYNC, new Param1<string>(m_MyFactionID), true);
	}
	//! END FACTION

	//! SHARED 
	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
    {
        super.OnRPC(sender, rpc_type, ctx);

		// Client receives data from server to tell it if the required quest is completed
		if (rpc_type == ZenFactionERPC.FACTION_SYNC)
		{
			Param1<string> client_receive_data = new Param1<string>("");
			if (!ctx.Read(client_receive_data))
				return;

			m_MyFactionID = client_receive_data.param1;
		}
	}

	override bool CanReceiveAttachment(EntityAI attachment, int slotId)
	{
		#ifndef SERVER
		// Prevent faction gear being worn if we're not a member of that faction
		if (GetGame().ConfigIsExisting("CfgVehicles " + attachment.GetType() + " isFaction"))
		{
			if (GetGame().ConfigGetInt("CfgVehicles " + attachment.GetType() + " isFaction") == 1)
			{
				if (!attachment.GetType().Contains(m_MyFactionID))
					return false;
			}
		}

		// Prevent ability to wear 2 ghillie's given that we allow ghillies on armband slot
		ItemBase checkItem;
		string checkType;
		if (slotId == InventorySlots.BACK)
		{
			checkItem = GetItemOnSlot("Armband");
			if (checkItem && checkItem != attachment)
			{
				checkType = checkItem.GetType();
				checkType.ToLower();
				if (checkType.Contains("ghillie"))
					return false;
			}

			checkItem = GetItemOnSlot("Belt");
			if (checkItem && checkItem != attachment)
			{
				checkType = checkItem.GetType();
				checkType.ToLower();
				if (checkType.Contains("ghillie"))
					return false;
			}
		}
		else
		if (slotId == InventorySlots.ARMBAND)
		{
			checkItem = GetItemOnSlot("Back");
			if (checkItem && checkItem != attachment)
			{
				checkType = checkItem.GetType();
				checkType.ToLower();
				if (checkType.Contains("ghillie"))
					return false;
			}

			checkItem = GetItemOnSlot("Belt");
			if (checkItem && checkItem != attachment)
			{
				checkType = checkItem.GetType();
				checkType.ToLower();
				if (checkType.Contains("ghillie"))
					return false;
			}
		}
		else
		if (slotId == InventorySlots.HIPS)
		{
			checkItem = GetItemOnSlot("Back");
			if (checkItem && checkItem != attachment)
			{
				checkType = checkItem.GetType();
				checkType.ToLower();
				if (checkType.Contains("ghillie"))
					return false;
			}

			checkItem = GetItemOnSlot("Armband");
			if (checkItem && checkItem != attachment)
			{
				checkType = checkItem.GetType();
				checkType.ToLower();
				if (checkType.Contains("ghillie"))
					return false;
			}
		}
		#endif

		return super.CanReceiveAttachment(attachment, slotId);
	}
	//! END SHARED

	vector m_LastBleedPosition = vector.Zero;

	void ForceBreakLegs()
	{
		if (GetBrokenLegs() == eBrokenLegs.BROKEN_LEGS)
			return;

		DamageAllLegs(GetMaxHealth("RightLeg", "") + 1);
		ProcessDirectDamage(DamageType.CUSTOM, this, "", "FallDamageHealth", WorldToModel(GetPosition()), 0.01);
	}

	bool Zen_HasItemType(string type)
	{
		array<EntityAI> items = {}; // Array for enumeration
		GetInventory().EnumerateInventory(InventoryTraversalType.PREORDER, items); // Enumerate inventory
		if (GetItemInHands())
			items.Insert(GetItemInHands());

		for (int i = 0; i < items.Count(); i++) // Loop through items
		{
			// Check null and if type is what we're looking for
			if (!items[i] || items[i].GetType() != type)
				continue;

			return true;
		}

		return false; // Return false if not found
	}

	override void OnPlayerLoaded()
	{
		super.OnPlayerLoaded();

		if (GetGame().IsClient())
		{
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(HideQuickBar, 500, false);
		}
	}

	void HideQuickBar()
	{
		if (m_Hud)
		{
			m_Hud.ShowQuickbarUI(false);
		}
	}

	override void SetActions()
	{
		super.SetActions();

		// Custom actions
		AddAction(ActionSkinChickenWithHands);
		AddAction(ActionCraftRagsWithHands);
		AddAction(ActionDigWormsWithHands);
		AddAction(ActionMineBushByHand);
		AddAction(ActionMineBarkByHand);
	}

	override void SetActions(out TInputActionMap InputActionMap)
	{
		super.SetActions(InputActionMap);

		AddAction(ActionZenSitByFire, InputActionMap);
		AddAction(ActionZenLieByFire, InputActionMap);
	}

	override float GetVisibilityCoef()
	{
		if (m_MovementState.m_iStanceIdx == DayZPlayerConstants.STANCEIDX_PRONE || m_MovementState.m_iStanceIdx == DayZPlayerConstants.STANCEIDX_RAISEDPRONE)
			return 0.01;

		if (m_MovementState.m_iStanceIdx == DayZPlayerConstants.STANCEIDX_CROUCH || m_MovementState.m_iStanceIdx == DayZPlayerConstants.STANCEIDX_RAISEDCROUCH)
			return m_VisibilityCoef * 0.5;

		return m_VisibilityCoef;
	}

	// Poison can food
	override bool Consume(ItemBase source, float amount, EConsumeType consume_type)
	{
		if (source && source.GetType() && source.GetType().Contains("UnknownFoodCan_Opened"))
		{
			UnknownFoodCan_Opened can = UnknownFoodCan_Opened.Cast(source);
			if (can.IS_POISON)
			{
				this.InsertAgent(eAgents.FOOD_POISON, amount);
			}
		}

		return super.Consume(source, amount, consume_type);
	}

	// Allows viewing inventory while inside cars - VicinityItemManager.c handles not being able to pick up items outside of the car
	override void OnCommandVehicleStart()
	{
		m_AnimCommandStarting = HumanMoveCommandID.CommandVehicle;

		//if (GetInventory())
		//	GetInventory().LockInventory(LOCK_FROM_SCRIPT);

		ItemBase itemInHand = GetItemInHands();
		EntityAI itemOnHead = FindAttachmentBySlotName("Headgear");

		if (itemInHand && itemInHand.GetCompEM())
			itemInHand.GetCompEM().SwitchOff();

		TryHideItemInHands(true);

		if (itemOnHead && itemOnHead.GetCompEM())
			itemOnHead.GetCompEM().SwitchOff();

		HumanCommandVehicle hcv = GetCommand_Vehicle();
		if (hcv && hcv.GetVehicleSeat() == DayZPlayerConstants.VEHICLESEAT_DRIVER)
		{
			TryHideItemInHands(true);
			OnVehicleSeatDriverEnter();
		}
	}

	override void OnCommandVehicleFinish()
	{
		//if (GetInventory())
		//	GetInventory().UnlockInventory(LOCK_FROM_SCRIPT);

		TryHideItemInHands(false, true);

		if (m_IsVehicleSeatDriver)
		{
			TryHideItemInHands(false, true);
			OnVehicleSeatDriverLeft();
		}
	}
};