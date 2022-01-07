#include <iostream>
#include <string>
#include <vector>
#include "Iterator.hpp"

using namespace std;

/*
 * 迭代器模式(Iterator):提供一种方法顺序访问一个聚合对象中的各个元素，而又不暴露该对象的内部表示方式。
 * 当你要访问一个聚集对象，额日期额不管这些对象是什么都要遍历的时候，你就应该考虑使用迭代器模式，也就是说为遍历不同的聚集结构提供如开始，下一个，是否结束，当前哪一项等统一的接口。
 *
 * 当你需要对聚集对象有多种遍历方式的时候，就可以考虑使用迭代器模式
 * 迭代器模式就是分离了集合对象的遍历行为，抽象出一个迭代器来负责，这样既可以做到不暴露集合的内部结构，又可以让外部代码透明的访问内部的数据
 *
 */

int main()
{
    ConcreteAggregate *a = new ConcreteAggregate();
    (*a)[0] = 1;
    (*a)[1] = 2;
    (*a)[2] = 3;
    (*a)[3] = 4;

    Iterator_item *i = new ConcreteIterator(a);
    object item = (*i).First();
    while (!i->IsDone())
    {
        cout << i->CurentItem() << ": 请买车票" << endl;
        ;
        i->Next();
    }

    system("pause");
    return 0;
}
