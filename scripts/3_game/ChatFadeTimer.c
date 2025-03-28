class ChatFadeTimer extends TimerBase
{
	private Widget m_widget;
	bool m_fadeIn;
	float m_alpha;

	void ChatFadeTimer()
	{
		OnInit(CALL_CATEGORY_GUI);
		m_fadeIn = true;
	}

	void FadeIn(Widget w, float time, float maxAlpha, bool continue_ = true)
	{
		float alpha = w.GetAlpha();

		if (continue_ && alpha > 0.6 - 0.05)
		{
			w.SetAlpha(0.6);
			w.Show(true);
			return;
		}

		m_widget = w;
		m_fadeIn = true;

		OnStart(time, false);

		if (m_widget)
		{
			alpha = m_widget.GetAlpha();
			m_widget.SetAlpha(0);
			m_widget.Show(true);
		}

		if (continue_)
		{
			m_time = alpha * time;
		}
	}

	void FadeOut(Widget w, float time, bool continue_ = true)
	{
		w.SetAlpha(0);
		w.Show(false);
		return;

		m_alpha = w.GetAlpha();

		if (continue_ && m_alpha < 0.05)
		{
			w.SetAlpha(0);
			w.Show(false);
			return;
		}

		m_widget = w;
		m_fadeIn = false;

		OnStart(time, false);

		if (m_widget && !continue_)
		{
			m_alpha = 0.6;
			m_widget.SetAlpha(m_alpha);
			m_widget.Show(true);
		}

		if (continue_)
		{
			m_time = (0.6 - m_alpha) * time;
		}
	}

	override private void OnTimer()
	{
		if (m_widget)
		{
			if (m_fadeIn)
			{
				m_widget.SetAlpha(0.6);
			}
			else
			{
				m_widget.SetAlpha(0);
				m_widget.Show(false);
			}
		}
	}

	override private void OnUpdate()
	{
		float timeDiff = m_time / m_duration;
		float progress = Math.Max(0.0, timeDiff);
		float alpha = timeDiff;

		if (m_widget)
		{
			if (m_fadeIn)
			{
				if (alpha > 0.6)
					alpha = 0.6;
				m_widget.SetAlpha(alpha);
			}
			else
			{
				alpha = m_alpha - timeDiff;
				if (alpha > 0.6)
					alpha = 0.6;
				m_widget.SetAlpha(alpha);
			}
		}
	}
};