#include <iostream>
#include <string>
#include "Database_item.hpp"

using namespace std;

/*
 * ���󹤳�ģʽ(Abstract Factory)���ṩige����һϵ����ػ����໥��������Ľӿڣ�������ָ�����Ǿ�����ࡣ
 * �ŵ㣺
 *  1�����ڽ�����Ʒϵ�У����ھ��幤������һ��������ֻ��Ҫ�ڳ�ʼ����ʱ�����һ�Σ�����ǵĸı�һ�����õľ��幤����÷ǳ����ף���ֻ��Ҫ�ı���幤������ʹ�ò�ͬ�Ĳ�Ʒ���á�
 *  2�����þ���Ĵ���ʵ�������ڿͻ��˷��룬�ͻ���ʱͨ�����ǵĳ���ӿڲ���ʵ������Ʒ�ľ�������Ҳ�����幤����ʵ�ַ��룬��������ڿͻ������С�
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