#pragma once

#include "ACmd.hpp"

class Client {};
class Channel {};

class JoinCmd : public ACmd // almost finish
{
	private:
		void creatNewChannel(Client *client, std::string &channelName);
		bool isValidChannelName(std::string& name);
		void joinChannel(Client *client, std::string &channelName, std::string &key);

	public:
		JoinCmd(Server &Server);
		void execute(cmdCtx &ctx);

};