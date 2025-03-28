modded class AviatorGlasses extends Clothing
{
	override int GetGlassesEffectID()
	{
		return PPERequesterBank.REQ_GLASSESTACTICAL;//REQ_GLASSESAVIATOR;
	}
};

modded class SportGlasses_Black extends SportGlasses_ColorBase
{
	override int GetGlassesEffectID()
	{
		return PPERequesterBank.REQ_GLASSESSPORTBLACK;
	}
};

modded class SportGlasses_Blue extends SportGlasses_ColorBase
{
	override int GetGlassesEffectID()
	{
		return PPERequesterBank.REQ_GLASSESSPORTBLUE;
	}
};

modded class SportGlasses_Green extends SportGlasses_ColorBase
{
	override int GetGlassesEffectID()
	{
		return PPERequesterBank.REQ_GLASSESSPORTGREEN;
	}
};

modded class SportGlasses_Orange extends SportGlasses_ColorBase
{
	override int GetGlassesEffectID()
	{
		return PPERequesterBank.REQ_GLASSESSPORTORANGE;
	}
};

modded class DesignerGlasses extends Clothing // casual glasses
{
	override int GetGlassesEffectID()
	{
		return PPERequesterBank.REQ_GLASSESDESIGNER;
	}
};