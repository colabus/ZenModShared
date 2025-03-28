modded class ItemBase
{
	// 25% chance to spawn disinfected
	override void EEOnCECreate()
	{
		super.EEOnCECreate();

		if (Math.RandomFloat01() < 0.75)
			SetCleanness(0);
	}

	// For things like books which contain $UNT$ in title and can't be bothered config.cpp'ing them all
	override string GetDisplayName()
	{
		string displayName = super.GetDisplayName();

		if (displayName.IndexOf("$UNT$") > -1)
		{
			displayName.Replace("$UNT$", "");
		}

		return displayName;
	}

	override string GetTooltip()
	{
		string descriptionText = super.GetTooltip();

		if (descriptionText.IndexOf("$UNT$") > -1)
		{
			descriptionText.Replace("$UNT$", "");
		}

		if (ConfigGetBool("isFaction"))
		{
			descriptionText = descriptionText + " | This item belongs to a faction, only faction members can use it.";
		}

		return descriptionText;
	}

	override void OnQuantityChanged(float delta)
	{
		super.OnQuantityChanged(delta);

		if (GetQuantity() <= 0.01)
		{
			if (GetLiquidType() == LIQUID_WATER)
			{
				RemoveAllAgents();
			}
		}
	}

	/*
	static ref array<string> NESTED_WHITELIST =
	{
		"Sheath"
	};

	override void UpdateQuickbarShortcutVisibility(PlayerBase player)
	{
		bool isNested = GetHierarchyParent() && !GetHierarchyParent().GetInventory().AreChildrenAccessible();

		if (isNested)
		{
			isNested = false; //test

			foreach (string s : NESTED_WHITELIST)
			{
				s.ToLower();
				string type = GetType();

				if (type.Contains(s))
				{
					ZenFunctions.DebugMessage("Exception!");
					isNested = false;
					break;
				}
			}
		}

		player.SetEnableQuickBarEntityShortcut(this, !GetHierarchyParent() || isNested);
	}
	*/
};
