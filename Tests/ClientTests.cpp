#include <iostream>
#include "../Client/Client.h"
#include "../Server/Server.h"
using namespace std;
int main()
{
    Client client;
    client.establishConnectionWithServer();
    client.readResponse();

    return 0;
}