#include "../../include/Cmd.hpp"


ACmd::ACmd(Server &server, bool reqRegister) : server(server), reqRegister(reqRegister)
{
}

void JoinCmd::execute(cmdCtx &ctx)
{
	if(ctx.params.empty())
	{

	}
	Channel *channel = server.foundChannel(ctx.params[0]);
	if(!channel)
	{
		server.createChannel(cmdCtx.client, ctx.params[0]);
		//
	}
	if (channel.haslimit())
	{
		if(channel.getlimit() > channel.getSize())
		{
			//
		}
	}
	if(channel.isinveted())
	{
		Client *invited = channel.searchInvited(ctx.client);
		if (!invited)
		{
			//not invited
		}
	}
	if (channel.hasKey())
	{
		if(ctx.params.size())
	}
}

