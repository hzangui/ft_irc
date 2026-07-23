#pragma once

class TopicCmd : public ACmd
{
	private:
		/* data */
	public:
		TopicCmd(Server &Server);
		void execute(cmdCtx &ctx);
};