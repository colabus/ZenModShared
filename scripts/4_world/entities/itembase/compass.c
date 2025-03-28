// Damage compass slightly each time it is opened - HP=70
modded class Compass
{
	override void Open()
	{
		super.Open();
		AddHealth(-0.5);
	}

	override void Close()
	{
		super.Close();
		AddHealth(-0.5);
	}
}