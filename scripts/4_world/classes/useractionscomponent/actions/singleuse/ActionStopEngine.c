modded class ActionStopEngine
{
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{	
        HumanCommandVehicle vehCmd = player.GetCommand_Vehicle();			
        if (vehCmd && vehCmd.GetVehicleSeat() == DayZPlayerConstants.VEHICLESEAT_DRIVER)
        {
            Transport trans = vehCmd.GetTransport();
            if (trans)
            {
                Car car;
                if (Class.CastTo(car, trans) && car.EngineIsOn())
                {
                    return true;
                }
            }
        }

        return super.ActionCondition(player, target, item);
    }
}