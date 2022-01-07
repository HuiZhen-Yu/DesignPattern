#ifndef SINGLENTEN_H_
#define SINGLENTEN_H_

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Singleton
{
private:
    Singleton();
    Singleton(const Singleton &rhs);
    /* ������Ա */

public:
    void setup()
    {
    }
    static Singleton getInstance();
    /* ������Ա */
};

Singleton Singleton::getInstance()
{
    static Singleton sig;
    return sig;
}


#endif