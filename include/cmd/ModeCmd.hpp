#pragma once

class ModeCmd : public ACmd
{
	private:
		/* data */
	public:
		ModeCmd(Server &Server);
		void execute(cmdCtx &ctx);
};