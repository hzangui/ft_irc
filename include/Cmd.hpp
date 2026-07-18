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
	private:
		Server &server;
		bool reqRegister;

	public:
		ACmd(Server &server, bool reqRegister);
		virtual void execute(cmdCtx &ctx) = 0;
};

class JoinCmd : public ACmd
{
	private:
		/* data */
	public:
		JoinCmd(Server &Server, bool reqRegister);
		void execute(cmdCtx &ctx);

};

class PrvmsgCmd : public ACmd
{
	private:
		/* data */
	public:
		PrvmsgCmd(Server &Server, bool reqRegister);
		void execute(cmdCtx &ctx);
};

class PartCmd : public ACmd
{
	private:
		/* data */
	public:
		PartCmd(Server &Server, bool reqRegister);
		void execute(cmdCtx &ctx);
};

class KickCmd : public ACmd
{
	private:
		/* data */
	public:
		KickCmd(Server &Server, bool reqRegister);
		void execute(cmdCtx &ctx);
};

class ModeCmd : public ACmd
{
	private:
		/* data */
	public:
		ModeCmd(Server &Server, bool reqRegister);
		void execute(cmdCtx &ctx);
};

class InviteCmd : public ACmd
{
	private:
		/* data */
	public:
		InviteCmd(Server &Server, bool reqRegister);
		void execute(cmdCtx &ctx);
};

class TopicCmd : public ACmd
{
	private:
		/* data */
	public:
		TopicCmd(Server &Server, bool reqRegister);
		void execute(cmdCtx &ctx);
};



