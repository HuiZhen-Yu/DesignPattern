#ifndef BASKET_ADAPTER_H_
#define BASKET_ADAPTER_H_

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

//��Ա
class Player
{
protected:
    string name;

public:
    Player(const string &name) : name(name)
    {
    }
    virtual void Attack() = 0;
    virtual void Defence() = 0;
    virtual ~Player()
    {
        
    }
};

//ǰ��
class Forwards : public Player
{
public:
    Forwards(const string &name) : Player(name)
    {
    }
    void Attack() override
    {
        cout << "ǰ�� " << name << " ����" << endl;
    }
    void Defence() override
    {
        cout << "ǰ�� " << name << " ����" << endl;
    }
    ~Forwards() = default;
};

//�з�
class Center : public Player
{
public:
    Center(const string &name) : Player(name)
    {
    }
    void Attack() override
    {
        cout << "�з� " << name << " ����" << endl;
    }
    void Defence() override
    {
        cout << "�з� " << name << " ����" << endl;
    }
    ~Center() = default;
};

//����
class Guards : public Player
{
public:
    Guards(const string &name) : Player(name)
    {
    }
    void Attack() override
    {
        cout << "���� " << name << " ����" << endl;
    }
    void Defence() override
    {
        cout << "���� " << name << " ����" << endl;
    }
    ~Guards() = default;
};

//�⼮�з�
class ForeignCenter
{
private:
    string name;

public:
    string &get_name()
    {
        return name;
    }
    void set_name(const string &name)
    {
        this->name = name;
    }
    void Forward()
    {
        cout << "�⼮�з� " << name << " ����" << endl;
    }
    void Back()
    {
        cout << "�⼮�з� " << name << " ����" << endl;
    }
};

//��������
class Translater : public Player
{
    private:
    ForeignCenter *wjzf = new ForeignCenter();
    public:
    Translater(const string & name) : Player(name)
    {
        wjzf->set_name(name);
    }
    void Attack()
    {
        wjzf->Forward();
    }
    void Defence() override
    {
        wjzf->Back();
    }
    ~Translater()
    {
        delete wjzf;
    }
};
#endif