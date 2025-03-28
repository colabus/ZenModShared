// I think a repacked mod broke my JAnimRegister technique, so this is an unfortunate work-around until I figure out which mod is doing it
modded class ModItemRegisterCallbacks
{
    override void RegisterEmptyHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
        super.RegisterEmptyHanded(pType, pBehavior);
    }

    override void RegisterOneHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
        super.RegisterOneHanded(pType, pBehavior);

        // Misc
        pType.AddItemInHandsProfileIK("Zen_DexBottle", "dz/anims/workspaces/player/player_main/props/player_main_1h_pills.asi", pBehavior, "dz/anims/anm/player/ik/gear/VitaminBottle.anm");
        pType.AddItemInHandsProfileIK("NBC_Case_DW", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/protector_case.anm");
        pType.AddItemInHandsProfileIK("Zen_JournalBook", "dz/anims/workspaces/player/player_main/weapons/player_main_1h_knife.asi", pBehavior, "dz/anims/anm/player/ik/gear/book.anm");
        pType.AddItemInHandsProfileIK("Zen_ConcussionGrenade", "dz/anims/workspaces/player/player_main/weapons/player_main_1h_knife.asi", pBehavior, "dz/anims/anm/player/ik/gear/hammer_ik.anm");
        pType.AddItemInHandsProfileIK("Zen_BoltCutter", "dz/anims/workspaces/player/player_main/weapons/player_main_1h_pipe.asi", pBehavior, "dz/anims/anm/player/ik/gear/crowbar.anm");
        pType.AddItemInHandsProfileIK("Zen_EasterEgg", "dz/anims/workspaces/player/player_main/props/player_main_1h_fruit.asi", pBehavior, "dz/anims/anm/player/ik/gear/apple.anm");
		pType.AddItemInHandsProfileIK("Zen_ValiumBottle", "dz/anims/workspaces/player/player_main/weapons/player_main_1h_knife.asi", pBehavior, "dz/anims/anm/player/ik/gear/hammer_ik.anm");
		pType.AddItemInHandsProfileIK("Zen_CraftableMapKit", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/tripwire.anm");
		pType.AddItemInHandsProfileIK("Zen_MapPin_Base", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/bait_worm_pinned.anm");

        // ZenVirus
        pType.AddItemInHandsProfileIK("Zen_Virus_Cure_Injector", "dz/anims/workspaces/player/player_main/props/player_main_1h_morphine.asi", pBehavior, "dz/anims/anm/player/ik/gear/morphine.anm");
        pType.AddItemInHandsProfileIK("Zen_Virus_Cure_Injector_Empty", "dz/anims/workspaces/player/player_main/props/player_main_1h_morphine.asi", pBehavior, "dz/anims/anm/player/ik/gear/morphine.anm");
        pType.AddItemInHandsProfileIK("Zen_Virus_Injector", "dz/anims/workspaces/player/player_main/props/player_main_1h_morphine.asi", pBehavior, "dz/anims/anm/player/ik/gear/morphine.anm");
        pType.AddItemInHandsProfileIK("Zen_Virus_Injector_Empty", "dz/anims/workspaces/player/player_main/props/player_main_1h_morphine.asi", pBehavior, "dz/anims/anm/player/ik/gear/morphine.anm");
        pType.AddItemInHandsProfileIK("Zen_Virus_PathogenVial", "dz/anims/workspaces/player/player_main/props/player_main_1h_pills.asi", pBehavior, "dz/anims/anm/player/ik/gear/VitaminBottle.anm");
        pType.AddItemInHandsProfileIK("Zen_Virus_AntiBodiesVial", "dz/anims/workspaces/player/player_main/props/player_main_1h_pills.asi", pBehavior, "dz/anims/anm/player/ik/gear/VitaminBottle.anm");
        pType.AddItemInHandsProfileIK("Zen_Virus_Cure_Petridish", "dz/anims/workspaces/player/player_main/player_main_1h.asi", pBehavior, "dz/anims/anm/player/ik/gear/powdered_milk.anm");
    }

    override void RegisterTwoHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
        super.RegisterTwoHanded(pType, pBehavior);

        // ZenVirus
        pType.AddItemInHandsProfileIK("Zen_Virus_Cure_Microscope", "dz/anims/workspaces/player/player_main/player_main_2h.asi", pBehavior, "dz/anims/anm/player/ik/two_handed/BatteryCar.anm");
        pType.AddItemInHandsProfileIK("TentBag", "dz/anims/workspaces/player/player_main/player_main_2h.asi", pBehavior, "dz/anims/anm/player/ik/two_handed/tent_medium_packed.anm");

        // Misc
        pType.AddItemInHandsProfileIK("bl_firewoodstorage", "dz/anims/workspaces/player/player_main/props/player_main_2h_jerrycan.asi", pBehavior, "dz/anims/anm/player/ik/two_handed/jerrycan.anm");
        pType.AddItemInHandsProfileIK("ZenMapUnfolded", "dz/anims/workspaces/player/player_main/player_main_2h.asi", pBehavior, "dz/anims/anm/player/ik/two_handed/BatteryCar.anm");
    }

    override void RegisterHeavy(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
        super.RegisterHeavy(pType, pBehavior);
        pType.AddItemInHandsProfileIK("zen_bl_logstorage_kit", "dz/anims/workspaces/player/player_main/player_main_heavy.asi", pBehavior, "dz/anims/anm/player/ik/heavy/metal_sheet.anm");
        pType.AddItemInHandsProfileIK("Zen_CraftableMap", "dz/anims/workspaces/player/player_main/player_main_heavy.asi", pBehavior, "dz/anims/anm/player/ik/heavy/metal_sheet.anm");
    }

    override void RegisterRestrained(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
        super.RegisterRestrained(pType, pBehavior);
    }

    override void RegisterSurrender(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
        super.RegisterSurrender(pType, pBehavior);
    }

    override void RegisterPistol(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
        super.RegisterPistol(pType, pBehavior);
    }

    override void RegisterFireArms(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
        super.RegisterFireArms(pType, pBehavior);
    }

    override void RegisterArcheryItem(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
        super.RegisterArcheryItem(pType, pBehavior);
    }

    override void RegisterPoleArms(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
        super.RegisterPoleArms(pType, pBehavior);
    }

    override void RegisterLauncher(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
        super.RegisterLauncher(pType, pBehavior);
    }

    override void RegisterCustom(DayZPlayerType pType)
    {
        super.RegisterCustom(pType);
    }

    override void CustomBoneRemapping(DayZPlayerType pType)
    {
        super.CustomBoneRemapping(pType);
    }
}