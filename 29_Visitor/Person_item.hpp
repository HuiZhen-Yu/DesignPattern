#ifndef PERSION_ITEM_H_
#define PERSION_ITEM_H_

#include <iostream>
#include <string>
#include <map>

using std::cout;
using std::endl;
using std::map;
using std::pair;
using std::string;

class Man;
class Women;

class Action
{
    //得到的结论或者反应
public:
    virtual void GetManConclosion(Man *ConcreteElement) = 0;
    virtual void GetWomanConclosion(Women *ConcreteElement) = 0;
    virtual ~Action() = default;
};

class Success : public Action
{
public:
    void GetManConclosion(Man *ConcreteElement) override
    {
        cout << "Man成功时，背后多半有一个伟大的女人。" << endl;
    }
    void GetWomanConclosion(Women *ConcreteElement) override
    {
        cout << "Woman成功时，背后大多有一个不成功的男人。" << endl;
    }
};

class Failing : public Action
{
public:
    void GetManConclosion(Man *ConcreteElement) override
    {
        cout << "Man失败时，闷头喝酒，谁也不用劝。" << endl;
    }
    void GetWomanConclosion(Women *ConcreteElement) override
    {
        cout << "Woman失败时，两眼泪汪汪，谁也劝不了。" << endl;
    }
};

class Amativeness : public Action
{
public:
    void GetManConclosion(Man *ConcreteElement) override
    {
        cout << "Man恋爱时，凡是不懂也要装懂。" << endl;
    }
    void GetWomanConclosion(Women *ConcreteElement) override
    {
        cout << "Woman恋爱时，遇事懂也装不懂。" << endl;
    }
};

class Person
{
public:
    virtual void Accept(Action *visitor) = 0;
    virtual ~Person() = default;
};

class Man : public Person
{
private:
    string name = "Man";

public:
    void Accept(Action *visitor) override
    {
        visitor->GetManConclosion(this);
    }
};

class Women : public Person
{
private:
    string name = "Woman";

public:
    void Accept(Action *visitor) override
    {
        visitor->GetWomanConclosion(this);
    }
};

class ObjectStructure
{
private:
    map<string, Person *> elements;

public:
    void Attach(string name, Person *person)
    {
        elements.insert(pair<string, Person *>(name, person));
    }
    void Detach(string name)
    {
        elements.erase(name);
    }
    void Display(Action *visitor)
    {
        for(auto i: elements)
        {
            i.second->Accept(visitor);
        }
    }
    ~ObjectStructure()
    {
        for(auto i: elements)
        {
            delete i.second;
        }
    }
};

#endif