modded class Hatchet
{
	protected void HatchetShowSimpleSelection(string selectionName, bool hide = false)
    {
        TStringArray selectionNames = new TStringArray;
        ConfigGetTextArray("simpleHiddenSelections", selectionNames);

		if (!selectionNames)
			return;

        int selectionId = selectionNames.Find(selectionName);
        SetSimpleHiddenSelectionState(selectionId, hide);
    }

	void Hatchet()
	{
		HatchetShowSimpleSelection("backwards", 0);
		HatchetShowSimpleSelection("zbytek", 1);
	}

	void SetBackwards(bool b)
	{
		if (b)
		{
			HatchetShowSimpleSelection("backwards", 1);
			HatchetShowSimpleSelection("zbytek", 0);
		}
		else 
		{
			HatchetShowSimpleSelection("backwards", 0);
			HatchetShowSimpleSelection("zbytek", 1);
		}
	}
};