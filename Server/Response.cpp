#include "Response.h"

// Constructor
Response::Response(int statusCode, string reasonPhrase, string contentType, int contentLength, string responseBody)
    : statusCode(statusCode), reasonPhrase(reasonPhrase), contentType(contentType), contentLength(contentLength), responseBody(responseBody)
{
}
Response::Response()
{

}
// Destructor
Response::~Response() {}

// Getter for statusCode
int Response::getStatusCode()
{
    return statusCode;
}

// Getter for reasonPhrase 
string Response::getReasonPhase()
{
    return reasonPhrase;
}

// Getter for contentType
string Response::getContentType()
{
    return contentType;
}

// Getter for contentLength
int Response::getContentLength()
{
    return contentLength;
}

// Getter for responseBody
string Response::getResponseBody()
{
    return responseBody;
}

// Setter for statusCode
void Response::setStatusCode(int code)
{
    statusCode = code;
}

// Setter for reasonPhrase 
void Response::setReasonPhrase(string phrase)
{
    reasonPhrase = phrase;
}

// Setter for contentType
void Response::setContentype(string type)
{
    contentType = type;
    // Optionally update contentLength based on the body
    contentLength = responseBody.length();
}

// Setter for responseBody
void Response::setResponseBody(string body)
{
    responseBody = body;
    contentLength = body.length(); // Automatically set contentLength when the body is set
}
