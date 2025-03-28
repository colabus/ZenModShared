modded class Wreck_Mi8_Crashed
{
	ZenHeliZombiesTrigger trigger;

	static ref array<string> RussianPilots =
	{
		"ZmbM_RU_EMR_Officer",
		"ZmbM_RU_Olive_Officer",
		"ZmbM_RU_Blue_PilotCoveralls",
		"ZmbM_RU_Orange_PilotCoveralls",
		"ZmbM_RU_Classic_GorkaSuit",
		"ZmbM_RU_EMR_GorkaSuit",
		"ZmbM_RU_EMRAlt_GorkaSuit",
		"ZmbM_RU_EMRDes_GorkaSuit",
		"ZmbM_RU_EMRFull_GorkaSuit",
		"ZmbM_RU_Multicam_GorkaSuit",
		"ZmbM_RU_SURPAT_GorkaSuit",
		"ZmbM_RU_EMR_Soldier",
		"ZmbM_RU_EMRDes_Soldier"
	};

	void ~Wreck_Mi8_Crashed()
	{
		if(trigger)
			trigger.StopSpawn();
	}

	void Wreck_Mi8_Crashed()
	{
		#ifdef SERVER
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(SetupZombies, 1000, false);
		#endif
	}

	void SetupZombies()
	{
		trigger = ZenHeliZombiesTrigger.Cast(GetGame().CreateObjectEx("ZenHeliZombiesTrigger", GetPosition(), ECE_CREATEPHYSICS));
		if (trigger)
		{
			trigger.SetupZenHeliZombiesTrigger(3600, 300, Math.RandomIntInclusive(5, 9), RussianPilots, 20);
		}
	}
}

modded class Wreck_UH1Y extends CrashBase
{
	ZenHeliZombiesTrigger trigger;

	static ref array<string> AmericanPilots =
	{
		"ZmbM_LDF_Olive_PilotCoveralls",
		"ZmbM_LDF_Woodland_PilotCoveralls",
		"ZmbM_UN_Grey_PilotCoveralls",
		"ZmbM_US_Airforce_Grey_PilotCoveralls",
		"ZmbM_US_Airforce_Olive_PilotCoveralls",
		"ZmbM_US_Airforce_Tan_PilotCoveralls",
		"ZmbM_US_Army_M81_PilotCoveralls",
		"ZmbM_US_Army_OCP_PilotCoveralls",
		"ZmbM_US_Army_Olive_PilotCoveralls",
		"ZmbM_US_Army_Tan_PilotCoveralls",
		"ZmbM_US_Army_UCP_PilotCoveralls",
		"ZmbM_US_Marines_M81_PilotCoveralls",
		"ZmbM_US_Marines_Olive_PilotCoveralls",
		"ZmbM_US_Marines_Tan_PilotCoveralls",
		"ZmbM_US_National_M81_PilotCoveralls",
		"ZmbM_US_National_OCP_PilotCoveralls",
		"ZmbM_US_National_Olive_PilotCoveralls",
		"ZmbM_US_National_UCP_PilotCoveralls",
		"ZmbM_US_Army_M81_BDU",
		"ZmbM_US_Army_OCP_BDU",
		"ZmbM_US_Army_UCP_BDU",
		"ZmbM_US_Marines_DesertMarpat_BDU",
		"ZmbM_US_Marines_WoodlandMarpat_BDU",
		"ZmbM_US_Airforce_GreyDigital_BDU",
		"ZmbM_US_National_M81_BDU",
		"ZmbM_US_National_OCP_BDU",
		"ZmbM_US_National_UCP_BDU"
	};

	void ~Wreck_UH1Y()
	{
		if (trigger)
			trigger.StopSpawn();
	}

	void Wreck_UH1Y()
	{
		#ifdef SERVER
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(SetupZombies, 1000, false);
		#endif
	}

	void SetupZombies()
	{
		trigger = ZenHeliZombiesTrigger.Cast(GetGame().CreateObjectEx("ZenHeliZombiesTrigger", GetPosition(), ECE_CREATEPHYSICS));
		if (trigger)
		{
			trigger.SetupZenHeliZombiesTrigger(3600, 300, Math.RandomIntInclusive(5, 9), AmericanPilots, 20);
		}
	}
}