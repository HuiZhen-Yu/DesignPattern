#include <iostream>
#include <string>
#include "Adapter.hpp"
#include "Basket_adapter.hpp"

using namespace std;

/*
 * 适配器模式(Adapter):将一个类的接口转换成客户希望的另外一个接口。Adapter模式使得原本用于接口不兼容而不能一起工作的那些类可以一起工作
 * 当数据的数据和行为都正确，但接口不符时，我们应该考虑使用适配器，目的是使控制范围之外的一个原有对象与某个接口匹配。
 * 适配器模式组要应用于希望复用一些现存的类，但是接口又与复用环境要求不一致的情况。
 */

int main()
{
    Target *target = new Adapter();
    target->Request();
    delete target;

    Player *b = new Forwards("巴蒂尔");
    b->Attack();
    Player *m = new Guards("麦克格雷迪");
    m->Attack();
    Player *ym = new Translater("姚明");
    ym->Defence();

    delete b, m, ym;
    system("pause");
    return 0;
}
