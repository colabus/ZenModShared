class ActionZenLieByFireCB : ActionInteractBaseCB
{
    override void CreateActionComponent()
    {
        m_ActionData.m_ActionComponent = new CASingleUse;
    }

    override void InitActionComponent()
    {
        // ZenSleep compatibility
#ifdef ZenSleep
        if (m_ActionData.m_Player)
        {
            m_ActionData.m_Player.ResetSleep();
        }
#endif

        super.InitActionComponent();
    }
}

class ActionZenLieByFire : ActionInteractBase
{
    void ActionZenLieByFire()
    {
        m_CallbackClass = ActionZenLieByFireCB;
        m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_INTERACTONCE;
        m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_CROUCH;
    }

    override string GetText()
    {
        return "#STR_USRACT_ID_EMOTE_LYINGDOWN by fire";
    }

    override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
    {
        if (player.GetItemInHands() || !target || !target.GetObject())
            return false;

        Fireplace fireplaceTarget = Fireplace.Cast(target.GetObject());
        if (!fireplaceTarget || !fireplaceTarget.IsBurning())
            return false;

        float distance = vector.Distance(target.GetObject().GetPosition(), player.GetPosition());
        return distance <= 2;
    }

    override void OnEndClient(ActionData action_data)
    {
        if (action_data.m_Player.GetEmoteManager())
        {
            action_data.m_Player.GetEmoteManager().CreateEmoteCBFromMenu(EmoteConstants.ID_EMOTE_LYINGDOWN);
        }
    }
}