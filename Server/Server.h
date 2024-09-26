// Include guards to prevent multiple inclusions
#pragma once
#ifndef SERVER_H
#define SERVER_H

#include <string>
#include <iostream>
#include <vector>
#include "Response.h"
#include "../Client/Request.h"
#include "../Client/Client.h"
#include <set>
using namespace std;
class Server
{
public:
    Server();
    ~Server();
    int establishConnectionWithClient() const;
    int receiveRequest()const;
    Response makeResponse() const;
    int sendResponse(Response &response) const;
    void readRequest(Request &request) const;

private:
    int serverSocket;
    sockaddr_in *serverAddress;
    set<pair<int,string>> connectedClients;
};
#endif