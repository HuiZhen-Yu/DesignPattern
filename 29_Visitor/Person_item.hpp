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
    //�õ��Ľ��ۻ��߷�Ӧ
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
        cout << "Man�ɹ�ʱ����������һ��ΰ���Ů�ˡ�" << endl;
    }
    void GetWomanConclosion(Women *ConcreteElement) override
    {
        cout << "Woman�ɹ�ʱ����������һ�����ɹ������ˡ�" << endl;
    }
};

class Failing : public Action
{
public:
    void GetManConclosion(Man *ConcreteElement) override
    {
        cout << "Manʧ��ʱ����ͷ�Ⱦƣ�˭Ҳ����Ȱ��" << endl;
    }
    void GetWomanConclosion(Women *ConcreteElement) override
    {
        cout << "Womanʧ��ʱ��������������˭ҲȰ���ˡ�" << endl;
    }
};

class Amativeness : public Action
{
public:
    void GetManConclosion(Man *ConcreteElement) override
    {
        cout << "Man����ʱ�����ǲ���ҲҪװ����" << endl;
    }
    void GetWomanConclosion(Women *ConcreteElement) override
    {
        cout << "Woman����ʱ�����¶�Ҳװ������" << endl;
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