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

class Parse
{
	private:
	static std::string tokinization(std::string &rowStr);
	public:
	static cmdCtx parser(Client *client, std::string &rowCmd);
};



class ACmd
{
	protected:
		Server &server;
		bool reqRegister;

	public:
		static std::vector split(std::string &str, char del);
		ACmd(Server &server, bool reqRegister);
		virtual void execute(cmdCtx &ctx) = 0;
};

class JoinCmd : public ACmd // almost finish
{
	private:
		void creatNewChannel(Client *client, std::string &channelName);
		bool isValidChannelName(std::string& name);
		void joinChannel(cmdCtx &ctx);

	public:
		JoinCmd(Server &Server);
		void execute(cmdCtx &ctx);

};

class PrvmsgCmd : public ACmd
{
	private:
		/* data */
	public:
		PrvmsgCmd(Server &Server);
		void execute(cmdCtx &ctx);
};

class PartCmd : public ACmd //almost finish
{
	private:
		/* data */
	public:
		PartCmd(Server &Server);
		void execute(cmdCtx &ctx);
};

class KickCmd : public ACmd
{
	private:
		/* data */
	public:
		KickCmd(Server &Server);
		void execute(cmdCtx &ctx);
};

class ModeCmd : public ACmd
{
	private:
		/* data */
	public:
		ModeCmd(Server &Server);
		void execute(cmdCtx &ctx);
};

class InviteCmd : public ACmd
{
	private:
		/* data */
	public:
		InviteCmd(Server &Server);
		void execute(cmdCtx &ctx);
};

class TopicCmd : public ACmd
{
	private:
		/* data */
	public:
		TopicCmd(Server &Server);
		void execute(cmdCtx &ctx);
};



