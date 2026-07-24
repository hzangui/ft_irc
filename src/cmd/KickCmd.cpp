#pragma once
#include "../../include/cmd/KickCmd.hpp"
#include "../../include/Server.hpp"
#include "../../include/Channel.hpp"
#include "../../include/Client.hpp"


KickCmd::KickCmd(Server &server) : ACmd(server, true)
{
}

void KickCmd::execute(cmdCtx &ctx)
{
	Channel *channel = server.findChannel(ctx.params[0]);
	Client *target;

	if(!channel)
	{
		//channel not existe;
	}
	if(!channel->isMember(ctx.client))
	{
		// sender not member of channel;
	}
	if(!channel->isOperator(ctx.client))
	{
		// sender not a operator;
	}
	target = channel->findMember(ctx.params[1]);
	if (!target)
	{
		// target not in the channel;
	}
	//send msg brodcast;
	channel->removeMember(target);
	target->leaveChannel(channel);
}
