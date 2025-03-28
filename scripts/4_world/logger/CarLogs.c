modded class CarScript
{
	bool m_LoggedCrash = false;

	override void EEHitBy(TotalDamageResult damageResult, int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos, float speedCoef)
	{
		super.EEHitBy(damageResult, damageType, source, component, dmgZone, ammo, modelPos, speedCoef);

		if (m_LoggedCrash)
			return;

		if (GetHealth() <= 0 || (dmgZone == "Engine" && GetHealth("Engine", "") <= 0))
		{
			string debugStr = "";

			if (source)
				debugStr = debugStr + "source=" + source.GetType();

			string passengersStr = "";
			int crewCnt = CrewSize();
			if (crewCnt > 0)
			{
				for (int i = 0; i < CrewSize(); i++)
				{
					Human crew = CrewMember(i);
					if (!crew)
						continue;

					PlayerBase pb = PlayerBase.Cast(crew);
					if (pb)
					{
						passengersStr = passengersStr + pb.GetIdentity().GetName() + " (" + pb.GetIdentity().GetPlainId() + "),";
					}
				}
			}

			ZenModLogger.Log("Car Ruined @ " + this.GetPosition() + ": carType=" + this.GetType() + " damageType=" + damageType + " " + debugStr + " ammo=" + ammo + " passengers=" + passengersStr, "vehicle");
			m_LoggedCrash = true;
		}
	}
}

/*
modded class ActionAddCarCover : ActionCoverUncoverCar
{
	override void OnFinishProgressServer(ActionData action_data)
	{
		super.OnFinishProgressServer(action_data);
		PlayerBase player = PlayerBase.Cast(action_data.m_Player);
		CarScript carobj = CarScript.Cast(action_data.m_Target.GetObject());

		ZenModLogger.Log("Car Covered @ " + carobj.GetPosition() + ": carType=" + carobj.GetType() + " player=" + player.GetIdentity().GetName() + " (" + player.GetIdentity().GetPlainId() + ")", "vehicle");

		LogVehicleItems(carobj);
	}

	void LogVehicleItems(CarScript carobj)
	{
		if (!carobj)
			return;

		EntityAI car;
		Class.CastTo(car, carobj);
		string logMsg = "items=";

		array<EntityAI> children = new array<EntityAI>;
		car.GetInventory().EnumerateInventory(InventoryTraversalType.LEVELORDER, children);
		int count = children.Count();
		for (int i = 0; i < count; i++)
		{
			EntityAI child = children.Get(i);
			if (child)
			{
				logMsg = logMsg + child.GetType() + "(" + child.GetQuantity() + "),";
			}
		}

		ZenModLogger.Log("  CarInventory: " + logMsg, "vehicle");
	}
}

modded class ActionRemoveCarCover : ActionCoverUncoverCar
{
	override void OnFinishProgressServer(ActionData action_data)
	{
		super.OnFinishProgressServer(action_data);
		PlayerBase player = PlayerBase.Cast(action_data.m_Player);
		CarScript carobj = CarScript.Cast(action_data.m_Target.GetObject());

		ZenModLogger.Log("Car Uncovered @ " + carobj.GetPosition() + ": carType=" + carobj.GetType() + " player=" + player.GetIdentity().GetName() + " (" + player.GetIdentity().GetPlainId() + ")", "vehicle");

		//LogVehicleItems(carobj);
	}

	void LogVehicleItems(CarScript carobj)
	{
		if (!carobj)
			return;

		EntityAI car;
		Class.CastTo(car, carobj);
		string logMsg = "items=";

		array<EntityAI> children = new array<EntityAI>;
		car.GetInventory().EnumerateInventory(InventoryTraversalType.LEVELORDER, children);
		int count = children.Count();
		for (int i = 0; i < count; i++)
		{
			EntityAI child = children.Get(i);
			if (child)
			{
				logMsg = logMsg + child.GetType() + "(" + child.GetQuantity() + "),";
			}
		}

		//ZenModLogger.Log("  CarInventory: " + logMsg, "vehicle");
	}
}
*/