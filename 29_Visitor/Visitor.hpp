#ifndef VISITOR_H_
#define VISITOR_H_

#include <iostream>
#include <string>
#include <map>

using std::cout;
using std::endl;
using std::map;
using std::pair;
using std::string;

class ConcreteElementA;
class ConcreteElementB;

class Visitor
{
public:
    virtual void VisitConcreteElementA(ConcreteElementA *concreteElementA) = 0;
    virtual void VisitConcreteElementB(ConcreteElementB *concreteElementB) = 0;
    virtual ~Visitor() = 0;
}

class ConcreteVisitor1 : public Visitor
{
public:
    void VisitConcreteElementA(ConcreteElementA *concreteElementA)
    {
        cout << "CA访问C1" << endl;
    }
    void VisitConcreteElementB(ConcreteElementB *concreteElementB)
    {
        cout << "CB访问C1" << endl;
    }
};

class ConcreteVisitor2 : public Visitor
{
public:
    void VisitConcreteElementA(ConcreteElementA *concreteElementA)
    {
        cout << "CA访问C2" << endl;
    }
    void VisitConcreteElementB(ConcreteElementB *concreteElementB)
    {
        cout << "CB访问C2" << endl;
    }
};

class Element
{
public:
    virtual void Accept(Visitor *visitor) = 0;
    virtual ~Element() = default;
};

class ConcreteElementA : public Element
{
public:
    void Accept(Visitor *visitor) override
    {
        visitor->VisitConcreteElementA(this);
    }
    void OperatorA()
    {
    }
};

class ConcreteElementB : public Element
{
public:
    void Accept(Visitor *visitor) override
    {
        visitor->VisitConcreteElementB(this);
    }
    void OperatorB()
    {
    }
};

class ObjectStructure
{
private:
    map<string, Element *> elements;

public:
    void Attach(string name, Element *element)
    {
        elements.insert(pair<string, Element *>(name, element));
    }
    void Detach(string name)
    {
        elements.erase(name);
    }
    void Accetp(Visitor *visitor)
    {
        for (auto i : elements)
        {
            i.second->Accept(visitor);
        }
    }
};

#endif // !VISITOR_H_