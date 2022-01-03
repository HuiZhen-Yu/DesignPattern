#ifndef OPTIMIZESIMPLEFACTORY_H_
#define OPTIMIZESIMPLEFACTORY_H_

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

/*
 * ʹ�ü򵥹����Ľ����󹤳�
 */

class User
{
private:
    int _id;
    string name;

public:
    int get_id()
    {
        return _id;
    }
    void set_id(int value)
    {
        _id = value;
    }

    string &get_name()
    {
        return name;
    }
    void set_name(const string &name)
    {
        this->name = name;
    }
};

class IUser
{
public:
    virtual void Insert(User *user) = 0;
    virtual User *GetUser(int id) = 0;
};

// SqlserverUser�࣬���ڷ���SQL Server��User
class SqlserverUser : public IUser
{
public:
    void Insert(User *user) override
    {
        cout << "��SQL Server�и�User�����һ����¼" << endl;
    }
    User *GetUser(int id) override
    {
        cout << "��SQL Server�и���ID�õ�User���һ����¼: "
             << "ID = " << id << endl;
        return nullptr;
    }
};

// AccessUser�࣬���ڷ���Access��User
class AccessUser : public IUser
{
public:
    void Insert(User *user) override
    {
        cout << "��Access�и�User�����һ����¼" << endl;
    }
    User *GetUser(int id) override
    {
        cout << "��Access�и���ID�õ�User��һ����¼: "
             << "ID = " << id << endl;
        return nullptr;
    }
};
class Department
{
private:
    int _id;
    string _deptName;

public:
    int get_id()
    {
        return _id;
    }
    void set_id(int id)
    {
        _id = id;
    }
    string &get_name()
    {
        return _deptName;
    }
    void set_name(string &name)
    {
        _deptName = name;
    };
};

class IDepartment
{
public:
    virtual void Insert(Department *dep) = 0;
    virtual Department *GetDepartment(int id) = 0;
};

// SqlserverDepartment�࣬���ڷ���SQL Server��User
class SqlserverDepartment : public IDepartment
{
public:
    void Insert(Department *dep) override
    {
        cout << "��SQL Server�и�User�����һ����¼" << endl;
    }
    Department *GetDepartment(int id) override
    {
        cout << "��SQL Server�и���ID�õ�User���һ����¼: "
             << "ID = " << id << endl;
        return nullptr;
    }
};

// AccessUser�࣬���ڷ���Access��User
class AccessDepartment : public IDepartment
{
public:
    void Insert(Department *dep) override
    {
        cout << "��Access�и�Department�����һ����¼" << endl;
    }
    Department *GetDepartment(int id) override
    {
        cout << "��Access�и���ID�õ�Department��һ����¼: "
             << "ID = " << id << endl;
        return nullptr;
    }
};

//ͨ��������������ǿ���ʵ��ҵ���߼������ݷ��ʵĽ���
class DataAccess
{
private:
    static string db;

public:
    static IUser *CreatUser()
    {
        IUser *result = nullptr;
        switch (*db.c_str())
        {
        case 'S':
            result = new SqlserverUser();
            break;
        case 'A':
            result = new AccessUser();
            break;
        default:
            break;
        }
        return result;
    }

    static IDepartment *CreatDepartment()
    {
        IDepartment *result = nullptr;
        switch (*db.c_str())
        {
        case 'S':
            result = new SqlserverDepartment();
            break;
        case 'A':
            result = new AccessDepartment();
            break;
        default:
            break;
        }
    }
};

string DataAccess::db = "Sqlserver";
// string DataAccess::db = "Access";

/*����һ��������ͨ��ģ��������switch case*/
#endif // !OPTIMIZESIMPLEFACTORY_H_