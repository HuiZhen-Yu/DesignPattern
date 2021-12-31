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
        cout << "具体类A方法1实现"<< endl;
    }
    void PrimitiveOperation2() override
    {
        cout << "具体类A方法2实现"<< endl;
    }
};


class ConcreteClassB : public AbstractClass
{
    public:
    void PrimitiveOperation1() override
    {
        cout << "具体类B方法1实现"<< endl;
    }
    void PrimitiveOperation2() override
    {
        cout << "具体类B方法2实现"<< endl;
    }
};

