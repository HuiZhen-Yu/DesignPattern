#include <iostream>
#include <string>
#include <memory>
#include "TemplateMethod.hpp"

#define PTR 0
using namespace std;
/*
* ģ�巽��ģʽ������һ�������е��㷨�ĹǼܣ�����һЩ�����ӳٵ������С�ģ�巽��ʹ��������Բ��ı�һ���㷨�Ľṹ�����ض�����㷨��ĳЩ�ض�����
* AbstractClass�ǳ����࣬��ʵҲ����һ������ģ�壬���岢ʵ����һ��ģ�巽�������ģ�巽��һ����һ�������߼��ĹǼܣ����߼�����ɲ�������Ӧ�ĳ�������У��Ƴٵ�����ʵ�֡�
* ConcreteClassʵ�ָ����������һ�����߶�����󷽷���ÿһ��AbstractClass��������������ConcreteClass��֮��Ӧ����ÿһ��ConcreteClass�����Ը�����Щ���󷽷���
* ģ�巽��ģʽ�ص㣺
*     ģ�巽����������Ϊ���Ƶ����࣬ȥ�������е��ظ������������������ơ�ģ�巽��ģʽ�ṩ��һ���ܺõĴ��븴��ƽ̨��
*  ���������Ϊ�Ϳɱ����Ϊ�ڷ���������ʵ���л�����һ���ʱ�򣬲������Ϊ�ͻ����������ظ����֣�����ͨ��ģ�巽������Щ��Ϊ���Ƶ���һ�ĵط���������������ظ��Ĳ�����Ϊ�ľ�����
*/
int main()
{
#if PTR
    AbstractClass *c = nullptr;
    c = new ConcreteClassA();
    c->TemplateMethod();
    delete c;
    c = new ConcreteClassB();
    c->TemplateMethod();
    delete c;
#else
    shared_ptr<AbstractClass> c = make_shared<ConcreteClassA>();
    c->TemplateMethod();

    c = make_shared<ConcreteClassB>();
    c->TemplateMethod();
#endif
    

    string name;
    cin >> name;
    return 0; // default
}