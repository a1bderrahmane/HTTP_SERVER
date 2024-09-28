#include <iostream>
#include "../Client/Client.h"
#include "../Server/Server.h"
#include "Utils.h"
using namespace std;

int main()
{
    printLog("This is the Server's side");
    Server server;
    printLog("establishing connection with the client") ;
    int socket = server.establishConnectionWithClient();
    printLog("receiving the request from the client");
    Request request =server.receiveRequest(socket);
    cout<<request.getMethod()<<endl;
    cout<<"response body :"<<request.getRequestBody()<<endl;
    printLog("sending a response to the client");
    server.makeResponse(request,socket);
    return 0;
}