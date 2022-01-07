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
    /* 其他成员 */

public:
    void setup()
    {
    }
    static Singleton getInstance();
    /* 其他成员 */
};

Singleton Singleton::getInstance()
{
    static Singleton sig;
    return sig;
}


#endif