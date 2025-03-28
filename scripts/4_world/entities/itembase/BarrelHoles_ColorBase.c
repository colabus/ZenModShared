modded class BarrelHoles_ColorBase
{
	protected int restartsWhileOpened = 0;

	override void OnStoreSave(ParamsWriteContext ctx)
	{   
		super.OnStoreSave(ctx);
		ctx.Write(restartsWhileOpened);
	}
	
	override bool OnStoreLoad( ParamsReadContext ctx, int version )
	{
		if (!super.OnStoreLoad(ctx, version))
			return false;

		if (!ctx.Read(restartsWhileOpened))
		{
			return false;
		}

		if (m_Openable.IsOpened())
		{
			restartsWhileOpened++;
			if (restartsWhileOpened >= 2)
			{
				restartsWhileOpened = 0;
				CloseLoad();
			}
		}
		else 
		{
			restartsWhileOpened = 0;
		}
		
		return true;
	}
};