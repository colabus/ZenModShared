modded class CutOutPumpkinSeeds
{
	override void Init()
	{
		super.Init();

		m_ResultSetQuantity[0] = Math.RandomIntInclusive(1, 3);
	}
}

modded class CutOutZucchiniSeeds
{
	override void Init()
	{
		super.Init();
		
		m_ResultSetQuantity[0] = Math.RandomIntInclusive(1, 6);
	}
}

modded class CutOutTomatoSeeds
{
	override void Init()
	{
		super.Init();

		m_ResultSetQuantity[0] = Math.RandomIntInclusive(1, 6);
	}
}

modded class CutOutPepperSeeds
{
	override void Init()
	{
		super.Init();

		m_ResultSetQuantity[0] = Math.RandomIntInclusive(1, 6);
	}
}