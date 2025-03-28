modded class ActionBuildPart
{
	override void OnFinishProgressServer(ActionData action_data)
	{
		super.OnFinishProgressServer(action_data);

		if (!GetGame().IsServer())
			return;

		PlayerBase player = PlayerBase.Cast(action_data.m_Player);
		if (player)
		{
			BaseBuildingBase base_building = BaseBuildingBase.Cast(action_data.m_Target.GetObject());
			Construction construction = base_building.GetConstruction();

			ZenModLogger.Log("Player " + player.GetIdentity().GetName() + " (" + player.GetIdentity().GetPlainId() + ") BUILT " + action_data.m_Target.GetObject().GetDisplayName() + " using " + action_data.m_MainItem.GetDisplayName() + " @ " + player.GetPosition(), "basebuild");
		}
	}
}

modded class ActionDismantlePart
{
	override void OnFinishProgressServer(ActionData action_data)
	{
		super.OnFinishProgressServer(action_data);

		if (!GetGame().IsServer())
			return;

		PlayerBase player = PlayerBase.Cast(action_data.m_Player);
		if (player)
		{
			BaseBuildingBase base_building = BaseBuildingBase.Cast(action_data.m_Target.GetObject());
			Construction construction = base_building.GetConstruction();
			ConstructionActionData construction_action_data = action_data.m_Player.GetConstructionActionData();
			ConstructionPart construction_part = construction_action_data.GetTargetPart();
			ZenModLogger.Log("Player " + player.GetIdentity().GetName() + " (" + player.GetIdentity().GetPlainId() + ") DISMANTLED " + action_data.m_Target.GetObject().GetDisplayName() + " using " + action_data.m_MainItem.GetDisplayName() + " @ " + player.GetPosition(), "basebuild");
			
			/*string s = "";
			int partCount = 0;
			for (int i = 0; i < construction.GetConstructionParts().Count(); ++i)
			{
				string key = construction.GetConstructionParts().GetKey(i);
				ConstructionPart value = construction.GetConstructionParts().Get(key);

				if (value.IsBuilt())
				{
					s = s + value.GetPartName() + ",";
					partCount++;
				}
			}

			player.Zen_SendMessage("DISMANTLED - parts left: " + partCount + " - " + s);*/
		}
	}

	// Copy & pasted from vanilla and removed part that wouldn't allow dismantle when code lock is attached
	override bool DismantleCondition(PlayerBase player, ActionTarget target, ItemBase item, bool camera_check)
	{
		if (player && !player.IsPlacingLocal() && !player.IsPlacingServer())
		{
			Object target_object = target.GetObject();
			EntityAI target_entity;
			if (target_object && target_object.CanUseConstruction())
			{
				//invalid if is gate and is locked
				if (Class.CastTo(target_entity, target_object) && (target_entity.FindAttachmentBySlotName("Material_FPole_Flag")))
				{
					return false;
				}

				string part_name = target_object.GetActionComponentName(target.GetComponentIndex());

				BaseBuildingBase base_building = BaseBuildingBase.Cast(target_object);
				Construction construction = base_building.GetConstruction();
				ConstructionPart construction_part = construction.GetConstructionPartToDismantle(part_name, item);

				if (construction_part)
				{
					//invalid on gate if the gate is opened
					if (construction_part.IsGate() && base_building.IsOpened())
						return false;

					//camera and position checks
					bool checked = false;

					if (construction_part.IsBase())
						checked = true;

					if (!checked && base_building.IsPlayerInside(player, part_name) && !player.GetInputController().CameraIsFreeLook())
					{
						//Camera check (client-only)
						if (camera_check)
						{
							if (GetGame() && (!GetGame().IsDedicatedServer()))
							{
								if (base_building.IsFacingCamera(part_name))
								{
									return false;
								}
							}
						}

						checked = true;
					}

					if (checked)
					{
						ConstructionActionData construction_action_data = player.GetConstructionActionData();
						construction_action_data.SetTargetPart(construction_part);

						return true;
					}
				}
			}
		}

		return false;
	}
}