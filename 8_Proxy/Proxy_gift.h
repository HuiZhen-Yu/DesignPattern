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

//׷������
class Pursuit : public IGiveGift
{
public:
	Pursuit(SchoolGirl* mm)
	{
		this->mm = mm;
	}

	void GiveDolls() override
	{
		cout << mm->get() + " ����������" << endl;
	}

	void GiveFlovers() override
	{
		cout << mm->get() + " �����ʻ�" << endl;
	}

	void GiveChocolate() override
	{
		cout << mm->get() + " �����ɿ���" << endl;
	}

	~Pursuit() = default;

private:
	SchoolGirl* mm;
};


//������
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

