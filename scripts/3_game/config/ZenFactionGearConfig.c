class ZenFactionGearConfig
{
	// Config location
	private const static string zenModFolder = "$profile:\\Zenarchist\\";
	private const static string zenConfigName = "ZenFactionGearConfig.json";
	private const static string CURRENT_VERSION = "1";

	// Saved to json
	string CONFIG_VERSION = "";

	ref array<ref ZenFaction> Factions;

	void Load()
	{
		Factions = new ref array<ref ZenFaction>;

		// Don't load JSON on server
		if (!GetGame().IsDedicatedServer())
			return;

		if (FileExist(zenModFolder + zenConfigName))
		{
			JsonFileLoader<ZenFactionGearConfig>.JsonLoadFile(zenModFolder + zenConfigName, this);

			if (CONFIG_VERSION != CURRENT_VERSION)
			{
				// Mismatch, back up old version
				JsonFileLoader<ZenFactionGearConfig>.JsonSaveFile(zenModFolder + zenConfigName + "_old", this);
			}
			else
			{
				// Loaded fine, stop here
				return;
			}
		}

		CONFIG_VERSION = CURRENT_VERSION;

		Factions.Clear();
		Factions.Insert(new ZenFaction("AdminTest", "76561197983963610"));

		Save();
	};

	void Save()
	{
		if (!FileExist(zenModFolder))
		{
			MakeDirectory(zenModFolder);
		}

		JsonFileLoader<ZenFactionGearConfig>.JsonSaveFile(zenModFolder + zenConfigName, this);
	}

	ZenFaction GetPlayerFaction(string steamID)
	{
		foreach (ZenFaction fac : Factions)
		{
			if (fac.LeaderID == steamID)
			{
				return fac;
			}

			foreach (string sid : fac.MemberIDs)
			{
				if (sid == steamID)
				{
					return fac;
				}
			}
		}

		return NULL;
	}

	bool IsLeader(string steamID)
	{
		ZenFaction faction = GetPlayerFaction(steamID);
		return faction != NULL && faction.LeaderID == steamID;
	}
}

class ZenFaction
{
	string FactionID;
	string LeaderID;
	ref array<string> MemberIDs;

	void ZenFaction(string name, string stid)
	{
		FactionID = name;
		LeaderID = stid;
	}
}

ref ZenFactionGearConfig m_ZenFactionGearConfig;

static ZenFactionGearConfig GetZenFactionGearConfig()
{
	if (!m_ZenFactionGearConfig)
	{
		m_ZenFactionGearConfig = new ZenFactionGearConfig;
		m_ZenFactionGearConfig.Load();
	}

	return m_ZenFactionGearConfig;
};