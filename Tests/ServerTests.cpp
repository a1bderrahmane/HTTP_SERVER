#include <iostream>
#include "../Client/Client.h"
#include "../Server/Server.h"
using namespace std;
int main()
{
    Server server;
    int socket = server.establishConnectionWithClient();
    Request request =server.receiveRequest(socket);
    cout<<request.getMethod()<<endl;
    cout<<request.getURI()<<endl;
    server.makeResponse(request,socket);
    return 0;
}