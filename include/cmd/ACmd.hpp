#pragma once

#include <vector>
#include <string>
#include <sstream>
#include "../Server.hpp"

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