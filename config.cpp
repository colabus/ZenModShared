class CfgPatches
{
	/*
	Repair Kit Types
	1: Weapon Cleaning Kit
	2: Sewing Kit
	3: Leather Sewing Kit
	4: Whetstone
	5: Duct Tape
	6: Tire Repair Kit
	7: Electronic Repair Kit
	8: Epoxy Putty
	*/

	/*
	Rotation Flags
	ROTATE_Front		=	1
	ROTATE_Top			=	2 
	ROTATE_Left			=	4 
	ROTATE_Right		=	8 
	ROTATE_LeftRight	=	12 
	ROTATE_Back			=	16 - example: used on ZenRunes
	ROTATE_FrontBack	=	17 
	ROTATE_Bottom		=	32 
	ROTATE_BottomTop	=	34 
	ROTATE_All			=	63 
	ROTATE_Ignore		=	64
	*/

	class ZenModShared
	{
		requiredVersion = 0.1;
		units[] = {};
		requiredAddons[] =
		{
			"DZ_Data",
			"DZ_Scripts",
			"DZ_data_aiconfigs",
			"DZ_Gear_Consumables",
			"DZ_Gear_Drinks",
			"DZ_Gear_Food",
			"DZ_Gear_Books",
			"DZ_Gear_Camping",
			"DZ_Structures_Bliss_Signs",
			"DZ_Worlds_Chernarusplus_World",
			"DZ_Weapons_Archery_Crossbow",
			"DZ_Weapons_Melee_Blade",
			"DZ_Gear_Navigation",
			"DZ_Weapons_Firearms",
			// For clothing mods
			"DZ_Characters_Gloves",
			//"DZ_Characters_Backpacks",
			"DZ_Characters_Belts",
			"DZ_Characters_Headgear",
			"DZ_Characters_Glasses",
			"DZ_Characters_Masks",
			"DZ_Characters_Pants",
			"DZ_Characters_Shoes",
			"DZ_Characters_Tops",
			"DZ_Characters_Vests",
			"Spur_Military_Bag",
			// Other
			"DZ_Vehicles_Wheeled", // For making humvee to manual
			"DZ_Weapons_Ammunition", // For crossbow bolties
			"DZ_Gear_Cooking", // For fireplace editing
			"DZ_Weapons_Optics", // For the Mosin long range scope
			"ZenModPack", // Contains all my custom mods
			"ZenDoubleArmbands", // For faction armbands
			"ZenStreetLights", // For ensuring power station doesn't store battery
			"cabin_mod", // For overriding RaGed's cabin mod stacking of 40 stones and 10 logs
			//"ZenComboLocks", // For second pair of bolt cutters
			"SkullMask", // For new skull with name engraved in it
			"DZ_Weapons_Firearms_Winchester70", // For fixing its silly coloured names for spraypaint
		};
	};
};

class CfgMods
{
	class ZenModShared
	{
		dir = "ZenModShared";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "ZenModShared";
		credits = "";
		author = "Zenarchist";
		authorID = "0";
		version = "1.0";
		extra = 0;
		type = "mod";
		dependencies[] = { "Game","World","Mission" };
		class defs
		{
			class imageSets
			{
				files[] =
				{
					"ZenModShared/data/gui/slots/BoltSlot.imageset"
				};
			};
			class gameScriptModule
			{
				value = "";
				files[] = { "ZenModShared/scripts/3_game" };
			};
			class worldScriptModule
			{
				value = "";
				files[] = { "ZenModShared/scripts/4_World" };
			};
			class missionScriptModule
			{
				value = "";
				files[] = { "ZenModShared/scripts/5_mission" };
			};
		};
	};
};

class CfgVehicles
{
	class Inventory_Base;
	class Container_Base;
	class MilitaryBoots_ColorBase;
	class AnimalBase;
	class Bottle_Base;
	class SodaCan_ColorBase;
	class Edible_Base;
	class Box_Base;
	class Clothing;
	class Archery_Base;
	class HuntingKnife;
	class AK_Bayonet;
	class M9A1_Bayonet;
	class SmershBag;
	class SmershVest;
	class GorkaEJacket_ColorBase;
	class WorkingGloves_ColorBase;
	class Spur_MilBag_ColorBase;
	class MountainBag_ColorBase;
	class CargoPants_ColorBase;
	class PlateCarrierHolster;
	class PlateCarrierPouches;
	class PlateCarrierVest;
	class Bandana_ColorBase;
	class GorkaPants_ColorBase;
	class AliceBag_ColorBase;
	class UndergroundStash;
	class BaseballCap_ColorBase;
	class BaseballCap_BackColorBase;
	class M65Jacket_ColorBase;
	class FoodAnimationSources;
	class FruitStageTransitions;
	class Worm;
	class ZombieMaleBase;

	class ZenGutBait : Worm
	{
		model = "\dz\gear\food\animal_smallguts.p3d";
		displayName = "Gut Bait";
		descriptionShort = "A piece cut from animal guts - makes for great fish bait!";
	};

	//! NBC Clothing insulation
	class NBCGloves_ColorBase : Clothing
	{
		heatIsolation = 1.0;
	}
	class NBCHoodBase : Clothing
	{
		heatIsolation = 1.0;
	};
	class NBCPantsBase : Clothing
	{
		heatIsolation = 1.0;
	};
	class NBCBootsBase : Clothing
	{
		heatIsolation = 1.0;
	};
	class NBCJacketBase : Clothing
	{
		heatIsolation = 1.0;
	};

	class Vodka : Bottle_Base
	{
		scope = 2;
		displayName = "$STR_CfgVehicles_Vodka0";
		descriptionShort = "$STR_CfgVehicles_Vodka1";
		model = "\dz\gear\drinks\VodkaBottles.p3d";
		weight = 450;
		itemSize[] = { 1,3 };
		destroyOnEmpty = 0;
		varQuantityDestroyOnMin = 0;
		varLiquidTypeInit = 2048;
		liquidContainerType = "1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256 + 512 + 1024 + 2048 + 4096 + 8192 + 16384 + 32768 + 65536  - (1 + 2 + 4 + 8 + 16 + 32 + 64 + 128 + 256) -32768";
		varQuantityInit = 500;
		varQuantityMin = 0;
		varQuantityMax = 500;
		varTemperatureMax = 1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 20;
					healthLevels[] =
					{

						{
							1,

							{
								"DZ\gear\drinks\data\VodkaBottles.rvmat"
							}
						},

						{
							0.69999999,

							{
								"DZ\gear\drinks\data\VodkaBottles.rvmat"
							}
						},

						{
							0.5,

							{
								"DZ\gear\drinks\data\VodkaBottles_damage.rvmat"
							}
						},

						{
							0.30000001,

							{
								"DZ\gear\drinks\data\VodkaBottles_damage.rvmat"
							}
						},

						{
							0,

							{
								"DZ\gear\drinks\data\VodkaBottles_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		soundImpactType = "glass";
		class AnimEvents
		{
			class SoundWeapon
			{
				class GlassBottle_in_B
				{
					soundSet = "GlassBottle_in_B_SoundSet";
					id = 202;
				};
				class GlassBottle_in_C
				{
					soundSet = "GlassBottle_in_C_SoundSet";
					id = 203;
				};
				class WaterBottle_in_C1
				{
					soundSet = "WaterBottle_in_C1_SoundSet";
					id = 204;
				};
				class GlassBottle_out_A
				{
					soundSet = "GlassBottle_out_A_SoundSet";
					id = 205;
				};
				class GlassBottle_out_B
				{
					soundSet = "GlassBottle_out_B_SoundSet";
					id = 206;
				};
				class WellPond_loop
				{
					soundSet = "WellPond_loop_SoundSet";
					id = 209;
				};
				class WellBottle_loop
				{
					soundSet = "WellBottle_loop_SoundSet";
					id = 210;
				};
			};
		};
	};

	//! Berries 
	class ZenBerryBase: Edible_Base
	{
		scope=2;
		displayName="Berries";
		descriptionShort="$STR_SambucusBerry1";
		model="\dz\gear\food\Sambucus_nigra.p3d";
		debug_ItemCategory=6;
		weight=0;
		itemSize[]={1,1};
		stackedUnit="g";
		absorbency=0.40000001;
		varQuantityInit=50;
		varQuantityMin=0;
		varQuantityMax=50;
		quantityBar=1;
		inventorySlot[]=
		{
			"Ingredient",
			"BerryB"
		};
		containsSeedsType="";
		containsSeedsQuantity="0";
		hiddenSelections[]=
		{
			"cs_raw",
			"cs_dried"
		};
		hiddenSelectionsTextures[]=
		{
			"dz\gear\food\data\sambucus_nigra_CO.paa",
			"dz\gear\food\data\sambucus_nigra_dried_CO.paa",
			"dz\gear\food\data\sambucus_nigra_dried_CO.paa",
			"dz\gear\food\data\sambucus_nigra_dried_CO.paa",
			"dz\gear\food\data\sambucus_nigra_burnt_CO.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\gear\food\data\sambucus_nigra_raw.rvmat",
			"dz\gear\food\data\sambucus_nigra_boiled.rvmat",
			"dz\gear\food\data\sambucus_nigra_baked.rvmat",
			"dz\gear\food\data\sambucus_nigra_dried.rvmat",
			"dz\gear\food\data\sambucus_nigra_burnt.rvmat",
			"dz\gear\food\data\sambucus_nigra_rotten.rvmat"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=10;
					healthLevels[]=
					{
						
						{
							1,
							{}
						},
						
						{
							0.69999999,
							{}
						},
						
						{
							0.5,
							{}
						},
						
						{
							0.30000001,
							{}
						},
						
						{
							0,
							{}
						}
					};
				};
			};
		};
		class AnimationSources: FoodAnimationSources
		{
		};
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[]={0,0,0};
					nutrition_properties[]={2.5,50,80,1,0};
					cooking_properties[]={0,0};
				};
				class Rotten
				{
					visual_properties[]={-1,-1,5};
					nutrition_properties[]={2,37.5,40,1,0,16};
					cooking_properties[]={0,0};
				};
				class Baked
				{
					visual_properties[]={0,1,1};
					nutrition_properties[]={1.75,90,40,1,0};
					cooking_properties[]={70,35};
				};
				class Boiled
				{
					visual_properties[]={0,2,2};
					nutrition_properties[]={1.5,90,80,1,0};
					cooking_properties[]={70,45};
				};
				class Dried
				{
					visual_properties[]={1,3,3};
					nutrition_properties[]={0.75,90,8,1,0};
					cooking_properties[]={70,30,80};
				};
				class Burned
				{
					visual_properties[]={0,4,4};
					nutrition_properties[]={2,37.5,20,1,0};
					cooking_properties[]={100,20};
				};
			};
			class FoodStageTransitions: FruitStageTransitions
			{
			};
		};
		soundImpactType="organic";
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet="openTunaCan_SoundSet";
					id=204;
				};
				class pickUpItem
				{
					soundSet="Zucchini_pickup_SoundSet";
					id=797;
				};
				class Eating_TakeFood
				{
					soundSet="Eating_TakeFood_Soundset";
					id=889;
				};
				class Eating_BoxOpen
				{
					soundSet="Eating_BoxOpen_Soundset";
					id=893;
				};
				class Eating_BoxShake
				{
					soundSet="Eating_BoxShake_Soundset";
					id=894;
				};
				class Eating_BoxEnd
				{
					soundSet="Eating_BoxEnd_Soundset";
					id=895;
				};
			};
		};
	};
	class Zen_SambucusBerry: ZenBerryBase
	{
		scope=2;
		displayName="Berries";
		descriptionShort="$STR_SambucusBerry1";
		model="\dz\gear\food\Sambucus_nigra.p3d";
		debug_ItemCategory=6;
		weight=0;
		itemSize[]={1,1};
		stackedUnit="g";
		absorbency=0.40000001;
		varQuantityInit=50;
		varQuantityMin=0;
		varQuantityMax=50;
		quantityBar=1;
		inventorySlot[]=
		{
			"Ingredient",
			"BerryB"
		};
		containsSeedsType="";
		containsSeedsQuantity="0";
		hiddenSelections[]=
		{
			"cs_raw",
			"cs_dried"
		};
		hiddenSelectionsTextures[]=
		{
			"dz\gear\food\data\sambucus_nigra_CO.paa",
			"dz\gear\food\data\sambucus_nigra_dried_CO.paa",
			"dz\gear\food\data\sambucus_nigra_dried_CO.paa",
			"dz\gear\food\data\sambucus_nigra_dried_CO.paa",
			"dz\gear\food\data\sambucus_nigra_burnt_CO.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\gear\food\data\sambucus_nigra_raw.rvmat",
			"dz\gear\food\data\sambucus_nigra_boiled.rvmat",
			"dz\gear\food\data\sambucus_nigra_baked.rvmat",
			"dz\gear\food\data\sambucus_nigra_dried.rvmat",
			"dz\gear\food\data\sambucus_nigra_burnt.rvmat",
			"dz\gear\food\data\sambucus_nigra_rotten.rvmat"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=10;
					healthLevels[]=
					{
						
						{
							1,
							{}
						},
						
						{
							0.69999999,
							{}
						},
						
						{
							0.5,
							{}
						},
						
						{
							0.30000001,
							{}
						},
						
						{
							0,
							{}
						}
					};
				};
			};
		};
		class AnimationSources: FoodAnimationSources
		{
		};
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[]={0,0,0};
					nutrition_properties[]={2.5,50,80,1,0};
					cooking_properties[]={0,0};
				};
				class Rotten
				{
					visual_properties[]={-1,-1,5};
					nutrition_properties[]={2,37.5,40,1,0,16};
					cooking_properties[]={0,0};
				};
				class Baked
				{
					visual_properties[]={0,1,1};
					nutrition_properties[]={1.75,90,40,1,0};
					cooking_properties[]={70,35};
				};
				class Boiled
				{
					visual_properties[]={0,2,2};
					nutrition_properties[]={1.5,90,80,1,0};
					cooking_properties[]={70,45};
				};
				class Dried
				{
					visual_properties[]={1,3,3};
					nutrition_properties[]={0.75,90,8,1,0};
					cooking_properties[]={70,30,80};
				};
				class Burned
				{
					visual_properties[]={0,4,4};
					nutrition_properties[]={2,37.5,20,1,0};
					cooking_properties[]={100,20};
				};
			};
			class FoodStageTransitions: FruitStageTransitions
			{
			};
		};
		soundImpactType="organic";
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet="openTunaCan_SoundSet";
					id=204;
				};
				class pickUpItem
				{
					soundSet="Zucchini_pickup_SoundSet";
					id=797;
				};
				class Eating_TakeFood
				{
					soundSet="Eating_TakeFood_Soundset";
					id=889;
				};
				class Eating_BoxOpen
				{
					soundSet="Eating_BoxOpen_Soundset";
					id=893;
				};
				class Eating_BoxShake
				{
					soundSet="Eating_BoxShake_Soundset";
					id=894;
				};
				class Eating_BoxEnd
				{
					soundSet="Eating_BoxEnd_Soundset";
					id=895;
				};
			};
		};
	};
	class Zen_SambucusBerry_Poison: Zen_SambucusBerry
	{
		scope=2;
		overdosedIncrement=0.5;
		hiddenSelectionsTextures[]=
		{
			"ZenModShared\data\textures\sambucus_poison_CO.paa",
			"dz\gear\food\data\sambucus_nigra_dried_CO.paa",
			"dz\gear\food\data\sambucus_nigra_dried_CO.paa",
			"dz\gear\food\data\sambucus_nigra_dried_CO.paa",
			"dz\gear\food\data\sambucus_nigra_burnt_CO.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\gear\food\data\sambucus_nigra_raw.rvmat",
			"dz\gear\food\data\sambucus_nigra_boiled.rvmat",
			"dz\gear\food\data\sambucus_nigra_baked.rvmat",
			"dz\gear\food\data\sambucus_nigra_dried.rvmat",
			"dz\gear\food\data\sambucus_nigra_burnt.rvmat",
			"dz\gear\food\data\sambucus_nigra_rotten.rvmat"
		};
	};
	class Zen_CaninaBerry: ZenBerryBase
	{
		scope=2;
		displayName="Berries";
		descriptionShort="$STR_CaninaBerry1";
		model="\dz\gear\food\canina_raw.p3d";
		debug_ItemCategory=6;
		itemSize[]={1,1};
		weight=0;
		stackedUnit="g";
		absorbency=0.40000001;
		varQuantityInit=50;
		varQuantityMin=0;
		varQuantityMax=50;
		quantityBar=1;
		inventorySlot[]=
		{
			"Ingredient",
			"BerryR"
		};
		ontainsSeedsType="";
		containsSeedsQuantity="0";
		hiddenSelections[]=
		{
			"cs_raw"
		};
		hiddenSelectionsTextures[]=
		{
			"dz\gear\food\data\canina_raw_CO.paa",
			"dz\gear\food\data\canina_baked_CO.paa",
			"dz\gear\food\data\canina_raw_CO.paa",
			"dz\gear\food\data\canina_dried_CO.paa",
			"dz\gear\food\data\canina_baked_CO.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\gear\food\data\canina_raw.rvmat",
			"dz\gear\food\data\canina_baked.rvmat",
			"dz\gear\food\data\canina_boiled.rvmat",
			"dz\gear\food\data\canina_dried.rvmat",
			"dz\gear\food\data\canina_burnt.rvmat",
			"dz\gear\food\data\canina_rotten.rvmat"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=10;
					healthLevels[]=
					{
						
						{
							1,
							{}
						},
						
						{
							0.69999999,
							{}
						},
						
						{
							0.5,
							{}
						},
						
						{
							0.30000001,
							{}
						},
						
						{
							0,
							{}
						}
					};
				};
			};
		};
		class AnimationSources: FoodAnimationSources
		{
		};
		class Food
		{
			class FoodStages
			{
				class Raw
				{
					visual_properties[]={0,0,0};
					nutrition_properties[]={2.5,50,80,1,0};
					cooking_properties[]={0,0};
				};
				class Rotten
				{
					visual_properties[]={-1,-1,5};
					nutrition_properties[]={2,37.5,40,1,0,16};
					cooking_properties[]={0,0};
				};
				class Baked
				{
					visual_properties[]={0,1,1};
					nutrition_properties[]={1.75,90,40,1,0};
					cooking_properties[]={70,35};
				};
				class Boiled
				{
					visual_properties[]={0,2,2};
					nutrition_properties[]={1.5,90,80,1,0};
					cooking_properties[]={70,45};
				};
				class Dried
				{
					visual_properties[]={0,3,3};
					nutrition_properties[]={0.75,90,8,1,0};
					cooking_properties[]={70,30,80};
				};
				class Burned
				{
					visual_properties[]={0,4,4};
					nutrition_properties[]={2,37.5,20,1,0};
					cooking_properties[]={100,20};
				};
			};
			class FoodStageTransitions: FruitStageTransitions
			{
			};
		};
		soundImpactType="organic";
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet="openTunaCan_SoundSet";
					id=204;
				};
				class pickUpItem
				{
					soundSet="Zucchini_pickup_SoundSet";
					id=797;
				};
				class Eating_TakeFood
				{
					soundSet="Eating_TakeFood_Soundset";
					id=889;
				};
				class Eating_BoxOpen
				{
					soundSet="Eating_BoxOpen_Soundset";
					id=893;
				};
				class Eating_BoxShake
				{
					soundSet="Eating_BoxShake_Soundset";
					id=894;
				};
				class Eating_BoxEnd
				{
					soundSet="Eating_BoxEnd_Soundset";
					id=895;
				};
			};
		};
	};
	class Zen_CaninaBerry_Poison: ZenBerryBase
	{
		scope=2;
		overdosedIncrement=0.5;
		hiddenSelectionsTextures[]=
		{
			"ZenModShared\data\textures\canina_poison_CO.paa",
			"dz\gear\food\data\canina_baked_CO.paa",
			"dz\gear\food\data\canina_raw_CO.paa",
			"dz\gear\food\data\canina_dried_CO.paa",
			"dz\gear\food\data\canina_baked_CO.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\gear\food\data\canina_raw.rvmat",
			"dz\gear\food\data\canina_baked.rvmat",
			"dz\gear\food\data\canina_boiled.rvmat",
			"dz\gear\food\data\canina_dried.rvmat",
			"dz\gear\food\data\canina_burnt.rvmat",
			"dz\gear\food\data\canina_rotten.rvmat"
		};
	};

	class BallisticHelmet_ColorBase: Clothing
	{
		inventorySlot[]+=
		{
			"Ingredient"
		};
	};
	class ConstructionHelmet_ColorBase: Clothing
	{
		inventorySlot[]+=
		{
			"Ingredient"
		};
	};
	class MotoHelmet_ColorBase: Clothing
	{
		inventorySlot[]+=
		{
			"Ingredient"
		};
	};
	class DarkMotoHelmet_ColorBase: Clothing
	{
		inventorySlot[]+=
		{
			"Ingredient"
		};
	};
	class GorkaHelmet: Clothing
	{
		inventorySlot[]+=
		{
			"Ingredient"
		};
	};
	class FirefightersHelmet_ColorBase: Clothing
	{
		inventorySlot[]+=
		{
			"Ingredient"
		};
	};
	class SkateHelmet_ColorBase: Clothing
	{
		inventorySlot[]+=
		{
			"Ingredient"
		};
	};
	class DirtBikeHelmet_ColorBase: Clothing
	{
		inventorySlot[]+=
		{
			"Ingredient"
		};
	};
	class HockeyHelmet_ColorBase: Clothing
	{
		inventorySlot[]+=
		{
			"Ingredient"
		};
	};
	class Mich2001Helmet: Clothing
	{
		inventorySlot[]+=
		{
			"Ingredient"
		};
	};
	class ZSh3PilotHelmet: Clothing
	{
		inventorySlot[]+=
		{
			"Ingredient"
		};
	};
	class Ssh68Helmet: Clothing
	{
		inventorySlot[]+=
		{
			"Ingredient"
		};
	};
	class NorseHelm: Clothing
	{
		inventorySlot[]+=
		{
			"Ingredient"
		};
	};

	class Zen_CraftableMapKit: Inventory_Base
	{
		scope=2;
		displayName="Wall Map Kit";
		descriptionShort="If I attach a map to this kit I can place a map on the wall.";
		model="\dz\gear\traps\tripwire.p3d";
		rotationFlags=16;
		attachments[]=
		{
			"map"
		};
		weight=600;
		itemSize[]={1,4};
		itemBehaviour=1;
		hiddenSelections[]=
		{
			"placing"
		};
		hiddenSelectionsTextures[]=
		{
			"dz\gear\traps\data\snaretrap_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\gear\traps\data\snaretrap.rvmat"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=50;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"dz\gear\traps\data\snaretrap.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"dz\gear\traps\data\snaretrap.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"dz\gear\traps\data\snaretrap_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"dz\gear\traps\data\snaretrap_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"dz\gear\traps\data\snaretrap_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class AnimationSources
		{
			class inventory
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=0;
			};
			class placing
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=1;
			};
			class triggered
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=1;
			};
		};
		soundImpactType="wood";
	};
	class Zen_CraftableMap: Inventory_Base
	{
		scope=2;
		displayName="$STR_CfgVehicles_ChernarusMap0";
		descriptionShort="$STR_CfgVehicles_ChernarusMap1";
		model="\DZ\structures_bliss\military\Houses\Proxy\mil_enoch_map.p3d";
		itemSize[]={10,10};
		weight=2000;
		itemBehaviour = 1;
		attachments[] +=
		{
			"ZenMapPin1",
			"ZenMapPin2",
			"ZenMapPin3"
		};
	};
	class Zen_MapPin_Base : Inventory_Base
	{
		scope = 2;
		displayName = "Map Pin";
		descriptionShort = "A small pin useful for placing on a map";
		model = "\ZenModShared\data\models\mappin\mappin.p3d";
		hiddenSelections[] = { "body" };
		hiddenSelectionsTextures[] = { "#(argb,8,8,3)color(0,0,0,1,CO)" };
		itemSize[] = { 1,1 };
		weight = 100;
		itemBehaviour = 1;
		alignHologramToTerain = 0;
		slopeTolerance = 0.30000001;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] =
					{

						{
							1,

							{
								"ZenModShared\data\models\mappin\pin.rvmat"
							}
						},

						{
							0.69999999,

							{
								"ZenModShared\data\models\mappin\pin.rvmat"
							}
						},

						{
							0.5,

							{
								"ZenModShared\data\models\mappin\pin.rvmat"
							}
						},

						{
							0.30000001,

							{
								"ZenModShared\data\models\mappin\pin.rvmat"
							}
						},

						{
							0,

							{
								"ZenModShared\data\models\mappin\pin.rvmat"
							}
						}
					};
				};
			};
		};
		soundImpactType = "plastic";
	};
	class Zen_MapPin_Red : Zen_MapPin_Base
	{
		scope = 2;
		hiddenSelections[] = { "body" };
		hiddenSelectionsTextures[] = { "#(argb,8,8,3)color(1,0,0,1,CO)" };
		inventorySlot[] = { "ZenMapPin1" };
	};
	class Zen_MapPin_Green : Zen_MapPin_Base
	{
		scope = 2;
		hiddenSelections[] = { "body" };
		hiddenSelectionsTextures[] = { "#(argb,8,8,3)color(0,1,0,1,CO)" };
		inventorySlot[] = { "ZenMapPin2" };
	};
	class Zen_MapPin_Blue : Zen_MapPin_Base
	{
		scope = 2;
		hiddenSelections[] = { "body" };
		hiddenSelectionsTextures[] = { "#(argb,8,8,3)color(0,0,1,1,CO)" };
		inventorySlot[] = { "ZenMapPin3" };
	};

	class ZenMapUnfolded: Inventory_Base 
	{
		scope=2;
		model="\ZenMiscAssets\data\misc\zen_map.p3d";
		displayName="$STR_CfgVehicles_ChernarusMap0";
		descriptionShort="$STR_CfgVehicles_ChernarusMap1";
		rotationFlags=2;
		itemSize[]={2,2};
		weight=40;
		selectionPaper="paper";
		absorbency=1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=50;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\gear\navigation\data\Map_chernarus.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\navigation\data\Map_chernarus.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\navigation\data\Map_chernarus_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\navigation\data\Map_chernarus_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\navigation\data\Map_chernarus_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};

	class Heatpack: Inventory_Base
	{
		scope=2;
		class EnergyManager
		{
			energyAtSpawn=2400;
			energyUsagePerSecond=1;
			updateInterval=60;
		};
	};

	// Define this object here so that we can have it not despawn when switching to summer, allowing us to auto-convert Winter stash into Summer stash
	class WinterStash: UndergroundStash
	{
		scope=2;
		model="WinterStash\Snow_dirtpile\Snow_dirtpile.p3d";
	};

	class Hatchet: Inventory_Base
	{
		scope=2;
		model="\ZenModShared\data\models\zen_hatchet.p3d";
		simpleHiddenSelections[]= 
		{
			"camo",
			"zbytek",
			"backwards"
	    };
	};

	class TacticalGoggles: Clothing
	{
		// Repairable with epoxy
		repairableWithKits[]={8};
		repairCosts[]={25};
	}

	// Easter egg edible 
	class Zen_EasterEgg: Edible_Base
	{
		scope=2;
		displayName="Easter Egg";
		descriptionShort="A delicious chocolate Easter Egg - very filling!";
		model="\dz\gear\consumables\EasterEgg.p3d";
		itemSize[]={1,1};
		stackedUnit="g";
		weight=10;
		weightPerQuantityUnit=0.0014600001;
		varQuantityInit=150;
		varQuantityMin=0;
		varQuantityMax=150;
		class Nutrition
		{
			fullnessIndex=3;
			energy=4500;
			water=0;
			nutritionalIndex=1;
			toxicity=0;
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=10;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"dz\gear\consumables\data\easter_egg.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"dz\gear\consumables\data\easter_egg.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"dz\gear\consumables\data\easter_egg_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"dz\gear\consumables\data\easter_egg_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"dz\gear\consumables\data\easter_egg_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		soundImpactType="plastic";
	};

	class Zen_AliceBag_Admin: AliceBag_ColorBase
	{
		scope=2;
		visibilityModifier=0.69999999;
		itemsCargoSize[]={10,150};
		attachments[] +=
		{
			"Melee",
			"Shoulder"
		};
		hiddenSelectionsTextures[]=
		{
			"\dz\characters\backpacks\data\alicebackpack_black_co.paa",
			"\dz\characters\backpacks\data\alicebackpack_black_co.paa",
			"\dz\characters\backpacks\data\alicebackpack_black_co.paa"
		};
	};

	class HuntingKnife_Black: HuntingKnife
	{
		scope=2;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"ZenModShared\data\textures\black_hunting_knife_co.paa"
		};
	};
	class AK_Bayonet_Black: AK_Bayonet
	{
		scope=2;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"ZenModShared\data\textures\black_russian_akm_bayonet_co.paa",
			"ZenModShared\data\textures\black_russian_akm_bayonet_co.paa"
		};
	};
	class M9A1_Bayonet_Black: M9A1_Bayonet
	{
		scope=2;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"ZenModShared\data\textures\black_m4_bayonet_co.paa",
			"ZenModShared\data\textures\black_m4_bayonet_co.paa"
		};
	};

	//! VANILLA OVERRIDES
	class Canteen : Bottle_Base
	{
		scope = 2;
		attachments[] = { "Material_Chlorine" };
		class GUIInventoryAttachmentsProps
		{
			class Materials
			{
				name = "Chlorine Tablets";
				description = "Chlorine Tablets";
				attachmentSlots[] = { "Material_Chlorine" };
				icon = "missing";
			};
		};
	};

	// Add weapon cleaning kit to crossbow
	class Crossbow_Base: Archery_Base
	{
		repairableWithKits[]+={1};
		repairCosts[]+={25};
	};

	//! OTHER
	class FireNoises
	{
		class NoiseCooking
		{
			strength=500;
			type="sound";
		}
	}

	class WaterPouch_ColorBase: Bottle_Base
	{
		varTemperatureMin=10;
		varTemperatureMax=10;
		varQuantityMax=1500;
		inventorySlot[] +=
		{
			"Belt_Left"
		};
	}

	class HeadlightH7_Box: Box_Base
	{
		scope = 2;
		class AnimEvents
		{
			class SoundWeapon
			{
				class interact
				{
					soundset="ammoboxUnpack_SoundSet";
					id=70;
				};
			};
		};
	}

	// Beers
	class BeerCan_VB: SodaCan_ColorBase
	{
		scope=2;
		displayName="Victoria Bitters";
		descriptionShort="For a hard earned thirst..";
		hiddenSelectionsTextures[]=
		{
			"ZenModShared\data\textures\sodacan_vb.paa"
		};
		inventorySlot[] +=
		{
			"DirectCookingA",
			"DirectCookingB",
			"DirectCookingC"
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class SodaCan_in_B
				{
					soundSet="SodaCan_in_B_SoundSet";
					id=202;
				};
				class WellPond_loop
				{
					soundSet="WellPond_loop_SoundSet";
					id=209;
				};
				class WellBottle_loop
				{
					soundSet="WellBottle_loop_SoundSet";
					id=210;
				};
				class pickup
				{
					soundSet="SodaCan_pickup_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="SodaCan_drop_SoundSet";
					id=898;
				};
			};
		};
	};
	class BeerCan_XXXX: SodaCan_ColorBase
	{
		scope=2;
		displayName="XXXX Gold";
		descriptionShort="Pride of Queensland.";
		hiddenSelectionsTextures[]=
		{
			"ZenModShared\data\textures\sodacan_xxxx.paa"
		};
		inventorySlot[] +=
		{
			"DirectCookingA",
			"DirectCookingB",
			"DirectCookingC"
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class SodaCan_in_B
				{
					soundSet="SodaCan_in_B_SoundSet";
					id=202;
				};
				class WellPond_loop
				{
					soundSet="WellPond_loop_SoundSet";
					id=209;
				};
				class WellBottle_loop
				{
					soundSet="WellBottle_loop_SoundSet";
					id=210;
				};
				class pickup
				{
					soundSet="SodaCan_pickup_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="SodaCan_drop_SoundSet";
					id=898;
				};
			};
		};
	};
	class BeerCan_Corona: SodaCan_ColorBase
	{
		scope=2;
		displayName="Corona";
		descriptionShort="From where you'd rather be";
		hiddenSelectionsTextures[]=
		{
			"ZenModShared\data\textures\sodacan_corona.paa"
		};
		inventorySlot[] +=
		{
			"DirectCookingA",
			"DirectCookingB",
			"DirectCookingC"
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class SodaCan_in_B
				{
					soundSet="SodaCan_in_B_SoundSet";
					id=202;
				};
				class WellPond_loop
				{
					soundSet="WellPond_loop_SoundSet";
					id=209;
				};
				class WellBottle_loop
				{
					soundSet="WellBottle_loop_SoundSet";
					id=210;
				};
				class pickup
				{
					soundSet="SodaCan_pickup_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="SodaCan_drop_SoundSet";
					id=898;
				};
			};
		};
	};

	class Empty_SodaCan_ColorBase; // from ZenLeftovers
	class Empty_BeerCan_VB : Empty_SodaCan_ColorBase
	{
		scope = 2;
		displayName="Victoria Bitters";
		descriptionShort = "$STR_ZenLeftoversDescription";
		hiddenSelectionsTextures[] = { "ZenModShared\data\textures\sodacan_vb.paa" };
	};
	class Empty_BeerCan_XXXX : Empty_SodaCan_ColorBase
	{
		scope = 2;
		displayName="XXXX Gold";
		descriptionShort = "$STR_ZenLeftoversDescription";
		hiddenSelectionsTextures[] = { "ZenModShared\data\textures\sodacan_xxxx.paa" };
	};
	class Empty_BeerCan_Corona : Empty_SodaCan_ColorBase
	{
		scope = 2;
		displayName="Corona";
		descriptionShort = "$STR_ZenLeftoversDescription";
		hiddenSelectionsTextures[] = { "ZenModShared\data\textures\sodacan_corona.paa" };
	};

	class Lockpick: Inventory_Base
	{
		repairableWithKits[] = { 8 }; // epoxy
		repairCosts[] = { 25 };
	};

	// Cars for missions that can't be covered or stolen
	class Hatchback_02_Black;
	class Zen_Mission_Gunter_Black : Hatchback_02_Black
	{
		displayName = "Stolen Gunter";
		class Cargo
		{
			itemsCargoSize[] = { 10,6 };
			allowOwnedCargoManipulation = 1;
			openable = 0;
		};
	};

	// Make containers for missions that can't be taken
	class WoodenCrate;
	class Zen_Mission_WoodenCrate : WoodenCrate
	{
		scope = 2;
		displayName = "A Wooden Box";
		descriptionShort = "A wooden box - it's badly damaged, if I try to pick it up it's going to fall to pieces.";
		inventorySlot[] = {};
	};
	class SeaChest;
	class Zen_Mission_SeaChest : SeaChest
	{
		scope = 2;
		displayName = "An Old Chest";
		descriptionShort = "An old wooden chest - it's badly damaged, if I try to pick it up it's going to fall to pieces.";
	};
	class MediumTent_Orange;
	class Zen_Mission_MediumTent : MediumTent_Orange
	{
		scope = 2;
		displayName = "Survivor Tent (Can't Be Packed)";
	}
	class Zen_Mission_AntiBodiesVial : Inventory_Base
	{
		scope = 2;
		displayName = "Antibodies Research Vial";
		descriptionShort = "A vial containing infection antibodies. Perhaps the UN can use this to help engineer a cure for the virus...";
		model = "\dz\gear\medical\InjectionVial.p3d";
		itemSize[] = { 2,2 };
		weight = 10000;
		lootCategory = "Medical";
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "ZenVirus\data\textures\Antibodiesvial_co.paa","ZenVirus\data\textures\Antibodiesvial_co.paa","ZenVirus\data\textures\Antibodiesvial_co.paa" };
	};
	class Zen_Mission_PathogenVial : Inventory_Base
	{
		scope = 2;
		displayName = "Pathogen Research Vial";
		descriptionShort = "A vial containing isolated infection pathogens. Perhaps the UN can use this to help engineer a cure for the virus...";
		model = "\dz\gear\medical\InjectionVial.p3d";
		itemSize[] = { 2,2 };
		weight = 10000;
		lootCategory = "Medical";
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "ZenVirus\data\textures\Ragevirusvial_co.paa","ZenVirus\data\textures\Ragevirusvial_co.paa","ZenVirus\data\textures\Ragevirusvial_co.paa" };
	};

	// Mission civilian Cars
	class Zen_MissionCarBase : SeaChest
	{
		scope=0;
		model="\DZ\structures\Wrecks\Vehicles\Wreck_sed01_aban1_white.p3d";
		displayName="Vehicle";
		physLayer = "item_large";
	};
	class Zen_MissionCar_1: Zen_MissionCarBase
	{
		scope=2;
		itemsCargoSize[] = { 10,100 };
		model="\DZ\structures\Wrecks\Vehicles\Wreck_sed01_aban1_white.p3d";
	};

	// Valium
	class Zen_ValiumBottle : Edible_Base
	{
		scope = 2;
		displayName = "Valium";
		descriptionShort = "Extremely high dose diazepam tablets. The label says DO NOT UNDER ANY CIRCUMSTANCES CONSUME WITH ALCOHOL. I wonder what would happen if I ate it and then drank some vodka...";
		model = "\dz\gear\medical\VitaminBottle.p3d";
		debug_ItemCategory = 7;
		varQuantityInit = 1;
		varQuantityMin = 0;
		varQuantityMax = 2;
		varQuantityDestroyOnMin = 1;
		itemSize[] = { 1,2 };
		weight = 20;
		stackedUnit = "pills";
		quantityBar = 0;
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "ZenModShared\data\textures\valium_bottle_co.paa" };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] =
					{

						{
							1,

							{
								"DZ\gear\medical\data\vitamin_bottle.rvmat"
							}
						},

						{
							0.69999999,

							{
								"DZ\gear\medical\data\vitamin_bottle.rvmat"
							}
						},

						{
							0.5,

							{
								"DZ\gear\medical\data\vitamin_bottle_damage.rvmat"
							}
						},

						{
							0.30000001,

							{
								"DZ\gear\medical\data\vitamin_bottle_damage.rvmat"
							}
						},

						{
							0,

							{
								"DZ\gear\medical\data\vitamin_bottle_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class VitaminBottle_open
				{
					soundSet = "VitaminBottle_open_SoundSet";
					id = 201;
				};
				class VitaminBottle_shake
				{
					soundSet = "VitaminBottle_shake_SoundSet";
					id = 202;
				};
				class VitaminBottle_close
				{
					soundSet = "VitaminBottle_close_SoundSet";
					id = 203;
				};
				class pickUpItem
				{
					soundSet = "vitaminbottle_pickup_SoundSet";
					id = 797;
				};
			};
		};
	};

	// Dextroamphetamine
	class Zen_DexBottle : Edible_Base
	{
		scope = 2;
		displayName = "Dextroamphetamine";
		descriptionShort = "Dextroamphetamine is a central nervous system stimulant and an amphetamine enantiomer that is prescribed for the treatment of attention deficit hyperactivity disorder and narcolepsy. It is also used as an athletic performance and cognitive enhancer, and recreationally as an aphrodisiac and euphoriant.";
		model = "\dz\gear\medical\VitaminBottle.p3d";
		debug_ItemCategory = 7;
		varQuantityInit = 1;
		varQuantityMin = 0;
		varQuantityMax = 10;
		varQuantityDestroyOnMin = 1;
		itemSize[] = { 1,2 };
		weight = 20;
		stackedUnit = "pills";
		quantityBar = 0;
		hiddenSelections[] = { "zbytek" };
		hiddenSelectionsTextures[] = { "ZenModShared\data\textures\dex_bottle_co.paa" };

		// Syberia
		medAdrenalinLevel=1;
		medAdrenalinTimeSec=600;
		overdosedIncrement=0.1;
		medicalItem = 1;

		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] =
					{

						{
							1,

							{
								"DZ\gear\medical\data\vitamin_bottle.rvmat"
							}
						},

						{
							0.69999999,

							{
								"DZ\gear\medical\data\vitamin_bottle.rvmat"
							}
						},

						{
							0.5,

							{
								"DZ\gear\medical\data\vitamin_bottle_damage.rvmat"
							}
						},

						{
							0.30000001,

							{
								"DZ\gear\medical\data\vitamin_bottle_damage.rvmat"
							}
						},

						{
							0,

							{
								"DZ\gear\medical\data\vitamin_bottle_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class VitaminBottle_open
				{
					soundSet = "VitaminBottle_open_SoundSet";
					id = 201;
				};
				class VitaminBottle_shake
				{
					soundSet = "VitaminBottle_shake_SoundSet";
					id = 202;
				};
				class VitaminBottle_close
				{
					soundSet = "VitaminBottle_close_SoundSet";
					id = 203;
				};
				class pickUpItem
				{
					soundSet = "vitaminbottle_pickup_SoundSet";
					id = 797;
				};
			};
		};
	};

	// Zombie sounds (no object - just a Noise)
	class Zen_Whistle : Inventory_Base
	{
		scope = 2;
		class NoiseCallZombies
		{
			strength = 500;
			type = "shot";
		};
	};

	// Extend handheld radio distance
	class Transmitter_Base;
	class PersonalRadio : Transmitter_Base
	{
		scope = 2;
		descriptionShort = "Long range personal radio with a frequency switch. Can reach survivors up to 10km away. Requires a battery to operate.";
		range = 10000;
		class EnergyManager
		{
			hasIcon = 1;
			autoSwitchOff = 1;
			energyUsagePerSecond = 0.001;
			plugType = 1;
			attachmentAction = 1;
			wetnessExposure = 0.1;
		};
	}

	// Second pair of bolt-cutters
	//class Zen_BoltCutter;
	//class Zen_BoltCutter2 : Zen_BoltCutter
	//{
	//	scope = 2;
	//};

	// Reduce shelter storage
	class ShelterBase;
	class ShelterStick : ShelterBase
	{
		scope = 2;
		itemsCargoSize[] = { 8,6 };
	};
	class ShelterFabric : ShelterBase
	{
		scope = 2;
		itemsCargoSize[] = { 9,8 };
	};
	class ShelterLeather : ShelterBase
	{
		scope = 2;
		itemsCargoSize[] = { 10,10 };
	}

	// Add Mosin long range scope
	class LongrangeOptic;
	class Zen_MosinLRS : LongrangeOptic
	{
		displayName = "Long Range Optic";
		descriptionShort = "A long range hunting scope designed specifically for the Mosin mount.";
		inventorySlot = "weaponOpticsMosin";
	};

	// Reduce bottle suppressor durability to 2 shots
	class ItemSuppressor;
	class ImprovisedSuppressor : ItemSuppressor
	{
		scope = 2;
		barrelArmor = 200; // 100 = 2 shots from a mosin
	};

	// Make rice make more sense
	class Rice : Edible_Base
	{
		displayName = "Cooked Rice";
		descriptionShort = "A bag of long-grained rice, pre-cooked and packaged for easier preparation.";
	};

	// Epoxy repair
	class CanisterGasoline : Bottle_Base
	{
		repairableWithKits[] = { 8 };
		repairCosts[] = { 25 };
		quantityBar = 1;
	};

	// Quiver for bolts
	class ZenQuiver : Inventory_Base
	{
		scope = 2;
		displayName = "Quiver";
		descriptionShort = "A quiver for carrying crossbow bolts!";
		model = "\dz\weapons\attachments\magazine\magazine_quiver.p3d";
		rotationFlags = 1;
		weight = 150;
		itemSize[] = { 2,3 };
		repairableWithKits[] = { 8 };
		repairCosts[] = { 30 };
		mass = 10;
		attachments[] =
		{
			"ZenQuiver1",
			"ZenQuiver2",
			"ZenQuiver3",
			"ZenQuiver4",
			"ZenQuiver5",
			"ZenQuiver6",
			"ZenQuiver7",
			"ZenQuiver8"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] =
					{

						{
							1,

							{
								"dz\characters\vests\data\chest_holster.rvmat",
							}
						},

						{
							0.69999999,

							{
								"dz\characters\vests\data\chest_holster.rvmat",
							}
						},

						{
							0.5,

							{
								"dz\characters\vests\data\chest_holster_damage.rvmat",
							}
						},

						{
							0.30000001,

							{
								"dz\characters\vests\data\chest_holster_damage.rvmat",
							}
						},

						{
							0,

							{
								"dz\characters\vests\data\chest_holster_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		soundImpactType = "textile";
	};

	// Re-describe some solar panel stuff
	class HouseNoDestruct;
	class PowerGenerator : Inventory_Base
	{
		class EnergyManager
		{
			hasIcon = 1;
			autoSwitchOff = 0;
			energyStorageMax = 10000;
			energyUsagePerSecond = 0.0001;
			reduceMaxEnergyByDamageCoef = 0.5;
			energyAtSpawn = 5000;
			powerSocketsCount = 4;
			compatiblePlugTypes[] = { 2,6 };
		};
	}

	class HumanSkull;
	class ZenHumanSkull : HumanSkull
	{
		inventorySlot[] =
		{
			"Ingredient"
		};
	};

	class Zen_CableReel: Inventory_Base
	{
		scope=2;
		displayName="$STR_CfgVehicles_CableReel0";
		descriptionShort="$STR_CfgVehicles_CableReel1";
		model="\dz\gear\camping\cable_reel.p3d";
		inventorySlot[]=
		{
			"CableReel"
		};
		slopeTolerance=0.2;
		yawPitchRollLimit[]={45,45,45};
		weight=5000;
		itemSize[]={3,4};
		itemBehaviour=2;
		rotationFlags=2;
		hiddenSelections[]=
		{
			"socket_1_plugged",
			"cord_plugged",
			"cord_folded",
			"placing"
		};
		hiddenSelectionsTextures[]=
		{
			"dz\gear\camping\data\cable_reel_co.paa",
			"dz\gear\camping\data\cable_reel_co.paa",
			"dz\gear\camping\data\cable_reel_co.paa",
			"dz\gear\camping\data\cable_reel_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\gear\camping\data\cable_reel.rvmat",
			"dz\gear\camping\data\cable_reel.rvmat",
			"dz\gear\camping\data\cable_reel.rvmat",
			"dz\gear\camping\data\cable_reel.rvmat"
		};
		hologramMaterial="cable_reel";
		hologramMaterialPath="dz\gear\camping\data";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=9999;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\gear\camping\data\cable_reel.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\camping\data\cable_reel.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\camping\data\cable_reel_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\camping\data\cable_reel_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\camping\data\cable_reel_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		soundImpactType="plastic";
		class EnergyManager
		{
			switchOnAtSpawn=1;
			powerSocketsCount=1;
			cordTextureFile="DZ\gear\camping\Data\plug_orange_CO.paa";
			isPassiveDevice=1;
			cordLength=100;
			plugType=2;
			compatiblePlugTypes[]={2,6};
		};
		class AnimationSources
		{
			class cord_folded
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=0;
			};
			class cord_plugged
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=1;
			};
			class socket_1_plugged
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=1;
			};
			class placing
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=0;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem_Light
				{
					soundSet="pickUpCableReelLight_SoundSet";
					id=796;
				};
				class pickUpItem
				{
					soundSet="pickUpCableReel_SoundSet";
					id=797;
				};
				class cablereel_drop
				{
					soundset="cablereel_drop_SoundSet";
					id=898;
				};
			};
		};
	};
	class Zen_Spotlight: Inventory_Base
	{
		scope=2;
		displayName="$STR_CfgVehicles_Spotlight0";
		descriptionShort="$STR_CfgVehicles_Spotlight1";
		model="\dz\gear\camping\spotlight.p3d";
		slopeTolerance=0.15000001;
		yawPitchRollLimit[]={18,18,18};
		hiddenSelections[]=
		{
			"placing",
			"cord_folded",
			"cord_plugged",
			"glass_unfolded",
			"reflector_unfolded",
			"glass_folded",
			"reflector_folded"
		};
		hiddenSelectionsTextures[]=
		{
			"dz\gear\camping\data\spotlight_co.paa",
			"dz\gear\camping\data\plug_yellow_co.paa",
			"dz\gear\camping\data\plug_yellow_co.paa",
			"dz\gear\camping\data\spotlight_glass_ca.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\gear\camping\data\spotlight.rvmat",
			"dz\gear\camping\data\plug.rvmat",
			"dz\gear\camping\data\plug.rvmat",
			"dz\gear\camping\data\spotlight_glass.rvmat"
		};
		hologramMaterial="spotlight";
		hologramMaterialPath="dz\gear\camping\data";
		weight=1700;
		itemSize[]={3,7};
		itemBehaviour=2;
		rotationFlags=2;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=9999;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\gear\camping\data\spotlight.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\camping\data\spotlight.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\camping\data\spotlight_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\camping\data\spotlight_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\camping\data\spotlight_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		repairableWithKits[]={7,10};
		repairCosts[]={25,30};
		soundImpactType="metal";
		class EnergyManager
		{
			hasIcon=1;
			energyUsagePerSecond=0.00001;
			cordTextureFile="DZ\gear\camping\Data\plug_yellow_CO.paa";
			cordLength=100;
			plugType=2;
			updateInterval=50;
		};
		class Reflectors
		{
			class Beam
			{
				color[]={0.80000001,0.89999998,1,1};
				brightness=20;
				radius=60;
				angle=140;
				angleInnerRatio=0.25;
				dayLight=0;
				position="beamStart";
				direction="beamTarget";
				hitpoint="glass_unfolded";
				selection="glass_unfolded";
			};
		};
		class AnimationSources
		{
			class cord_folded
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=1;
			};
			class cord_plugged
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=1;
			};
			class inventory
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=0;
			};
			class placing
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=1;
			};
			class reflector
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=1;
			};
			class reflector_folded
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=1;
			};
			class reflector_unfolded
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=1;
			};
			class glass_folded
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=1;
			};
			class glass_unfolded
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=1;
			};
			class spotlight_folded_cord_plugged
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=1;
			};
			class spotlight_folded_cord_folded
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=1;
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem_Light
				{
					soundSet="pickUpSpotLightLight_SoundSet";
					id=796;
				};
				class pickUpItem
				{
					soundSet="pickUpSpotLight_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="spotlight_drop_SoundSet";
					id=898;
				};
			};
		};
	};

	// Mission plane
	class ZenMission_Wreck_C130J : HouseNoDestruct
	{
		scope = 2;
		storageCategory = 4;
		model = "\DZ\structures\Wrecks\Aircraft\Wreck_C130J.p3d";
		forceFarBubble="true";
	};
	class ZenMission_Wreck_Hummer : HouseNoDestruct
	{
		scope = 2;
		storageCategory = 4;
		model = "DZ\structures\Wrecks\Vehicles\Wreck_HMMWV.p3d";
		forceFarBubble="true";
	};
	class ZenMission_Wreck_Heli : HouseNoDestruct
	{
		scope = 2;
		storageCategory = 4;
		model = "\DZ\structures\Wrecks\Aircraft\Wreck_UH1Y.p3d";
		forceFarBubble="true";
	};

	// Halloween - zombie mummy cargo size enlarged 
	class ZmbM_Mummy : ZombieMaleBase
	{
		class Cargo
		{
			itemsCargoSize[] = { 6,8 };
			allowOwnedCargoManipulation = 1;
			openable = 0;
		};
	};

	// Change vanilla items (stack size etc)
	class Pen_ColorBase : Inventory_Base
	{
		descriptionShort = "Regular coloured pen. Unsurprisingly, it can be used for writing things down. If I use it on blank paper I can leave notes for other survivors to find...";
	};
	class Paper : Inventory_Base
	{
		canBeSplit = 1;
		varQuantityInit = 1;
		varQuantityMin = 0;
		varQuantityMax = 5;
		varStackMax = 5;
		varQuantityDestroyOnMin = 1;
	};
	// Make punched card non-stackable as it inherits from Paper
	class PunchedCard : Paper
	{
		canBeSplit = 0;
		varQuantityInit = 1;
		varQuantityMin = 0;
		varQuantityMax = 1;
		varStackMax = 1;
		varQuantityDestroyOnMin = 1;
	};
	class NailBox : Box_Base
	{
		scope = 2;
		weight = 300;
	};
	class Nail : Inventory_Base
	{
		canBeSplit = 1;
		varQuantityInit = 1;
		varQuantityMin = 0;
		varQuantityMax = 1000;
		varStackMax = 250;
		varQuantityDestroyOnMin = 1;
		weight = 4;
	};
	class WoodenPlank : Inventory_Base
	{
		canBeSplit = 1;
		varQuantityInit = 1;
		varStackMax = 20;
		varQuantityDestroyOnMin = 1;
	};
	class Firewood : Inventory_Base
	{
		canBeSplit = 1;
		varQuantityInit = 1;
		varQuantityMin = 0;
		varQuantityMax = 6;
		varStackMax = 6;
		varQuantityDestroyOnMin = 1;
	};
	class FireplaceBase;
	class Fireplace : FireplaceBase
	{
		physLayer = "item_small";
		attachments[] +=
		{
			"Book"
		};
		class GUIInventoryAttachmentsProps
		{
			class Kindling
			{
				attachmentSlots[] +=
				{
					"Book"
				};
			};
		}
	};
	class FireplaceIndoor : FireplaceBase
	{
		attachments[] +=
		{
			"Book"
		};
		class GUIInventoryAttachmentsProps
		{
			class Kindling
			{
				attachmentSlots[] +=
				{
					"Book"
				};
			};
		}
	}
	class OvenIndoor : FireplaceBase
	{
		attachments[] +=
		{
			"Book"
		};
		class GUIInventoryAttachmentsProps
		{
			class Kindling
			{
				attachmentSlots[] +=
				{
					"Book"
				};
			};
		}
	}
	class Barrel_ColorBase : Container_Base
	{
		physLayer = "item_large";
	};
	class BarrelHoles_ColorBase : FireplaceBase
	{
		physLayer = "item_large";
		attachments[] +=
		{
			"Book"
		};
		class GUIInventoryAttachmentsProps
		{
			class Kindling
			{
				attachmentSlots[] +=
				{
					"Book"
				};
			};
		}
	}

	class Zen_BarrelHoles_Red : Barrel_ColorBase
	{

		displayName = "Community Barrel";
		descriptionShort = "This barrel is so worn out that if I try to move it I think it will fall apart. Better leave it where it is.";
		scope = 2;
		hiddenSelectionsTextures[] =
		{
			"\ZenModShared\data\textures\barrel_community_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 999999;
				}
			}
		};
	};

	// Change stone description
	class SmallStone : Inventory_Base
	{
		scope = 2;
		descriptionShort = "A smooth fragment of rock. If I find another one of these I can use this on it to create a primitive stone knife.";
		varTemperatureMax = 75;
		varTemperatureMin = 5;
		varTemperatureModifier = 0.1;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 250;
					healthLevels[] =
					{

						{
							1,

							{
								"DZ\gear\consumables\data\stone.rvmat"
							}
						},

						{
							0.69999999,

							{
								"DZ\gear\consumables\data\stone.rvmat"
							}
						},

						{
							0.5,

							{
								"DZ\gear\consumables\data\stone_damage.rvmat"
							}
						},

						{
							0.30000001,

							{
								"DZ\gear\consumables\data\stone_damage.rvmat"
							}
						},

						{
							0,

							{
								"DZ\gear\consumables\data\stone_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};

	// Make binoculars smaller
	class ItemOptics;
	class Binoculars : ItemOptics
	{
		scope = 2;
		itemSize[] = { 2,2 };
	}

	// Add field shovel
	class FieldShovel : Inventory_Base
	{
		scope = 2;
		displayName = "Field Shovel";
		descriptionShort = "An entrenching tool. This collapsible spade is used by military forces for a variety of purposes. Survivalists, freedivers, campers, hikers and other adventurers have found it to be indispensable in field use.";
		weight = 4200;
		itemBehaviour = 2;
	}

	// Reduce water bottle to Aussie standard size
	class WaterBottle : Bottle_Base
	{
		scope = 2;
		varQuantityInit = 600;
		varQuantityMin = 0;
		varQuantityMax = 600;
	};

	// Cooking pot durability
	class Pot : Bottle_Base
	{
		scope = 2;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 500;
				}
			}
		}
	};

	// Enable Paint Spray Can
	class Spraycan_ColorBase;
	class Spraycan_Black : Spraycan_ColorBase
	{
		itemSize[] = { 1,3 };
		displayName = "Black Spraypaint";
		descriptionShort = "A black semi-gloss aerosol paint. It can be used to paint guns and their parts, just make sure there are no attachments or they might get ruined.";
	};
	class Spraycan_Green : Spraycan_ColorBase
	{
		itemSize[] = { 1,3 };
		displayName = "Green Spraypaint";
		descriptionShort = "A green semi-gloss aerosol paint. It can be used to paint guns and their parts, just make sure there are no attachments or they might get ruined.";
	};

	// Chlorine tablet attachment to canteen
	class PurificationTablets : Edible_Base
	{
		scope = 2;
		inventorySlot[] = { "Material_Chlorine" };
	}

	class Handcuffs: Inventory_Base
	{
		inventorySlot[] = { "Handcuffs" };
	}
	class HandcuffKeys: Inventory_Base
	{
		inventorySlot[] = { "HandcuffKeys" };
	}

	// Weed
	class Cannabis : Edible_Base
	{
		scope = 2;
		displayName = "Cannabis";
		descriptionShort = "Some call it tamjee, some call it weed. Some call it marijuana, some a dem call it ganja. Never mind, got to legalize it. And don't criticize it. Legalize it, yeah. And I will advertise it. - Peter Tosh";
		inventorySlot[] = {};
		varQuantityInit=1;
		varQuantityMin=0;
		varQuantityMax=1;
	};
	class SeedBase;
	class CannabisSeeds : SeedBase
	{
		scope = 2;
		displayName = "Cannabis Seeds";
		descriptionShort = "Some call it tamjee, some call it weed. Some call it marijuana, some a dem call it ganja. Never mind, got to legalize it. And don't criticize it. Legalize it, yeah. And I will advertise it. - Peter Tosh";
	};
	class CannabisSeedsPack : Inventory_Base
	{
		scope = 2;
		displayName = "Cannabis Seeds";
		descriptionShort = "Some call it tamjee, some call it weed. Some call it marijuana, some a dem call it ganja. Never mind, got to legalize it. And don't criticize it. Legalize it, yeah. And I will advertise it. - Peter Tosh";
	};
	class PlantBase;
	class Plant_Cannabis : PlantBase
	{
		scope = 2;
		displayName = "Cannabis";
		descriptionShort = "Some call it tamjee, some call it weed. Some call it marijuana, some a dem call it ganja. Never mind, got to legalize it. And don't criticize it. Legalize it, yeah. And I will advertise it. - Peter Tosh";
		class Horticulture
		{
			GrowthStagesCount = 6;
			CropsCount = 2;
			CropsType = "Cannabis";
		};
	};

	// Custom shirts
	class Shirt_ColorBase;
	class Zen_Shirt_HunterCat : Shirt_ColorBase
	{
		scope = 2;
		heatIsolation = 0.8;
		displayName = "Hunter Shirt";
		descriptionShort = "A shirt with the infamous Hunter cat on it. If you find the other cat shirt and combine it, you can be the most fashionable survivor in the apocalypse!";
		hiddenSelectionsTextures[] =
		{
			"\ZenModShared\data\textures\clothing\tops\tshirt_black_huntercat_co.paa",
			"\ZenModShared\data\textures\clothing\tops\tshirt_black_huntercat_co.paa",
			"\ZenModShared\data\textures\clothing\tops\tshirt_black_huntercat_co.paa"
		};
	};
	class Zen_Shirt_PharaohCat : Shirt_ColorBase
	{
		scope = 2;
		heatIsolation = 0.8;
		displayName = "Pharaoh Shirt";
		descriptionShort = "A shirt with the infamous Pharaoh cat on it. If you find the other cat shirt and combine it, you can be the most fashionable survivor in the apocalypse!";
		hiddenSelectionsTextures[] =
		{
			"\ZenModShared\data\textures\clothing\tops\tshirt_black_pharaohcat_co.paa",
			"\ZenModShared\data\textures\clothing\tops\tshirt_black_pharaohcat_co.paa",
			"\ZenModShared\data\textures\clothing\tops\tshirt_black_pharaohcat_co.paa"
		};
	};
	class Zen_Shirt_BothCat : Shirt_ColorBase
	{
		scope = 2;
		itemsCargoSize[] = { 7,6 };
		quickBarBonus = 2;
		heatIsolation = 1.0;
		displayName = "Kitty Best Friends Shirt";
		descriptionShort = "A shirt with the two infamous Hunter & Pharaoh cats on it. Congratulations, you are the most fashionable survivor in the apocalypse!";
		hiddenSelectionsTextures[] =
		{
			"\ZenModShared\data\textures\clothing\tops\tshirt_black_bothcat_co.paa",
			"\ZenModShared\data\textures\clothing\tops\tshirt_black_bothcat_co.paa",
			"\ZenModShared\data\textures\clothing\tops\tshirt_black_bothcat_co.paa"
		};
	};

	// Make fishing rods repairable
	class FishingRod_Base_New;
	class FishingRod : FishingRod_Base_New
	{
		repairableWithKits[] = { 5,8 };
		repairCosts[] = { 25,25 };
	}

	// Remove fat from human skinning
	class Man;
	class SurvivorBase : Man
	{
		class Skinning
		{
			class Steaks
			{
				item = "HumanSteakMeat";
				count = 6;
				quantityMinMaxCoef[] = { 0.5,1 };
			};
			class Guts
			{
				item = "Guts";
				count = 1;
				quantityMinMaxCoef[] = { 0.1,0.50000001 };
			};
			class Lard
			{
				item = "HumanLard";
				count = 1;
				quantityMinMaxCoef[] = { 0.5,1 };
			};
			class Bones
			{
				item = "HumanBone";
				count = 1; // Reduce bones (to stop players farming themselves)
				quantityMinMaxCoef[] = { 0.1,0.2 };
			};
		};
	}

	// Trader flag
	class TerritoryFlag;
	class TraderFlag : TerritoryFlag
	{
		scope = 2;
	};
	// Trader flag
	class Flag_Base;
	class TradingFlag : Flag_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] =
		{
			"\ZenModShared\data\textures\flag_trader_co.paa"
		};
        color = "Trader";
	};
	class Armband_ColorBase : Clothing
	{
		isFaction=0; // Turn off faction checks for vanilla
	};
	class Armband_DoubleColorBase;
	class Armband_Trader: Armband_ColorBase
	{
        scope = 2;
        visibilityModifier = 0.94999999;
        hiddenSelectionsTextures[] =
        {
            "\ZenModShared\data\textures\flag_trader_co.paa",
            "\ZenModShared\data\textures\flag_trader_co.paa",
            "\ZenModShared\data\textures\flag_trader_co.paa",
            "\ZenModShared\data\textures\flag_trader_co.paa",
            "\ZenModShared\data\textures\flag_trader_co.paa",
            "\ZenModShared\data\textures\flag_trader_co.paa",
            "\ZenModShared\data\textures\flag_trader_co.paa",
            "\ZenModShared\data\textures\flag_trader_co.paa",
            "\ZenModShared\data\textures\flag_trader_co.paa"
        };
	};
	class Armband_DoubleTrader: Armband_DoubleColorBase 
	{
		scope = 2;
        visibilityModifier = 0.94999999;
        hiddenSelectionsTextures[] =
        {
            "\ZenModShared\data\textures\flag_trader_co.paa",
            "\ZenModShared\data\textures\flag_trader_co.paa",
            "\ZenModShared\data\textures\flag_trader_co.paa",
            "\ZenModShared\data\textures\flag_trader_co.paa",
            "\ZenModShared\data\textures\flag_trader_co.paa",
            "\ZenModShared\data\textures\flag_trader_co.paa",
            "\ZenModShared\data\textures\flag_trader_co.paa",
            "\ZenModShared\data\textures\flag_trader_co.paa",
            "\ZenModShared\data\textures\flag_trader_co.paa"
        };
	};
	// Aboriginal flag
	class Flag_Aboriginal : Flag_Base
	{
		scope = 2;
		hiddenSelectionsTextures[] =
		{
			"\ZenModShared\data\textures\flag_aboriginal_co.paa"
		};
        color = "Aboriginal";
	};
	class Armband_Aboriginal: Armband_ColorBase
	{
        scope = 2;
        visibilityModifier = 0.94999999;
        hiddenSelectionsTextures[] =
        {
            "\ZenModShared\data\textures\flag_aboriginal_co.paa",
            "\ZenModShared\data\textures\flag_aboriginal_co.paa",
            "\ZenModShared\data\textures\flag_aboriginal_co.paa",
            "\ZenModShared\data\textures\flag_aboriginal_co.paa",
            "\ZenModShared\data\textures\flag_aboriginal_co.paa",
            "\ZenModShared\data\textures\flag_aboriginal_co.paa",
            "\ZenModShared\data\textures\flag_aboriginal_co.paa",
            "\ZenModShared\data\textures\flag_aboriginal_co.paa",
            "\ZenModShared\data\textures\flag_aboriginal_co.paa"
        };
	};
	class Armband_DoubleAboriginal: Armband_DoubleColorBase
	{
        scope = 2;
        visibilityModifier = 0.94999999;
        hiddenSelectionsTextures[] =
        {
            "\ZenModShared\data\textures\flag_aboriginal_co.paa",
            "\ZenModShared\data\textures\flag_aboriginal_co.paa",
            "\ZenModShared\data\textures\flag_aboriginal_co.paa",
            "\ZenModShared\data\textures\flag_aboriginal_co.paa",
            "\ZenModShared\data\textures\flag_aboriginal_co.paa",
            "\ZenModShared\data\textures\flag_aboriginal_co.paa",
            "\ZenModShared\data\textures\flag_aboriginal_co.paa",
            "\ZenModShared\data\textures\flag_aboriginal_co.paa",
            "\ZenModShared\data\textures\flag_aboriginal_co.paa"
        };
	};

	class Wellies_ColorBase : Clothing
	{
		repairableWithKits[] = { 5,6 };
		repairCosts[] = { 30,30 };
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 250;
				};
			};
		};
	}
	class MilitaryBelt : Clothing
	{
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 250;
					healthLevels[] =
					{

						{
							1,

							{
								"DZ\characters\belts\data\mil_belt.rvmat"
							}
						},

						{
							0.69999999,

							{
								"DZ\characters\belts\data\mil_belt.rvmat"
							}
						},

						{
							0.5,

							{
								"DZ\characters\belts\data\mil_belt_damage.rvmat"
							}
						},

						{
							0.30000001,

							{
								"DZ\characters\belts\data\mil_belt_damage.rvmat"
							}
						},

						{
							0,

							{
								"DZ\characters\belts\data\mil_belt_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
	class RopeBelt : Clothing
	{
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] =
					{

						{
							1,

							{
								"DZ\characters\belts\data\Rope_Belt.rvmat"
							}
						},

						{
							0.69999999,

							{
								"DZ\characters\belts\data\Rope_Belt.rvmat"
							}
						},

						{
							0.5,

							{
								"DZ\characters\belts\data\Rope_Belt_damage.rvmat"
							}
						},

						{
							0.30000001,

							{
								"DZ\characters\belts\data\Rope_Belt_damage.rvmat"
							}
						},

						{
							0,

							{
								"DZ\characters\belts\data\Rope_Belt_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};

	class TireRepairKit : Inventory_Base
	{
		scope = 2;
		descriptionShort = "Can be used to repair vehicle tires, as well as any rubber item such as wellies or NBC gear.";
	}

	class Bone;
	class HumanBone : Bone
	{
		scope = 2;
		displayName = "Human Bones";
		descriptionShort = "It's a pile of bones, and they look like they're from a human...";
	}
	class Lard;
	class HumanLard : Lard
	{
		scope = 2;
		displayName = "Human Fat";
		descriptionShort = "It's human fat... I'd better not eat this, I hear it gives you kuru.";
	}

	// Custom Plate Pouches
	class Zen_PlateCarrierPouches_Desert_Camo : PlateCarrierPouches
	{
		scope = 2;
		hiddenSelections[] =
		{
			"zbytek"
		};
		hiddenSelectionsTextures[] =
		{
			"\ZenModShared\data\textures\clothing\vests\platecarriervest_desert_camo.paa"
		};
	};
	class Zen_PlateCarrierPouches_Wood_Camo : PlateCarrierPouches
	{
		scope = 2;
		hiddenSelections[] =
		{
			"zbytek"
		};
		hiddenSelectionsTextures[] =
		{
			"\ZenModShared\data\textures\clothing\vests\platecarriervest_wood_camo.paa"
		};
	};
	class Zen_PlateCarrierPouches_Black_Camo : PlateCarrierPouches
	{
		scope = 2;
		hiddenSelections[] =
		{
			"zbytek"
		};
		hiddenSelectionsTextures[] =
		{
			"\ZenModShared\data\textures\clothing\vests\platecarriervest_black_camo.paa"
		};
	};

	// Custom stab vests
	class PoliceVest;
	class Zen_PoliceVest_Orel : PoliceVest
	{
		scope = 2;
		hiddenSelectionsTextures[] =
		{
			"\ZenModShared\data\textures\clothing\vests\policevest_orel_co.paa",
			"\ZenModShared\data\textures\clothing\vests\policevest_orel_co.paa",
			"\ZenModShared\data\textures\clothing\vests\policevest_orel_co.paa"
		};
	};

	// Custom backpacks
	class HuntingBag;
	class Zen_HuntingBag_Brown : HuntingBag
	{
		scope = 2;
		visibilityModifier = 0.24999999;
		hiddenSelectionsTextures[] =
		{
			"\ZenModShared\data\textures\clothing\backpacks\hunting_brown_co.paa",
			"\ZenModShared\data\textures\clothing\backpacks\hunting_brown_co.paa",
			"\ZenModShared\data\textures\clothing\backpacks\hunting_brown_co.paa"
		};
	}
	class Zen_HuntingBag_Blue : HuntingBag
	{
		scope = 2;
		hiddenSelectionsTextures[] =
		{
			"\ZenModShared\data\textures\clothing\backpacks\hunting_blue_co.paa",
			"\ZenModShared\data\textures\clothing\backpacks\hunting_blue_co.paa",
			"\ZenModShared\data\textures\clothing\backpacks\hunting_blue_co.paa"
		};
	}
	class Zen_HuntingBag_Teal : HuntingBag
	{
		scope = 2;
		hiddenSelectionsTextures[] =
		{
			"\ZenModShared\data\textures\clothing\backpacks\hunting_teal_co.paa",
			"\ZenModShared\data\textures\clothing\backpacks\hunting_teal_co.paa",
			"\ZenModShared\data\textures\clothing\backpacks\hunting_teal_co.paa"
		};
	}
	class Zen_HuntingBag_Camo : HuntingBag
	{
		scope = 2;
		hiddenSelectionsTextures[] =
		{
			"\ZenModShared\data\textures\clothing\backpacks\hunting_camo_co.paa",
			"\ZenModShared\data\textures\clothing\backpacks\hunting_camo_co.paa",
			"\ZenModShared\data\textures\clothing\backpacks\hunting_camo_co.paa"
		};
	}

	// Hats
	class Zen_BaseballCap_Camo : BaseballCap_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.54999999;
		hiddenSelectionsTextures[] =
		{
			"\ZenModShared\data\textures\clothing\hats\baseballcap_camo_co.paa",
			"\ZenModShared\data\textures\clothing\hats\baseballcap_camo_co.paa",
			"\ZenModShared\data\textures\clothing\hats\baseballcap_camo_co.paa"
		};
	};
	class Zen_BaseballCap_BackCamo : BaseballCap_BackColorBase
	{
		scope = 2;
		visibilityModifier = 0.54999999;
		hiddenSelectionsTextures[] =
		{
			"\ZenModShared\data\textures\clothing\hats\baseballcap_camo_co.paa",
			"\ZenModShared\data\textures\clothing\hats\baseballcap_camo_co.paa",
			"\ZenModShared\data\textures\clothing\hats\baseballcap_camo_co.paa"
		};
	};
	class Zen_BaseballCap_DarkCamo : BaseballCap_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.54999999;
		hiddenSelectionsTextures[] =
		{
			"\ZenModShared\data\textures\clothing\hats\baseballcap_darkcamo_co.paa",
			"\ZenModShared\data\textures\clothing\hats\baseballcap_darkcamo_co.paa",
			"\ZenModShared\data\textures\clothing\hats\baseballcap_darkcamo_co.paa"
		};
	};
	class Zen_BaseballCap_BackDarkCamo : BaseballCap_BackColorBase
	{
		scope = 2;
		visibilityModifier = 0.54999999;
		hiddenSelectionsTextures[] =
		{
			"\ZenModShared\data\textures\clothing\hats\baseballcap_darkcamo_co.paa",
			"\ZenModShared\data\textures\clothing\hats\baseballcap_darkcamo_co.paa",
			"\ZenModShared\data\textures\clothing\hats\baseballcap_darkcamo_co.paa"
		};
	};
	class Zen_BaseballCap_Zenarchist : BaseballCap_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.04999999;
		descriptionShort = "Zenarchist's cap. One of a kind, extremely rare.";
		hiddenSelectionsTextures[] =
		{
			"\ZenModShared\data\textures\clothing\hats\baseballcap_blackzen_co.paa",
			"\ZenModShared\data\textures\clothing\hats\baseballcap_blackzen_co.paa",
			"\ZenModShared\data\textures\clothing\hats\baseballcap_blackzen_co.paa"
		};
	};
	class Zen_BaseballCap_BackZenarchist : BaseballCap_BackColorBase
	{
		scope = 2;
		visibilityModifier = 0.04999999;
		descriptionShort = "Zenarchist's cap. One of a kind, extremely rare.";
		hiddenSelectionsTextures[] =
		{
			"\ZenModShared\data\textures\clothing\hats\baseballcap_blackzen_co.paa",
			"\ZenModShared\data\textures\clothing\hats\baseballcap_blackzen_co.paa",
			"\ZenModShared\data\textures\clothing\hats\baseballcap_blackzen_co.paa"
		};
	};

	// Winter camo net ghillie (color bases from ZenModPack)
	class Zen_GhillieSuit_ColorBase;
	class Zen_WinterCamoNet_GhillieSuit : Zen_GhillieSuit_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.5;
		hiddenSelectionsTextures[] =
		{
			"\ZenModShared\data\textures\clothing\ghillie\winter_camo_ghillie\winter_ghillie_net_co.paa",
			"\ZenModShared\data\textures\clothing\ghillie\winter_camo_ghillie\winter_ghillie_net_co.paa",
			"\ZenModShared\data\textures\clothing\ghillie\winter_camo_ghillie\winter_ghillie_net_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 300;
					healthLevels[] =
					{

						{
							1.0,

							{
								"\ZenModShared\data\textures\clothing\ghillie\winter_camo_ghillie\winter_winter_ghillie_net_co.paa"
							}
						},

						{
							0.69999999,

							{
								"\ZenModShared\data\textures\clothing\ghillie\winter_camo_ghillie\winter_winter_ghillie_net_co.paa"
							}
						},

						{
							0.5,

							{
								"\ZenModShared\data\textures\clothing\ghillie\winter_camo_ghillie\winter_winter_ghillie_net_co.paa"
							}
						},

						{
							0.30000001,

							{
								"\ZenModShared\data\textures\clothing\ghillie\winter_camo_ghillie\winter_winter_ghillie_net_co.paa"
							}
						},

						{
							0.0099999998,

							{
								"\ZenModShared\data\textures\clothing\ghillie\winter_camo_ghillie\winter_winter_ghillie_net_co.paa"
							}
						}
					};
				};
			};
		};
	};
	class Zen_GhillieHood_ColorBase;
	class Zen_WinterCamoNet_GhillieHood : Zen_GhillieHood_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.69999999;
		hiddenSelectionsTextures[] =
		{
			"\ZenModShared\data\textures\clothing\ghillie\winter_camo_ghillie\winter_ghillie_net_co.paa",
			"\ZenModShared\data\textures\clothing\ghillie\winter_camo_ghillie\winter_ghillie_net_co.paa",
			"\ZenModShared\data\textures\clothing\ghillie\winter_camo_ghillie\winter_ghillie_net_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] =
					{

						{
							1.0,

							{
								"\ZenModShared\data\textures\clothing\ghillie\winter_camo_ghillie\winter_ghillie_net_co.paa"
							}
						},

						{
							0.69999999,

							{
								"\ZenModShared\data\textures\clothing\ghillie\winter_camo_ghillie\winter_ghillie_net_co.paa"
							}
						},

						{
							0.5,

							{
								"\ZenModShared\data\textures\clothing\ghillie\winter_camo_ghillie\winter_ghillie_net_co.paa"
							}
						},

						{
							0.30000001,

							{
								"\ZenModShared\data\textures\clothing\ghillie\winter_camo_ghillie\winter_ghillie_net_co.paa"
							}
						},

						{
							0.0099999998,

							{
								"\ZenModShared\data\textures\clothing\ghillie\winter_camo_ghillie\winter_ghillie_net_co.paa"
							}
						}
					};
				};
			};
		};
	};
	class Zen_GhillieTop_ColorBase;
	class Zen_WinterCamoNet_GhillieTop : Zen_GhillieTop_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.60000002;
		hiddenSelectionsTextures[] =
		{
			"\ZenModShared\data\textures\clothing\ghillie\winter_camo_ghillie\winter_ghillie_net_co.paa",
			"\ZenModShared\data\textures\clothing\ghillie\winter_camo_ghillie\winter_ghillie_net_co.paa",
			"\ZenModShared\data\textures\clothing\ghillie\winter_camo_ghillie\winter_ghillie_net_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] =
					{

						{
							1.0,

							{
								"\ZenModShared\data\textures\clothing\ghillie\winter_camo_ghillie\winter_ghillie_net_co.paa"
							}
						},

						{
							0.69999999,

							{
								"\ZenModShared\data\textures\clothing\ghillie\winter_camo_ghillie\winter_ghillie_net_co.paa"
							}
						},

						{
							0.5,

							{
								"\ZenModShared\data\textures\clothing\ghillie\winter_camo_ghillie\winter_ghillie_net_co.paa"
							}
						},

						{
							0.30000001,

							{
								"\ZenModShared\data\textures\clothing\ghillie\winter_camo_ghillie\winter_ghillie_net_co.paa"
							}
						},

						{
							0.0099999998,

							{
								"\ZenModShared\data\textures\clothing\ghillie\winter_camo_ghillie\winter_ghillie_net_co.paa"
							}
						}
					};
				};
			};
		};
	};
	class Zen_GhillieBushrag_ColorBase;
	class Zen_WinterCamoNet_GhillieBushrag : Zen_GhillieBushrag_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.69999999;
		hiddenSelectionsTextures[] =
		{
			"\ZenModShared\data\textures\clothing\ghillie\winter_camo_ghillie\winter_ghillie_net_co.paa",
			"\ZenModShared\data\textures\clothing\ghillie\winter_camo_ghillie\winter_ghillie_net_co.paa",
			"\ZenModShared\data\textures\clothing\ghillie\winter_camo_ghillie\winter_ghillie_net_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] =
					{

						{
							1.0,

							{
								"\ZenModShared\data\textures\clothing\ghillie\winter_camo_ghillie\winter_ghillie_net_co.paa"
							}
						},

						{
							0.69999999,

							{
								"\ZenModShared\data\textures\clothing\ghillie\winter_camo_ghillie\winter_ghillie_net_co.paa"
							}
						},

						{
							0.5,

							{
								"\ZenModShared\data\textures\clothing\ghillie\winter_camo_ghillie\winter_ghillie_net_co.paa"
							}
						},

						{
							0.30000001,

							{
								"\ZenModShared\data\textures\clothing\ghillie\winter_camo_ghillie\winter_ghillie_net_co.paa"
							}
						},

						{
							0.0099999998,

							{
								"\ZenModShared\data\textures\clothing\ghillie\winter_camo_ghillie\winter_ghillie_net_co.paa"
							}
						}
					};
				};
			};
		};
	};
	class GhillieAtt_ColorBase;
	class Zen_WinterCamoNet_GhillieAtt : GhillieAtt_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] =
		{
			"\ZenModShared\data\textures\clothing\ghillie\winter_camo_ghillie\winter_ghillie_net_co.paa",
			"\ZenModShared\data\textures\clothing\ghillie\winter_camo_ghillie\winter_ghillie_net_co.paa",
			"\ZenModShared\data\textures\clothing\ghillie\winter_camo_ghillie\winter_ghillie_net_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] =
					{

						{
							1.0,

							{
								"\ZenModShared\data\textures\clothing\ghillie\winter_camo_ghillie\winter_ghillie_net_co.paa"
							}
						},

						{
							0.69999999,

							{
								"\ZenModShared\data\textures\clothing\ghillie\winter_camo_ghillie\winter_ghillie_net_co.paa"
							}
						},

						{
							0.5,

							{
								"\ZenModShared\data\textures\clothing\ghillie\winter_camo_ghillie\winter_ghillie_net_co.paa"
							}
						},

						{
							0.30000001,

							{
								"\ZenModShared\data\textures\clothing\ghillie\winter_camo_ghillie\winter_ghillie_net_co.paa"
							}
						},

						{
							0.0099999998,

							{
								"\ZenModShared\data\textures\clothing\ghillie\winter_camo_ghillie\winter_ghillie_net_co.paa"
							}
						}
					};
				};
			};
		};
	};
	class Zen_WinterCamoNet_Strip : Inventory_Base
	{
		scope = 2;
		displayName = "Strip of Camo Netting";
		descriptionShort = "A short strip crafted from a camo net. If I combine it with some Netting I can make a ghillie out of this...";
		model = "\DZ\gear\crafting\sackcloth_rag.p3d";
		hiddenSelections[] =
		{
			"zbytek"
		};
		hiddenSelectionsTextures[] =
		{
			"\ZenModShared\data\textures\clothing\ghillie\winter_camo_ghillie\winter_strip_co.paa"
		};
		weight = 50;
		itemSize[] = { 1,3 };
		canBeSplit = 1;
		varQuantityInit = 1;
		varQuantityMin = 0;
		varQuantityMax = 10;
		rotationFlags = 17;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] =
					{

						{
							1,

							{
								"DZ\gear\consumables\data\weaponcamo.rvmat"
							}
						},

						{
							0.69999999,

							{
								"DZ\gear\consumables\data\weaponcamo.rvmat"
							}
						},

						{
							0.5,

							{
								"DZ\gear\consumables\data\weaponcamo_damage.rvmat"
							}
						},

						{
							0.30000001,

							{
								"DZ\gear\consumables\data\weaponcamo_damage.rvmat"
							}
						},

						{
							0,

							{
								"DZ\gear\consumables\data\weaponcamo_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};

	// Helmets
	class Zen_Mich2001Helmet_Black : Mich2001Helmet
	{
		scope = 2;
		visibilityModifier = 0.54999999;
		hiddenSelectionsTextures[] =
		{
			"\ZenModShared\data\textures\clothing\helmets\mich2001_black_co.paa",
			"\ZenModShared\data\textures\clothing\helmets\mich2001_black_co.paa",
			"\ZenModShared\data\textures\clothing\helmets\mich2001_black_co.paa"
		};
	};
	class Zen_Mich2001Helmet_Camo : Mich2001Helmet
	{
		scope = 2;
		visibilityModifier = 0.54999999;
		hiddenSelectionsTextures[] =
		{
			"\ZenModShared\data\textures\clothing\helmets\mich2001_camo_co.paa",
			"\ZenModShared\data\textures\clothing\helmets\mich2001_camo_co.paa",
			"\ZenModShared\data\textures\clothing\helmets\mich2001_camo_co.paa"
		};
	};
	class Zen_Mich2001Helmet_DarkCamo : Mich2001Helmet
	{
		scope = 2;
		visibilityModifier = 0.54999999;
		hiddenSelectionsTextures[] =
		{
			"\ZenModShared\data\textures\clothing\helmets\mich2001_darkcamo_co.paa",
			"\ZenModShared\data\textures\clothing\helmets\mich2001_darkcamo_co.paa",
			"\ZenModShared\data\textures\clothing\helmets\mich2001_darkcamo_co.paa"
		};
	};
	class Zen_Mich2001Helmet_Zenarchist : Mich2001Helmet
	{
		scope = 2;
		visibilityModifier = 0.54999999;
		hiddenSelectionsTextures[] =
		{
			"\ZenModShared\data\textures\clothing\helmets\mich2001_zenarchist_co.paa",
			"\ZenModShared\data\textures\clothing\helmets\mich2001_zenarchist_co.paa",
			"\ZenModShared\data\textures\clothing\helmets\mich2001_zenarchist_co.paa"
		};
	};

	// Tops
	class TacticalShirt_ColorBase;
	class Zen_TacticalShirt_Zenarchist : TacticalShirt_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.19999999;
		hiddenSelectionsTextures[] =
		{
			"\ZenModShared\data\textures\clothing\tops\pcu5jacket_blackzen_co.paa",
			"\ZenModShared\data\textures\clothing\tops\pcu5jacket_blackzen_co.paa",
			"\ZenModShared\data\textures\clothing\tops\pcu5jacket_blackzen_co.paa"
		};
	};
	class Zen_TacticalShirt_Black_Australia : TacticalShirt_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] =
		{
			"\ZenModShared\data\textures\clothing\tops\pcu5jacket_black_aus_co",
			"\ZenModShared\data\textures\clothing\tops\pcu5jacket_black_aus_co",
			"\ZenModShared\data\textures\clothing\tops\pcu5jacket_black_aus_co"
		};
	};
	class Zen_TacticalShirt_Olive_Australia : TacticalShirt_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] =
		{
			"\ZenModShared\data\textures\clothing\tops\pcu5jacket_olive_aus_co",
			"\ZenModShared\data\textures\clothing\tops\pcu5jacket_olive_aus_co",
			"\ZenModShared\data\textures\clothing\tops\pcu5jacket_olive_aus_co"
		};
	};
	class Zen_TacticalShirt_Tan_Australia : TacticalShirt_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] =
		{
			"\ZenModShared\data\textures\clothing\tops\pcu5jacket_tan_aus_co",
			"\ZenModShared\data\textures\clothing\tops\pcu5jacket_tan_aus_co",
			"\ZenModShared\data\textures\clothing\tops\pcu5jacket_tan_aus_co",
		};
	};

	// Custom Plate Holsters
	class Zen_PlateCarrierHolster_Desert_Camo : PlateCarrierHolster
	{
		scope = 2;
		hiddenSelections[] =
		{
			"zbytek"
		};
		hiddenSelectionsTextures[] =
		{
			"\ZenModShared\data\textures\clothing\vests\platecarriervest_desert_camo.paa"
		};
	};
	class Zen_PlateCarrierHolster_Wood_Camo : PlateCarrierHolster
	{
		scope = 2;
		hiddenSelections[] =
		{
			"zbytek"
		};
		hiddenSelectionsTextures[] =
		{
			"\ZenModShared\data\textures\clothing\vests\platecarriervest_wood_camo.paa"
		};
	};
	class Zen_PlateCarrierHolster_Black_Camo : PlateCarrierHolster
	{
		scope = 2;
		hiddenSelections[] =
		{
			"zbytek"
		};
		hiddenSelectionsTextures[] =
		{
			"\ZenModShared\data\textures\clothing\vests\platecarriervest_black_camo.paa"
		};
	};

	// Custom vests
	class PressVest_ColorBase;
	class Zen_PressVest_Green_Camo : PressVest_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.29999999;
		hiddenSelectionsTextures[] =
		{
			"\ZenModShared\data\textures\clothing\vests\pressvest_green_camo_co.paa",
			"\ZenModShared\data\textures\clothing\vests\pressvest_green_camo_co.paa",
			"\ZenModShared\data\textures\clothing\vests\pressvest_green_camo_co.paa"
		};
	};
	class Zen_PressVest_Black_Camo : PressVest_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.19999999;
		hiddenSelectionsTextures[] =
		{
			"\ZenModShared\data\textures\clothing\vests\pressvest_black_camo_co.paa",
			"\ZenModShared\data\textures\clothing\vests\pressvest_black_camo_co.paa",
			"\ZenModShared\data\textures\clothing\vests\pressvest_black_camo_co.paa"
		};
	};

	// Custom plate carriers
	class Zen_PlateCarrierVest_Police : PlateCarrierVest
	{
		scope = 2;
		descriptionShort = "Hard-plate reinforced bulletproof vest, able to absorb various types of impact damage. Worn by police officers responding to dangerous situations.";
		attachments[]=
		{
			"Handcuffs",
			"HandcuffKeys"
		};
		hiddenSelections[] =
		{
			"camoGround",
			"camoMale",
			"camoFemale"
		};
		hiddenSelectionsTextures[] =
		{
			"\ZenModShared\data\textures\clothing\vests\ballisticvest_police_co.paa",
			"\ZenModShared\data\textures\clothing\vests\ballisticvest_police_co.paa",
			"\ZenModShared\data\textures\clothing\vests\ballisticvest_police_co.paa"
		};
	};
	class Zen_PlateCarrierVest_Desert_Camo : PlateCarrierVest
	{
		scope = 2;
		hiddenSelections[] =
		{
			"camoGround",
			"camoMale",
			"camoFemale"
		};
		hiddenSelectionsTextures[] =
		{
			"\ZenModShared\data\textures\clothing\vests\platecarriervest_desert_camo.paa",
			"\ZenModShared\data\textures\clothing\vests\platecarriervest_desert_camo.paa",
			"\ZenModShared\data\textures\clothing\vests\platecarriervest_desert_camo.paa"
		};
	};
	class Zen_PlateCarrierVest_Wood_Camo : PlateCarrierVest
	{
		scope = 2;
		hiddenSelections[] =
		{
			"camoGround",
			"camoMale",
			"camoFemale"
		};
		hiddenSelectionsTextures[] =
		{
			"\ZenModShared\data\textures\clothing\vests\platecarriervest_wood_camo.paa",
			"\ZenModShared\data\textures\clothing\vests\platecarriervest_wood_camo.paa",
			"\ZenModShared\data\textures\clothing\vests\platecarriervest_wood_camo.paa"
		};
	};
	class Zen_PlateCarrierVest_Black_Camo : PlateCarrierVest
	{
		scope = 2;
		hiddenSelections[] =
		{
			"camoGround",
			"camoMale",
			"camoFemale"
		};
		hiddenSelectionsTextures[] =
		{
			"\ZenModShared\data\textures\clothing\vests\platecarriervest_black_camo.paa",
			"\ZenModShared\data\textures\clothing\vests\platecarriervest_black_camo.paa",
			"\ZenModShared\data\textures\clothing\vests\platecarriervest_black_camo.paa"
		};
	};

	// Custom shoes 
	class MilitaryBoots_BlackPunk: MilitaryBoots_ColorBase
	{
		scope=2;
		visibilityModifier=0.69999999;
		hiddenSelectionsTextures[]=
		{
			"\ZenModShared\data\textures\clothing\shoes\MilitaryBoots_blackpunk_co.paa",
			"\ZenModShared\data\textures\clothing\shoes\MilitaryBoots_blackpunk_co.paa",
			"\ZenModShared\data\textures\clothing\shoes\MilitaryBoots_blackpunk_co.paa"
		};
	};

	// Convert Hummer to manual
	class CarScript;
	class Offroad_02 : CarScript
	{
		scope = 2;
		class SimulationModule
		{
			class Gearbox
			{
				type = "GEARBOX_MANUAL";
				reverse = 2.0799999;
				ratios[] = { 2.48,1.48,1,0.75 };
			};
		}
	};

	// Trader flag kit
	class TerritoryFlagKit;
	class TraderFlagKit : TerritoryFlagKit
	{
		scope = 2;
		displayName = "TRADER FLAG KIT";
	};
	class TraderFlagKitPlacing : TraderFlagKit
	{
		scope = 1;
		displayName = "This is a hologram";
		descriptionShort = "Nothing to see here, move along";
		model = "\DZ\gear\camping\territory_flag_kit_placing.p3d";
		storageCategory = 10;
		hiddenSelections[] =
		{
			"placing"
		};
		hiddenSelectionsTextures[] =
		{
			"dz\gear\consumables\data\pile_of_planks_co.tga"
		};
		hiddenSelectionsMaterials[] =
		{
			"dz\gear\camping\data\fence_pile_of_planks.rvmat"
		};
		hologramMaterial = "tent_medium";
		hologramMaterialPath = "dz\gear\camping\data";
		alignHologramToTerain = 0;
		slopeTolerance = 0.30000001;
	};

	//! FACTION GEAR

	// Test admin faction
	class Flag_AdminTest: Flag_Base
	{
		scope=2;
		isFaction=1;
		hiddenSelectionsTextures[]=
		{
			"\ZenModShared\data\factions\AdminTest\Flag_AdminTest.paa"
		};
		color="AdminTest";
	};
	class Armband_AdminTest: Armband_ColorBase
	{
		scope=2;
		color="AdminTest";
		isFaction=1;
		hiddenSelectionsTextures[]=
		{
			"\ZenModShared\data\factions\AdminTest\Flag_AdminTest.paa",
			"\ZenModShared\data\factions\AdminTest\Flag_AdminTest.paa",
			"\ZenModShared\data\factions\AdminTest\Flag_AdminTest.paa",
			"\ZenModShared\data\factions\AdminTest\Flag_AdminTest.paa",
			"\ZenModShared\data\factions\AdminTest\Flag_AdminTest.paa",
			"\ZenModShared\data\factions\AdminTest\Flag_AdminTest.paa",
			"\ZenModShared\data\factions\AdminTest\Flag_AdminTest.paa",
			"\ZenModShared\data\factions\AdminTest\Flag_AdminTest.paa",
			"\ZenModShared\data\factions\AdminTest\Flag_AdminTest.paa"
		};
	};
	class Armband_DoubleAdminTest: Armband_DoubleColorBase
	{
		scope=2;
		color="AdminTest";
		isFaction=1;
		hiddenSelectionsTextures[]=
		{
			"\ZenModShared\data\factions\AdminTest\Flag_AdminTest.paa",
			"\ZenModShared\data\factions\AdminTest\Flag_AdminTest.paa",
			"\ZenModShared\data\factions\AdminTest\Flag_AdminTest.paa",
			"\ZenModShared\data\factions\AdminTest\Flag_AdminTest.paa",
			"\ZenModShared\data\factions\AdminTest\Flag_AdminTest.paa",
			"\ZenModShared\data\factions\AdminTest\Flag_AdminTest.paa",
			"\ZenModShared\data\factions\AdminTest\Flag_AdminTest.paa",
			"\ZenModShared\data\factions\AdminTest\Flag_AdminTest.paa",
			"\ZenModShared\data\factions\AdminTest\Flag_AdminTest.paa"
		};
	};
	class TacticalShirt_AdminTest : TacticalShirt_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] =
		{
			"\ZenModShared\data\factions\AdminTest\bdu_jacket_co.paa",
			"\ZenModShared\data\factions\AdminTest\bdu_jacket_co.paa",
			"\ZenModShared\data\factions\AdminTest\bdu_jacket_co.paa"
		};
	};

	// DownUnder faction 
	class Flag_DownUnder: Flag_Base
	{
		scope=2;
		isFaction=1;
		descriptionShort = "Faction Armband";
		hiddenSelectionsTextures[]=
		{
			"\ZenModShared\data\factions\DownUnder\Flag_co.paa",
		};
		color="DownUnder";
	};
	class Armband_DownUnder: Armband_ColorBase
	{
		scope=2;
		color="DownUnder";
		isFaction=1;
		descriptionShort = "Faction Armband";
		hiddenSelectionsTextures[]=
		{
			"\ZenModShared\data\factions\DownUnder\Flag_co.paa",
			"\ZenModShared\data\factions\DownUnder\Flag_co.paa",
			"\ZenModShared\data\factions\DownUnder\Flag_co.paa",
			"\ZenModShared\data\factions\DownUnder\Flag_co.paa",
			"\ZenModShared\data\factions\DownUnder\Flag_co.paa",
			"\ZenModShared\data\factions\DownUnder\Flag_co.paa",
			"\ZenModShared\data\factions\DownUnder\Flag_co.paa",
			"\ZenModShared\data\factions\DownUnder\Flag_co.paa",
			"\ZenModShared\data\factions\DownUnder\Flag_co.paa"
		};
	};
	class Armband_DoubleDownUnder: Armband_DoubleColorBase
	{
		scope=2;
		color="DownUnder";
		isFaction=1;
		hiddenSelectionsTextures[]=
		{
			"\ZenModShared\data\factions\DownUnder\Flag_co.paa",
			"\ZenModShared\data\factions\DownUnder\Flag_co.paa",
			"\ZenModShared\data\factions\DownUnder\Flag_co.paa",
			"\ZenModShared\data\factions\DownUnder\Flag_co.paa",
			"\ZenModShared\data\factions\DownUnder\Flag_co.paa",
			"\ZenModShared\data\factions\DownUnder\Flag_co.paa",
			"\ZenModShared\data\factions\DownUnder\Flag_co.paa",
			"\ZenModShared\data\factions\DownUnder\Flag_co.paa",
			"\ZenModShared\data\factions\DownUnder\Flag_co.paa"
		};
	};

	// Naruto faction 
	class Flag_Naruto: Flag_Base
	{
		scope=2;
		isFaction=1;
		descriptionShort = "Faction Armband";
		hiddenSelectionsTextures[]=
		{
			"\ZenModShared\data\factions\Naruto\Flag_co.paa",
		};
		color="Naruto";
	};
	class Armband_Naruto: Armband_ColorBase
	{
		scope=2;
		color="Naruto";
		isFaction=1;
		descriptionShort = "Faction Armband";
		hiddenSelectionsTextures[]=
		{
			"\ZenModShared\data\factions\Naruto\Flag_co.paa",
			"\ZenModShared\data\factions\Naruto\Flag_co.paa",
			"\ZenModShared\data\factions\Naruto\Flag_co.paa",
			"\ZenModShared\data\factions\Naruto\Flag_co.paa",
			"\ZenModShared\data\factions\Naruto\Flag_co.paa",
			"\ZenModShared\data\factions\Naruto\Flag_co.paa",
			"\ZenModShared\data\factions\Naruto\Flag_co.paa",
			"\ZenModShared\data\factions\Naruto\Flag_co.paa",
			"\ZenModShared\data\factions\Naruto\Flag_co.paa"
		};
	};
	class Armband_DoubleNaruto: Armband_DoubleColorBase
	{
		scope=2;
		color="Naruto";
		isFaction=1;
		hiddenSelectionsTextures[]=
		{
			"\ZenModShared\data\factions\Naruto\Flag_co.paa",
			"\ZenModShared\data\factions\Naruto\Flag_co.paa",
			"\ZenModShared\data\factions\Naruto\Flag_co.paa",
			"\ZenModShared\data\factions\Naruto\Flag_co.paa",
			"\ZenModShared\data\factions\Naruto\Flag_co.paa",
			"\ZenModShared\data\factions\Naruto\Flag_co.paa",
			"\ZenModShared\data\factions\Naruto\Flag_co.paa",
			"\ZenModShared\data\factions\Naruto\Flag_co.paa",
			"\ZenModShared\data\factions\Naruto\Flag_co.paa"
		};
	};

	// SeaHawks faction 
	class Flag_SeaHawks: Flag_Base
	{
		scope=2;
		isFaction=1;
		descriptionShort = "Faction Armband | Faction Gear: Baseball Cap, Field Jacket.";
		hiddenSelectionsTextures[]=
		{
			"\ZenModShared\data\factions\SeaHawks\Flag_co.paa"
		};
		color="SeaHawks";
	};
	class Armband_SeaHawks: Armband_ColorBase
	{
		scope=2;
		color="SeaHawks";
		isFaction=1;
		descriptionShort = "Faction Armband | Faction Gear: Baseball Cap, Field Jacket.";
		hiddenSelectionsTextures[]=
		{
			"\ZenModShared\data\factions\SeaHawks\Flag_co.paa",
			"\ZenModShared\data\factions\SeaHawks\Flag_co.paa",
			"\ZenModShared\data\factions\SeaHawks\Flag_co.paa",
			"\ZenModShared\data\factions\SeaHawks\Flag_co.paa",
			"\ZenModShared\data\factions\SeaHawks\Flag_co.paa",
			"\ZenModShared\data\factions\SeaHawks\Flag_co.paa",
			"\ZenModShared\data\factions\SeaHawks\Flag_co.paa",
			"\ZenModShared\data\factions\SeaHawks\Flag_co.paa",
			"\ZenModShared\data\factions\SeaHawks\Flag_co.paa"
		};
	};
	class Armband_DoubleSeaHawks: Armband_DoubleColorBase
	{
		scope=2;
		color="SeaHawks";
		isFaction=1;
		hiddenSelectionsTextures[]=
		{
			"\ZenModShared\data\factions\SeaHawks\Flag_co.paa",
			"\ZenModShared\data\factions\SeaHawks\Flag_co.paa",
			"\ZenModShared\data\factions\SeaHawks\Flag_co.paa",
			"\ZenModShared\data\factions\SeaHawks\Flag_co.paa",
			"\ZenModShared\data\factions\SeaHawks\Flag_co.paa",
			"\ZenModShared\data\factions\SeaHawks\Flag_co.paa",
			"\ZenModShared\data\factions\SeaHawks\Flag_co.paa",
			"\ZenModShared\data\factions\SeaHawks\Flag_co.paa",
			"\ZenModShared\data\factions\SeaHawks\Flag_co.paa"
		};
	};
	class BaseballCap_SeaHawks : BaseballCap_ColorBase
	{
		scope = 2;
		visibilityModifier = 0.54999999;
		hiddenSelectionsTextures[] =
		{
			"\ZenModShared\data\factions\SeaHawks\baseballcap_co.paa",
			"\ZenModShared\data\factions\SeaHawks\baseballcap_co.paa",
			"\ZenModShared\data\factions\SeaHawks\baseballcap_co.paa"
		};
	};
	class BaseballCap_BackSeaHawks : BaseballCap_BackColorBase
	{
		scope = 2;
		visibilityModifier = 0.54999999;
		hiddenSelectionsTextures[] =
		{
			"\ZenModShared\data\factions\SeaHawks\baseballcap_co.paa",
			"\ZenModShared\data\factions\SeaHawks\baseballcap_co.paa",
			"\ZenModShared\data\factions\SeaHawks\baseballcap_co.paa"
		};
	};
	class M65Jacket_SeaHawks: M65Jacket_ColorBase
	{
		scope=2;
		visibilityModifier=0.69999999;
		hiddenSelectionsTextures[]=
		{
			"\ZenModShared\data\factions\SeaHawks\M65_Jacket_co.paa",
			"\ZenModShared\data\factions\SeaHawks\M65_Jacket_co.paa",
			"\ZenModShared\data\factions\SeaHawks\M65_Jacket_co.paa"
		};
	};

	// BigBoiClan faction
	class Flag_BigBoiClan: Flag_Base
	{
		scope=2;
		isFaction=1;
		//descriptionShort = "BigBoiClan Faction Gear: Tactical Shirt, Working Gloves, Assault Boots, Military Bag, Mountain Bag, Cargo Pants, Plate Carrier (and attachments), Bandana, Tactical Helmet, Canteen, Smersh Bag & Vest.";
		hiddenSelectionsTextures[]=
		{
			"\ZenModShared\data\factions\BigBoiClan\Flag_co.paa",
		};
		color="BigBoiClan";
	};
	class Armband_BigBoiClan: Armband_ColorBase
	{
		scope=2;
		color="BigBoiClan";
		isFaction=1;
		hiddenSelectionsTextures[]=
		{
			"\ZenModShared\data\factions\BigBoiClan\Flag_co.paa",
			"\ZenModShared\data\factions\BigBoiClan\Flag_co.paa",
			"\ZenModShared\data\factions\BigBoiClan\Flag_co.paa",
			"\ZenModShared\data\factions\BigBoiClan\Flag_co.paa",
			"\ZenModShared\data\factions\BigBoiClan\Flag_co.paa",
			"\ZenModShared\data\factions\BigBoiClan\Flag_co.paa",
			"\ZenModShared\data\factions\BigBoiClan\Flag_co.paa",
			"\ZenModShared\data\factions\BigBoiClan\Flag_co.paa",
			"\ZenModShared\data\factions\BigBoiClan\Flag_co.paa",
		};
	};
	class Armband_DoubleBigBoiClan: Armband_DoubleColorBase
	{
		scope=2;
		color="BigBoiClan";
		isFaction=1;
		hiddenSelectionsTextures[]=
		{
			"\ZenModShared\data\factions\BigBoiClan\Flag_co.paa",
			"\ZenModShared\data\factions\BigBoiClan\Flag_co.paa",
			"\ZenModShared\data\factions\BigBoiClan\Flag_co.paa",
			"\ZenModShared\data\factions\BigBoiClan\Flag_co.paa",
			"\ZenModShared\data\factions\BigBoiClan\Flag_co.paa",
			"\ZenModShared\data\factions\BigBoiClan\Flag_co.paa",
			"\ZenModShared\data\factions\BigBoiClan\Flag_co.paa",
			"\ZenModShared\data\factions\BigBoiClan\Flag_co.paa",
			"\ZenModShared\data\factions\BigBoiClan\Flag_co.paa",
		};
	};

	// MatthewBoulay faction
	class Flag_MatthewBoulay: Flag_Base
	{
		scope=2;
		isFaction=1;
		descriptionShort = "Faction Flag | Faction Gear: Tactical Shirt, Working Gloves, Assault Boots, Military Bag, Mountain Bag, Cargo Pants, Plate Carrier (and attachments), Bandana, Tactical Helmet, Canteen, Smersh Bag & Vest.";
		hiddenSelectionsTextures[]=
		{
			"\ZenModShared\data\factions\MatthewBoulay\Flag_co.paa",
		};
		color="MatthewBoulay";
	};
	class Armband_MatthewBoulay: Armband_ColorBase
	{
		scope=2;
		color="MatthewBoulay";
		isFaction=1;
		descriptionShort = "Faction Armband | Faction Gear: Tactical Shirt, Working Gloves, Assault Boots, Military Bag, Mountain Bag, Cargo Pants, Plate Carrier (and attachments), Bandana, Tactical Helmet, Canteen, Smersh Bag & Vest.";
		hiddenSelectionsTextures[]=
		{
			"\ZenModShared\data\factions\MatthewBoulay\Flag_co.paa",
			"\ZenModShared\data\factions\MatthewBoulay\Flag_co.paa",
			"\ZenModShared\data\factions\MatthewBoulay\Flag_co.paa",
			"\ZenModShared\data\factions\MatthewBoulay\Flag_co.paa",
			"\ZenModShared\data\factions\MatthewBoulay\Flag_co.paa",
			"\ZenModShared\data\factions\MatthewBoulay\Flag_co.paa",
			"\ZenModShared\data\factions\MatthewBoulay\Flag_co.paa",
			"\ZenModShared\data\factions\MatthewBoulay\Flag_co.paa",
			"\ZenModShared\data\factions\MatthewBoulay\Flag_co.paa",
		};
	};
	class Armband_DoubleMatthewBoulay: Armband_DoubleColorBase
	{
		scope=2;
		color="MatthewBoulay";
		isFaction=1;
		hiddenSelectionsTextures[]=
		{
			"\ZenModShared\data\factions\MatthewBoulay\Flag_co.paa",
			"\ZenModShared\data\factions\MatthewBoulay\Flag_co.paa",
			"\ZenModShared\data\factions\MatthewBoulay\Flag_co.paa",
			"\ZenModShared\data\factions\MatthewBoulay\Flag_co.paa",
			"\ZenModShared\data\factions\MatthewBoulay\Flag_co.paa",
			"\ZenModShared\data\factions\MatthewBoulay\Flag_co.paa",
			"\ZenModShared\data\factions\MatthewBoulay\Flag_co.paa",
			"\ZenModShared\data\factions\MatthewBoulay\Flag_co.paa",
			"\ZenModShared\data\factions\MatthewBoulay\Flag_co.paa",
		};
	};
	class Canteen_MatthewBoulay: Canteen
	{
		scope = 2;
		isFaction=1;
		hiddenSelections[] =
		{
			"zbytek"
		};
		hiddenSelectionsTextures[] =
		{
			"\ZenModShared\data\factions\MatthewBoulay\canteen_co.paa"
		};
	};
	class TacticalShirt_MatthewBoulay : TacticalShirt_ColorBase
	{
		scope = 2;
		isFaction=1;
		hiddenSelectionsTextures[] =
		{
			"\ZenModShared\data\factions\MatthewBoulay\pcu5jacket_black_co.paa",
			"\ZenModShared\data\factions\MatthewBoulay\pcu5jacket_black_co.paa",
			"\ZenModShared\data\factions\MatthewBoulay\pcu5jacket_black_co.paa"
		};
	};
	class CargoPants_MatthewBoulay: CargoPants_ColorBase
	{
		scope=2;
		isFaction=1;
		hiddenSelectionsTextures[]=
		{
			"\ZenModShared\data\factions\MatthewBoulay\cargopants_co.paa",
			"\ZenModShared\data\factions\MatthewBoulay\cargopants_co.paa",
			"\ZenModShared\data\factions\MatthewBoulay\cargopants_co.paa"
		};
	};
	class PlateCarrierVest_MatthewBoulay : PlateCarrierVest
	{
		scope = 2;
		isFaction=1;
		hiddenSelections[] =
		{
			"camoGround",
			"camoMale",
			"camoFemale"
		};
		hiddenSelectionsTextures[] =
		{
			"\ZenModShared\data\factions\MatthewBoulay\platecarriervest_black.paa",
			"\ZenModShared\data\factions\MatthewBoulay\platecarriervest_black.paa",
			"\ZenModShared\data\factions\MatthewBoulay\platecarriervest_black.paa"
		};
	};
	class PlateCarrierPouches_MatthewBoulay : PlateCarrierPouches
	{
		scope = 2;
		isFaction=1;
		hiddenSelections[] =
		{
			"zbytek"
		};
		hiddenSelectionsTextures[] =
		{
			"\ZenModShared\data\factions\MatthewBoulay\platecarriervest_black.paa"
		};
	};
	class PlateCarrierHolster_MatthewBoulay : PlateCarrierHolster
	{
		scope = 2;
		isFaction=1;
		hiddenSelections[] =
		{
			"zbytek"
		};
		hiddenSelectionsTextures[] =
		{
			"\ZenModShared\data\factions\MatthewBoulay\platecarriervest_black.paa"
		};
	};
	class Mich2001Helmet_MatthewBoulay : Mich2001Helmet
	{
		scope = 2;
		isFaction=1;
		hiddenSelectionsTextures[] =
		{
			"\ZenModShared\data\factions\MatthewBoulay\mich2001_black_co.paa",
			"\ZenModShared\data\factions\MatthewBoulay\mich2001_black_co.paa",
			"\ZenModShared\data\factions\MatthewBoulay\mich2001_black_co.paa"
		};
	};
	class WorkingGloves_MatthewBoulay: WorkingGloves_ColorBase
	{
		scope=2;
		isFaction=1;
		hiddenSelectionsTextures[]=
		{
			"\ZenModShared\data\factions\MatthewBoulay\WorkingGloves_co.paa",
			"\ZenModShared\data\factions\MatthewBoulay\WorkingGloves_co.paa",
			"\ZenModShared\data\factions\MatthewBoulay\WorkingGloves_co.paa"
		};
	};
	class MilitaryBoots_MatthewBoulay: MilitaryBoots_ColorBase
	{
		scope=2;
		isFaction=1;
		hiddenSelectionsTextures[]=
		{
			"\ZenModShared\data\factions\MatthewBoulay\MilitaryBoots_black_co.paa",
			"\ZenModShared\data\factions\MatthewBoulay\MilitaryBoots_black_co.paa",
			"\ZenModShared\data\factions\MatthewBoulay\MilitaryBoots_black_co.paa"
		};
	};
	class Spur_MilBag_MatthewBoulay: Spur_MilBag_ColorBase
	{
		scope=2;
		isFaction=1;
		hiddenSelections[]=
		{
			"camoGround",
			"camoMale",
			"camoFemale"
		};
		hiddenSelectionsTextures[]=
		{
			"\ZenModShared\data\factions\MatthewBoulay\mountain_black_co.paa",
			"\ZenModShared\data\factions\MatthewBoulay\mountain_black_co.paa",
			"\ZenModShared\data\factions\MatthewBoulay\mountain_black_co.paa"
		};
	};
	class MountainBag_MatthewBoulay : MountainBag_ColorBase
	{
		scope = 2;
		isFaction=1;
		hiddenSelectionsTextures[] =
		{
			"\ZenModShared\data\factions\MatthewBoulay\mountain_black_co.paa",
			"\ZenModShared\data\factions\MatthewBoulay\mountain_black_co.paa",
			"\ZenModShared\data\factions\MatthewBoulay\mountain_black_co.paa"
		};
	};
	class Bandana_MatthewBoulay: Bandana_ColorBase
	{
		scope=2;
		isFaction=1;
		hiddenSelectionsTextures[]=
		{
			"\ZenModShared\data\factions\MatthewBoulay\Bandana_co.paa",
			"\ZenModShared\data\factions\MatthewBoulay\Bandana_co.paa",
			"\ZenModShared\data\factions\MatthewBoulay\Bandana_co.paa",
			"\ZenModShared\data\factions\MatthewBoulay\Bandana_co.paa",
			"\ZenModShared\data\factions\MatthewBoulay\Bandana_co.paa"
		};
	};
	class GorkaEJacket_MatthewBoulay: GorkaEJacket_ColorBase
	{
		scope=2;
		visibilityModifier=0.75;
		hiddenSelectionsTextures[]=
		{
			"\ZenModShared\data\factions\MatthewBoulay\gorka_upper_co.paa",
			"\ZenModShared\data\factions\MatthewBoulay\gorka_upper_co.paa",
			"\ZenModShared\data\factions\MatthewBoulay\gorka_upper_co.paa"
		};
	};
	class GorkaPants_MatthewBoulay: GorkaPants_ColorBase
	{
		scope=2;
		visibilityModifier=0.75;
		hiddenSelectionsTextures[]=
		{
			"\ZenModShared\data\factions\MatthewBoulay\gorka_pants_co.paa",
			"\ZenModShared\data\factions\MatthewBoulay\gorka_pants_co.paa",
			"\ZenModShared\data\factions\MatthewBoulay\gorka_pants_co.paa"
		};
	};
	class SmershBag_MatthewBoulay: SmershBag
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\ZenModShared\data\factions\MatthewBoulay\smersh_co.paa",
			"\ZenModShared\data\factions\MatthewBoulay\smersh_co.paa",
			"\ZenModShared\data\factions\MatthewBoulay\smersh_co.paa"
		};
	};
	class SmershVest_MatthewBoulay: SmershVest
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\ZenModShared\data\factions\MatthewBoulay\smersh_co.paa",
			"\ZenModShared\data\factions\MatthewBoulay\smersh_co.paa",
			"\ZenModShared\data\factions\MatthewBoulay\smersh_co.paa"
		};
	}
};

// Inventory slots
class CfgSlots
{
	class Slot_Material_Chlorine
	{
		name = "Material_Chlorine";
		displayName = "Chlorine Tablets";
		selection = "Material_Chlorine";
		ghostIcon = "missing";
		show = "true";
		stackMax = 0;
		description = "Chlorine Tablets.";
	};
	class Slot_Handcuffs
	{
		name = "Handcuffs";
		displayName = "Handcuffs";
		selection = "Handcuffs";
		ghostIcon = "missing";
		show = "true";
	};
	class Slot_HandcuffKeys
	{
		name = "HandcuffKeys";
		displayName = "Handcuff Keys";
		selection = "HandcuffKeys";
		ghostIcon = "missing";
		show = "true";
	};
	class Slot_Book
	{
		name = "Book";
		displayName = "Book";
		description = "Book";
		ghostIcon = "set:dayz_inventory image:book";
		stackMax = 1;
	};
	class Slot_ZenQuiver1
	{
		name = "ZenQuiver1";
		displayName = "Bolt";
		description = "Bolt";
		ghostIcon = "set:BoltSlot image:Bolt";
		stackMax = 5;
	};
	class Slot_ZenQuiver2
	{
		name = "ZenQuiver2";
		displayName = "Bolt";
		description = "Bolt";
		ghostIcon = "set:BoltSlot image:Bolt";
		stackMax = 5;
	};
	class Slot_ZenQuiver3
	{
		name = "ZenQuiver3";
		displayName = "Bolt";
		description = "Bolt";
		ghostIcon = "set:BoltSlot image:Bolt";
		stackMax = 5;
	};
	class Slot_ZenQuiver4
	{
		name = "ZenQuiver4";
		displayName = "Bolt";
		description = "Bolt";
		ghostIcon = "set:BoltSlot image:Bolt";
		stackMax = 5;
	};
	class Slot_ZenQuiver5
	{
		name = "ZenQuiver5";
		displayName = "Bolt";
		description = "Bolt";
		ghostIcon = "set:BoltSlot image:Bolt";
		stackMax = 5;
	};
	class Slot_ZenQuiver6
	{
		name = "ZenQuiver6";
		displayName = "Bolt";
		description = "Bolt";
		ghostIcon = "set:BoltSlot image:Bolt";
		stackMax = 5;
	};
	class Slot_ZenQuiver7
	{
		name = "ZenQuiver7";
		displayName = "Bolt";
		description = "Bolt";
		ghostIcon = "set:BoltSlot image:Bolt";
		stackMax = 5;
	};
	class Slot_ZenQuiver8
	{
		name = "ZenQuiver8";
		displayName = "Bolt";
		description = "Bolt";
		ghostIcon = "set:BoltSlot image:Bolt";
		stackMax = 5;
	};
	class Slot_ZenMapPin1
	{
		name = "ZenMapPin1";
		displayName = "Pin";
		description = "Pin";
		ghostIcon = "missing";
		stackMax = 1;
	};
	class Slot_ZenMapPin2
	{
		name = "ZenMapPin2";
		displayName = "Pin";
		description = "Pin";
		ghostIcon = "missing";
		stackMax = 1;
	};
	class Slot_ZenMapPin3
	{
		name = "ZenMapPin3";
		displayName = "Pin";
		description = "Pin";
		ghostIcon = "missing";
		stackMax = 1;
	};
}

// Unfortunate this is necessary - lowers volume of all snowmobiles
class CfgSoundShaders
{
	class Silent_SoundShader
	{
		samples[] =
		{
			{
				"ZenModShared\data\silent",
				1
			}
		};

		volume = 0;
		range = 1;
	};

	class baseCharacter_SoundShader;
	class animalSkinning_Soundshader: baseCharacter_SoundShader
	{
		samples[]=
		{
			
			{
				"DZ\sounds\Characters\actions\misc\animalSkinning_0",
				1
			},
			
			{
				"DZ\sounds\Characters\actions\misc\animalSkinning_1",
				1
			},
			
			{
				"DZ\sounds\Characters\actions\misc\animalSkinning_2",
				1
			},
			
			{
				"DZ\sounds\Characters\actions\misc\animalSkinning_3",
				1
			},
			
			{
				"DZ\sounds\Characters\actions\misc\animalSkinning_4",
				1
			},
			
			{
				"DZ\sounds\Characters\actions\misc\animalSkinning_5",
				1
			}
		};
		volume=0.56234133 / 2;
	};
};

class CfgSoundSets
{
	class Silent_SoundSet
	{
		soundShaders[] =
		{
			"Silent_SoundShader"
		};
	};
};

class CfgMagazines
{
	class Ammunition_Base;
	class Ammo_HuntingBolt : Ammunition_Base
	{
		itemSize[] = { 3,1 };
		inventorySlot[] +=
		{
			"ZenQuiver1",
			"ZenQuiver2",
			"ZenQuiver3",
			"ZenQuiver4",
			"ZenQuiver5",
			"ZenQuiver6",
			"ZenQuiver7",
			"ZenQuiver8"
		};
	};
	class Ammo_ImprovisedBolt_1 : Ammunition_Base
	{
		itemSize[] = { 3,1 };
		inventorySlot[] +=
		{
			"ZenQuiver1",
			"ZenQuiver2",
			"ZenQuiver3",
			"ZenQuiver4",
			"ZenQuiver5",
			"ZenQuiver6",
			"ZenQuiver7",
			"ZenQuiver8"
		};
	};
	class Ammo_ImprovisedBolt_2 : Ammunition_Base
	{
		itemSize[] = { 3,1 };
		inventorySlot[] +=
		{
			"ZenQuiver1",
			"ZenQuiver2",
			"ZenQuiver3",
			"ZenQuiver4",
			"ZenQuiver5",
			"ZenQuiver6",
			"ZenQuiver7",
			"ZenQuiver8"
		};
	};
};

class CfgWorlds
{
	class CAWorld;
	class ChernarusPlus: CAWorld
	{
		farCloudObjectRotationSpeed=2;//3;
		cloudObjectRotationSpeed=8;//9;
	}
	class Enoch: CAWorld
	{
		farCloudObjectRotationSpeed=2;//3;
		cloudObjectRotationSpeed=8;//9;
	}
}

class CfgWeapons
{
	class Winchester70;
	class Winchester70_Black: Winchester70
	{
		displayName="$STR_cfgWeapons_Winchester700";
		descriptionShort="$STR_cfgWeapons_Winchester701";
	};
	class Winchester70_Green: Winchester70
	{
		displayName="$STR_cfgWeapons_Winchester700";
		descriptionShort="$STR_cfgWeapons_Winchester701";
	};
}

class AIParams
{
	class AgentTeams
	{
		class Predator
		{
			friends[] -=
			{
				"Zombies"
			};
		};
		class Zombies
		{
			friends[] -=
			{
				"Predator",
				"AmbientLife"
			};
		};
	};
};
