#include <iostream>
#include <string>
#include "Mediator.hpp"

using namespace std;

/*
 * 中介者模式(Mediator): 用一个中介对象来封装一些列的对象交互。中介者使各对象不需要显示的相互引用，从而使其耦合松散，而且可以独立的改变他们的交互。
 * 缺点：
 * 1. 中介者模式很容易再系统中应用，也很容易在系统中误用。当系统出现了多对多复杂交互模式的时候，不要急于使用中介者模式，而要反思你的系统在设计上是不是合理。
 * 2.由于ConcreteMediator控制了集中化，于是就把交互复杂性变为了中介者的复杂性，这就是的中介者会变得比任何一个ConcreteColleague都复杂。
 * 优点：
 * 1. Mediator的出现减少了各个Colleague的耦合，使得可以独立地改变和复用各个Colleague类和Mediator；
 * 2. 由于把对象如何协作进行了抽象，将中介作为一个独立的概念并将其封装在一个对象中，这样关注的对象就从对象各自本身的行为转移到他们之间的交互上面来了，那就会站在一个宏观的角度去看待系统。
 * 
 */

int main(int argc, char **argv)
{

    ConcreteMediator *m = new ConcreteMediator();

    ConcreteColleague1 *c1 = new ConcreteColleague1(m);
    ConcreteColleague2 *c2 = new ConcreteColleague2(m);

    m->set_c1(c1);
    m->set_c2(c2);

    c1->Send("吃过饭了吗？");
    c2->Send("没有呢，你打算请客？");

    delete m;
    delete c1;
    delete c2;

    system("pause");
    return 0;
}