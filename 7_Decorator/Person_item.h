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
		cout << "װ���: " + name << endl;
	}
private:
	string name;
};

//������Dectorator
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

//���������ConcreteDecorator
class TShirts : public Finery
{
public:
	void Show() override
	{
		cout << "��T�� ";
		Finery::Show();
	}
};

class BigTrouser : public Finery
{
public:
	void Show() override
	{
		cout << "��� ";
		Finery::Show();
	}
};

class WearSneakers : public Finery
{
public:
	void Show() override
	{
		cout << "����Ь ";
		Finery::Show();
	}
};

class WearSuit : public Finery
{
public:
	void Show() override
	{
		cout << "��װ ";
		Finery::Show();
	}
};

class WearTie : public Finery
{
public:
	void Show() override
	{
		cout << "��� ";
		Finery::Show();
	}
};

class WearTLeatherShoes : public Finery
{
public:
	void Show() override
	{
		cout << "ƤЬ ";
		Finery::Show();
	}
};