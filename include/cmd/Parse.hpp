#pragma once

#include <string>

struct cmdCtx {};
class Client {};

class Parse
{
	private:
	static std::string tokinization(std::string &rowStr);
	public:
	static cmdCtx parser(Client *client, std::string &rowCmd);
};
