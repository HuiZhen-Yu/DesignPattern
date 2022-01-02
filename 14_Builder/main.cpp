#include <iostream>
#include <string>
#include <memory>
#include "Builder.hpp"

using namespace std;

/*
 * 建造者模式（builder）：将一个复杂对象的构建与它的表示分离，使得同样的构建过程可以创建不同的表示
 * 如果我们使用了建造者模式，那么用户就只需要指定需要建造的类型就可以得到他们，二具体建造的过程和细节就绪需要知道了
 * 建造者模式是在当创建复杂对象的算法应该独立于该对象的组成部分以及他们的装配方式时适用的模式。
 */

int main(int argc, char **argv)
{

    Director *director = new Director();
    Builder *b1 = new ConcreteBuilder1();
    Builder *b2 = new ConcreteBuilder2();

    director->Construct(b1);
    Product *p1 = b1->GetResult();
    p1->show();

    director->Construct(b2);
    Product *p2 = b2->GetResult();
    p2->show();
    delete director, b1, b2, p1;

    system("pause");
    return 0;
}