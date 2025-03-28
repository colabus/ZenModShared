modded class CAContinuousMineWood
{
	static const ref array<string> BERRIES =
	{
		"Zen_SambucusBerry",
		"Zen_CaninaBerry"
	};

	override void CreatePrimaryItems(ActionData action_data)
	{
		// VANILLA OVERRIDE TO RANDOMIZE LOG HEALTH
		string material;
		int increment;
		for (int i = 0; i < m_MaterialAndQuantityMap.Count(); i++)
		{
			material = m_MaterialAndQuantityMap.GetKey(i);
			
			if (material != "")
			{
				increment = m_MaterialAndQuantityMap.GetElement(i);
				
				if ( !m_MinedItem[i] )
				{
					m_MinedItem[i] = ItemBase.Cast(GetGame().CreateObjectEx(material,action_data.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE));
					m_MinedItem[i].SetQuantity(increment);

					if (action_data.m_MainItem)
					{
						m_MinedItem[i].SetHealth01("", "", action_data.m_MainItem.GetHealth01());
					}
				}
				else 
				if (m_MinedItem[i].HasQuantity())
				{
					if ( m_MinedItem[i].IsFullQuantity() )
					{
						int stack_max = m_MinedItem[i].GetQuantityMax();
						
						increment -= stack_max - m_MinedItem[i].GetQuantity();
						if (increment >= 1.0)
						{
							m_MinedItem[i] = ItemBase.Cast(GetGame().CreateObjectEx(material,action_data.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE));
							m_MinedItem[i].SetQuantity(increment,false);

							if (action_data.m_MainItem)
							{
								m_MinedItem[i].SetHealth01("", "", action_data.m_MainItem.GetHealth01());
							}
						}
					}
					else
					{
						m_MinedItem[i].AddQuantity(increment,false);
					}
				}
				else
				{
					m_MinedItem[i] = ItemBase.Cast(GetGame().CreateObjectEx(material,action_data.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE));
					if (action_data.m_MainItem)
					{
						m_MinedItem[i].SetHealth01("", "", action_data.m_MainItem.GetHealth01());
					}
				}
			}
		}

		// Check bushes, spawn berries 
		Object targetObject;
		Class.CastTo(targetObject, action_data.m_Target.GetObject());
		if (targetObject != NULL && targetObject.IsBush())
		{
			float berryChance = 0.05;
			if (IsWinter())
				berryChance = berryChance * 0.5;
			else if (IsSpring())
					berryChance = berryChance * 0.75;

			if (Math.RandomFloat01() < berryChance)
			{
				//10% chance of poison
				string berry = BERRIES.GetRandomElement();
				if (Math.RandomFloat01() < 0.1)
					berry = berry + "_Poison";

				GetGame().CreateObjectEx(berry, action_data.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE);
			}
		}

		// PERSISTENT TREES MOD COMPATIBILITY (ZenModPack) since I overrode this key method for that mod:
		SaveDeadTreeActionData(action_data);
	};
};