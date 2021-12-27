#include <iostream>
#include <string>

#include "LeiFengFactory.hpp"

using namespace std;

/* 
* �򵥹���ģʽ�빤�������Ƚϣ�
*		�򵥹���ģʽ������ŵ����ڹ������м�����˱�Ҫ���߼��жϣ����ݿͻ��˵�ѡ��������̬ʵ������ص��࣬���ڿͻ�����˵��ȥ����������Ʒ��������
* 
* ��������ģʽ��Factory Method��:
*      ����һ�����ڴ�������Ľӿڣ����������ʵ������һ���ࡣ��������ʹһ�����ʵ�����ӳٵ������ࡣ
*		���ǽ�������Ȼ������������֧��ϣ���ô���ǾͶ������֣�����������תԭ�����ǰѹ���������һ���ӿڣ�����ӿ�ֻ��һ�����������Ǵ��������Ʒ�ķ�����
*		Ȼ�����е�Ҫ����������Ĺ�����ȥʵ������ӿڣ�����һ���򵥹���ģʽ�Ĺ����࣬�����һ����������ӿںͶ���������ɶ���Ľӿڡ�
* ����ģʽʵ��ʱ���ͻ���Ҫ����ʵ������һ��������ʵ�������࣬ѡ���жϵ����⻹�Ǵ��ڵģ�Ҳ����˵���������Ѽ򵥹������ڲ��߼��ж��ѵ��˿ͻ��˽���
* 
*/

/*
* ���������˷��˼򵥹���Υ�����ŷ��ԭ���ȱ�㣬�ֱ����˷�װ������̵��ŵ㡣
* ���Ƕ��Ǽ��з�װ�˶���Ĵ�����ʹ��Ҫ��������ʱ������Ҫ����ĸĶ��Ϳ���ʵ�֣������˿ͻ����Ʒ�������ϡ���������ģʽʱ�򵥹���ģʽ�Ľ�һ���������ƹ㡣
* ����ʹ���˶�̬�ԣ���������ģʽ�����˼򵥹���ģʽ���ŵ㣬���ҿͷ�������ȱ�㡣����ȥ��������ÿ����һ����Ʒ����Ҫ����һ����Ʒ�������࣬�����˶���Ŀ�����
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
	//�򵥹���ģʽ	
	LeiFen * studentA = SimpleFactory::CreateLeiFeng("S");
	studentA->BuyRice();

	LeiFen * studentB = SimpleFactory::CreateLeiFeng("S");
	studentB->Sweep();

	LeiFen * studentc = SimpleFactory::CreateLeiFeng("S");
	studentc->Wash();

	//��������ģʽ
	IFactory * factory = new UndergraduateFactory();
	LeiFen * student = factory->createdLeiFeng();
	student->BuyRice();
	student->Wash();
	student->Sweep();

	string name;
	cin>>name;
	return 0;
}