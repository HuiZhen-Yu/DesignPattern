#pragma once
#include <iostream>
#include <string>
#include <memory>

using std::cout;
using std::endl;
using std::string;
using std::shared_ptr;
using std::make_shared;

class IGiveGift
{
	virtual void GiveDolls() = 0;
	virtual void GiveFlovers() = 0;
	virtual void GiveChocolate() = 0;
};

class SchoolGirl
{
private:
	string name;
public:
	SchoolGirl() = default;
	SchoolGirl(const string& value)
		:name(value)
	{	}
	string& get()
	{
		return name;
	}

	void set(const string& name)
	{
		this->name = name;
	}
};

//追求者类
class Pursuit : public IGiveGift
{
public:
	Pursuit(SchoolGirl* mm)
	{
		this->mm = mm;
	}

	void GiveDolls() override
	{
		cout << mm->get() + " 送你洋娃娃" << endl;
	}

	void GiveFlovers() override
	{
		cout << mm->get() + " 送你鲜花" << endl;
	}

	void GiveChocolate() override
	{
		cout << mm->get() + " 送你巧克力" << endl;
	}

	~Pursuit() = default;

private:
	SchoolGirl* mm;
};


//代理类
class Proxy : public IGiveGift
{
private:
	//Pursuit* gg = nullptr;
	shared_ptr<Pursuit> gg;
public:
	Proxy(SchoolGirl* mm)
	{
		//gg = new Pursuit(mm);
		gg = make_shared<Pursuit>(mm);
	}
	
	void GiveDolls() override
	{
		gg->GiveDolls();
	}

	void GiveFlovers() override
	{
		gg->GiveFlovers();
	}

	void GiveChocolate() override
	{
		gg->GiveChocolate();
	}

	~Proxy()
	{	}
};

