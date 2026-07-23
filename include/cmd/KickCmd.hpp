#pragma once

class KickCmd : public ACmd
{
	private:
		/* data */
	public:
		KickCmd(Server &Server);
		void execute(cmdCtx &ctx);
};