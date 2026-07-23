#include "Server.hpp"
#include <vector>
#include <string>

struct cmdCtx
{
	Client *client;
	std::string cmdName;
	std::vector<std::string> params;
	std::string lastArg;
};
