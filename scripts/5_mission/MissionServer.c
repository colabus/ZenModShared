modded class MissionServer
{
	// Called when server mission initializes
	override void OnInit()
	{
		super.OnInit();

		// Load configs
		GetZenModConfig();
		GetZenPAS_Config();
		GetZenFactionGearConfig();

		GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(this.CreateBatteryPAS, 20000);
	}

	override void OnMissionStart()
	{
		super.OnMissionStart();
		ZenModLogger.Log("Server started.");
	}

	override void OnMissionFinish()
	{
		super.OnMissionFinish();
		SaveZenPAS();
	}

	override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity) 
	{
		super.InvokeOnConnect(player, identity);

		if (!player || !identity) 
			return;

		ZenFaction playerFaction = GetZenFactionGearConfig().GetPlayerFaction(identity.GetPlainId());
		if (!playerFaction)
			return;

		player.SetMyFactionID(playerFaction.FactionID);
	}

	void CreateBatteryPAS()
	{
		for (int i = 0; i < GetZenPAS_Config().PAS_Positions.Count(); i++)
		{
			ZenPASObject pas = GetZenPAS_Config().PAS_Positions.Get(i);
			array<Object> objectsNearPAS = new array<Object>;
			GetGame().GetObjectsAtPosition3D(pas.Location, 3, objectsNearPAS, null);

			for (int x = 0; x < objectsNearPAS.Count(); x++)
			{
				if (objectsNearPAS[x].IsInherited(Land_Radio_PanelPAS))
				{
					Land_Radio_PanelPAS pas_obj = Land_Radio_PanelPAS.Cast(objectsNearPAS[x]);

					if (pas_obj)
					{
						pas_obj.CreateBattery(pas.BatteryType, pas.BatteryHealth, pas.BatteryCharge);
					}
				}
			}
		}
	}

	//! TODO: MAKE THIS A PLUGIN NOT A STATIC REF ARRAY?
	void SaveZenPAS()
	{
		GetZenPAS_Config().PAS_Positions.Clear();

		for (int i = 0; i < Land_Radio_PanelPAS.PAS_List.Count(); i++)
		{
			Land_Radio_PanelPAS pas = Land_Radio_PanelPAS.PAS_List.Get(i);

			if (!pas)
				continue;

			ItemBase battery = ItemBase.Cast(pas.FindAttachmentBySlotName("LargeBattery"));

			if (battery && battery.GetHealth() > 0)
			{
				GetZenPAS_Config().PAS_Positions.Insert(new ZenPASObject(pas.GetPosition(), battery.GetType(), battery.GetHealth(), battery.GetCompEM().GetEnergy()));
			}
		}

		GetZenPAS_Config().Save();
	}

	private void DumpObjectLocs()
	{
		ZenModLogger.Log("[DumpObjectLocs] Start object dump.");

		array<Object> objectsOnMap = new array<Object>;
		GetGame().GetObjectsAtPosition(Vector(5000, 200, 5000), 20000, objectsOnMap, null);

		string s = "";

		for (int x = 0; x < objectsOnMap.Count(); x++)
		{
			// Prepare classname(s)
			string debugName = "";
			string className = "";

			// Get classname(s)
			debugName = objectsOnMap[x].GetDebugNameNative();
			className = objectsOnMap[x].ClassName();

			// Convert to lower
			debugName.ToLower();
			className.ToLower();

			// If map object is what we're looking for
			//if (debugName.Contains("land_mil_tower_small") || className.Contains("land_mil_tower_small"))
			if (debugName.Contains("wreck_v3s"))
			{
				vector position = objectsOnMap[x].GetPosition();
				vector orientation = objectsOnMap[x].GetOrientation();
				vector rpy = Vector(orientation[2], orientation[1], orientation[0]);
				float a;
				if (rpy[2] <= -90) 
				{
					a = -rpy[2] - 270;
				}
				else 
				{
					a = 90 - rpy[2];
				}

				s = s + string.Format("<group name=\"%1\" pos=\"%2\" rpy=\"%3\" a=\"%4\"/>", objectsOnMap[x].GetType(), position.ToString(false), rpy.ToString(false), a) + "\n";

				//s = s + "\"" + position[0] + " " + position[1] + " " + position[2] + "\",";
			}
		}

		ZenModLogger.Log(s);
		ZenModLogger.Log("[DumpObjectLocs] End object dump.");
	}
};