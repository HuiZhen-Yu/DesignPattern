#ifndef BASKET_ADAPTER_H_
#define BASKET_ADAPTER_H_

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

//球员
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

//前锋
class Forwards : public Player
{
public:
    Forwards(const string &name) : Player(name)
    {
    }
    void Attack() override
    {
        cout << "前锋 " << name << " 进攻" << endl;
    }
    void Defence() override
    {
        cout << "前锋 " << name << " 防守" << endl;
    }
    ~Forwards() = default;
};

//中锋
class Center : public Player
{
public:
    Center(const string &name) : Player(name)
    {
    }
    void Attack() override
    {
        cout << "中锋 " << name << " 进攻" << endl;
    }
    void Defence() override
    {
        cout << "中锋 " << name << " 防守" << endl;
    }
    ~Center() = default;
};

//后卫
class Guards : public Player
{
public:
    Guards(const string &name) : Player(name)
    {
    }
    void Attack() override
    {
        cout << "后卫 " << name << " 进攻" << endl;
    }
    void Defence() override
    {
        cout << "后卫 " << name << " 防守" << endl;
    }
    ~Guards() = default;
};

//外籍中锋
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
        cout << "外籍中锋 " << name << " 进攻" << endl;
    }
    void Back()
    {
        cout << "外籍中锋 " << name << " 防守" << endl;
    }
};

//翻译者类
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