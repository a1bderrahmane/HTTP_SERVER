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
Request::~Request()
{
}
