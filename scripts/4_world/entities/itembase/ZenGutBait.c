class ZenGutBait extends Worm 
{
	override void DeferredInit()
	{
		super.DeferredInit();

		SetLifetimeMax(1800);
		SetLifetime(1800);
	}
};