modded class FireplaceBase
{
	private ref NoiseParams m_ExtraNoisePar;
	private int m_MakeExtraNoise;

	const int   LIFETIME_FIREPLACE_STONE_CIRCLE		= 604800;
	const int   LIFETIME_FIREPLACE_STONE_OVEN		= 1209600;

	const float FUEL_BURN_RATE_DEFAULT = 1.0;
	const float FUEL_BURN_RATE_STONES = 0.92;
	const float FUEL_BURN_RATE_OVEN = 0.75;

	void FireplaceBase()
	{
		m_FireConsumableTypes.Remove(ATTACHMENT_RAGS);
		m_FireConsumableTypes.Remove(ATTACHMENT_BANDAGE);
		m_FireConsumableTypes.Remove(ATTACHMENT_BOOK);
		m_FireConsumableTypes.Remove(ATTACHMENT_BARK_OAK);
		m_FireConsumableTypes.Remove(ATTACHMENT_BARK_BIRCH);
		m_FireConsumableTypes.Remove(ATTACHMENT_PAPER);
		m_FireConsumableTypes.Remove(ATTACHMENT_GIFTWRAP);
		m_FireConsumableTypes.Remove(ATTACHMENT_STICKS);
		m_FireConsumableTypes.Remove(ATTACHMENT_FIREWOOD);

		// Junk
		//m_FireConsumableTypes.Insert(ATTACHMENT_RAGS, new FireConsumableType(ATTACHMENT_RAGS, 14, true, "Rags"));
		m_FireConsumableTypes.Insert(ATTACHMENT_BOOK, new FireConsumableType(ATTACHMENT_BOOK, 14, true, "Book"));

		// Vanilla
		m_FireConsumableTypes.Insert(ATTACHMENT_RAGS, new FireConsumableType(ATTACHMENT_RAGS, 14, true, "Rags"));
		m_FireConsumableTypes.Insert(ATTACHMENT_BANDAGE, new FireConsumableType(ATTACHMENT_BANDAGE, 14, true, "MedicalBandage"));
		m_FireConsumableTypes.Insert(ATTACHMENT_BARK_OAK, new FireConsumableType(ATTACHMENT_BARK_OAK, 20, true, "OakBark"));
		m_FireConsumableTypes.Insert(ATTACHMENT_BARK_BIRCH, new FireConsumableType(ATTACHMENT_BARK_BIRCH, 14, true, "BirchBark"));
		m_FireConsumableTypes.Insert(ATTACHMENT_PAPER, new FireConsumableType(ATTACHMENT_PAPER, 10, true, "Paper"));
		m_FireConsumableTypes.Insert(ATTACHMENT_GIFTWRAP, new FireConsumableType(ATTACHMENT_GIFTWRAP, 10, true, "GiftWrapPaper"));

		//define fuel types
		m_FireConsumableTypes.Insert(ATTACHMENT_STICKS, new FireConsumableType(ATTACHMENT_STICKS, 50, false, "WoodenStick"));
		m_FireConsumableTypes.Insert(ATTACHMENT_FIREWOOD, new FireConsumableType(ATTACHMENT_FIREWOOD, 1200, false, "Firewood"));
	}

	override bool IsRefresherSignalingViable()
	{
		return !IsRuined() && GetInventory().AttachmentCount() > 0;
	}

	#ifdef SERVER
	override void Heating()
	{
		super.Heating();

		if (m_MakeExtraNoise < 3)
			return;

		if (m_MakeExtraNoise)
		{
			MakeCookingNoise();
		}
	}

	override void CookWithEquipment()
	{
		super.CookWithEquipment();
		m_MakeExtraNoise++;
	}

	override void CookOnDirectSlot(ItemBase slot_item, float temp_equip, float temp_ext)
	{
		super.CookOnDirectSlot(slot_item, temp_equip, temp_ext);
		m_MakeExtraNoise++;
	}
	#endif

	void MakeCookingNoise()
	{
		if (!m_ExtraNoisePar)
		{
			m_ExtraNoisePar = new NoiseParams();
			m_ExtraNoisePar.LoadFromPath("CfgVehicles FireNoises NoiseCooking");
		}

		NoiseSystem noise = GetGame().GetNoiseSystem();
		if (noise && m_ExtraNoisePar)
		{
			float multiplier = 1.0;
			if (GetGame().GetWorld().IsNight())
				multiplier = 1.5;
				
			noise.AddNoiseTarget(GetPosition() + "0 1 0", 10, m_ExtraNoisePar, multiplier);
			m_MakeExtraNoise = 0;
		}
	}
}
