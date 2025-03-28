modded class CarScript extends Car
{
	private int m_BatteryEnergy;
	protected ref Timer m_CarInvincibilityTimer;

	void CarScript()
	{
		RegisterNetSyncVariableInt("m_BatteryEnergy");
	}

	 override void OnUpdate( float dt )
    {
		#ifdef SERVER
        ItemBase battery;
        if(EngineIsOn() || IsScriptedLightsOn())
            battery = GetBattery();

        if (battery)
            UpdateBatteryEnergy(battery.GetCompEM().GetEnergy0To100());
		#endif

        super.OnUpdate(dt);
    }

	 override void EEItemDetached(EntityAI item, string slot_name)
	{
		super.EEItemDetached(item, slot_name);

		#ifdef SERVER
		if ( slot_name == "CarBattery" || slot_name == "TruckBattery" )
		{
			UpdateBatteryEnergy(0);
		}
		#endif
	}

	override void EEItemAttached(EntityAI item, string slot_name)
	{
		super.EEItemAttached(item, slot_name);

		#ifdef SERVER
		if ( slot_name == "CarBattery" || slot_name == "TruckBattery" )
		{
			UpdateBatteryEnergy(item.GetCompEM().GetEnergy0To100());
		}
		#endif
	}

	 // Server-side
	private void UpdateBatteryEnergy(int percent)
	{
        if (GetGame().IsServer() )
		{
		    if(m_BatteryEnergy == percent)
		    	return;

		    m_BatteryEnergy = percent;
		    SetSynchDirty();
        }
	}
	
	// Client-side only
	int GetBatteryEnergy0To100()
	{
		return m_BatteryEnergy;
	}

	// Drain fuel 4x fast
	override void OnFluidChanged(CarFluid fluid, float newValue, float oldValue)
	{
		if (fluid == CarFluid.FUEL)
		{
			newValue = newValue / 4;
		}

		super.OnFluidChanged(fluid, newValue, oldValue);
	}

	override void OnContact(string zoneName, vector localPos, IEntity other, Contact data)
	{
		if (GetGame().IsDedicatedServer())
		{
			float DamageHit = data.Impulse * m_dmgContactCoef;

			if (DamageHit > 0) // Make a sound.
			{
				SynchCrashLightSound(true);
			}

			if (GetSpeedometer() >= 60) // If you hit a tree while going over 60km/h, knock the tree down
			{
				SynchCrashHeavySound(true);

				Object tree = Object.Cast(other);
				if (tree.IsTree())
				{
					if (tree.IsCuttable() /* || tree.IsBush() */)
					{
						Class treeType = NULL;
						if (tree.IsInherited(TreeHard))
						{
							treeType = TreeHard.Cast(tree);
						} else
						if (tree.IsInherited(TreeSoft))
						{
							treeType = TreeSoft.Cast(tree);
						}
						else if ( tree.IsInherited(BushHard) )
						{
							treeType = BushHard.Cast( tree );
						}
						/*else if ( tree.IsInherited(BushSoft) )
						{
							treeType = BushSoft.Cast( tree );
						}
						*/
						if (treeType)
						{
							tree.DecreaseHealth("", "", 100, true);
							tree.OnTreeCutDown(this); //RPC Send
							dBodyDestroy(tree);
						}
					}
				}
			}
		}

		super.OnContact(zoneName, localPos, other, data);
	}

	override bool CanDisplayCargo()
	{
		if (GetGame().GetPlayer()) // Override since I've enabled the player inventory to be seen in cars
		{
			PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());

			if (player && player.IsInVehicle())
			{
				return false;
			}
		}

		return super.CanDisplayCargo();
	}

	override bool CanDisplayAttachmentCategory(string category_name)
	{
		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());

		if (!player)
			return false;

		bool inCar = player.IsInVehicle();

		category_name.ToLower();
		if (category_name == "body" || category_name == "engine")
		{
			return super.CanDisplayAttachmentCategory(category_name) && !inCar;
		}

		if (inCar && category_name == "chassis")
		{
			return super.CanDisplayAttachmentCategory(category_name) && CrewMemberIndex(player) == DayZPlayerConstants.VEHICLESEAT_DRIVER;
		}

		return super.CanDisplayAttachmentCategory(category_name);
	}

	//! COPIED FROM VANILLA, CAPPED MAX HEALTH DAMAGE TO 10% LEFT
	// Only allow damage if player is > 10 hp. We already break their legs + fuck em up with Syberia pain etc...
	// this is purely to stop players getting so angry over lag. At least now they have a fighting chance to 
	// save their stuff.
	override void DamageCrew(float dmg)
	{
		for ( int c = 0; c < CrewSize(); ++c )
		{
			Human crew = CrewMember( c );
			if ( !crew )
				continue;

			PlayerBase player;
			if ( Class.CastTo(player, crew ) )
			{
				if ( dmg > GameConstants.CARS_CONTACT_DMG_KILLCREW )
				{
					// Don't kill - just maim
					if (player.GetHealth() > 10)
						player.SetHealth(10);

					player.ForceBreakLegs();
					player.AddHealth("", "Shock", -100 );
				}
				else
				{
					float shockTemp = Math.InverseLerp(GameConstants.CARS_CONTACT_DMG_THRESHOLD, GameConstants.CARS_CONTACT_DMG_KILLCREW, dmg);
					shockTemp = Math.Clamp(shockTemp,0,1);
					float shock = Math.Lerp( 50, 150, shockTemp );
					float hp = Math.Lerp( 2, 100, shockTemp );

					#ifdef DIAG_DEVELOPER
					CrashDebugData.m_CrashDataPoint.m_CrewDamageBase = dmg;
					CrashDebugData.m_CrashDataPoint.m_ShockTemp = shockTemp;
					CrashDebugData.m_CrashDataPoint.m_DMGHealth = hp;
					CrashDebugData.m_CrashDataPoint.m_DMGShock = shock;
					if (DEBUG_OUTPUT_TYPE & EVehicleDebugOutputType.DAMAGE_APPLIED)
					{
						Debug.Log("--------------------------------------------------");
						Debug.Log("Crew DMG Base: " + dmg);
						Debug.Log("Crew shockTemp: " + shockTemp);
						Debug.Log("Crew DMG Health: " + hp);
						Debug.Log("Crew DMG Shock: " + shock);
						Debug.Log("--------------------------------------------------");
					}
					#endif
					
					player.AddHealth("", "Shock", -shock );

					if (player.GetHealth() - hp > 10)
					{
						player.AddHealth("", "Health", -hp);
					} else 
					{
						if (player.GetHealth() > 10)
							player.SetHealth(10);
					}

					// Break legs 
					if (shock > 50)
					{
						float breakPct = Math.Clamp(shock / 100, 0.01, 0.9);
						if (player.IsAlive() && Math.RandomFloat01() <= breakPct)
							player.ForceBreakLegs();
					}
				}
			}
		}
	}
}