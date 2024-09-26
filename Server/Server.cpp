#include "Server.h"
#include "Request.h"
#include "../Client/Request.h"

#define port 8080
Server::Server()
{
    // creating server socket
    // AF_INET: using IPV4 protocol family
    // SOCK_STREAM : using TCP type socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0); // return file descriptor
    if (serverSocket < 0)
    {
        cerr << "Error: Could not create socket" << endl;
        exit(EXIT_FAILURE);
    }
    serverAddress = new sockaddr_in;
    this->serverAddress->sin_addr.s_addr = INADDR_ANY; // Make it listen to all IPs
    this->serverAddress->sin_family = AF_INET;
    this->serverAddress->sin_port = htons(port);
    bind(serverSocket, (struct sockaddr *)serverAddress, sizeof(*serverAddress));
}
int Server::establishConnectionWithClient() const
{
    listen(serverSocket, 5); // listening to the assigned socket

    sockaddr_in clientAddress;                          // Structure to hold client's address (IPv4)
    socklen_t clientAddressLen = sizeof(clientAddress); // Size of the address structure

    int clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddress, &clientAddressLen);

    char clientIP[INET_ADDRSTRLEN]; // Buffer to hold the IP address in string form

    // Convert the client's IP address from numeric form to readable form
    inet_ntop(AF_INET, &clientAddress.sin_addr, clientIP, INET_ADDRSTRLEN);

    int clientPort = ntohs(clientAddress.sin_port); // Convert the client's port number from network to host byte order

    cout << "Client connected: IP = " << clientIP << ", Port = " << clientPort << endl;

    return clientSocket;
}
Request Server::receiveRequest(int clientSocket) const
{
    // recieving data
    Request request;

    char buffer[1024] = {0};
    int received = recv(clientSocket, buffer, sizeof(buffer), 0);
    if (received == -1)
    {
        cerr << "Error encoutered when trying to receive from client" << endl;
        return request;
    }
    cout << "Message from client: " << buffer << endl;
    int method = int(buffer[0]) - int('0');
    string HTTPmethod;
    if (method == 0)
    {
        HTTPmethod = "GET";
    }
    string uri = string(buffer + 1);
    request.setURI(uri);
    request.setMethod(HTTPmethod);
    return request;
}
// int Server:: sendResponse(Response &response) const
// {
// }
int Server::sendResponse(int clientSocket, Response &response) const
{
    string httpResponse;
    httpResponse += response.getResponseBody();
    const char *message = httpResponse.c_str();
    std::cout << "About to send: " << message << std::endl;
    ssize_t bytesSent = send(clientSocket, message, strlen(message), 0);
    if (bytesSent == -1)
    {
        std::cerr << "Error: Failed to send response to client" << std::endl;
        return -1; // Return failure
    }
    std::cout << "Sent " << bytesSent << " bytes to the client." << std::endl;

    return 0; // Return success
}

void Server::makeResponse(Request request, int clientSocket) const
{
    string HTTPmethod = request.getMethod();

    if (HTTPmethod == "GET")
    {
        string filePath = "../Server/Data/simpleHTML.html";
        // cout<<"file path ="<< filePath<<endl;
        ifstream file(filePath);
        // Create a Response object (preferably on the stack)
        Response response;
        // Check if the file can be opened
        if (!file.is_open())
        {
            // If the file can't be opened, send a 404 response
            response.setStatusCode(404);
            response.setReasonPhrase("Not Found");
            response.setContentype("text/plain");
            response.setResponseBody("404 Not Found");
            sendResponse(clientSocket, response);
            return;
        }

        // File opened successfully, build the response body
        string line;
        string responseBody = "";

        // Read the file line by line and accumulate the contents
        while (getline(file, line))
        {
            responseBody += line + "\n";
        }

        // Set the response fields
        response.setStatusCode(200);
        response.setReasonPhrase("OK");
        response.setContentype("text/html"); // Assuming an HTML file
        response.setResponseBody(responseBody);

        // Send the response
        // cout << "sending this :";
        // cout << responseBody << endl;
        sendResponse(clientSocket, response);

        // Close the file
        file.close();
    }
    else
    {
        // Handle other HTTP methods (e.g., POST) or send a 405 Method Not Allowed response
        Response response;
        response.setStatusCode(405);
        response.setReasonPhrase("Method Not Allowed");
        response.setContentype("text/plain");
        response.setResponseBody("405 Method Not Allowed");
        sendResponse(clientSocket, response);
    }
}

Server::~Server()
{
    close(serverSocket);

    delete serverAddress;
}
int Server::getServerSocket() const
{
    return serverSocket;
}