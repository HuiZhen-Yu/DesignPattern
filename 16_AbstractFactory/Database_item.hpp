#ifndef DATABASE_ITEM_H_
#define DATABASE_ITEM_H_

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

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

// SqlserverUser类，用于访问SQL Server的User
class SqlserverUser : public IUser
{
public:
    void Insert(User *user) override
    {
        cout << "在SQL Server中给User表添加一条记录" << endl;
    }
    User *GetUser(int id) override
    {
        cout << "在SQL Server中根据ID得到User表的一条记录: "
             << "ID = " << id << endl;
        return nullptr;
    }
};

// AccessUser类，用于访问Access的User
class AccessUser : public IUser
{
public:
    void Insert(User *user) override
    {
        cout << "在Access中给User表添加一条记录" << endl;
    }
    User *GetUser(int id) override
    {
        cout << "在Access中根据ID得到User表一条记录: "
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
    virtual void Insert(Department * dep) = 0;
    virtual Department* GetDepartment(int id) = 0;
};

// SqlserverDepartment类，用于访问SQL Server的User
class SqlserverDepartment : public IDepartment
{
public:
    void Insert(Department * dep) override
    {
        cout << "在SQL Server中给User表添加一条记录" << endl;
    }
    Department* GetDepartment(int id) override
    {
        cout << "在SQL Server中根据ID得到User表的一条记录: "
             << "ID = " << id << endl;
        return nullptr;
    }
};

// AccessUser类，用于访问Access的User
class AccessDepartment : public IDepartment
{
public:
    void Insert(Department * dep) override
    {
        cout << "在Access中给Department表添加一条记录" << endl;
    }
    Department* GetDepartment(int id) override
    {
        cout << "在Access中根据ID得到Department表一条记录: "
             << "ID = " << id << endl;
        return nullptr;
    }
};

//通过这个工厂，我们可以实现业务逻辑于数据访问的解耦
class IFactory
{
public:
    virtual IUser *CreateUser() = 0;
    virtual IDepartment *CreateDepartment() = 0; 
};

class SqlServerFactory : public IFactory
{
public:
    IUser *CreateUser()
    {
        return new SqlserverUser();
    }
    IDepartment *CreateDepartment()
    {
        return new SqlserverDepartment();
    }
};

class AccessFactory : public IFactory
{
public:
    IUser *CreateUser()
    {
        return new AccessUser();
    }
    IDepartment *CreateDepartment()
    {
        return new AccessDepartment();
    }
};
#endif // !DATABASE_ITEM_H_