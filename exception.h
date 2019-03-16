#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>
#include <string>

using namespace std;


class Exception: public exception
{
private:
    string message;
public:
    Exception(const string &mess): message(mess) {}

    virtual const char* what()
    {
        return message.c_str();
    }
};

#endif // EXCEPTION_H
