#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class AbstractClass
{
public:
    virtual void PrimitiveOperation1() = 0;
    virtual void PrimitiveOperation2() = 0;

    void TemplateMethod()
    {
        PrimitiveOperation1();
        PrimitiveOperation2();
        cout << "" << endl;
    }
};

class ConcreteClassA : public AbstractClass
{
    public:
    void PrimitiveOperation1() override
    {
        cout << "������A����1ʵ��"<< endl;
    }
    void PrimitiveOperation2() override
    {
        cout << "������A����2ʵ��"<< endl;
    }
};


class ConcreteClassB : public AbstractClass
{
    public:
    void PrimitiveOperation1() override
    {
        cout << "������B����1ʵ��"<< endl;
    }
    void PrimitiveOperation2() override
    {
        cout << "������B����2ʵ��"<< endl;
    }
};

