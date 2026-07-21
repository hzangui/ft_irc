#include "../../include/Cmd.hpp"


ACmd::ACmd(Server &server, bool reqRegister) : server(server), reqRegister(reqRegister)
{
}

JoinCmd::JoinCmd(Server &Server) : ACmd(Server, true)
{}



