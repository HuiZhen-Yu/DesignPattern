#include <iostream>
#include <string>

#include "LeiFengFactory.hpp"

using namespace std;

/* 
* 简单工厂模式与工厂方法比较：
*		简单工厂模式的最大优点在于工厂类中间包含了必要的逻辑判断，根据客户端的选择条件动态实例化相关的类，对于客户端来说，去除了与具体产品的依赖。
* 
* 工厂方法模式（Factory Method）:
*      定义一个用于创建对象的接口，让子类决定实例化哪一个类。工厂方法使一个类的实例化延迟到其子类。
*		我们讲过，既然这个工厂类与分支耦合，那么我们就对它下手，根据依赖倒转原则，我们把工厂类抽象出一个接口，这个接口只有一个方法，就是创建抽象产品的方法。
*		然后，所有的要生产具体类的工厂就去实现这个接口，这样一个简单工厂模式的工厂类，变成了一个工厂抽象接口和多个具体生成对象的接口。
* 工厂模式实现时，客户端要决定实例化哪一个工厂来实现运算类，选择判断的问题还是存在的，也就是说工厂方法把简单工厂的内部逻辑判断已到了客户端进行
* 
*/

/*
* 工厂方法克服了简单工厂违背开放封闭原则的缺点，又保持了封装对象过程的优点。
* 他们都是集中封装了对象的创建，使得要更换对象时，不需要做大的改动就可以实现，降低了客户与产品对象的耦合。工厂方法模式时简单工厂模式的进一步抽象与推广。
* 由于使用了多态性，工厂方法模式保持了简单工厂模式的优点，而且客服了它的缺点。但是去点是由于每增加一个产品就需要增加一个产品工厂的类，增加了额外的开发量
*/
int main()
{
	LeiFen * xueleifeng = new Undergraduate();

	xueleifeng->BuyRice();
	xueleifeng->Sweep();
	xueleifeng->Wash();

	LeiFen * student1 = new Undergraduate();
	LeiFen * student2 = new Undergraduate();
	LeiFen * student3 = new Undergraduate();

	student1->BuyRice();
	student2->Sweep();
	student3->Wash();

	delete xueleifeng,student1,student2,student3;
	//简单工厂模式	
	LeiFen * studentA = SimpleFactory::CreateLeiFeng("S");
	studentA->BuyRice();

	LeiFen * studentB = SimpleFactory::CreateLeiFeng("S");
	studentB->Sweep();

	LeiFen * studentc = SimpleFactory::CreateLeiFeng("S");
	studentc->Wash();

	//工厂方法模式
	IFactory * factory = new UndergraduateFactory();
	LeiFen * student = factory->createdLeiFeng();
	student->BuyRice();
	student->Wash();
	student->Sweep();

	string name;
	cin>>name;
	return 0;
}