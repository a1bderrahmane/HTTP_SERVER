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
}

Request *Client::makeRequest(const string &method) const
{
  string uri;
  string message;
  Request *request = nullptr;

  if (method == "GET")
  {
    // Handle GET request
    uri = "simpleHTML.html";
    message = "0" + uri; // Prefix GET requests with "0"
    request = new Request(method, uri);
  }
  else if (method == "POST")
  {
    // Handle POST request
    uri = "experiment.txt"; // Example path where the data will be stored
    message = "1" + uri;    // Prefix POST requests with "1"

    request = new Request(method, uri);

    string bodyContent = "Experimenting with POST request";
    message += "\r\n";
    request->setRequestBody(bodyContent);
    message += bodyContent;

    // Set the appropriate content type
    request->setContentType("text/plain");
  }
  if (request == nullptr)
  {
    cerr << "Error: Unsupported HTTP method!" << endl;
    return nullptr;
  }
  cout << "i am sending :" << message << endl;
  const char *c_message = message.c_str();
  send(clientSocket, c_message, strlen(c_message), 0);

  return request;
}

int Client::readResponse() const
// socketServer=server.getServerSocket()
{
  // recieving data
  char buffer[10000] = {0};
  int received = recv(clientSocket, buffer, sizeof(buffer), 0);
  if (received == -1)
  {
    cout << "Error encoutered when trying to receive from Server" << endl;
    return received;
  }
  cout << "Message from Server: " << endl
       << buffer << endl;
  return received;
}
Client::~Client()
{
  close(clientSocket);
  delete serverAddress;
}