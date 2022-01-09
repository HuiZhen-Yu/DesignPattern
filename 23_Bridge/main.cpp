#include <iostream>
#include <string>
#include "phone_item.hpp"

using namespace std;
/*
 * 很多时候继承会带来麻烦，比如对象的继承关系是在编译时就定好了，所以无法在运行时改变从父类继承的实现。
 * 子类的实现与它的父类有非常紧密的依赖关系，以至于父类实现中的任何变化必然会导致子类发生变化。当你需要复用子类时，如果继承下来的实现不适合解决新的问题，则父类必须重写或被其他更合适的类替换。
 * 合成服用原则(CAPR):尽量使用合成/聚合，尽量不要使用类的继承。
 * 合成(Composition,即组合)和聚合(Aggregation)都是关联的特殊种类。
 * 聚合表示一种若的'拥有'关系，体显了严格的部分和整体的关系，部分和整体的生命周期一样。（翅膀与大雁就是部分和张提，且生命周期相同，而大雁和雁群是聚合关系）,优先使用对象的合成/聚合将有助于你保持每个类被封装，并被集中在单个任务上，这样类和类继承层次会保持较小规模，并且不太可能增长为不可控制的庞然大物。
 */

/*
 * 桥接模式(Bridge):将抽象的部分与它的实现部分分离，是他们都可以独立的变化。
 * 
 */
int main()
{
    HandsetBrand *ab = nullptr;
    ab = new HandsetBrandN();

    ab->SetHandsetSoft(new HandsetGame());
    ab->Run();

    ab->SetHandsetSoft(new HandsetAddressList());
    ab->Run();

    HandsetBrand *ab2 = new HandsetBrandM();
    ab2->SetHandsetSoft(new HandsetGame());
    ab2->Run();
    ab2->SetHandsetSoft(new HandsetAddressList());
    ab2->Run();

    delete ab;
    delete ab2;

    system("pause");
    return 0;
}