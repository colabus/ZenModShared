modded class CarHud : VehicleHudBase
{
//DEPRECATED 1.27
//	override void RefreshHudVisibility()
//	{
//		super.RefreshHudVisibility();
//
//		m_IsHudVisible = ( !m_HudHidePlayer && !m_HudHideUI && m_HudState ) || m_HudInventory;
//
//		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
//		if (player && player.IsUnconscious())
//			m_IsHudVisible = false;
//
//		SetLeftStatsVisibility( m_IsHudVisible );
//		m_Badges.Show( m_IsHudVisible );
//		m_Notifiers.Show( m_IsHudVisible );
//		m_BadgeNotifierDivider.Show( m_IsHudVisible && m_AnyBadgeVisible );
//		m_SpecializatonPanel.Show(false);
//	}

	override void RefreshVehicleHud( float timeslice )
	{
		super.RefreshVehicleHud(timeslice);
		if ( m_CurrentVehicle && !GetGame().GetUIManager().GetMenu() && m_VehiclePanel.IsVisible() )
		{
			int batColor = Colors.COLOR_PRISTINE;
			int energy = m_CurrentVehicle.GetBatteryEnergy0To100(); // pct.
			ItemBase battery = m_CurrentVehicle.GetBattery();
			if (battery == null)
				batColor = Colors.GRAY;
			else if(energy <= 11)
				batColor = Colors.COLOR_RUINED;
			else if(energy <= 25)
				batColor = Colors.COLOR_BADLY_DAMAGED;
			else if(energy <= 50)
				batColor = Colors.YELLOW;
			else if(energy < 75)
				batColor = Colors.COLOR_WORN;
			m_VehicleBatteryLight.Show(true);
			m_VehicleBatteryLight.SetColor(batColor);
			m_VehicleBatteryLight.SetAlpha(1);
		}
	}
};