class ZenModConfig
{
	// Config location
	private const static string zenModFolder = "$profile:\\Zenarchist\\";
	private const static string zenConfigName = "ZenModConfig.json";

	// Main config data
	int InfectedWolfSpawnTime = 60; // The base time to spawn an infected wolf near a random player (also ~+60 mins in ZenInfectedWolfSpawn.c)
	float ExtraWolfChance = 0.5; // 50% chance of extra wolves spawning
	float DamageSolarBattery = 0.0001; // How much to damage the solar truck battery when it's in use
	float DamageSolarPanel = 0.0; // How much to damage the solar panel when it's in use
	float DamageGPS = 0.0001; // How much to damage the GPS when it's in use
	float DamageRadio = 0.0001; // How much to damage the personal radio when it's in use
	int Contam_TickSecs = 90; // How often to check if the player is in the contam zone
	float Contam_Damage = 1.0; // How much damage to do to items worn in the contam zone

	// Load config file or create default file if config doesn't exsit
	void Load()
	{
		if (GetGame().IsDedicatedServer())
		{
			if (FileExist(zenModFolder + zenConfigName))
			{	// If config exists, load file
				JsonFileLoader<ZenModConfig>.JsonLoadFile(zenModFolder + zenConfigName, this);
			}
			else // Config file does not exist, create default file
			{
				// Save config
				Save();
			}
		}
	}

	// Save config
	void Save()
	{
		if (!FileExist(zenModFolder))
		{	// If config folder doesn't exist, create it.
			MakeDirectory(zenModFolder);
		}

		// Save JSON config
		JsonFileLoader<ZenModConfig>.JsonSaveFile(zenModFolder + zenConfigName, this);
	}
}

// Save config data
ref ZenModConfig m_ZenModConfig;

// Helper function to return Config data storage object
static ZenModConfig GetZenModConfig()
{
	if (!m_ZenModConfig)
	{
		Print("[ZenModConfig] Init");
		m_ZenModConfig = new ZenModConfig;
		m_ZenModConfig.Load();
	}

	return m_ZenModConfig;
};