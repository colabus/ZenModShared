class Vodka : Bottle_Base 
{
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionWashHandsItem);
	}

	override bool CanHaveTemperature()
	{
		return false;
	}
};