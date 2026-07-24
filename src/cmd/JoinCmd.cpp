#include "../../include/cmd/JoinCmd.hpp"
#include "../../include/Server.hpp"
#include "../../include/Channel.hpp"
#include "../../include/Client.hpp"


JoinCmd::JoinCmd(Server &Server) : ACmd(Server, true)
{}


void JoinCmd::creatNewChannel(Client *client, std::string &channelName)
{
	if (!isValidChannelName(channelName))
	{
		// invalid name;
		return;
	}
	Channel *channel = server.createChannel(channelName);
	channel->addMember(client);
	channel->addOperator(client);
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

void JoinCmd::joinChannel(Client *client, std::string &channelName, std::string &key)
{
	Channel *channel = server.findChannel(channelName);

	if(channel->hasLimit() && channel->size() >= channel->getLimit())
	{
		// can't join
	}
	else if(channel->inviteOnly() && !channel->isInvited(client))	
	{
		//is not invited;
	}
	else if(channel->hasKey() && key != channel->getKey())
	{
		//key invalid;
	}
	else
	{
		channel->addMember(client);
		// msg
	}
	
}

void JoinCmd::execute(cmdCtx &ctx)
{
	std::vector<std::string> channelsNames = split(ctx.params[0], ',');
	std::vector<std::string> keys;
	
	if (ctx.params.size() > 1)
		keys = split(ctx.params[1], ',');
	
	if (keys.size() < channelsNames.size())
	{
		for(int i = 0; i < channelsNames.size(); i++)
			keys.push_back(std::string(""));
	}
	for(int i = 0; i < channelsNames.size(); i++)
	{
		if (!server.channelExists(channelsNames[i]))
		{
			creatNewChannel(ctx.client, channelsNames[i]);
			return;
		}
		joinChannel(ctx.client, channelsNames[i], keys[i]);
	}
}