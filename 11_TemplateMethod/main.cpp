#include <iostream>
#include <string>
#include <memory>
#include "TemplateMethod.hpp"

#define PTR 0
using namespace std;
/*
* 模板方法模式：定义一个操作中的算法的骨架，而将一些步骤延迟到子类中。模板方法使得子类可以不改变一个算法的结构即可重定义该算法的某些特定步骤
* AbstractClass是抽象类，其实也就是一个抽象模板，定义并实现了一个模板方法，这个模板方法一般是一个顶级逻辑的骨架，而逻辑的组成步骤在相应的抽象操作中，推迟到子类实现。
* ConcreteClass实现父类所定义的一个或者多个抽象方法，每一个AbstractClass都可以由任意多个ConcreteClass与之对应，而每一个ConcreteClass都可以给出这些抽象方法。
* 模板方法模式特点：
*     模板方法将不变行为搬移到超类，去除子类中的重复代码来体现它的优势。模板方法模式提供了一个很好的代码复用平台。
*  当不变的行为和可变的行为在方法的子类实现中混杂在一起的时候，不变的行为就会在子类中重复出现，我们通过模板方法将这些行为搬移到单一的地方，帮助子类拜托重复的不变行为的纠缠。
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