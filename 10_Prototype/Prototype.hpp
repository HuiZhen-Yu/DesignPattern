#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

//ԭ����
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

//����ԭ����
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
