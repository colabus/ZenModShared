class Zen_DexBottle extends Edible_Base
{
    override void InitItemVariables()
    {
        super.InitItemVariables();
        can_this_be_combined = true;
    }

    override bool CanHaveTemperature()
	{
		return false;
	}

    override void SetActions()
    {
        super.SetActions();
        AddAction(ActionForceConsumeSingle);
        AddAction(ActionConsumeSingle);
    }

    override void OnConsume(float amount, PlayerBase consumer)
    {
        if (consumer.GetModifiersManager().IsModifierActive(Zen_eModifiers.MDF_DEX))
        {
            consumer.GetModifiersManager().DeactivateModifier(Zen_eModifiers.MDF_DEX);
        }

        consumer.GetModifiersManager().ActivateModifier(Zen_eModifiers.MDF_DEX);
    }
}
