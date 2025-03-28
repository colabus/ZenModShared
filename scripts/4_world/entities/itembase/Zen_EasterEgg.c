class Zen_EasterEgg extends Edible_Base
{
	void Zen_EasterEgg()
	{
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionEat);
		AddAction(ActionForceFeed);
	}

	override bool CanHaveTemperature()
	{
		return false;
	}
}