/*modded class PPERequester_GlassesAviator extends PPERequester_GameplayBase
{
	override protected void OnStart(Param par = null)
	{
		super.OnStart();

		SetTargetValueFloat(PostProcessEffectType.GodRays, PPEGodRays.PARAM_INTENSITY, true, 0, PPEGodRays.L_0_GLASSES, PPOperators.LOWEST);
		SetTargetValueColor(PostProcessEffectType.Glow, PPEGlow.PARAM_COLORIZATIONCOLOR, { 0.1,0.1,0.1,0.0 }, PPEGlow.L_23_GLASSES, PPOperators.SUBSTRACT);
	}
}*/

modded class PPERequester_GlassesSportBlue extends PPERequester_GameplayBase
{
	override protected void OnStart(Param par = null)
	{
		super.OnStart();

		SetTargetValueFloat(PostProcessEffectType.GodRays, PPEGodRays.PARAM_INTENSITY, true, 0, PPEGodRays.L_0_GLASSES, PPOperators.LOWEST);
		SetTargetValueColor(PostProcessEffectType.Glow, PPEGlow.PARAM_COLORIZATIONCOLOR, { 0.1,0.1,0.0,0.0 }, PPEGlow.L_23_GLASSES, PPOperators.SUBSTRACT);
	}
}

modded class PPERequester_GlassesSportGreen extends PPERequester_GameplayBase
{
	override protected void OnStart(Param par = null)
	{
		super.OnStart();

		SetTargetValueFloat(PostProcessEffectType.GodRays, PPEGodRays.PARAM_INTENSITY, true, 0, PPEGodRays.L_0_GLASSES, PPOperators.LOWEST);
		SetTargetValueColor(PostProcessEffectType.Glow, PPEGlow.PARAM_COLORIZATIONCOLOR, { 0.1,0.0,0.1,0.0 }, PPEGlow.L_23_GLASSES, PPOperators.SUBSTRACT);
	}
}

modded class PPERequester_GlassesSportOrange extends PPERequester_GameplayBase
{
	override protected void OnStart(Param par = null)
	{
		super.OnStart();

		SetTargetValueFloat(PostProcessEffectType.GodRays, PPEGodRays.PARAM_INTENSITY, true, 0, PPEGodRays.L_0_GLASSES, PPOperators.LOWEST);
		SetTargetValueColor(PostProcessEffectType.Glow, PPEGlow.PARAM_COLORIZATIONCOLOR, { 0.0,0.1,0.1,0.0 }, PPEGlow.L_23_GLASSES, PPOperators.SUBSTRACT);
	}
}

modded class PPERequester_GlassesSportBlack extends PPERequester_GameplayBase
{
	override protected void OnStart(Param par = null)
	{
		super.OnStart();

		SetTargetValueFloat(PostProcessEffectType.GodRays, PPEGodRays.PARAM_INTENSITY, true, 0, PPEGodRays.L_0_GLASSES, PPOperators.LOWEST);
		SetTargetValueColor(PostProcessEffectType.Glow, PPEGlow.PARAM_COLORIZATIONCOLOR, { 0.1,0.1,0.1,0.0 }, PPEGlow.L_23_GLASSES, PPOperators.SUBSTRACT);
	}
}

modded class PPERequester_GlassesDesignerBlack extends PPERequester_GameplayBase
{
	override protected void OnStart(Param par = null)
	{
		super.OnStart();

		SetTargetValueFloat(PostProcessEffectType.GodRays, PPEGodRays.PARAM_INTENSITY, true, 0, PPEGodRays.L_0_GLASSES, PPOperators.LOWEST);
		SetTargetValueColor(PostProcessEffectType.Glow, PPEGlow.PARAM_COLORIZATIONCOLOR, { 0.1,0.1,0.1,0.0 }, PPEGlow.L_23_GLASSES, PPOperators.SUBSTRACT);
	}
}