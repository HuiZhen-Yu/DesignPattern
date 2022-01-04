#pragma once
#include <iostream>
#include <memory>

using std::cout;
using std::endl;

// subject�࣬������RealSubject��Proxy�Ĺ��ýӿڣ����������κ�ʹ��RealSubject�ĵͰ�ʹ��Proxy
class Subject
{
public:
	virtual void Request() = 0;
	virtual ~Subject() = default;
};

// RealSubject�࣬����Proxy���������ʵʵ��
class RealSubject : Subject
{
public:
	void Request() override
	{
		cout << "��ʵ������" << endl;
	}
};

// Proxy�࣬����һ������ʹ�ô�����Է���ʵ�壬���ṩһ����Subject�Ľӿ���ͬ�Ľӿڣ���������Ϳ�����������ʵ��
class Proxy : public Subject
{
private:
	RealSubject *realSubject;

public:
	void Request() override
	{
		if (realSubject == nullptr)
		{
			realSubject = new RealSubject();
		}

		realSubject->Request();
	}
	~Proxy()
	{
		delete realSubject;
	}
};

#if 0
	//�ͻ��˴���
	Proxy proxy = new Proxy;
	proxy.Request();
#endif
