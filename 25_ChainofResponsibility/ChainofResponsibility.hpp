#ifndef CHAINOFRESPONSIBILITY_H_
#define CHAINOFRESPONSIBILITY_H_

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Handler
{
protected:
    Handler *successor = nullptr;

public:
    void SetSuccessor(Handler *successor)
    {
        this->successor = successor;
    }
    virtual void HandleRequest(int request) = 0;
    virtual ~Handler()
    {
        delete successor;
    }
};

class ConcreteHandler1 : public Handler
{
private:
    string name;

public:
    ConcreteHandler1(string name = "经理：")
        : name(name)
    {
    }
    void HandleRequest(int request) override
    {
        if (request >= 0 && request < 10)
        {
            cout << this->name << "处理请求：" << request << endl;
        }
        else if (successor != nullptr)
        {
            successor->HandleRequest(request);
        }
    }
    ~ConcreteHandler1() = default;
};

class ConcreteHandler2 : public Handler
{
private:
    string name;

public:
    ConcreteHandler2(string name = "总监：")
        : name(name)
    {
    }
    void HandleRequest(int request) override
    {
        if (request >= 10 && request < 20)
        {
            cout << this->name << "处理请求：" << request << endl;
        }
        else if (successor != nullptr)
        {
            successor->HandleRequest(request);
        }
    }
    ~ConcreteHandler2() = default;
};

class ConcreteHandler3 : public Handler
{
private:
    string name;

public:
    ConcreteHandler3(string name = "董事长：")
        : name(name)
    {
    }
    void HandleRequest(int request) override
    {
        if (request >= 20 && request < 30)
        {
            cout << this->name << "处理请求：" << request << endl;
        }
        else if (successor != nullptr)
        {
            successor->HandleRequest(request);
        }
    }
    ~ConcreteHandler3() = default;
};
#endif // !CHAINOFRESPONSIBILITY_H_