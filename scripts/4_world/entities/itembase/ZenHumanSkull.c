static const int ZENHUMANSKULLRPC_RESPONSE = -34827569;
static const int ZENHUMANSKULLRPC_REQUEST = -34827568;

class ZenHumanSkull extends ItemBase
{
	string m_DeadPlayerName = "";
	bool m_HasReceivedName = false;

	void ZenHumanSkull()
	{
		RegisterNetSyncVariableBool("m_HasReceivedName");
	}

	override void DeferredInit()
	{
		super.DeferredInit();

		if (!m_HasReceivedName)
		{
			// Client load - request player name
			RPCSingleParam(ZENHUMANSKULLRPC_REQUEST, new Param1<bool>(true), true, NULL);
		}
	}

	void SetDeadPlayerName(string name)
	{
		m_DeadPlayerName = name;
		m_HasReceivedName = false;
		SetSynchDirty();
	}

    override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		super.OnRPC(sender, rpc_type, ctx);

		Param1<string> params = new Param1<string>(m_DeadPlayerName);

		// Client-side receiver
		if (rpc_type == ZENHUMANSKULLRPC_RESPONSE)
		{
			if (!ctx.Read(params) || !params.param1)
				return;

			m_DeadPlayerName = params.param1;
			m_HasReceivedName = true;
		}
		else 
		// Server-side receiver
		if (rpc_type == ZENHUMANSKULLRPC_REQUEST)
		{
			RPCSingleParam(ZENHUMANSKULLRPC_RESPONSE, new Param1<string>(m_DeadPlayerName), true, sender);
		}
	}

	override bool NameOverride(out string output)
	{
		if (m_DeadPlayerName != "")
		{
			output = "#STR_WindStride_HumanSkull (" + m_DeadPlayerName + ")";
			return true;
		}
		
		return false;
	}

	override bool OnStoreLoad(ParamsReadContext ctx, int version)
	{
		super.OnStoreLoad(ctx, version);

		if (!ctx.Read(m_DeadPlayerName))
			m_DeadPlayerName = "Unknown";

		return true;
	}

	override void OnStoreSave(ParamsWriteContext ctx)
	{
		super.OnStoreSave(ctx);

		ctx.Write(m_DeadPlayerName);
	}
}