modded class ChatLine
{
	private const int 	 DEFAULT_COLOUR = ARGB(255, 255, 255, 255);
	private const int 	 GAME_TEXT_COLOUR = ARGB(255, 255, 255, 255);
	private const int 	 ADMIN_TEXT_COLOUR = ARGB(255, 255, 0, 0);

	ref WrapSpacerWidget m_Wrapper;
	float m_FadeInDelta = 0;
	private ref ChatFadeTimer 	m_ChatFadeTimer;

	void ChatLine(Widget root_widget)
	{
		m_RootWidget = GetGame().GetWorkspace().CreateWidgets("ZenModShared/data/gui/layouts/day_z_chat_item.layout", root_widget);

		m_Wrapper = WrapSpacerWidget.Cast(m_RootWidget.FindAnyWidget("ChatItemWidget"));
		m_NameWidget = TextWidget.Cast(m_RootWidget.FindAnyWidget("ChatItemSenderWidget"));
		m_TextWidget = TextWidget.Cast(m_RootWidget.FindAnyWidget("ChatItemTextWidget"));

		m_FadeTimer = new WidgetFadeTimer;
		m_ChatFadeTimer = new ChatFadeTimer;
		m_TimeoutTimer = new Timer(CALL_CATEGORY_GUI);
	}

	override void SetColour(int colour)
	{
		m_NameWidget.SetColor(ARGB(255, 255, 255, 0));
		m_TextWidget.SetColor(colour);
	}

	override void Set(ChatMessageEventParams params)	// Param 1 --> Channel, Param 2 --> sender name, Param 3 --> message, Param 4 ?? 
	{
		int channel;

		m_FadeInDelta = 0;
		m_NameWidget.SetText("");
		m_TextWidget.SetText("");

		SetColour(DEFAULT_COLOUR);
		m_RootWidget.Show(true);

		channel = params.param1; // 0 = Survior   1 = Game/System   2 = Admin 

		if (channel & CCSystem)
		{
			// Game
			if (params.param2 != "")
			{
				m_NameWidget.SetText(GAME_PREFIX + ":");
			}

			SetColour(GAME_TEXT_COLOUR);
			m_TextWidget.SetText(params.param3);
		}
		else if (channel & CCAdmin)
		{
			// Admin
			m_NameWidget.SetText(ADMIN_PREFIX + ":");
			SetColour(ADMIN_TEXT_COLOUR);
			m_TextWidget.SetText(" " + params.param3);
		}
		else if (channel & CCTransmitter)
		{
			// Radio - Trasnmitter
			m_NameWidget.SetText(RADIO_PREFIX + params.param2 + ":");
		}
		else if (channel == 0 || channel & CCDirect)
		{
			// Player
			if (params.param2 != "")
			{
				m_NameWidget.SetText(params.param2 + ": ");
			}

			m_TextWidget.SetText(params.param3);
		} else
			m_TextWidget.SetText(params.param3);

		// 0.5 second fade-in duration
		m_ChatFadeTimer.FadeIn(m_RootWidget, FADE_IN_DURATION, 0.6);

		// 30 sec fadeout timer, 3 sec fadeout duration
		m_TimeoutTimer.Run(FADE_TIMEOUT, m_ChatFadeTimer, "FadeOut", new Param2<Widget, float>(m_RootWidget, FADE_OUT_DURATION));
	}
};

modded class ChatInputMenu extends UIScriptedMenu
{
	override void OnShow()
	{
		super.OnShow();
		GetUApi().GetInputByName("UAPersonView").Lock();
	}

	override void OnHide()
	{
		super.OnHide();
		GetUApi().GetInputByName("UAPersonView").Unlock();
	}

	override void Update(float timeslice)
	{
		GetUApi().GetInputByName("UAPersonView").Lock();

		if (m_BackInputWrapper.InputP().LocalPress())
		{
			GetUApi().GetInputByName("UAPersonView").Unlock();
			Close();
		}
	}
};