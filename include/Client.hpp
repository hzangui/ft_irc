#pragma once
#include <string>
#include <vector>
#include "Channel.hpp"

class Client
{
	private:
		int socket;
		std::string nick;
		std::vector <Channel*> channels;
		std::map<std::string, Channel*> channelName;
		std::string username;
		bool registred;

	public:
		
		std::string getNick();
		bool isJoinded(std::string name);
		
		void addChannel(Channel *channel);
		void removeChannel(std::string name);
		
		bool isRegistred();
		
};


