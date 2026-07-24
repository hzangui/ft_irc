#include "../../include/cmd/InviteCmd.hpp"
#include "../../include/Server.hpp"
#include "../../include/Channel.hpp"
#include "../../include/Client.hpp"

InviteCmd::InviteCmd(Server &server) : ACmd(server, true)
{}



void InviteCmd::execute(cmdCtx &ctx)
{
	Client *invited = server.findClient(ctx.params[0]);
	Channel *channel = server.findChannel(ctx.params[1]);
	if (!invited)
	{
		//invited not existe;
	}
	if (!channel)
	{
		//channel not existe;
	}
	if (!ctx.client->isInChannel(ctx.params[0]));
	{
		//you not in the channel
	}
	if (channel->inviteOnly() && !channel->isOperator(ctx.client))
	{
		// need operator permission;
	}
	if (channel->isMember(invited))
	{
		// already is in the channel;
	}
	channel->addInvited(invited);
	// send msgs;
}