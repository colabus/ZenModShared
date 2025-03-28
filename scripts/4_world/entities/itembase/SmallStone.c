modded class SmallStone
{
	override bool CanHaveTemperature()
	{
		return true;
	}

	override bool IsTemperatureVisible()
	{
		FireplaceBase fire = FireplaceBase.Cast(GetHierarchyParent());
		if (fire != NULL)
			return true;

		return GetTemperature() > 10;
	}
	
	//! COPY PASTA ITEMBASE.C - 90% slower cooling/heating
	override void AddTemperature(float value)
	{
		SetTemperature(GetTemperature() + (value / 10));
	}
}