#include <iostream>
#include <string>
#include "Singlenton.hpp"

using namespace std;

/*
 * 单例模式(Singleton)：保证一个类仅有一个实例，并提供一个访问它的全局访问点；
 * 通常我们可以让一个全局变量使得一个对象被访问，但它不能防止你实例化多个对象。一个最好的办法就是，让类自身负责保存他的唯一实例。
 * 这个类可以保证额米有其他实例可以被创建，并且可以提供一个访问该实例的办法。
 */

int main()
{
    Singleton::getInstance(); //生成唯一的一个实例
    system("pause");
    return 0;
}