#pragma once
#include <memory>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

//Component类
class Component
{
public:
	virtual void Operation() = 0;
};

//ConcreteComponent类
class ConcreteComponent : public Component
{
public:
	void Operation() override
	{
		cout << "具体对象的操作：" << endl;
	}
};

//Decorator类
class Decorator : public Component
{
protected:
	Component* component;
public:
	//设置Component
	void SetComponent(Component* component)
	{
		this->component = component;
	}
	//重写Operation(),实际执行的是component的operation()
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
		//首先运行原Component的operation()，再执行本类的功能，如addedState，相当于对原Component进行了装饰
		Decorator::Operation();
		addedState = "New State";
		cout << "具体装饰对象A的操作" << endl;
	}
private:
	//本类的独有功能，以区别于ConcreteDecoratorB
	string addedState;
};

class ConcreteDecoratorB : public Decorator
{

public:
	void Operation() override
	{
		//首先运行原Component的operation()，再执行本类的功能，如AddBehavior，相当于对原Component进行了装饰
		Decorator::Operation();
		AddBehavior();
		cout << "具体装饰对象B的操作" << endl;
	}

private:
	//本类的独有功能，以区别于ConcreteDecoratorA
	void AddBehavior()
	{

	}
};