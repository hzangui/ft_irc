#include "../../include/Cmd.hpp"

JoinCmd::JoinCmd(Server &Server) : ACmd(Server, true)
{}


void JoinCmd::creatNewChannel(Client *client, std::string &channelName)
{
	if (!isValidChannelName(channelName))
	{
		// invalid name;
		return;
	}
	Channel channel(channelName);
	channel.addMember(client);
	channel.addOperator(client);
	// chennel added;
}

bool isValidChannelName(std::string& name)
{
    if (name.size() < 2 || name[0] != '#')
        return false;

    for (size_t i = 1; i < name.size(); ++i)
    {
        if (name[i] == ' ' || name[i] == ',' || name[i] == ':')
            return false;
    }
    return true;
}

void JoinCmd::joinChannel(cmdCtx &ctx)
{
	Channel *channel = server.getChannel(ctx.params[0]);

	if(channel->hasLimit() && channel->getSize() >= channel->getLimit())
	{
		// can't join
	}
	else if(channel->reqInvite() && !channel->isInvited(ctx.client))	
	{
		//is not invited;
	}
	else if(channel->hasKey() && (ctx.params.size() < 2 || ctx.params[1] != channel->getKey()))
	{
		//key invalid;
	}
	else
	{
		channel->addMember(ctx.client);
	}
	
}

void JoinCmd::execute(cmdCtx &ctx)
{
	if (!server.existChannel(ctx.params[0]))
	{
		creatNewChannel(ctx.client, ctx.params[0]);
		return;
	}
	joinChannel(ctx);
}