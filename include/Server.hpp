#pragma once

#include <map>
#include <string>

class Client;
class Channel;
class ACmd;

class Server
{
private:

    //==========================
    // Network
    //==========================

    int _listenFd;
    int _epollFd;
    int _port;

    std::string _password;

    //==========================
    // Clients
    //==========================

    std::map<int, Client*> _clientsByFd;
    std::map<std::string, Client*> _clientsByNick;

    //==========================
    // Channels
    //==========================

    std::map<std::string, Channel*> _channels;

    //==========================
    // Commands
    //==========================

    std::map<std::string, ACmd*> _commands;

public:

    Server(int port, const std::string &password);
    ~Server();

    //==========================
    // Command dispatcher
    //==========================

    void dispatchCommand(Client *client,
                         const std::string &command);

    //==========================
    // Client lookup
    //==========================

    Client *findClient(int fd) const;

    Client *findClient(const std::string &nick) const;

    bool nicknameExists(const std::string &nick) const;

    //==========================
    // Channel lookup
    //==========================

    Channel *findChannel(const std::string &name) const;

    bool channelExists(const std::string &name) const;

    Channel *createChannel(const std::string &name);

    void removeChannel(Channel *channel);

    //==========================
    // Getters
    //==========================

    const std::string &getPassword() const;
};