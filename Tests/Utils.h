#include <iostream>
#include <cstring>
using namespace std;
void printLog(const string& message)
{
    cout << "\033[35m"<<"LOG :" << message << "\033[0m" << endl;
}