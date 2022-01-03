#include <iostream>
#include <string>
#include "Database_item.hpp"

using namespace std;

/*
 * 抽象工厂模式(Abstract Factory)：提供ige创建一系列相关或者相互依赖对象的接口，而无需指定他们具体的类。
 * 优点：
 *  1、易于交换产品系列，由于具体工厂类在一个引用中只需要在初始化的时候出现一次，这就是的改变一个引用的具体工厂变得非常容易，它只需要改变具体工厂即可使用不同的产品配置。
 *  2、它让具体的创建实例过程于客户端分离，客户端时通过他们的抽象接口操纵实例，产品的具体类名也被具体工厂的实现分离，不会出现在客户代码中。
 */

int main()
{
    User *user = new User;
    Department *department = new Department();

    IFactory *factory = new SqlServerFactory();
    IFactory *factory2 = new AccessFactory();

    IUser *iu = factory->CreateUser();
    IDepartment *id = factory2->CreateDepartment();

    iu->Insert(user);
    iu->GetUser(2);

    id->Insert(department);
    id->GetDepartment(4);
    delete user, factory, iu, department, factory2, id;

    system("pause");
    return 0;
}