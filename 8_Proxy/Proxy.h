#pragma once
#include <iostream>
#include <memory>

using std::cout;
using std::endl;

// subject类，定义了RealSubject和Proxy的共用接口，这样就在任何使用RealSubject的低昂使用Proxy
class Subject
{
public:
	virtual void Request() = 0;
	virtual ~Subject() = default;
};

// RealSubject类，定义Proxy所代表的真实实体
class RealSubject : Subject
{
public:
	void Request() override
	{
		cout << "真实的请求" << endl;
	}
};

// Proxy类，保存一个引用使得代理可以访问实体，并提供一个与Subject的接口相同的接口，这样代理就可以用来代替实体
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
	//客户端代码
	Proxy proxy = new Proxy;
	proxy.Request();
#endif
