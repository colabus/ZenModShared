modded class TentBase
{
	override void DeferredInit()
	{
		super.DeferredInit();

		if (GetState() == PACKED)
			SetLifetime(10800); // 3 hrs, give time to despawn before server restart if no one is around
	}
}