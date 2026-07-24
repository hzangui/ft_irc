#pragma once

#include "ACmd.hpp"

class Client {};
class Channel {};

class ModeCmd : public ACmd
{
	private:
		/* data */
	public:
		ModeCmd(Server &Server);
		void execute(cmdCtx &ctx);
};