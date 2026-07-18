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
		std::string username;
		bool registred;

	public:
		Client(/* args */);
		~Client();
};


