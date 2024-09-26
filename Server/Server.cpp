#include "Server.h"
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
    // recieving data
    char buffer[1024] = {0};
    recv(clientSocket, buffer, sizeof(buffer), 0);
    cout << "Message from client: " << buffer
         << endl;

    return clientSocket;
}



int Server::receiveRequest()const
{

}
Server::~Server()
{
    close(serverSocket);

    delete serverAddress;
}
