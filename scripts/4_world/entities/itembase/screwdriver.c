modded class Screwdriver
{
    override void SetActions()
    {
        super.SetActions();

        AddAction(ActionDismantleRFSolarPanel);
        AddAction(ActionCreateGreenhouseGardenPlot);
    }
};