#include "../../include/Cmd.hpp"


std::string Parse::tokinization(std::string &rowStr)
{
    std::string token;

    size_t pos = rowStr.find_first_not_of(" \n\t");
    if (pos == std::string::npos)
        return token;

    size_t epos = rowStr.find_first_of(" \n\t", pos);

    if (epos == std::string::npos)
    {
        token = rowStr.substr(pos);
        rowStr.clear();
        return token;
    }

    token = rowStr.substr(pos, epos - pos);
    rowStr.erase(0, epos);

    return token;
}

cmdCtx Parse::parser(Client *client, std::string &rowCmd)
{
    cmdCtx ctx;
    ctx.client = client;
    std::string token;
    size_t pos = rowCmd.find(" :");
    if (pos != std::string::npos)
    {
        ctx.lastArg = rowCmd.substr(pos + 1);
        rowCmd.erase(rowCmd.begin() + pos, rowCmd.end());
    }
    if ((ctx.cmdName = tokinization(rowCmd)) == "")
        return ctx;
    for(;true;)
    {
        if ((token = tokinization(rowCmd)) == "")
            break;
        ctx.params.push_back(token);
    }
    return ctx;
}

