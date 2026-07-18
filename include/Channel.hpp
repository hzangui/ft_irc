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
		
		bool hasKey();
		bool hasLimit();
		bool reqInvite();
		bool changeTopic();

		std::string getKey();
		size_t getLimit();

		bool isOperator(Client *client);
		bool isInvited(Client *client);
		bool isMember(Client *client);

		
};
