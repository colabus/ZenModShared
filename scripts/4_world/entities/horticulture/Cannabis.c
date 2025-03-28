modded class Plant_Cannabis : PlantBase
{
	void Plant_Cannabis()
	{
		m_DeleteDryPlantTime = 14400;			// 4 hours	| For how long in seconds can an unwatered plant exist before it disappears
		m_SpoiledRemoveTime = 3600;				// 1 hour	| For how long in seconds a spoiled plant will exist
		m_FullMaturityTime = 7200;				// 2 hours	| How much time needs plant to be full grown in seconds
		m_SpoilAfterFullMaturityTime = 14400;	// 4 hours	| How long in seconds it takes for plant to be spoiled after it is full grown
	}
};

modded class Cannabis
{
	override void DeferredInit()
	{
		super.DeferredInit();
		SetQuantity(1); // full quantity
	}

	override void SetActions()
	{
		super.SetActions();
		
		// Don't eat your weed
		RemoveAction(ActionForceFeed);
		RemoveAction(ActionEat);
	}
}