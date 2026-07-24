#pragma once

#include "ACmd.hpp"


class TopicCmd : public ACmd
{
	private:
		/* data */
	public:
		TopicCmd(Server &Server);
		void execute(cmdCtx &ctx);
};