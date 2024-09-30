// Include guards to prevent multiple inclusions
#pragma once     // or use traditional include guards: #ifndef CLIENT_H
#ifndef CLIENT_H // If CLIENT_H is not defined
#define CLIENT_H
// Include necessary headers (like <string>, <vector>, etc.)
#include <string>
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include <arpa/inet.h>
#include <vector>
#include "Request.h"
#include "../Server/Response.h"
using namespace std;
class Client
{
public:
    // Public member functions
    Client();  // Constructor
    ~Client(); // Destructor

    int establishConnectionWithServer() const;
    Request *makeRequest(const string& method) const;
    Request *makePostRequest() const;
    int sendRequest(Request &request) const;
    int readResponse() const;

private:
    int clientSocket;
    sockaddr_in *serverAddress;
};
#endif // CLIENT_H
