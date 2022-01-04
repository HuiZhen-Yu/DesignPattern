#ifndef STATE_H_
#define STATE_H_

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

/* 这段代码有问题，根据我现在的能力，暂时还不能解决，留给以后的自己 */
class Context;

class State
{
public:
    virtual void Handle(Context *context) = 0;
};

class Context
{
private:
    State *state;

public:
    Context(State *sta)
    {
        state = sta;
    }
    State *get_state()
    {
        return state;
    }
    void set_state(State *sta)
    {
        state = sta;
        cout << "当前状态: " << endl;
    }
    void Request()
    {
        state->Handle(this);
    }
};

class ConcreteStateB;
class ConcreteStateA : public State
{
public:
    void Handle(Context *context) override
    {
        ConcreteStateB *cb =new ConcreteStateB(); 
        context->set_state(cb);
        //name = "stateB";
    }
};

class ConcreteStateB : public State
{
public:
    void Handle(Context *context) override
    {
        context->set_state(new ConcreteStateA());
       // name = "stateA";
    }
};

#endif // !STATE_H_