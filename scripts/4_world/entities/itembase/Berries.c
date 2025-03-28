class ZenBerryBase extends Edible_Base
{
	override bool CanBeCooked()
	{
		return true;
	}		
	
	override bool CanBeCookedOnStick()
	{
		return false;
	}
	
	override bool IsFruit()
	{
		return true;
	}

	override bool CanDecay()
	{
		return true;
	}
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionForceFeed);
		AddAction(ActionEat);
	}
}

class Zen_SambucusBerry				extends ZenBerryBase {};
class Zen_CaninaBerry				extends ZenBerryBase {};

class Zen_SambucusBerry_Poison extends ZenBerryBase 
{
	override bool IsFoodRotten()
	{
		return true;
	}
};

class Zen_CaninaBerry_Poison extends ZenBerryBase 
{
	override bool IsFoodRotten()
	{
		return true;
	}
};

