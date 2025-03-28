class Land_SolarPanel : PowerGenerator
{
	ItemBase m_Battery;

	void Land_SolarPanel()
	{
		SetEventMask(EntityEvent.INIT); 
		SetAllowDamage(false);
	}

	override void EEInit()
	{
		super.EEInit();
		GetInventory().CreateAttachment("TruckBattery");
	}

	override bool CanPutIntoHands(EntityAI parent)
    {
        return false;
    }
	
	override bool CanPutInCargo(EntityAI parent)
    {
        return false;
    }

	override void OnInitEnergy()
	{
		super.OnInitEnergy();

		GetCompEM().SetEnergy(1500);		
	}
	
	override void OnWork( float consumed_energy )
	{
		super.OnWork(consumed_energy);

		//Force energy/fuel levels to full always
		GetCompEM().SetEnergy(1500);
	}

	override void OnWorkStart()
	{
		super.OnWorkStart();

		//Force energy/fuel levels to full always
		GetCompEM().SetEnergy(1500);

		if ( GetGame().IsDedicatedServer() )
		{
			ItemBase battery = ItemBase.Cast( GetCompEM().GetPluggedDevice() );
			if ( battery )
			{
				float battery_capacity = battery.GetCompEM().GetEnergyMax();
				battery.GetCompEM().SetEnergy(battery_capacity);
			}	
		}
	}
	
	override void EEItemAttached ( EntityAI item, string slot_name )
	{
		super.EEItemAttached ( item, slot_name );

		ItemBase item_IB = ItemBase.Cast( item );
		if ( item_IB.IsKindOf("TruckBattery") )
		{
			SetAnimationPhase( "battery_installed", 0 );
			m_Battery = item_IB;
			
			if ( !GetGame().IsServer()  ||  !GetGame().IsMultiplayer() )
				SEffectManager.PlaySound(SPARKPLUG_ATTACH_SOUND, GetPosition() );
		}
	}
	
	override void EEItemDetached ( EntityAI item, string slot_name )
	{
		super.EEItemDetached ( item, slot_name );

		ItemBase item_IB = ItemBase.Cast( item );
		if ( item_IB && item_IB.IsKindOf("TruckBattery") )
		{
			SetAnimationPhase( "battery_installed", 1 );
			m_Battery = NULL;
			GetCompEM().SwitchOff();
		}
	}

	override bool CanAddFuel( ItemBase container )
	{
		return false;
	}	
	
	override bool HasSparkplug()
	{
		if (m_Battery)
		{
			if (!m_Battery.IsRuined())
					return true;
		}

		return false;
	}
}