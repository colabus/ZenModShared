modded class OptionsMenuGame
{
	// All of this somehow breaks keybind savings for other keybinds?

	//protected Widget 						m_HardcoreDayZSection;
	//protected ref OptionSelectorMultistate	m_ShowRadio;

	void OptionsMenuGame(Widget parent, Widget details_root, GameOptions options, OptionsMenu menu)
	{
		// Hide VPP Admin tools settings
		m_VPPATSection.Show(false);
	}
};