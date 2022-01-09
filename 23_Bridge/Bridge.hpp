#ifndef BRIDGE_H_
#define BRIDGE_H_

#include <iostream>
#include <string>

using namespace std;
/*
 * 实现系统可能有多角度分类，每一种分类都有可能变化，那么就把这种多角度分离出来让他们独立变化，坚守他们之间的耦合。
 * 只要真正深入理解了设计原则，很多设计模式其实就是原则的应用而已，或许在不知不觉中就在使用设计模式了
 */

class Implementor
{
public:
    virtual void Operation() = 0;
    virtual ~Implementor() = default;
};

class ConcreteImplementorA : public Implementor
{
public:
    void Operation() override
    {
        cout << "具体实现A的方法执行" << endl;
    }
};

class ConcreteImplementorB : public Implementor
{
public:
    void Operation() override
    {
        cout << "具体实现B的方法执行" << endl;
    }
};

class Abstraction
{
protected:
    Implementor *implementor;

public:
    void SetImplementor(Implementor *implementor)
    {
        this->implementor = implementor;
    }
    virtual void Operation()
    {
        implementor->Operation();
    }
    virtual ~Abstraction()
    {
        delete implementor;
    }
};

class RefinedAbstraction : public Abstraction
{
public:
    void Operation() override
    {
        implementor->Operation();
    }
};

#endif // !BRIDGE_H_