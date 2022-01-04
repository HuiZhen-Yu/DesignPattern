#ifndef ADAPTER_H_
#define ADAPTER_H_

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Target
{
public:
    virtual void Request()
    {
        cout << "普通请求！" << endl;
    }
    virtual ~Target() = default;
};

class Adaptee
{
public:
    void SpecificRequest()
    {
        cout << "特殊请求！" << endl;
    }
};

class Adapter : public Target
{
private:
    Adaptee *adaptee = new Adaptee();

public:
    void Request()
    {
        adaptee->SpecificRequest();
    }
    ~Adapter()
    {
        delete adaptee;
    }
};
#endif // ! ADAPTER_H_