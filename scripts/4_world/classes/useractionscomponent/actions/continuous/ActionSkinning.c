/*modded class ActionSkinning extends ActionContinuousBase
{
	override void OnFinishProgressServer(ActionData action_data)
	{
		if (action_data.m_Target)
		{
			EntityAI body;
			Class.CastTo(body, action_data.m_Target.GetObject());
			PluginLifespan module_lifespan;

			if (body.GetType().Contains("bear")) // Animal Pack Override
			{
				// Delete animal carcass
				action_data.m_Target.GetObject().Delete();

				// Drop skinned loot
				DropRandom("BearSteakMeat", action_data.m_Target.GetObject().GetPosition(), 4, false);
				DropRandom("Bone", action_data.m_Target.GetObject().GetPosition(), 2, true, Math.RandomIntInclusive(5, 10));
				DropRandom("Lard", action_data.m_Target.GetObject().GetPosition());
				DropRandom("Guts", action_data.m_Target.GetObject().GetPosition());

				if (body.GetType().Contains("black"))
				{
					DropRandom("pelt_bear_black", action_data.m_Target.GetObject().GetPosition());
				}
				else
				if (body.GetType().Contains("blood"))
				{
					DropRandom("pelt_bear_blood", action_data.m_Target.GetObject().GetPosition());
				}

				// Update bloody hands
				module_lifespan = PluginLifespan.Cast(GetPlugin(PluginLifespan));
				module_lifespan.UpdateBloodyHandsVisibility(action_data.m_Player, true);
				return;
			}
			else
			if (body.GetType().Contains("fox"))
			{
				// Delete animal carcass
				action_data.m_Target.GetObject().Delete();

				// Drop skinned loot
				DropRandom("Zen_FoxMeat", action_data.m_Target.GetObject().GetPosition(), 2, false);
				DropRandom("Bone", action_data.m_Target.GetObject().GetPosition(), 1, true, Math.RandomIntInclusive(1, 3));
				DropRandom("Lard", action_data.m_Target.GetObject().GetPosition());
				DropRandom("Guts", action_data.m_Target.GetObject().GetPosition());
				DropRandom("pelt_fox", action_data.m_Target.GetObject().GetPosition());

				// Update bloody hands
				module_lifespan = PluginLifespan.Cast(GetPlugin(PluginLifespan));
				module_lifespan.UpdateBloodyHandsVisibility(action_data.m_Player, true);

				return;
			}
			else
			if (body.GetType().Contains("hyena"))
			{
				// Delete animal carcass
				action_data.m_Target.GetObject().Delete();

				// Drop skinned loot
				DropRandom("Zen_HyenaMeat", action_data.m_Target.GetObject().GetPosition(), Math.RandomIntInclusive(0, 1), false);
				DropRandom("Bone", action_data.m_Target.GetObject().GetPosition(), 1, true, Math.RandomIntInclusive(1, 2));
				DropRandom("Lard", action_data.m_Target.GetObject().GetPosition(), Math.RandomIntInclusive(0, 1));
				DropRandom("Guts", action_data.m_Target.GetObject().GetPosition());
				DropRandom("pelt_wolf_hyena", action_data.m_Target.GetObject().GetPosition());

				// Update bloody hands
				module_lifespan = PluginLifespan.Cast(GetPlugin(PluginLifespan));
				module_lifespan.UpdateBloodyHandsVisibility(action_data.m_Player, true);

				return;
			}
			else
			if (body.GetType().Contains("wolf_"))
			{
				// Delete animal carcass
				action_data.m_Target.GetObject().Delete();

				// Drop skinned loot
				DropRandom("WolfSteakMeat", action_data.m_Target.GetObject().GetPosition(), 2, false);
				DropRandom("Bone", action_data.m_Target.GetObject().GetPosition(), 1, true, Math.RandomIntInclusive(1, 3));
				DropRandom("Lard", action_data.m_Target.GetObject().GetPosition());
				DropRandom("Guts", action_data.m_Target.GetObject().GetPosition());

				if (body.GetType().Contains("black"))
				{
					DropRandom("pelt_wolf_black", action_data.m_Target.GetObject().GetPosition());
				}
				else
				if (body.GetType().Contains("brown"))
				{
					DropRandom("pelt_wolf_brown", action_data.m_Target.GetObject().GetPosition());
				}

				// Update bloody hands
				module_lifespan = PluginLifespan.Cast(GetPlugin(PluginLifespan));
				module_lifespan.UpdateBloodyHandsVisibility(action_data.m_Player, true);
				return;
			}
				
		}

		super.OnFinishProgressServer(action_data);
	}

	void DropRandom(string type, vector loc, int count = 1, bool randHealth = false, int quantity = -1)
	{
		ItemBase item;
		vector r = loc;

		for (int i = 0; i < count; i++)
		{
			r[0] = r[0] + Math.RandomIntInclusive(-0.5, 0.5);
			r[2] = r[2] + Math.RandomIntInclusive(-0.5, 0.5);
			item = ItemBase.Cast(GetGame().CreateObjectEx(type, r, ECE_PLACE_ON_SURFACE));

			if (!item)
			{
				continue;
			}

			item.PlaceOnSurface();

			if (randHealth)
			{
				float rndHlt = Math.RandomFloat(0.35, 0.65);
				item.SetHealth01("", "", rndHlt);
			}

			if (quantity != -1)
			{
				item.SetQuantity(quantity);
			}
		}
	}
}*/