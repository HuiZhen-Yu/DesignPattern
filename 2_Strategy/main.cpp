#include <iostream>
#include "cash_item.h"

/* 
* 商场促销，策略模式 （strategy）
* 定义了算法家族，分别封装，让他们之间相互替换，此模式让算法的变法不会影响到使用算法的客户
* 策略模式是一种定义一系列算法的方法，从概念上看，所有的算法完成相同的工作，只是实现不同，他可以用相同的方式调用所有的算法，减少了各种算法与使用算法类之间的耦合
* 策略模式的strategy类层次为context定义了一系列的可重用的算法或行为。继承有助于西区出这些算法中的公共功能
* 优点：简化了单元测试，因为每个算法都有自己的类，可以通过自己的接口单独测试
*/

/* 策略模式与简单工厂结合 */
using namespace std;


int main()
{
	double totalPrices = 0.0;

	/* N B R */
	CashContext csuper = CashContext("B");
	totalPrices = csuper.GetResult(200.0 * 3);
	cout << totalPrices << endl;

	return 0;
}

