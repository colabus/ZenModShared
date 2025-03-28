modded class Land_Underground_Stairs_Exit : Land_Underground_EntranceBase
{
	void Land_Underground_Stairs_Exit()
	{
		#ifdef SERVER
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(OpenSwarogDoor, 5111, false);
		#endif
	}

	void OpenSwarogDoor()
	{
		if (vector.Distance(GetPosition(), "5176.257813 517.082825 2219.919922") <= 1)
		{
			SetAnimationPhase("EntranceDoor", 1);
		}
	}
};