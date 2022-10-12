#pragma once
#include <string>
using namespace std;
class MyException
{
private:
    string message;

public:
    MyException(string message)
    {
        this->message = message;
    }
    string getMessage()
    {
        return this->message;
    }
};