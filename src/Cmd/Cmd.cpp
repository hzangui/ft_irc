#include "../../include/Cmd.hpp"


ACmd::ACmd(Server &server, bool reqRegister) : server(server), reqRegister(reqRegister)
{
}

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
	
}

void JoinCmd::execute(cmdCtx &ctx)
{
	if (!server.existChannel(ctx.params[0]))
	{
		creatNewChannel(ctx.client, ctx.params[0]);
		return;
	}

}

