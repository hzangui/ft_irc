#include "../../include/cmd/ACmd.hpp"


ACmd::ACmd(Server &server, bool reqRegister) : server(server), reqRegister(reqRegister)
{}

std::vector<std::string> split(const std::string &str, char delim)
{
    std::vector<std::string> result;
    std::string token;

    for (size_t i = 0; i < str.size(); i++)
    {
        if (str[i] == delim)
        {
            result.push_back(token);
            token.clear();
        }
        else
            token += str[i];
    }
    result.push_back(token);

    return result;
}