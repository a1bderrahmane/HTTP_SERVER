#include "Request.h"
using namespace std;
Request::Request(string method, string uri, string host , string contentType, int contentLength , string requestBody )
{
    method = method;
    uri = uri;
    host = host;
    contentType = contentType;
    contentLength = contentLength;
    requestBody=requestBody;
}
Request::Request()
{
    
}
// Getters
string Request::getMethod() const {
    return method;
}

string Request::getURI() const {
    return uri;
}

string Request::getHost() const {
    return host;
}

string Request::getcontentType() const {
    return contentType;
}

int Request::getContentLength() const {
    return contentLength;
}

string Request::getRequestBody() const {
    return requestBody;
}

// Setters
void Request::setMethod(string method) {
    this->method = method;
}

void Request::setURI(string uri) {
    this->uri = uri;
}

void Request::setHost(string host) {
    this->host = host;
}

void Request::setContentType(string type) {
    this->contentType = type;
}

void Request::setContentLength(int length) {
    this->contentLength = length;
}

void Request::setRequestBody(string body) {
    this->requestBody = body;
}
Request::~Request()
{
}
