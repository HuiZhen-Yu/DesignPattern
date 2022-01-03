#ifndef OBSERVER_H_
#define OBSERVER_H_

#include <vector>
#include <iostream>
#include <string>
#include <map>

using std::cout;
using std::endl;
using std::map;
using std::string;
using std::vector;

//观察者模式具体实例 

// Observer类抽象观察者，为所有的具体观察者定义一个接口，在得到主题的通知时更新自己，这个接口叫做更新接口。
//抽象观察者一般用一个抽象类或者一个接口实现。更新接口通常包含一个Update()方法，这个方法叫做更新方法

class Observer
{
public:
    string name;

public:
    virtual void Update() = 0;
};

class Subject
{
private:
    vector<Observer *> observers1;
    map<string, Observer*> observers;
public:
    //增加观察者
    void Attach(const string &name, Observer *observer)
    {
        //observers1.push_back(observer);
        observers.insert({name, observer});
    }
    //移除观察者
    void Detach(const string &name)
    {
        observers.erase(name);
        //observers1.pop_back();
    }
    //通知
    void Notify()
    {
        // for (auto j : observers1)
        //     j->Update();
        for (auto i = observers.begin(); i != observers.end(); ++i)
            (i->second)->Update();
    }
};


class ConcreteSubject : public Subject
{
private:
    string subjectState;
    //具体被观察者状态
public:
    string &get()
    {
        return subjectState;
    }
    void set(const string &value)
    {
        subjectState = value;
    }
};

class ConcreteObserver : public Observer
{
private:
    string name;
    string observerState;
    ConcreteSubject *subject;

public:
    ConcreteObserver(ConcreteSubject *subject, const string &name)
    {
        this->subject = subject;
        this->name = name;
    }

    void Update() override
    {
        observerState = subject->get();
        cout << "观察者 " << name << " 的新状态是: " << observerState << endl;
    }

    ConcreteSubject *Subget()
    {
        return subject;
    }

    void Subset(ConcreteSubject *value)
    {
        subject = value;
    }
};
#endif // !OBSERVER_H_