class ZenPAS_Config
{
	// Set actual config version (doesn't save to json)
	private static const string CONFIG_VERSION = "1";

	// Config version 
	string ConfigVersion = "";

	// Config location
	private static const string zenModFolder = "$profile:\\Zenarchist\\";
	private static string zenConfigName = "ZenPAS_Config.json";

	// Main config data
	ref array<ref ZenPASObject> PAS_Positions = new array<ref ZenPASObject>;

	// Load config file or create default file if config doesn't exsit
	void Load()
	{
		if (!GetGame().IsDedicatedServer())
			return;

		if (FileExist(zenModFolder + zenConfigName))
		{	
			// If config exists, load file
			JsonFileLoader<ZenPAS_Config>.JsonLoadFile(zenModFolder + zenConfigName, this);

			// If version mismatch, backup old version of json before replacing it
			if (ConfigVersion != CONFIG_VERSION)
			{
				JsonFileLoader<ZenPAS_Config>.JsonSaveFile(zenModFolder + zenConfigName + "_old", this);
				ConfigVersion = CONFIG_VERSION;
			}
			else
			{
				// Config exists and version matches, stop here.
				return;
			}
		}

		ConfigVersion = CONFIG_VERSION;

		// Save new config
		Save();
	}

	// Save config
	void Save()
	{
		if (!FileExist(zenModFolder))
		{
			// If config folder doesn't exist, create it.
			MakeDirectory(zenModFolder);
		}

		// Save JSON config
		JsonFileLoader<ZenPAS_Config>.JsonSaveFile(zenModFolder + zenConfigName, this);
	}
}

// Define a PAS
class ZenPASObject
{
	vector Location;
	string BatteryType;
	float BatteryHealth;
	float BatteryCharge;

	void ZenPASObject(vector loc, string t, float hp, float energy)
	{
		Location = loc;
		BatteryType = t;
		BatteryHealth = hp;
		BatteryCharge = energy;
	}
};

// Save config data
ref ZenPAS_Config m_ZenPAS_Config;

// Helper function to return Config data storage object
static ZenPAS_Config GetZenPAS_Config()
{
	if (!m_ZenPAS_Config)
	{
		Print("[ZenPAS_Config] Init");
		m_ZenPAS_Config = new ZenPAS_Config;
		m_ZenPAS_Config.Load();
	}

	return m_ZenPAS_Config;
};