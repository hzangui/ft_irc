#include "../../include/cmd/InviteCmd.hpp"

InviteCmd::InviteCmd(Server &server) : ACmd(server, true)
{}

Channel *InviteCmd::checkChannel(Client *client, std::string &channelName)
{
	Channel *channel = server.getChannel(channelName);
	if (!channel)
	{
		return NULL;
	}
	if(!channel->isMember(client))
	{
		return NULL;
	}
	if(channel->reqInvite() && !channel->isOperator(client))
	{
		return NULL;
	}
}

void InviteCmd::execute(cmdCtx &ctx)
{
	Channel *channel;
	
	if (!server.existChannel(ctx.params[1]))
	{
		channel
	}
	if (!ctx.client->isJoinded(ctx.params[1]))
	{
		//you not member of channel;
		return;
	}
	if (!ctx.c)

}