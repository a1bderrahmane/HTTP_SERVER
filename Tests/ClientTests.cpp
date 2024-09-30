#include <iostream>
#include <thread>
#include <mutex>
#include <queue>
#include "../Client/Client.h"
#include "../Server/Server.h"
#include "Utils.h"

using namespace std;
void clientQuery()
{
    printLog("This is the Client side");
    Client client;
    printLog("trying to connect with the server");
    client.establishConnectionWithServer();
    printLog("sending the request");
    client.makeRequest("GET");
    printLog("reading the response");
    client.readResponse();
}

int main()
{
    // thread Clientsthread[10];
    // for (int i = 0; i < 10; ++i)
    //     Clientsthread[i] = thread(clientQuery);
    // for (auto &th : Clientsthread)
    //     th.join(); // Wait for all threads to finish

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