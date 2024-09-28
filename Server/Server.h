// Include guards to prevent multiple inclusions
#pragma once
#ifndef SERVER_H
#define SERVER_H

#include <string>
#include <iostream>
#include <set>
#include <vector>
#include <fstream>
#include <filesystem>
#include <unistd.h>  // For getcwd
#include <limits.h>  // For PATH_MAX
#include "Response.h"
#include "../Client/Request.h"

#include "../Client/Client.h"
using namespace std;
class Server
{
public:
    Server();
    ~Server();
    int establishConnectionWithClient() const;
    Request receiveRequest(int clientSocket) const;
    void makeResponse(Request request, int clientSocket) const;
    // int sendResponse(Response &response) const;
    int sendResponse(int clientSocket, Response &response) const;
    void readRequest(Request &request) const;
    int getServerSocket() const;

private:
    int serverSocket;
    sockaddr_in *serverAddress;
    set<pair<int, string>> connectedClients;
};
#endif