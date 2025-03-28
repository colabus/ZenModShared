modded class WaterBottle
{
	// 1.26 fix for filling water bottles with hot liquid
	override void AffectLiquidContainerOnFill(int liquid_type, float amount)
	{
		float liquidTemperature = GetGame().GetMission().GetWorldData().GetLiquidTypeEnviroTemperature(liquid_type);
		if (liquidTemperature > GetTemperatureMax())
		{
			float temperatureDiff = liquidTemperature - GetTemperature();
			float tTime = Math.Clamp(Math.InverseLerp(DAMAGE_ENVIRO_TEMPDIFF_MIN, DAMAGE_ENVIRO_TEMPDIFF_MAX, temperatureDiff), 0, 1);
			float temperatureDiffCoef = Math.Lerp(DAMAGE_ENVIRO_LIQUID_COEF_MIN, DAMAGE_ENVIRO_LIQUID_COEF_MAX, tTime);
			float damageVal = GetMaxHealth("", "Health") / GetQuantityMax();
			float damageFinal = amount * damageVal * temperatureDiffCoef;
			DecreaseHealth(damageFinal, false);
		}
	}
};