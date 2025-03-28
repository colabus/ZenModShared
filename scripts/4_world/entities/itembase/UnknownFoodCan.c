modded class UnknownFoodCan_Opened : Edible_Base
{
	bool IS_POISON = false;

	void UnknownFoodCan_Opened()
	{
		InsertAgent(eAgents.FOOD_POISON, 1);

		if (Math.RandomFloat01() < 0.25)
			IS_POISON = true;
	}

	// Save stuff
	override void OnStoreSave(ParamsWriteContext ctx)
	{
		super.OnStoreSave(ctx);

		if (GetDayZGame().IsDedicatedServer())
		{
			ctx.Write(IS_POISON);
		}
	}

	// Load stuff
	override bool OnStoreLoad(ParamsReadContext ctx, int version)
	{
		bool load = super.OnStoreLoad(ctx, version);

		if (load && GetDayZGame().IsDedicatedServer())
		{
			ctx.Read(IS_POISON);
		}

		return load;
	}
};