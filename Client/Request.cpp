#include "Request.h"

Request::Request(string method, string uri, string host = "", string contentType = "", int contentLength = 0, string requestBody = "")
{
    string method = method;
    string uri = uri;
    string host = host;
    string contentType = contentType;
    int contentLength = contentLength;
    string requestBody=requestBody;
}
Request::~Request()
{
}
