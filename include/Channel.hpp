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
		std::map<int, Client*> clientFds;
		std::map<std::string, Client*> ClientNick;
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

		void changeKey(bool value);
		void changelimit(bool value);
		void changetopic(bool value);
		void changeReqInvit(bool value);

		void addMember(Client *client);
		void addInvited(Client *client);
		void addOperator(Client *client);
		
		void removeClient(Client *client);
		void removeOperator(Client *client);
		void removeInvited(Client *client);

		void setTopic(std::string &topic);
		void setKey(std::string key);
		void setLimit(size_t limit);

		

};
