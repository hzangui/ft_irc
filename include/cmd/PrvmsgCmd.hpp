#pragma once

#include "ACmd.hpp"


class PrvmsgCmd : public ACmd
{
	private:
		/* data */
	public:
		PrvmsgCmd(Server &Server);
		void execute(cmdCtx &ctx);
};
