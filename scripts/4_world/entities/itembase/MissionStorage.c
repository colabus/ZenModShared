class Zen_Mission_WoodenCrate extends WoodenCrate
{
	void Zen_Mission_WoodenCrate()
	{
		if (GetGame().IsDedicatedServer())
		{
			SetAllowDamage(false);
		}
	}

	override bool CanPutInCargo(EntityAI parent)
	{
		return parent && parent.IsInherited(UndergroundStash);
	}

	override bool CanPutIntoHands(EntityAI parent)
	{
		return false;
	}

	override bool CanBeDigged()
	{
		return false;
	}
};

class Zen_Mission_SeaChest extends SeaChest
{
	void Zen_Mission_SeaChest()
	{
		if (GetGame().IsDedicatedServer())
		{
			SetAllowDamage(false);
		}
	}

	override bool CanPutInCargo(EntityAI parent)
	{
		return parent && parent.IsInherited(UndergroundStash);
	}

	override bool CanPutIntoHands(EntityAI parent)
	{
		return false;
	}

	override bool CanBeDigged()
	{
		return false;
	}
};

class Zen_BarrelHoles_Red extends Barrel_ColorBase
{
	void Zen_BarrelHoles_Red()
	{
		if (GetGame().IsDedicatedServer())
		{
			SetAllowDamage(false);
		}
	}

	override bool CanPutInCargo(EntityAI parent)
	{
		return false;
	}

	override bool CanPutIntoHands(EntityAI parent)
	{
		return false;
	}

	override void EEHitBy(TotalDamageResult damageResult, int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos, float speedCoef)
	{
		return;
	}

	override void EOnInit(IEntity other, int extra)
	{
		super.EOnInit(other, extra);

		if (GetGame().IsDedicatedServer())
			SetHealth(GetMaxHealth());
	};
};

class Zen_Mission_MediumTent extends MediumTent_Orange
{
	void Zen_Mission_MediumTent()
	{
		if (GetGame().IsDedicatedServer())
		{
			SetAllowDamage(false);
		}
	}

	override void SetActions()
	{
		AddAction(ActionToggleTentOpen);
	}
};

class Zen_MissionCarBase extends Zen_Mission_SeaChest
{
}