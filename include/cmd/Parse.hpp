#pragma once

class Parse
{
	private:
	static std::string tokinization(std::string &rowStr);
	public:
	static cmdCtx parser(Client *client, std::string &rowCmd);
};
