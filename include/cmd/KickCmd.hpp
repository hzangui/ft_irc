#pragma once

#include "ACmd.hpp"

class Client {};
class Channel {};

class KickCmd : public ACmd
{
	private:
		/* data */
	public:
		KickCmd(Server &Server);
		void execute(cmdCtx &ctx);
};