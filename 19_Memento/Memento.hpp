#ifndef MEMENTO_H_
#define MEMENTO_H_

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Memento
{
private:
    string state;

public:
    Memento(const string &out_state)
        : state(out_state)
    {
    }
    string get_state() const
    {
        //需要保存的数据属性，可以是多个
        return state;
    }
};

class Originator
{
private:
    string state;

public:
    string get_state() const
    {
        return state;
    }
    void set_state(const string &value)
    {
        state = value;
    }
    Memento *CreateMemento()
    {
        return (new Memento(state));
    }
    void set_memento(Memento *memento)
    {
        state = memento->get_state();
    }
    void show()
    {
        cout << "State = " << state << endl;
    }
};

//管理者类
class Caretaker
{
private:
    Memento *memento = nullptr;

public:
    Memento *get_memento()
    {
        return memento;
    }
    void set_memento(Memento *value)
    {
       delete memento;
       memento = value;
    }
};
#endif // !MEMENTO_H_