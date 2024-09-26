#include "Client.h"

using namespace std;
#define port 8080
// Public member functions
Client::Client()
{
  clientSocket = socket(AF_INET, SOCK_STREAM, 0);
  if (clientSocket < 0)
  {
    cerr << "Error: Could not create socket" << endl;
    exit(EXIT_FAILURE);
  }
  serverAddress = new sockaddr_in;
  this->serverAddress->sin_addr.s_addr = INADDR_ANY; // Make it listen to all IPs
  this->serverAddress->sin_family = AF_INET;
  this->serverAddress->sin_port = htons(port);
  // probably the ip address for the moment is irrelevant

  // get ready to make a connection
}

int Client::establishConnectionWithServer() const
{
  {
    // Attempt to connect the client socket to the server
    int connectionStatus = connect(clientSocket, (struct sockaddr *)serverAddress, sizeof(*serverAddress));

    // Check if connection was successful
    if (connectionStatus < 0)
    {
      cerr << "Error: Could not connect to server" << endl;
      return -1; // Return an error code
    }

    cout << "Connected to server successfully" << endl;
    return 0; // Return success
  }
  const char *message = "Hello, server!";
  send(clientSocket, message, strlen(message), 0);
}
Request* Client::makeGetRequest() const
{
  string uri;
  cout << "Insert the URI :" << endl;
  cin >> uri;
  Request* request= new Request("GET",uri);
  return request;
}
// int Client::sendRequest(Request &request) const
// {
// }
// void Client::readResponse(Response &response) const
// {
// }

Client::~Client()
{
  close(clientSocket);
  delete serverAddress;
}
