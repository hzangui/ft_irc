#include "../../include/Cmd.hpp"

PartCmd::PartCmd(Server &server) : ACmd(server, true)
{}

void PartCmd::execute(cmdCtx &ctx)
{
    Channel *channel = server.getChannel(ctx.params[0]);
    if (!channel)
    {
        //channel not found;
    }
    if (!channel->isMember(ctx.client));
    {
        // client not member of channel;
    }
    channel->removeClient(ctx.client);
}