#include <iostream>
#include <string>
#include <vector>
//此头文件有问题，两个类互相包含实例化问题 （大话数据结构chapter16 page164）
//#include "state.hpp"

using namespace std;

/*
 * 面向对象设计其实就是希望做到代码的责任分解。
 * 状态模式（state）:当一个对象的内在状态改变时允许改变其行为，这个对象看起来好像是被改变了类。
 * 状态模式主要解决的就是当控制一个对象状态转换的条件表达式过于复杂时的情况。吧状态的判断逻辑转移到表示不同状态的一系列类当中，可以把复杂的判断逻辑简化。
 * 状态模式的好处就是将与特定状态相关的行为局部化，并且将不同的状态行为分开来
 * 当一个对象的行为取决于它的状态，并且它必须在运行时候时刻根据状态改变他的行为时，就可以考虑使用状态模式。
 */

int main()
{
    // //const测试
    // volatile const int a = 4;
    // int *p = (int *)&a;
    // *p = 5;
    // cout << "*p = " << *p << endl;
    // cout << "a = " << a << endl;
    

    // ConcreteStateA *CreA = new ConcreteStateA();
    // Context *c = new Context(CreA);
    // c->Request();
    // c->Request();

    system("pause");
    return 0;
}