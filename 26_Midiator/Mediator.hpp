#ifndef MEDIATOR_H_
#define MEDIATOR_H_

#include <iostream>
#include <string>

using namespace std;

class Colleague;

class Mediator
{
public:
    virtual void Send(string message, Colleague *colleague) = 0;
    virtual ~Mediator() = default;
};

class Colleague
{
protected:
    Mediator *mediator;

public:
    Colleague(Mediator *mediator)
        : mediator(mediator)
    {
    }
    virtual ~Colleague() = default;
};

class ConcreteColleague1 : public Colleague
{
public:
    ConcreteColleague1(Mediator *mediator)
        : Colleague(mediator)
    {
    }
    void Send(string message)
    {
        mediator->Send(message, this);
    }
    void Notify(string message)
    {
        cout << "同事1得到消息：" << message << endl;
    }
};

class ConcreteColleague2 : public Colleague
{
public:
    ConcreteColleague2(Mediator *mediator)
        : Colleague(mediator)
    {
    }
    void Send(string message)
    {
        mediator->Send(message, this);
    }
    void Notify(string message)
    {
        cout << "同事2得到消息：" << message << endl;
    }
};

class ConcreteMediator : public Mediator
{
private:
    ConcreteColleague1 *colleague1;
    ConcreteColleague2 *colleague2;

public:
    void set_c1(ConcreteColleague1 *c1)
    {
        colleague1 = c1;
    }
    void set_c2(ConcreteColleague2 *c2)
    {
        colleague2 = c2;
    }
    void Send(string message, Colleague *colleague)
    {
        if (colleague == colleague1)
        {
            colleague2->Notify(message);
        }
        else
        {
            colleague1->Notify(message);
        }
    }
};

#endif // !MEDIATOR_H_