#include <iostream>
#include "Decorator.h"
#include "Person_item.h"


using namespace std;

/*
* 装饰模式（Decorator），动态地给一个对象添加一些额外地职责，就增加功能来说，装饰模式比生成子类更为灵活
* Component 是定义一个对象接口，也可以给这些对象动态的添加职责。ConcreteComponent 是一个具体地对象，也可以给这个对象添加一些职责。
* Decorator 装饰抽象类，继承了Component从外类来扩展Component类的功能，但是对于Component来说，是无需知道Decorator的存在的。
* 至于ConcreteDecorator就是具体的装饰对象，起到给Component添加职责的作用。
*/

/* 
* 总结
* 装饰模式是为已有功能动态的添加更多功能的一种方式：其把每个要装饰的功能放在单独的类中，并让这个类包装她所要装饰的对象，因此当需要执行特殊行为时，客户代码就可以再运行时根据需要有选择地，按顺序的使用修饰功能包装对象了。
* 优点：
* 1.把类中的装饰功能从类中搬移去除，这样可以简化原有的类
* 2.有效的把类的核心职责和装饰功能区分开了，而且可以去除相关类中重复的装饰逻辑
*/

int main()
{
	ConcreteComponent* c = new ConcreteComponent();
	ConcreteDecoratorA* d1 = new ConcreteDecoratorA();
	ConcreteDecoratorB* d2 = new ConcreteDecoratorB();

	/*
	* 装饰的方法就是首先用ConcreteComponent实例化对象c，
	* 然后使用ConcreteDecoratorA的实例化对象来包装c，
	* 再用concreteDectorB的实例化对象d2来包装d1，最终执行d2的Operation()
	*/
	d1->SetComponent(c);	
	d2->SetComponent(d1);
	d2->Operation();
	delete c, d1, d2;
	cout << endl;
	/*
	* 1.装饰模式是利用SetComponent来对对象进行包装的，这样每个装饰对象的实现就和如何使用这个对象分开了，
	*   每个装饰对只关心自己的功能，不需要关心如何被添加到对象链当中
	* 2.如果只有一个ConcreteComponent类而没有抽象的Component类，那么Dectorator类可以说是ConcreteComponent的一个子类。
	*   同样道理，如果只有一个concretedecorator类那么就没有必要建立一个单独的decorator类，而可以吧decorator和concretedecorator的责任合并成一个类
	*/

	Person* xc1 = new Person("小菜");
	Person* xc2 = new Person("大鸟");
	cout << "第一种装扮" << endl;
	WearSneakers* pqx = new WearSneakers();
	BigTrouser* kk = new BigTrouser();
	TShirts* dtx = new TShirts();

	pqx->Dectorate(xc1);
	kk->Dectorate(pqx);
	dtx->Dectorate(kk);
	dtx->Show();
	delete pqx, kk, dtx;
	cout << "Hello world!!" << endl;
	cout << endl;

	cout << "第二种装扮" << endl;
	WearTLeatherShoes* px = new WearTLeatherShoes();
	WearTie* ld = new WearTie();
	WearSuit* xz = new WearSuit();

	px->Dectorate(xc2);
	ld->Dectorate(px);
	xz->Dectorate(ld);
	xz->Show();
	delete px, ld, xz;
	cout << endl;


	cout << "第三种装扮" << endl;
	WearTLeatherShoes* px2 = new WearTLeatherShoes();
	WearTie* ld2 = new WearTie();
	WearSuit* xz2 = new WearSuit();

	px2->Dectorate(xc1);
	ld2->Dectorate(px2);
	xz2->Dectorate(ld2);
	xz2->Show();
	delete xc1, px2, ld2, xz2;
	cout << endl;
	return 0;
}

