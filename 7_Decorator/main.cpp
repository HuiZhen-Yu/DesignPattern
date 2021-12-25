#include <iostream>
#include "Decorator.h"
#include "Person_item.h"


using namespace std;

/*
* װ��ģʽ��Decorator������̬�ظ�һ���������һЩ�����ְ�𣬾����ӹ�����˵��װ��ģʽ�����������Ϊ���
* Component �Ƕ���һ������ӿڣ�Ҳ���Ը���Щ����̬�����ְ��ConcreteComponent ��һ������ض���Ҳ���Ը�����������һЩְ��
* Decorator װ�γ����࣬�̳���Component����������չComponent��Ĺ��ܣ����Ƕ���Component��˵��������֪��Decorator�Ĵ��ڵġ�
* ����ConcreteDecorator���Ǿ����װ�ζ����𵽸�Component���ְ������á�
*/

/* 
* �ܽ�
* װ��ģʽ��Ϊ���й��ܶ�̬����Ӹ��๦�ܵ�һ�ַ�ʽ�����ÿ��Ҫװ�εĹ��ܷ��ڵ��������У�����������װ����Ҫװ�εĶ�����˵���Ҫִ��������Ϊʱ���ͻ�����Ϳ���������ʱ������Ҫ��ѡ��أ���˳���ʹ�����ι��ܰ�װ�����ˡ�
* �ŵ㣺
* 1.�����е�װ�ι��ܴ����а���ȥ�����������Լ�ԭ�е���
* 2.��Ч�İ���ĺ���ְ���װ�ι������ֿ��ˣ����ҿ���ȥ����������ظ���װ���߼�
*/

int main()
{
	ConcreteComponent* c = new ConcreteComponent();
	ConcreteDecoratorA* d1 = new ConcreteDecoratorA();
	ConcreteDecoratorB* d2 = new ConcreteDecoratorB();

	/*
	* װ�εķ�������������ConcreteComponentʵ��������c��
	* Ȼ��ʹ��ConcreteDecoratorA��ʵ������������װc��
	* ����concreteDectorB��ʵ��������d2����װd1������ִ��d2��Operation()
	*/
	d1->SetComponent(c);	
	d2->SetComponent(d1);
	d2->Operation();
	delete c, d1, d2;
	cout << endl;
	/*
	* 1.װ��ģʽ������SetComponent���Զ�����а�װ�ģ�����ÿ��װ�ζ����ʵ�־ͺ����ʹ���������ֿ��ˣ�
	*   ÿ��װ�ζ�ֻ�����Լ��Ĺ��ܣ�����Ҫ������α���ӵ�����������
	* 2.���ֻ��һ��ConcreteComponent���û�г����Component�࣬��ôDectorator�����˵��ConcreteComponent��һ�����ࡣ
	*   ͬ���������ֻ��һ��concretedecorator����ô��û�б�Ҫ����һ��������decorator�࣬�����԰�decorator��concretedecorator�����κϲ���һ����
	*/

	Person* xc1 = new Person("С��");
	Person* xc2 = new Person("����");
	cout << "��һ��װ��" << endl;
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

	cout << "�ڶ���װ��" << endl;
	WearTLeatherShoes* px = new WearTLeatherShoes();
	WearTie* ld = new WearTie();
	WearSuit* xz = new WearSuit();

	px->Dectorate(xc2);
	ld->Dectorate(px);
	xz->Dectorate(ld);
	xz->Show();
	delete px, ld, xz;
	cout << endl;


	cout << "������װ��" << endl;
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

