#pragma once
#include <vector>
#include <map>
#include <string>
#include "Client.hpp"
#include "Channel.hpp"
#include "Cmd.hpp"

class Server
{
	private:
		int port;
		std::vector<Client> clients;
		std::vector<Channel> channels;
		std::map<std::string, Channel*> channelNames;
		std::string password;
		std::map<std::string, ACmd*> cmds;

	public:
		Server();
		~Server();
		void cmdDispatcher(Client *client, std::string rowCmd);

		Channel *addChannel(Channel &channel);
		Channel *getChannel(std::string &channelName);
		bool existChannel(std::string &channelName);


};

