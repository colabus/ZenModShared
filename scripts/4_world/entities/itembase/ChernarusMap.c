modded class ChernarusMap
{
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionZenUnfoldMap);
	}
}

class ZenMapUnfolded extends ItemBase
{
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionZenFoldMap);
	}
}