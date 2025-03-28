// Unfortunate base building plus workaround
modded class ShelterBase extends TentBase
{
	override void Deconstruct()
	{
		this.SpawnConstructionMaterialPiles(this, GetMaterialPath(), GetShelterVariant());
		SpawnKit();
		Delete();
	}

	static void SpawnConstructionMaterialPiles(notnull EntityAI entity, string cfg_path, string main_part_name, string damagezone_name = "", bool is_base = false)
	{
		int	child_count = GetGame().ConfigGetChildrenCount(cfg_path);

		for (int i = 0; i < child_count; i++)
		{
			string child_name;
			GetGame().ConfigGetChildName(cfg_path, i, child_name);

			//get type, quantity from material
			string config_path;
			string type;
			string slot_name;
			config_path = cfg_path + " " + child_name + " " + "type";
			GetGame().ConfigGetText(config_path, type);
			config_path = cfg_path + " " + child_name + " " + "slot_name";
			GetGame().ConfigGetText(config_path, slot_name);
			config_path = cfg_path + " " + child_name + " " + "quantity";
			float quantity = GetGame().ConfigGetFloat(config_path);
			config_path = cfg_path + " " + child_name + " " + "lockable";
			bool lockable = GetGame().ConfigGetInt(config_path);

			//receive material quantity
			ItemBase attachment = ItemBase.Cast(entity.FindAttachmentBySlotName(slot_name));
			int slot_id;

			//material still attached
			if (lockable)			//if lockable 
			{
				if (attachment)
				{
					InventoryLocation src = new InventoryLocation;
					attachment.GetInventory().GetCurrentInventoryLocation(src);
					bsbDebugPrint("[bsb] " + Object.GetDebugName(entity) + " DropNonUsableMaterials UNlocking slot=" + src.GetSlot());
					entity.GetInventory().SetSlotLock(src.GetSlot(), false);

					//detach if base
					if (is_base)
					{
						entity.GetInventory().DropEntity(InventoryMode.PREDICTIVE, entity, attachment);
					}
				}
			}
			else
			{
				float pile_health;
				float qty_coef;
				vector destination = entity.GetPosition();
				//placed on helper memory point, if available
				if (entity.MemoryPointExists("" + main_part_name + "_materials"))
				{
					destination = entity.GetMemoryPointPos("" + main_part_name + "_materials");
					destination = GetGame().ObjectModelToWorld(entity, destination);
				}
				else if (entity.MemoryPointExists(main_part_name))
				{
					destination = entity.GetMemoryPointPos(main_part_name);
					destination = GetGame().ObjectModelToWorld(entity, destination);
				}
				//pile_health = GameConstants.DAMAGE_WORN_VALUE * MiscGameplayFunctions.GetTypeMaxGlobalHealth(type);
				pile_health = entity.GetHealth01(damagezone_name, "Health") * MiscGameplayFunctions.GetTypeMaxGlobalHealth(type);
				qty_coef = 1 - (entity.GetHealthLevel(damagezone_name) * Construction.DECONSTURCT_MATERIAL_LOSS) - Construction.DECONSTURCT_MATERIAL_LOSS;
				quantity *= qty_coef;
				quantity = Math.Max(Math.Floor(quantity), 1);
				MiscGameplayFunctions.CreateItemBasePiles(type, destination, quantity, pile_health, true);
			}
		}
	}
}