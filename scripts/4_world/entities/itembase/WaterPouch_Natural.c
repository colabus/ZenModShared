class WaterPouch_Natural : Bottle_Base 
{
	// copy paste from WaterBottle
	override bool CanPutInCargo( EntityAI parent )
	{
		if( !super.CanPutInCargo(parent) ) {return false;}	
		if ( parent && (parent.IsKindOf("WatterBottle"))/* && !(parent.IsKindOf("Container_Base"))*/)
		{
			return false;
		}
		
		return true;
	}
	
	override bool IsOpen()
	{
		return true;
	}

	override bool IsContainer()
	{
		return true;
	}
};