class Zen_ValiumBottle : Edible_Base
{
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionForceConsumeSingle);
		AddAction(ActionConsumeSingle);
	}
};