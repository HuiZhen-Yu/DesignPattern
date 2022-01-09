#ifndef BRIDGE_H_
#define BRIDGE_H_

#include <iostream>
#include <string>

using namespace std;
/*
 * ʵ��ϵͳ�����ж�Ƕȷ��࣬ÿһ�ַ��඼�п��ܱ仯����ô�Ͱ����ֶ�Ƕȷ�����������Ƕ����仯����������֮�����ϡ�
 * ֻҪ����������������ԭ�򣬺ܶ����ģʽ��ʵ����ԭ���Ӧ�ö��ѣ������ڲ�֪�����о���ʹ�����ģʽ��
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
        cout << "����ʵ��A�ķ���ִ��" << endl;
    }
};

class ConcreteImplementorB : public Implementor
{
public:
    void Operation() override
    {
        cout << "����ʵ��B�ķ���ִ��" << endl;
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