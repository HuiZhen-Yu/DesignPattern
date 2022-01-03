#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

//�۲���ģʽӦ��ʵ��
class Observer;

class Subject
{
public:
    virtual void Attach(Observer *observer) = 0;
    virtual void Detach(Observer *obserner) = 0;
    virtual void Notify() = 0;
    void set(const string &sub)
    {
        SubjectState = sub;
    }
    string &get()
    {
        return SubjectState;
    }

private:
    string SubjectState;
};

class Observer
{
protected:
    string name;
    Subject *sub;

public:
    Observer(const string &name, Subject *sub)
        : name(name), sub(sub)
    {
    }
    virtual void Update() = 0;
};

class Boss : public Subject
{
private:
    vector<Observer *> observers;
    string action;
    string SubjectState;

public:
    string &get()
    {
        return action;
    }
    void set(const string &value)
    {
        action = value;
    }
    void Attach(Observer *observer) override
    {
        observers.push_back(observer);
    }
    void Detach(Observer *observer) override
    {
        observers.pop_back();
    }
    //����֮ǰһ��Ҫ���������������ֻ�������ͨ����û��
    void Notify() override
    {
        for (auto * i : observers)
            i->Update();
    }
};

// class Secretary: public Subject
// {
// private:
//     vector<Observer *> observers;
//     string action;
//     string SubjectState;

// public:
//     string &get()
//     {
//         return action;
//     }
//     void set(const string &value)
//     {
//         action = value;
//     }
//     void Attach(Observer *observer)
//     {
//         observers.push_back(observer);
//     }
//     void Detach(Observer *observer)
//     {
//         observers.pop_back();
//     }
//     void Notify()
//     {
//         for (auto i : observers)
//             i->Update();
//     }
// };



class StockObserver : public Observer
{
public:
    StockObserver(const string &name, Subject *sub)
        : Observer(name, sub)
    {
    }
    void Update() override
    {
        cout << sub->get() << " " << name << "�رչ�Ʊ���飬������ȥ����" << endl;
    }
};

class NBAObserver : public Observer
{
public:
    NBAObserver(const string &name, Subject *sub)
        : Observer(name, sub)
    {
    }
    void Update() override
    {
        cout << sub->get() << " " << name << "�ر�NBAֱ����������ȥ����" << endl;
    }
};
#endif