#include <iostream>
#include <string>
#include <map>
#include "Person_item.hpp"

using namespace std;

/*
 * 访问者模式(visitor)：表示一个作用于某对象节后中的各元素的操作。它使你可以在不改变个元素的类的前提下定义作用于这些元素的新操作。
 * 访问模式适用于数据结构相对稳定的系统，它把数据结构和作用于结构上的操作这件的耦合解脱开，使得操作集合可以相对自由的演化。
 * 缺点：使增加新的数据结构变得困难了。
 */

int main(int argc, char **argv)
{

    ObjectStructure *o = new ObjectStructure();
    o->Attach("1", new Man());
    o->Attach("2", new Women());

    Success *v1 = new Success();
    o->Display(v1);

    Failing *v2 = new Failing();
    o->Display(v2);

    Amativeness *v3 = new Amativeness();
    ;
    o->Display(v3);

    delete o;

    system("pause");
    return 0;
}