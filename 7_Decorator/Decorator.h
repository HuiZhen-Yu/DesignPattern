#pragma once
#include <memory>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

//Component��
class Component
{
public:
	virtual void Operation() = 0;
};

//ConcreteComponent��
class ConcreteComponent : public Component
{
public:
	void Operation() override
	{
		cout << "�������Ĳ�����" << endl;
	}
};

//Decorator��
class Decorator : public Component
{
protected:
	Component* component;
public:
	//����Component
	void SetComponent(Component* component)
	{
		this->component = component;
	}
	//��дOperation(),ʵ��ִ�е���component��operation()
	void Operation() override
	{
		component->Operation();
	}
};

class ConcreteDecoratorA : public Decorator
{

public:
	void Operation() override
	{
		//��������ԭComponent��operation()����ִ�б���Ĺ��ܣ���addedState���൱�ڶ�ԭComponent������װ��
		Decorator::Operation();
		addedState = "New State";
		cout << "����װ�ζ���A�Ĳ���" << endl;
	}
private:
	//����Ķ��й��ܣ���������ConcreteDecoratorB
	string addedState;
};

class ConcreteDecoratorB : public Decorator
{

public:
	void Operation() override
	{
		//��������ԭComponent��operation()����ִ�б���Ĺ��ܣ���AddBehavior���൱�ڶ�ԭComponent������װ��
		Decorator::Operation();
		AddBehavior();
		cout << "����װ�ζ���B�Ĳ���" << endl;
	}

private:
	//����Ķ��й��ܣ���������ConcreteDecoratorA
	void AddBehavior()
	{

	}
};