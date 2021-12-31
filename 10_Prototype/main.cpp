#include <iostream>
#include <string>
#include "Prototype.hpp"
#include "Resume.hpp"
using namespace std;

/*
 * 原型模式（Prototype），用原型实例指定创建对象的种类，并且通过拷贝这些原型创建新的对象
 * 原型模式其实就是从一个对象在创建另外一个可定制的对象，而且不需要知道任何创建的细节
 * 一般在初始化的信息不发生变化的情况下，克隆是最好的方法，这即隐藏了对象创建的细节，又对性能大大提高了，这样等于是不用重新初始化对象，而是动态的获得对象运行时的状态
 */

/*
* 浅复制与深复制，C#中的MenberwiseClone()方法就是这样，如果字段是值类型的，则对该字段执行逐位复制，如果字段是引用类型，则复制引用但不复制引用的对象；
* 因此原始对象及其副本引用同一对象
* 浅复制：被复制对象的所有变量都含有与原来的的对象相同的值，而所有的对其他对象的引用都仍然指向原来的对象。
* 深复制：把引用对象的变量指向复制过的新对象，而不是原有的被引用的对象
*/
int main(int argc, char **argv)
{
    ConcretePrototype1 *p1 = new ConcretePrototype1("I");
    ConcretePrototype1 *c1 = (ConcretePrototype1 *)p1->Clone();
    cout << "Cloned: {0}" << c1->get() << endl;

    Resume *a = new Resume("大鸟");
    a->SetPersonalInfo("male", "29");
    a->SetWorkExperience("1998-2000", "xxxx");

    //只需要调用clone方法就可以实现新简历的生成，并且可以再修改新简历的细节
    Resume *b = (Resume *)a->Clone();
    b->SetWorkExperience("1998-2006", "yyyy");

    Resume *c = (Resume *)a->Clone();
    c->SetPersonalInfo("female", "24");

    a->Display();
    b->Display();
    c->Display();

    delete a, b, c;

    string name;
    cin >> name;

    return 0;
}