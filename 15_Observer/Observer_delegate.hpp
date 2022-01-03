#ifndef OBSERVER_DELEGATE
#define OBSERVER_DELEGATE

#include <vector>
#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::vector;

/*
* 观察模式的不足，当其它的插件功能已经完善的时候，我们无法进行观察
* 这可以通过时间委托实现,委托是一种引用方法的类型。一旦为委托分配了方法，委托将于该方法具有完全相同的行为。委托方法的使用可以像其他任何参数一样，具有参数和返回值。
* 委托可以看成是对函数的抽象，委托的实例将代表一个具体的函数(可以通过函数指针实现)
* 委托对象所搭载的所有方法必须具有相同的原型和形式，也就是拥有相同的参数列表和返回值类型。
*/
class StockObserver
{
    private:
    string name;
    //Subject sub;
};

#endif // !OBSERVER_DELEGATE
