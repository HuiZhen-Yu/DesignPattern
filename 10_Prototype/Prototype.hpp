#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

//原型类
class Prototype
{
private:
    string id;

public:
    Prototype(const string &id) : id(id) {}
    string &get()
    {
        return id;
    }
    virtual Prototype *Clone() = 0;
};

//具体原型类
class ConcretePrototype1 : public Prototype
{
public:
    ConcretePrototype1(const string &id)
        : Prototype(id)
    {
    }

    Prototype *Clone() override
    {
        return (Prototype *)new ConcretePrototype1(get());

    }
};
