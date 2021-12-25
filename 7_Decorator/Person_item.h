#pragma once
#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Person
{
public:
	Person() = default;
	Person(string name)
	{
		this->name = name;
	}

	virtual void Show()
	{
		cout << "装扮的: " + name << endl;
	}
private:
	string name;
};

//服饰类Dectorator
class Finery : public Person
{
protected:
	Person* component = nullptr;
	
public:
	void Dectorate(Person* component)
	{
		this->component = component;
	}

	void Show() override
	{
		if (component != nullptr)
		{
			component->Show();
		}
	}
};

//具体服饰类ConcreteDecorator
class TShirts : public Finery
{
public:
	void Show() override
	{
		cout << "大T恤 ";
		Finery::Show();
	}
};

class BigTrouser : public Finery
{
public:
	void Show() override
	{
		cout << "垮裤 ";
		Finery::Show();
	}
};

class WearSneakers : public Finery
{
public:
	void Show() override
	{
		cout << "破球鞋 ";
		Finery::Show();
	}
};

class WearSuit : public Finery
{
public:
	void Show() override
	{
		cout << "西装 ";
		Finery::Show();
	}
};

class WearTie : public Finery
{
public:
	void Show() override
	{
		cout << "领带 ";
		Finery::Show();
	}
};

class WearTLeatherShoes : public Finery
{
public:
	void Show() override
	{
		cout << "皮鞋 ";
		Finery::Show();
	}
};