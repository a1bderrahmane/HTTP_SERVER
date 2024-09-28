#include <iostream>
#include "../Client/Client.h"
#include "../Server/Server.h"
#include "Utils.h"
using namespace std;
int main()
{
    printLog("This is the Client side");
    Client client;
    printLog("trying to connect with the server");
    client.establishConnectionWithServer();
    printLog("sending the request");
    client.makeRequest("POST");
    printLog("reading the response");

    client.readResponse();

    return 0;
}