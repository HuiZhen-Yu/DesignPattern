#include <iostream>
#include <string>
#include <memory>
#include "Facade.hpp"

using namespace std;
/*
 * 外观模式（Facade）：为子系统中的一组接口提供一个一致的界面，此模式定义了一个高层接口，这个接口使得这一子系统更加容易使用
 * 何时使用外观模式：
 *     首先在设计初期阶段，应该要有以适的将不同的两个层分离，比如经典的三层架构，就需要考虑在数据访问层和业务逻辑层，业务逻辑层和表示层的层与层之间建立外观Facade，
 * 这样可以为复杂的子系统提供一个简单的接口，使得耦合大大降低。
 *      其次在开发阶段，子系统往往因为不断地重构演化二变得越来越复杂，增加外观Facade可以提供一个简单的接口，减少他们之间地依赖。
 *      在维护一个一流地大型系统时，可能这个系统已经非常难以维护和扩展了，你可以为新系统开发一个外观Facade类，类提供设计粗糙或高度复杂的遗留代码的比较清晰简单的接口，让新系统与Facade对象交互，Facade与遗留代码交互所有复杂的工作。
 * 
 */

int main()
{
    Facade *facade = new Facade();
    facade->MethodA();
    facade->MethodB();
    delete facade;
    system("pause");
    return 0;
}