modded class Land_Radio_PanelPAS extends PASBroadcaster
{
	static ref array<Land_Radio_PanelPAS> PAS_List = new array<Land_Radio_PanelPAS>;

	override void EEItemAttached(EntityAI item, string slot_name)
	{
		super.EEItemAttached(item, slot_name);

		ItemBase itemBase = ItemBase.Cast(item);
		if (GetGame().IsDedicatedServer() && itemBase && GetType() != "Zen_PowerControlPanel")
		{
			if (!itemBase.IsRuined() && itemBase.GetHealth() > 0)
			{
				PAS_List.Insert(this);
			}
		}
	}

	override void EEItemDetached(EntityAI item, string slot_name)
	{
		super.EEItemDetached(item, slot_name);

		int removeIdx = -1;
		for (int i = 0; i < PAS_List.Count(); i++)
		{
			if (vector.Distance(PAS_List.Get(i).GetPosition(), GetPosition()) < 1)
			{
				removeIdx = i;
				break;
			}
		}

		PAS_List.Remove(removeIdx);
	}

	void CreateBattery(string type, float health, float energy)
	{
		ItemBase battery = ItemBase.Cast(GetInventory().CreateAttachment(type));

		if (!battery)
			return;

		battery.SetHealth(health);
		battery.GetCompEM().SetEnergy(energy);
	}
};

modded class Zen_PowerControlPanel
{
	override void CreateBattery(string type, float health, float energy)
	{
		// do nothing
	}
};