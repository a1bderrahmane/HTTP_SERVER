#pragma once
#ifndef RESPONSE_H
#define RESPONSE_H

#include <string>
#include <iostream>
using namespace std;
class Response
{
public:
    Response();

    Response(int statusCode,string seasonPhrase,string contentType,int contentLength,string responseBody);
    ~Response();
    int getStatusCode();
    string getReasonPhase();
    string getContentType();
    int getContentLength();
    string getResponseBody();

    void setStatusCode(int code);
    void setReasonPhrase(string phrase);
    void setContentype(string type);
    void setResponseBody(string body);

private:
    // Status Line
    int statusCode;
    string reasonPhrase;
    // Headers
    string contentType;
    int contentLength;

    // Body (optional)
    string responseBody;
};
#endif