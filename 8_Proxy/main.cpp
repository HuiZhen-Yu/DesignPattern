#include <iostream>
#include "Proxy_gift.h"

using namespace std;

/*
* ����ģʽ��proxy����Ϊ���������ṩһ�ִ����Կ��ƶ��������ķ��ʣ�
* Ӧ�ã�
* 1.Զ�̴���Ҳ����Ϊһ����������ڲ�ͬ�ĵ�ַ�ռ��ṩ�ֲ�����������������һ����������ڲ�ͬ��ַ�ռ����ʵ��
* 2.��������Ǹ�����Ҫ���������ܴ�Ķ���ͨ���������ʵ������Ҫ�ܳ�ʱ�����ʵ���󣨴�web��ҳ��ʱ��δ�򿪵�ͼƬ�򣬾���ͨ�������������������ʵ��ͼƬ����ʱ����洢����ʵͼƬ��·����ߴ磩
* 3.��ȫ��������������ʵ�������ʱ��Ȩ��
* 4.����ָ�룺��ָ��������ʵ�Ķ���ʱ������������һЩ��(�������ʵ��������ô�������û�ж�������ʱ���ͷ��ڴ�)
* ����ģʽ�����ڷ��ʶ����ʱ��������һ���ļ���ԣ���Ϊ���ּ���ԣ����Ը��Ӷ�����;
*/



int main()
{
	SchoolGirl* jiaojiao = new SchoolGirl();
	jiaojiao->set("���");

	Proxy* daili = new Proxy(jiaojiao);
	
	daili->GiveDolls();
	daili->GiveFlovers();
	daili->GiveChocolate();

	delete jiaojiao, daili;
	
	jiaojiao = nullptr;
	daili = nullptr;

	//�ͻ��˴���

	return 0;
}


