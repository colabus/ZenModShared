modded class ActionDeployObject
{
    private vector m_DeployPosition;
    private string m_DeployType;
    private float m_MinDistance;

    private static const float MIN_DIST_BASE = 1.0;
    private static const float MIN_DIST_TENT = 2.0;

    private static const ref array<string> CHECK_OBJECTS =
    {
        "tent",
        "shelter"
    };

    override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
        #ifndef SERVER
        if (player.GetItemInHands())
        {
            m_DeployPosition = player.GetHologramLocal().GetProjectionEntity().GetPosition();
            m_DeployType = player.GetItemInHands().GetType();
            m_MinDistance = MIN_DIST_BASE;

            if (player.GetItemInHands().IsInherited(TentBase))
            {
                m_MinDistance = MIN_DIST_TENT;
            }
        }
        #endif

		return super.ActionCondition(player, target, item);
	}

	override bool ActionConditionContinue(ActionData action_data)
	{
		#ifdef SERVER
        return super.ActionConditionContinue(action_data);
        #else
        string checkType = m_DeployType;
        checkType.ToLower();
        checkType.Replace("placing", "");
        bool checkDist = false;

        foreach (string s : CHECK_OBJECTS)
        {
            if (checkType.Contains(s) && !checkType.Contains("stair"))
            {
                checkDist = true;
                break;
            }
        }

        if (!checkDist)
            return super.ActionConditionContinue(action_data);

		string nearobjType;
        float dist;
		array<Object> nearest_objects = new array<Object>;
        GetGame().GetObjectsAtPosition3D(m_DeployPosition, 3, nearest_objects, NULL);

        foreach (Object nearobj : nearest_objects)
        {
            if (nearobj.IsHologram() || nearobj.IsMan())
                continue;

            if (nearobj.IsInherited(PartyTent) && !checkType.Contains("party"))
                continue;

            if (nearobj.IsInherited(CarTent) && checkType.Contains("kit"))
                continue;

            dist = vector.Distance(m_DeployPosition, nearobj.GetPosition());

			nearobjType = nearobj.GetType();
			nearobjType.ToLower();

			// Ignore expansion floor/roof, interferes with storage kit placement etc
			if (nearobjType.Contains("floor") || nearobjType.Contains("roof"))
				continue;

            if (nearobj.IsInherited(BaseBuildingBase) || nearobj.IsInherited(TentBase))
            {
                if (dist <= m_MinDistance)
                {
                    string kitDisplayName = GetGame().ConfigGetTextOut("CfgVehicles " + checkType + " displayName");
					string displayMsg = "You cannot place " + kitDisplayName + " within " + MiscGameplayFunctions.TruncateToS(m_MinDistance, 1) + "m of " + nearobj.GetDisplayName() + "! Distance: " + MiscGameplayFunctions.TruncateToS(dist, 2) + "m";

					ExpansionNotification(new StringLocaliser("DEPLOY WARNING", "DEPLOY WARNING"), displayMsg).Error(action_data.m_Player.GetIdentity());
                    //ZenFunctions.ZenClientMessage(displayMsg);
                    return false;
                }
            }
        }
        #endif

		return super.ActionConditionContinue(action_data);
	}

    // Don't allow placement @ 0 0 0
    override void OnFinishProgressServer(ActionData action_data)
    {
        if (action_data.m_Player && action_data.m_Player.GetHologramServer())
        {
            if (action_data.m_Player.GetLocalProjectionPosition() == vector.Zero)
                return;
        }

        super.OnFinishProgressServer(action_data);
    }
}