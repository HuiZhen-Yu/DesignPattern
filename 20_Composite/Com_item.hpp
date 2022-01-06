#ifndef COM_ITEM_H_
#define COM_ITEM_H_

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

class Company
{
protected:
    string name;

public:
    Company(const string &name)
        : name(name)
    {
    }
    string get_name() const
    {
        return name;
    }
    virtual void Add(Company *c) = 0;
    virtual void Remove(Company *c) = 0;
    virtual void Display(int depth) = 0;
    virtual void LineofDuty() = 0;
    virtual ~Company() = default;
};

class ConcreteCompany : public Company
{
private:
    map<string, Company *> children;
    vector<string> names;

public:
    ConcreteCompany(const string &name)
        : Company(name)
    {
    }
    void Add(Company *c) override
    {
        names.push_back(c->get_name());
        children.insert(pair<string, Company *>(c->get_name(), c));
    }
    void Remove(Company *c) override
    {
        cout << "暂时还不能删除" << endl;
    }
    void Display(int depth)
    {
        cout << string(depth, '-') << " " << name << endl;
        for (auto i : names)
        {
            children[i]->Display(depth + 2);
        }
    }
    void LineofDuty() override
    {

        cout << name << ": " << endl;
        for (auto i : names)
        {
            children[i]->LineofDuty();
        }
    }
    ~ConcreteCompany()
    {
        cout << "执行析构函数" << endl;
        for (auto i : names)
        {
            cout << "释放: " << i << endl;
            delete children[i];
        }
    }
};

class HRDepartment : public Company
{
public:
    HRDepartment(const string &name)
        : Company(name)
    {
    }
    void Add(Company *c) override
    {
    }
    void Remove(Company *c) override
    {
    }
    void Display(int depth) override
    {
        cout << string(depth, '-') << " " << name << endl;
    }
    void LineofDuty()
    {
        cout << name << ": "
             << "员工招募培训管理" << endl;
    }
};
class FinanceDepartment : public Company
{

public:
    FinanceDepartment(const string &name)
        : Company(name)
    {
    }
    void Add(Company *c) override
    {
    }
    void Remove(Company *c) override
    {
    }
    void Display(int depth) override
    {
        cout << string(depth, '-') << " " << name << endl;
    }
    void LineofDuty()
    {
        cout << name << ": "
             << "公司财务收支管理" << endl;
    }
};

#endif