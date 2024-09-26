#include <iostream>
#include "../Client/Client.h"
#include "../Server/Server.h"
using namespace std;
int main()
{
    Server server;
    server.establishConnectionWithClient();
    return 0;
}