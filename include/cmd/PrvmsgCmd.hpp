#pragma once

class PrvmsgCmd : public ACmd
{
	private:
		/* data */
	public:
		PrvmsgCmd(Server &Server);
		void execute(cmdCtx &ctx);
};
