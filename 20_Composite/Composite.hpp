#ifndef COMPOSITE_H_
#define COMPOSITE_H_

#include <iostream>
#include <string>
#include <map>
#include <vector>

using std::cout;
using std::endl;
using std::map;
using std::pair;
using std::string;
using std::vector;

class Component
{
protected:
    string name;

public:
    Component(const string &name)
        : name(name)
    {
    }
    string get_name()
    {
        return name;
    }
    virtual void Add(Component *c) = 0;
    virtual void Remove(Component *c) = 0;
    virtual void Display(int depth) = 0;
    virtual ~Component(){};
};

class Leaf : public Component
{
public:
    Leaf(const string &name)
        : Component(name)
    {
    }
    void Add(Component *c) override
    {
        cout << "Cannot add to a leaf" << endl;
    }
    void Remove(Component *c) override
    {
        cout << "Cannot remove from a leaf" << endl;
    }
    void Display(int depth) override
    {
        cout << string(depth, '-') << " " << name << endl;
    }
};

class Composite : public Component
{
private:
    map<string, Component *> children;
    vector<string> names;

public:
    Composite(const string &name)
        : Component(name)
    {
    }
    void Add(Component *c) override
    {
        names.push_back(c->get_name());
        children.insert(pair<string, Component *>(c->get_name(), c));
    }
    void Remove(Component *c) override
    {
        children.erase(c->get_name());
    }
    void Display(int depth) override
    {
        cout << string(depth, '-') << " " << name << endl;
        for (auto i : names)
        {
            children[i]->Display(depth + 2);
        }
    }
    ~Composite() override
    {
        cout << "执行析构函数" << endl;
        for (auto i : names)
        {
            cout << "释放: " << i << endl;
            delete children[i];
        }
    }
};

#endif // !COMPOSITE_H_