class ZenFactions
{
	static void AssignWinterTextures(EntityAI item)
	{
		if (!item || !IsWinter())
			return;

		string config_path = "CfgVehicles " + item.GetType() + " hiddenSelectionsTextures";
		ref array<string> hiddenSelectionTextures = new array<string>;
		GetGame().ConfigGetTextArray(config_path, hiddenSelectionTextures);

		for (int i = 0; i < hiddenSelectionTextures.Count(); i++)
		{
			string texture = hiddenSelectionTextures.Get(i);
			texture.Replace(".paa", "_winter.paa");
			item.SetObjectTexture(i, texture);
		}
	}
}

class Flag_MatthewBoulay: Flag_Base
{
	void Flag_MatthewBoulay()
	{
		ZenFactions.AssignWinterTextures(this);
	}
}

class Armband_MatthewBoulay: Armband_ColorBase
{
	void Armband_MatthewBoulay()
	{
		ZenFactions.AssignWinterTextures(this);
	}

	override void SwitchItemSelectionTextureEx(EItemManipulationContext context, Param par = null)
	{
		super.SwitchItemSelectionTextureEx(context, par);

		if (!IsWinter())
			return;
		
		if (context == EItemManipulationContext.ATTACHING || context == EItemManipulationContext.UPDATE)
		{
			Param1<PlayerBase> data = Param1<PlayerBase>.Cast(par);
			if (!data)
			{
				return;
			}
			
			PlayerBase player = data.param1;
			
			int selection_idx = -1;
			string texture;
			
			array<string> show_selections = new array<string>;
			array<string> hide_selections = new array<string>;
			
			//has top
			if (player.FindAttachmentBySlotName("Body"))
			{
				show_selections.Insert("camoMale_big_a");
				show_selections.Insert("camoMale_big_b");
				show_selections.Insert("camoFemale_big_a");
				show_selections.Insert("camoFemale_big_b");
				
				hide_selections.Insert("camoMale_small_a");
				hide_selections.Insert("camoMale_small_b");
				hide_selections.Insert("camoFemale_small_a");
				hide_selections.Insert("camoFemale_small_b");
			}
			//has no top
			else
			{
				hide_selections.Insert("camoMale_big_a");
				hide_selections.Insert("camoMale_big_b");
				hide_selections.Insert("camoFemale_big_a");
				hide_selections.Insert("camoFemale_big_b");
				
				show_selections.Insert("camoMale_small_a");
				show_selections.Insert("camoMale_small_b");
				show_selections.Insert("camoFemale_small_a");
				show_selections.Insert("camoFemale_small_b");
			}
			
			int i;
			for (i = 0; i < show_selections.Count(); i++)
			{
				selection_idx = GetHiddenSelectionIndex(show_selections[i]);
				texture = GetHiddenSelectionsData().GetHiddenSelectionsTextures()[selection_idx];
				texture.Replace(".paa", "_winter.paa");
				SetObjectTexture( selection_idx, texture );
			}
			
			for (i = 0; i < hide_selections.Count(); i++)
			{
				selection_idx = GetHiddenSelectionIndex(hide_selections[i]);
				SetObjectTexture( selection_idx, "" );
			}
		}
	}
}

class Armband_DoubleMatthewBoulay: Armband_DoubleColorBase
{
	void Armband_DoubleMatthewBoulay()
	{
		ZenFactions.AssignWinterTextures(this);
	}

	override void SwitchItemSelectionTextureEx(EItemManipulationContext context, Param par = null)
	{
		super.SwitchItemSelectionTextureEx(context, par);

		if (!IsWinter())
			return;
		
		if (context == EItemManipulationContext.ATTACHING || context == EItemManipulationContext.UPDATE)
		{
			Param1<PlayerBase> data = Param1<PlayerBase>.Cast(par);
			if (!data)
			{
				return;
			}
			
			PlayerBase player = data.param1;
			
			int selection_idx = -1;
			string texture;
			
			array<string> show_selections = new array<string>;
			array<string> hide_selections = new array<string>;
			
			//has top
			if (player.FindAttachmentBySlotName("Body"))
			{
				show_selections.Insert("camoMale_big_a");
				show_selections.Insert("camoMale_big_b");
				show_selections.Insert("camoFemale_big_a");
				show_selections.Insert("camoFemale_big_b");
				
				hide_selections.Insert("camoMale_small_a");
				hide_selections.Insert("camoMale_small_b");
				hide_selections.Insert("camoFemale_small_a");
				hide_selections.Insert("camoFemale_small_b");
			}
			//has no top
			else
			{
				hide_selections.Insert("camoMale_big_a");
				hide_selections.Insert("camoMale_big_b");
				hide_selections.Insert("camoFemale_big_a");
				hide_selections.Insert("camoFemale_big_b");
				
				show_selections.Insert("camoMale_small_a");
				show_selections.Insert("camoMale_small_b");
				show_selections.Insert("camoFemale_small_a");
				show_selections.Insert("camoFemale_small_b");
			}
			
			int i;
			for (i = 0; i < show_selections.Count(); i++)
			{
				selection_idx = GetHiddenSelectionIndex(show_selections[i]);
				texture = GetHiddenSelectionsData().GetHiddenSelectionsTextures()[selection_idx];
				texture.Replace(".paa", "_winter.paa");
				SetObjectTexture( selection_idx, texture );
			}
			
			for (i = 0; i < hide_selections.Count(); i++)
			{
				selection_idx = GetHiddenSelectionIndex(hide_selections[i]);
				SetObjectTexture( selection_idx, "" );
			}
		}
	}
}

// Bandana
class Bandana_MatthewBoulay extends Bandana_ColorBase 
{
	void Bandana_MatthewBoulay()
	{
		ZenFactions.AssignWinterTextures(this);
	}
}

class Canteen_MatthewBoulay extends Canteen 
{
	void Canteen_MatthewBoulay()
	{
		ZenFactions.AssignWinterTextures(this);
	}
}

class TacticalShirt_MatthewBoulay : TacticalShirt_ColorBase
{
	void TacticalShirt_MatthewBoulay()
	{
		ZenFactions.AssignWinterTextures(this);
	}
}

class CargoPants_MatthewBoulay: CargoPants_ColorBase
{
	void CargoPants_MatthewBoulay()
	{
		ZenFactions.AssignWinterTextures(this);
	}
}

class PlateCarrierVest_MatthewBoulay : PlateCarrierVest
{
	void PlateCarrierVest_MatthewBoulay()
	{
		ZenFactions.AssignWinterTextures(this);
	}
}

class PlateCarrierPouches_MatthewBoulay : PlateCarrierPouches
{
	void PlateCarrierPouches_MatthewBoulay()
	{
		ZenFactions.AssignWinterTextures(this);
	}
}

class PlateCarrierHolster_MatthewBoulay : PlateCarrierHolster
{
	void PlateCarrierHolster_MatthewBoulay()
	{
		ZenFactions.AssignWinterTextures(this);
	}
}

class Mich2001Helmet_MatthewBoulay : Mich2001Helmet
{
	void Mich2001Helmet_MatthewBoulay()
	{
		ZenFactions.AssignWinterTextures(this);
	}
}

class WorkingGloves_MatthewBoulay: WorkingGloves_ColorBase
{
	void WorkingGloves_MatthewBoulay()
	{
		ZenFactions.AssignWinterTextures(this);
	}
}

class MilitaryBoots_MatthewBoulay: MilitaryBoots_ColorBase
{
	void MilitaryBoots_MatthewBoulay()
	{
		ZenFactions.AssignWinterTextures(this);
	}
}

class Spur_MilBag_MatthewBoulay: Spur_MilBag_ColorBase
{
	void Spur_MilBag_MatthewBoulay()
	{
		ZenFactions.AssignWinterTextures(this);
	}
}

class MountainBag_MatthewBoulay : MountainBag_ColorBase
{
	void MountainBag_MatthewBoulay()
	{
		ZenFactions.AssignWinterTextures(this);
	}
}

class GorkaEJacket_MatthewBoulay: GorkaEJacket_ColorBase
{
	void GorkaEJacket_MatthewBoulay()
	{
		ZenFactions.AssignWinterTextures(this);
	}
}

class GorkaPants_MatthewBoulay: GorkaPants_ColorBase
{
	void GorkaPants_MatthewBoulay()
	{
		ZenFactions.AssignWinterTextures(this);
	}
}

class SmershBag_MatthewBoulay: SmershBag
{
	void SmershBag_MatthewBoulay()
	{
		ZenFactions.AssignWinterTextures(this);
	}
}

class SmershVest_MatthewBoulay: SmershVest
{
	void SmershVest_MatthewBoulay()
	{
		ZenFactions.AssignWinterTextures(this);
	}
}