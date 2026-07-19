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
		int getsocket();
		bool isRegistred();
		bool isJoinded(std::string channel);
		
		void setNick(std::string &nick);
		void setRegister(bool value);
		void setUsername(std::string &username);
		void setSocket(int fd);

		void addChannel(Channel *channel);
		void removeChannel(std::string name);
		
};


