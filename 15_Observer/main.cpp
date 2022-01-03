#include <iostream>
#include <string>
#include <vector>
//#include "Observer_boss.hpp"
#include "Observer.hpp"

using namespace std;

/*
 * 观察者模式定义了一种一对多的依赖关系，让多个观察者对象同时监听某一个主题的对象。这个主题对象在状态发生变化时，会通知所有观察者对象，使他们能够自动更新自己。
 * 观察者模式特点：及那个一个系统分割成一系列相互写作的类，有一个很不好的副作用，那就是需要维护相关对象间的一致性，我们不希望为了维持一致性而使各类紧密耦合，这样会给维护、扩展和重用都带来麻烦。
 * 当一个对象的改变需要同时改变其他对象的时候，而且他不知道具体有多少对象有待改变时，应该考虑使用观察者模式。
 * 当一个抽象模型有两个方面，其中一方面依赖于另一方面，这时用观察者模式可以将这两者封装在独立的对象中，使他们各自独立的改变和复用
 * 总的来讲，观察者模式所作的工作其实就是在解除耦合。让耦合的双方都依赖于抽象，而不是依赖于具体。从而是的各自的变化都不会影响另一边的变化。
 */

int main()
{
    // Boss *huhansan = new Boss();
    // StockObserver *tongshi1 = new StockObserver("asdh", huhansan);
    // NBAObserver *tongshi2 = new NBAObserver("tonshi2", huhansan);

    // huhansan->Attach(tongshi1);
    // huhansan->Attach(tongshi2);

    // huhansan->set("huilai");
    // huhansan->Notify();
    // delete huhansan, tongshi1, tongshi2;

    ConcreteSubject *s = new ConcreteSubject();
    ConcreteObserver *cons1 = new ConcreteObserver(s, "X");
    ConcreteObserver *cons2 = new ConcreteObserver(s, "Y");
    ConcreteObserver *cons3 = new ConcreteObserver(s, "Z");

    s->Attach("X", cons1);
    s->Attach("Y", cons2);
    s->Attach("Z", cons3);

    s->set("ABC");
    s->Notify();
    delete cons1, cons2, cons3;

    system("pause");
    return 0;
}
