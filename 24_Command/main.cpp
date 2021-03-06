#include <iostream>
#include <string>
#include "Command.hpp"

using namespace std;

/*
 * 命令模式(Command):将一个请求分装为一个对象，从而实例可用不同的请求对客户进行参数优化；对请求排队或记录请求日志，以及支持可撤销的操作
 * 优点：
 * 1. 较容易地设计一个命令队列；
 * 2.再需要的情况下，可以较容易地将命令记入日志；
 * 3.允许接收请求地一方决定是否要否决请求；
 * 4.可以容易地实现对请求地撤销与重做；
 * 5.由于加进新的具体命令类不影响其他的类，因此增加新的具体命令类很容易。
 * 6.将请求一个操作地对象与知道怎么执行一个操作地对象分隔开。
 * 
 * 敏捷开发原则告诉我们，不要为代码添加基于猜测的、实际不需要地功能。
 * 如果不清楚一个系统是否需要命令模式，一般就不要着急去实现它，事实上，在需要的时候通过重构实现这个模式并不困难，只有再真正需要如撤销/恢复操作等功能时，把原来的代码重构为命令模式才有意义。
 */

int main(int argc, char **argv)
{
    Receiver *r = new Receiver();
    Command *c = new ConcreteCommand(r);
    Invoker *i = new Invoker();
    i->SetCommand(c);
    i->ExecuteCommand();
    delete i;
    system("pause");
    return 0;
}