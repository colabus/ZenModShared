class HardcoreDayZClientConfig
{
	// Config location
	private const static string zenModFolder = "$profile:\\";
	private const static string zenConfigName = "HardcoreDayZClientConfig.json";
	private const static string CURRENT_VERSION = "2";

	// Update CURRENT_VERSION if you change option var names!
	string CONFIG_VERSION = "";

	// Settings data
	bool ShowRadio = true;
	bool MusicMuted = false;

	void Load()
	{
		if (FileExist(zenModFolder + zenConfigName))
		{
			JsonFileLoader<HardcoreDayZClientConfig>.JsonLoadFile(zenModFolder + zenConfigName, this);

			if (CONFIG_VERSION != CURRENT_VERSION)
			{
				CONFIG_VERSION = CURRENT_VERSION;
			}
			else
			{
				// Config exists and version matches, stop here.
				return;
			}
		}

		Save();
	};

	void Save()
	{
		if (!FileExist(zenModFolder))
		{
			MakeDirectory(zenModFolder);
		}

		JsonFileLoader<HardcoreDayZClientConfig>.JsonSaveFile(zenModFolder + zenConfigName, this);
	}
}

ref HardcoreDayZClientConfig m_HardcoreDayZClientConfig;

static HardcoreDayZClientConfig GetHardcoreDayZClientConfig()
{
	if (!m_HardcoreDayZClientConfig)
	{
		m_HardcoreDayZClientConfig = new HardcoreDayZClientConfig;
		m_HardcoreDayZClientConfig.Load();
	}

	return m_HardcoreDayZClientConfig;
};