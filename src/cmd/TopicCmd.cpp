#include "../../include/cmd/TopicCmd.hpp"
#include "../../include/Server.hpp"
#include "../../include/Channel.hpp"
#include "../../include/Client.hpp"

TopicCmd::TopicCmd(Server &server):ACmd(server, true)
{}

void TopicCmd::execute(cmdCtx &ctx)
{
    Channel *channel = server.findChannel(ctx.params[0]);
    
    if (!channel)
    {
        //channel not exist;
    }
    if(ctx.lastArg.empty())
    {
        if (channel->getTopic().empty())
        {
            //channel have empty topic;
        }
        else
        {
            //msg with topic of channel;
        }
    }
    if (channel->topicRestricted() && !channel->isOperator(ctx.client))
    {
        // client not a operator;
    }
    //msg brodcast
    channel->setTopic(ctx.lastArg);
}