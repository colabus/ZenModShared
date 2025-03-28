// Used on gebsfishing mod but seemed to be broken when loaded onto main server, maybe due to Mod load order?
/* Override fishing action to add HookBobber1 to bait hooks
modded class FishingActionData : ActionData
{
	override void InitBait(ItemBase item)
	{
		super.InitBait(item);
		m_IsBaitAnEmptyHook = !m_Bait.ConfigIsExisting("hookType") && !item.IsKindOf("HookBobber1Bait");
	}
};

// Override Gebsfish to remove some of the shitty fish (or American description fish)
modded class ActionFishingNewCB : ActionContinuousBaseCB
{
	ref array<string> m_JunkTypes = { "Wellies_Black","Wellies_Brown","Wellies_Green","Wellies_Grey","Pot","Netting","Rag","WaterBottle","Compass","ChernarusMap","Canteen"};

	void SendMsg(Object reciever, string message)
	{
		PlayerBase man;
		if (GetGame().IsServer() && Class.CastTo(man, reciever) && m_TirednessReportParam && reciever.IsAlive() && message != "")
		{
			m_TirednessReportParam.param1 = message;
			GetGame().RPCSingleParam(man, ERPCs.RPC_USER_ACTION_MESSAGE, m_TirednessReportParam, true, man.GetIdentity());
		}
	}

	int rndFish;
	string replaceHook;
	override void HandleFishingResultSuccess()
	{
		SendMsg(m_ActionDataFishing.m_Player, "FISH TEST F ISH TEST!!!");
		if (!GetGame().IsMultiplayer() || GetGame().IsServer())
		{
			ItemBase fish;
			ItemBase hook = ItemBase.Cast(m_ActionDataFishing.m_MainItem.FindAttachmentBySlotName("Hook"));

			if (hook.GetType() == "Bait")
				replaceHook = "Hook";
			else
				replaceHook = "HookBobber1";

			//SendChat(m_ActionDataFishing.m_Player, "Using hook type: " + hook.GetType());
			//SendChat(m_ActionDataFishing.m_Player, "Empty hook: " + m_ActionDataFishing.m_IsBaitAnEmptyHook);

			if (!m_ActionDataFishing.m_Bait)
				m_ActionDataFishing.InitBait(ItemBase.Cast(m_ActionDataFishing.m_MainItem.FindAttachmentBySlotName("Hook")));

			if (!m_ActionDataFishing.IsBaitEmptyHook())
			{
				m_ActionDataFishing.m_Bait.AddHealth(-m_ActionDataFishing.FISHING_DAMAGE);
				MiscGameplayFunctions.TurnItemIntoItem(m_ActionDataFishing.m_Bait, replaceHook, m_ActionDataFishing.m_Player);
			}
			else
			{
				m_ActionDataFishing.m_Bait.AddHealth(-m_ActionDataFishing.FISHING_DAMAGE);
			}
			rndFish = Math.RandomFloatInclusive(0.0, 17.0);
			float rnd = Math.RandomFloatInclusive(0.0, 1.0);
			if (rnd > m_ActionDataFishing.FISHING_GARBAGE_CHANCE)
			{
				if (m_ActionDataFishing.m_IsSurfaceSea)
				{
					switch (rndFish)
					{
						case 0.00:
							fish = ItemBase.Cast(GetGame().CreateObjectEx("Mackerel", m_ActionDataFishing.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE));
							break;
						case 1.00:
							fish = ItemBase.Cast(GetGame().CreateObjectEx("Angelfish", m_ActionDataFishing.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE));
							break;
						case 2.00:
							fish = ItemBase.Cast(GetGame().CreateObjectEx("Bluemarlin", m_ActionDataFishing.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE));
							break;
						case 3.00:
							fish = ItemBase.Cast(GetGame().CreateObjectEx("Bonita", m_ActionDataFishing.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE));
							break;
						case 4.00:
							fish = ItemBase.Cast(GetGame().CreateObjectEx("Cherrysalmon", m_ActionDataFishing.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE));
							break;
						case 5.00:
							fish = ItemBase.Cast(GetGame().CreateObjectEx("Flatheadmullet", m_ActionDataFishing.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE));
							break;
						case 6.00:
							fish = ItemBase.Cast(GetGame().CreateObjectEx("Leopardshark", m_ActionDataFishing.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE));
							break;
						case 7.00:
							fish = ItemBase.Cast(GetGame().CreateObjectEx("Pacificcod", m_ActionDataFishing.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE));
							break;
						case 8.00:
							fish = ItemBase.Cast(GetGame().CreateObjectEx("Redheadcichlid", m_ActionDataFishing.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE));
							break;
						case 9.00:
							fish = ItemBase.Cast(GetGame().CreateObjectEx("Roughneckrock", m_ActionDataFishing.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE));
							break;
						case 10.00:
							fish = ItemBase.Cast(GetGame().CreateObjectEx("Severum", m_ActionDataFishing.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE));
							break;
						case 11.00:
							fish = ItemBase.Cast(GetGame().CreateObjectEx("Shrimp", m_ActionDataFishing.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE));
							break;
						case 12.00:
							fish = ItemBase.Cast(GetGame().CreateObjectEx("Bluetang", m_ActionDataFishing.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE));
							break;
						case 13.00:
							fish = ItemBase.Cast(GetGame().CreateObjectEx("Hairtailfish", m_ActionDataFishing.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE));
							break;
						case 14.00:
							fish = ItemBase.Cast(GetGame().CreateObjectEx("Humpheadwrasse", m_ActionDataFishing.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE));
							break;
						case 15.00:
							fish = ItemBase.Cast(GetGame().CreateObjectEx("Siamesetigerfish", m_ActionDataFishing.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE));
							break;
						case 16.00:
							fish = ItemBase.Cast(GetGame().CreateObjectEx("Asianseabass", m_ActionDataFishing.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE));
							break;
						case 17.00:
							fish = ItemBase.Cast(GetGame().CreateObjectEx("Asianseabass", m_ActionDataFishing.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE));
							break;
						default:
					}
				}

				else
				{
					switch (rndFish)
					{
						case 1.00:
							fish = ItemBase.Cast(GetGame().CreateObjectEx("Crayfish", m_ActionDataFishing.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE));
							break;
						case 2.00:
							fish = ItemBase.Cast(GetGame().CreateObjectEx("Bluegill", m_ActionDataFishing.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE));
							break;
						case 3.00:
							fish = ItemBase.Cast(GetGame().CreateObjectEx("Blackbass", m_ActionDataFishing.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE));
							break;
						//case 4.00:
						//	fish = ItemBase.Cast(GetGame().CreateObjectEx("Catfish", m_ActionDataFishing.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE));
						//	break;
						case 5.00:
							fish = ItemBase.Cast(GetGame().CreateObjectEx("Largemouthbass", m_ActionDataFishing.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE));
							break;
						//case 6.00:
						//	fish = ItemBase.Cast(GetGame().CreateObjectEx("Minnow", m_ActionDataFishing.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE));
						//	break;
						//case 7.00:
						//	fish = ItemBase.Cast(GetGame().CreateObjectEx("Northernpike", m_ActionDataFishing.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE));
						//	break;
						case 8.00:
							fish = ItemBase.Cast(GetGame().CreateObjectEx("Perch", m_ActionDataFishing.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE));
							break;
						//case 9.00:
						//	fish = ItemBase.Cast(GetGame().CreateObjectEx("Sauger", m_ActionDataFishing.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE));
						//	break;
						case 10.00:
							fish = ItemBase.Cast(GetGame().CreateObjectEx("Crayfish", m_ActionDataFishing.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE));
							break;
						case 11.00:
							fish = ItemBase.Cast(GetGame().CreateObjectEx("Trout", m_ActionDataFishing.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE));
							break;
						case 12.00:
							fish = ItemBase.Cast(GetGame().CreateObjectEx("Whitebass", m_ActionDataFishing.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE));
							break;
						//case 13.00:
						//	fish = ItemBase.Cast(GetGame().CreateObjectEx("Bowfin", m_ActionDataFishing.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE));
						//	break;
						//case 14.00:
						//	fish = ItemBase.Cast(GetGame().CreateObjectEx("Slimysculpin", m_ActionDataFishing.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE));
						//	break;
						case 15.00:
							fish = ItemBase.Cast(GetGame().CreateObjectEx("Minnow", m_ActionDataFishing.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE));
							break;
						case 16.00:
							fish = ItemBase.Cast(GetGame().CreateObjectEx("Largemouthbass", m_ActionDataFishing.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE));
							break;
						case 17.00:
							fish = ItemBase.Cast(GetGame().CreateObjectEx("Largemouthbass", m_ActionDataFishing.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE));
							break;
						default:
							fish = ItemBase.Cast(GetGame().CreateObjectEx("Carp", m_ActionDataFishing.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE));
							break;
					}
				}
			}
			else
			{
				if (!m_ActionDataFishing.m_IsSurfaceSea)
				{
					string junk_type = m_JunkTypes.Get(Math.RandomInt(0, m_JunkTypes.Count()));
					fish = ItemBase.Cast(GetGame().CreateObjectEx(junk_type, m_ActionDataFishing.m_Player.GetPosition(), ECE_PLACE_ON_SURFACE));
					fish.SetHealth("", "Health", fish.GetMaxHealth("", "Health") * 0.1);
				}
			}

			if (fish)
			{
				//Print("---Caught something: " + fish + "---");
				fish.SetWet(0.3);
				if (fish.HasQuantity())
				{
					float coef = Math.RandomFloatInclusive(1.0, 1.0);
					float item_quantity = fish.GetQuantityMax() * coef;
					item_quantity = Math.Round(item_quantity);
					fish.SetQuantity(item_quantity);
				}
			}

			m_ActionDataFishing.m_MainItem.AddHealth(-1); // TODO: CHECK IF THIS DOES ANYTHING BAD?
		}
	}

	override void HandleFishingResultFailure()
	{
		if (!GetGame().IsMultiplayer() || GetGame().IsServer())
		{
			if (!m_ActionDataFishing.m_Bait)
				m_ActionDataFishing.InitBait(ItemBase.Cast(m_ActionDataFishing.m_MainItem.FindAttachmentBySlotName("Hook")));

			if (Math.RandomFloatInclusive(0.0, 1.0) > m_ActionDataFishing.FISHING_HOOK_LOSS) //loss of worm only
			{
				if (!m_ActionDataFishing.IsBaitEmptyHook())
				{
					m_ActionDataFishing.m_Bait.AddHealth(-m_ActionDataFishing.FISHING_DAMAGE);
					MiscGameplayFunctions.TurnItemIntoItem(m_ActionDataFishing.m_Bait, replaceHook, m_ActionDataFishing.m_Player);
				}
			}
			else //loss of the entire hook
			{
				m_ActionDataFishing.m_Bait.Delete();
			}

			m_ActionDataFishing.m_MainItem.AddHealth(-m_ActionDataFishing.FISHING_DAMAGE);
		}
	}
};*/