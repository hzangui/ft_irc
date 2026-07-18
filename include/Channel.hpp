#pragma once
#include <string>
#include <vector>
#include "Client.hpp"

class Channel
{
	private:
		std::string name;
		std::string topic;
		std::vector<Client *> clients;
		std::vector<Client *> operators;
		std::vector<Client *> invetedClients;
		std::string key;
		size_t limit;
		bool requareInvit;
		bool changeTopic;
		bool hasKey;
		bool haslimit;




	public:
		Channel(/* args */);
		~Channel();
};
