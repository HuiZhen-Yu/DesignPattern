#include <iostream>
#include "Proxy_gift.h"

using namespace std;

/*
* 代理模式（proxy）：为其他对象提供一种代理以控制对这个对象的访问；
* 应用：
* 1.远程代理：也就是为一个生存对象在不同的地址空间提供局部代表。这样可以隐藏一个对象存在于不同地址空间的事实。
* 2.虚拟代理：是根据需要创建开销很大的对象。通过它来存放实例化需要很长时间的真实对象（打开web网页的时候，未打开的图片框，就是通过虚拟代理来代替了真实的图片，此时代理存储了真实图片的路径与尺寸）
* 3.安全代理：用来控制真实对象访问时的权限
* 4.智能指针：是指当调用真实的对象时，代理处理另外一些事(如计算真实对象的引用次数，当没有对象引用时就释放内存)
* 代理模式就是在访问对象的时候引入了一定的间接性，因为这种间接性，可以附加多种用途
*/



int main()
{
	SchoolGirl* jiaojiao = new SchoolGirl();
	jiaojiao->set("李娇娇");

	Proxy* daili = new Proxy(jiaojiao);
	
	daili->GiveDolls();
	daili->GiveFlovers();
	daili->GiveChocolate();

	delete jiaojiao, daili;
	
	jiaojiao = nullptr;
	daili = nullptr;

	//客户端代码

	return 0;
}


