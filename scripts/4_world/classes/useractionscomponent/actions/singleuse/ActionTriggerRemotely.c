modded class ActionTriggerRemotely : ActionSingleUseBase
{
	override void OnExecuteServer(ActionData action_data)
	{
		super.OnExecuteServer(action_data);

		RemoteDetonatorTrigger rdt = RemoteDetonatorTrigger.Cast(action_data.m_MainItem);
		if (rdt) 
		{
			float hp = rdt.GetHealth();
			rdt.DeleteSafe();
			action_data.m_Player.GetHumanInventory().ReplaceItemWithNew(InventoryMode.SERVER, new ZenReplaceDetonatorLambda(rdt, "RemoteDetonator", hp - 13.5)); // 40hp = 3 uses
		}
	}
};

class ZenReplaceDetonatorLambda : ReplaceItemWithNewLambdaBase
{
	float m_NewItemHealth = 1;

	void ZenReplaceDetonatorLambda(EntityAI old_item, string new_item_type, float health)
	{
		m_OldItem = old_item;
		m_NewItemType = new_item_type;
		m_NewItemHealth = health;
	}

	override void CopyOldPropertiesToNew(notnull EntityAI old_item, EntityAI new_item)
	{
		ItemBase newItem = ItemBase.Cast(new_item);

		if (newItem)
		{
			newItem.SetHealth(m_NewItemHealth);
			newItem.SetSynchDirty();
		}
	}
};