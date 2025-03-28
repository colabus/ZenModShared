modded class Hologram
{
	override string ProjectionBasedOnParent()
	{
		Zen_CraftableMapKit mapKit = Zen_CraftableMapKit.Cast(m_Parent);
		if (mapKit != NULL)
		{
			return "Zen_CraftableMap";
		}

		return super.ProjectionBasedOnParent();
	}

	override override void SetProjectionPosition(vector position)
	{
		if (m_Parent != NULL)
		{
			SharpWoodenStick stick = SharpWoodenStick.Cast(m_Parent);
			if (stick != NULL)
			{
				m_Projection.SetPosition(position + "0 0.3 0");
				return;
			}

			if (m_Parent.Type() == Zen_CraftableMapKit || m_Parent.Type() == Zen_CraftableMap)
			{
				// Pull map forward slightly from wall, and lower it slightly as it places itself quite high
				m_Projection.SetPosition(ZenFunctions.MovePositionCloserToThisPosition(position, m_Player.GetOrientation(), 0.08) - "0 0.25 0");
				return;
			}

			if (m_Parent != NULL && m_Parent.IsInherited(Zen_MapPin_Base))
			{
				// Pull map forward slightly from wall, and lower it slightly as it places itself quite high
				m_Projection.SetPosition(ZenFunctions.MovePositionCloserToThisPosition(position, m_Player.GetOrientation(), -0.05));
				return;
			}
		}

		super.SetProjectionPosition(position);
	}

	bool m_WasZenMap = false;

	void ~Hologram()
    {
#ifndef SERVER
        if (GetGame() != NULL && m_Player != NULL)
        {
            if (m_WasZenMap)
            {
				m_Player.TryHideItemInHands(false);
            }
        }
#endif
    }

	static const string textureNameZen = "#(argb,8,8,3)color(0.5,0.5,0.5,0.75,ca)";

	override void RefreshVisual()
	{
#ifndef SERVER
		m_WasZenMap = false;

		if (m_Parent != NULL && m_Parent.Type() == Zen_CraftableMap && m_Player.IsPlacingLocal())
        {
			m_Player.TryHideItemInHands(true);
			m_WasZenMap = true;
        }
#endif

		super.RefreshVisual();
	}
}