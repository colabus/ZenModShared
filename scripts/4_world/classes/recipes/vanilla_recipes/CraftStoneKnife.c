modded class CraftStoneKnife extends RecipeBase
{	
	override void Init()
	{
		super.Init();

		// small stone hp = 100
		m_IngredientAddHealth[1] = -50;
	}
};