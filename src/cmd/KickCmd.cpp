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

}
