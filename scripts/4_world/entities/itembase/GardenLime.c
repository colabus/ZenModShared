modded class GardenLime
{
	// Make garden lime combinable like pills, but not splittable
	override void InitItemVariables()
	{
		super.InitItemVariables();
		can_this_be_combined = true;
	}
}