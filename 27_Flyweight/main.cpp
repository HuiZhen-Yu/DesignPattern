#include <iostream>
#include <string>
#include "Flyweight.hpp"

using namespace std;

/*
 * 享元模式(Flyweight): 运用共享技术有效的支持大量细粒度的对象
 * 享元模式可以避免大量非常相似类的开销。在程序设计中，有时候需要生成大量细粒度的类实例来表示数据。
 * 如果能发现这些实例除了几个参数外基本上都是相同的，有时就能够大幅度的减少需要实例化的类的数量。
 * 如果能把这些参数移到类实例的外面，在方法调用时将他们传递进来，就可以通过共享大幅度的减少单个实例的数目。
 * 
 * 应用：如果一个应用程序使用了大量的对象，而大量的这些对象造成了很大的存储开销时就应该考虑使用；
 *       还有就是对象的大多数状态可以外部状态，如果删除对象的外部状态，那么就可以用相对较少的共享对象取代很对组对象，此时可以用共享模式。
 */

int main(int argc, char **argv)
{
    int extrinsic = 22;
    FlyweightFactory *f = new FlyweightFactory();
    Flyweight *fx = f->GetFlyweight("X");
    fx->Operation(--extrinsic);

    Flyweight *fy = f->GetFlyweight("Y");
    fx->Operation(--extrinsic);

    Flyweight *fz = f->GetFlyweight("Z");
    fx->Operation(--extrinsic);

    Flyweight *uf = new UnsharedConcreteFlyweight();
    uf->Operation(--extrinsic);

    delete fx;
    delete fy;
    delete fz;
    delete uf;
    system("pause");
    return 0;
}