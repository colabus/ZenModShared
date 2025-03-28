modded class Icon
{
	override void RefreshMuzzleIcon()
	{
		for (int x = 0; x < m_AmmoIcons.Count(); x++) 
		{
			if (m_AmmoIcons[x]) 
			{
				m_AmmoIcons[x].Show(false);
			}
		}
	}
}

modded class ItemManager
{
	override void PrepareTooltip(EntityAI item, int x = 0, int y = 0)
	{
		super.PrepareTooltip(item, x, y);

		InspectMenuNew.ZenUpdateAmmoInfo(m_TooltipWidget, item);
	}
}

modded class InspectMenuNew
{
	override void SetItem(EntityAI item)
	{
		super.SetItem(item);

		InspectMenuNew.ZenUpdateAmmoInfo(layoutRoot, item);
	}

	// Hide ammo count
	static void ZenUpdateAmmoInfo(Widget root_widget, EntityAI item)
	{
		if (!item) 
			return;

		if (item.IsInherited(Magazine))
		{
			WidgetTrySetText(root_widget, "ItemQuantityWidget", "", Colors.COLOR_DEFAULT);
		}
	}
}

modded class ItemActionsWidget extends ScriptedWidgetEventHandler
{
	protected override void SetWeaponQuantity(int chamber, int mag, string itemWidget, string quantityPBWidget, string quantityTextWidget, bool enabled)
	{
		Widget widget = m_Root.FindAnyWidget(itemWidget);
		if (!enabled) 
		{
			widget.Show(false);
			return;
		}

		string wpn_qty = "";
		ProgressBarWidget progressBar;
		TextWidget textWidget;
		Class.CastTo(progressBar, widget.FindAnyWidget(quantityPBWidget));
		Class.CastTo(textWidget, widget.FindAnyWidget(quantityTextWidget));
		widget.Show(false);
		Weapon_Base wpn;
		Magazine maga;
		int mag_quantity = -1;

		if (!Class.CastTo(wpn, m_EntityInHands)) 
		{
			return;
		}

		progressBar.Show(false);

		if (Magnum.Cast(wpn)) 
		{
			mag_quantity = 0;
			for (int j = 0; j < wpn.GetMuzzleCount(); j++) 
			{
				if (wpn.IsChamberFull(j) && !wpn.IsChamberFiredOut(j)) 
				{
					mag_quantity++;
				}
			}

			textWidget.SetText(mag_quantity.ToString());
			return;
		}

		for (int i = 0; i < wpn.GetMuzzleCount(); i++) 
		{
			if (i > 0 && (wpn.GetMuzzleCount() < 3 || i % 2 == 0)) 
			{
				wpn_qty += " ";
			}

			if (wpn.IsChamberEmpty(i)) 
			{
				wpn_qty += "-";
			}
			else 
			if (wpn.IsChamberFiredOut(i)) 
			{
				wpn_qty += "F";
			}
			else 
			{
				wpn_qty += "+";
			}
		}

		if (wpn.IsJammed()) 
		{
			wpn_qty = "X";
		}

		textWidget.SetText(wpn_qty);
		textWidget.Show(true);
		textWidget.GetParent().Show(true);
	}
}