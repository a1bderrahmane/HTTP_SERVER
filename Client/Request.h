// Include guards to prevent multiple inclusions
#pragma once      // or use traditional include guards: #ifndef Request_H
#ifndef REQUEST_H // If REQUEST_H is not defined
#define REQUEST_H
// Include necessary headers (like <string>, <vector>, etc.)
#include <string>
#include <iostream>
using namespace std;
class Request
{
public:
    // Public member functions
    Request(string method, string uri, string host = "", string contentType = "", int contentLength = 0, string requestBody = "");  // Constructor
    ~Request(); // Destructor

    // getters
    string getMethod()const;
    string getURI()const;
    string getHost()const;
    string getcontentType()const;
    int getContentLength()const;
    string getRequestBody()const;

    // setters
    void setMethod(string method);
    void setURI(string uri);
    void setHost(string host);
    void setContentType(string type);
    void setContentLength(int length);
    void setRequestBody(string body);

private:
    // request start line
    string method;
    string uri;
    // header
    string host;
    string contentType;
    int contentLength;
    // body
    string requestBody; // for the moment we will be dealing only with textual data
};

#endif // REQUEST_H
