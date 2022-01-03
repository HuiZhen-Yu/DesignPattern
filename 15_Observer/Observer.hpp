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

//�۲���ģʽ����ʵ�� 

// Observer�����۲��ߣ�Ϊ���еľ���۲��߶���һ���ӿڣ��ڵõ������֪ͨʱ�����Լ�������ӿڽ������½ӿڡ�
//����۲���һ����һ�����������һ���ӿ�ʵ�֡����½ӿ�ͨ������һ��Update()��������������������·���

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
    //���ӹ۲���
    void Attach(const string &name, Observer *observer)
    {
        //observers1.push_back(observer);
        observers.insert({name, observer});
    }
    //�Ƴ��۲���
    void Detach(const string &name)
    {
        observers.erase(name);
        //observers1.pop_back();
    }
    //֪ͨ
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
    //���屻�۲���״̬
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
        cout << "�۲��� " << name << " ����״̬��: " << observerState << endl;
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