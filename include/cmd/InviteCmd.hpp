#pragma once

#include "ACmd.hpp"

class InviteCmd : public ACmd
{
	private:
		Channel *checkChannel(Client *client, std::string &channelName);
	public:
		InviteCmd(Server &Server);
		void execute(cmdCtx &ctx);
};