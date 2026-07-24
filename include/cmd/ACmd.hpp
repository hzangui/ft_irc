#pragma once

#include <vector>
#include <string>
#include <sstream>

class Server{};

struct cmdCtx
{
	Client *client;
	std::string cmdName;
	std::vector<std::string> params;
	std::string lastArg;
};


class ACmd
{
	protected:
		Server &server;
		bool reqRegister;

	public:
		static std::vector<std::string> split(std::string &str, char del);
		ACmd(Server &server, bool reqRegister);
		virtual void execute(cmdCtx &ctx) = 0;
};