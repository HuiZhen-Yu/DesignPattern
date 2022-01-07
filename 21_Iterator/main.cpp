#include <iostream>
#include <string>
#include <vector>
#include "Iterator.hpp"

using namespace std;

/*
 * ������ģʽ(Iterator):�ṩһ�ַ���˳�����һ���ۺ϶����еĸ���Ԫ�أ����ֲ���¶�ö�����ڲ���ʾ��ʽ��
 * ����Ҫ����һ���ۼ����󣬶����ڶ����Щ������ʲô��Ҫ������ʱ�����Ӧ�ÿ���ʹ�õ�����ģʽ��Ҳ����˵Ϊ������ͬ�ľۼ��ṹ�ṩ�翪ʼ����һ�����Ƿ��������ǰ��һ���ͳһ�Ľӿڡ�
 *
 * ������Ҫ�Ծۼ������ж��ֱ�����ʽ��ʱ�򣬾Ϳ��Կ���ʹ�õ�����ģʽ
 * ������ģʽ���Ƿ����˼��϶���ı�����Ϊ�������һ�������������������ȿ�����������¶���ϵ��ڲ��ṹ���ֿ������ⲿ����͸���ķ����ڲ�������
 *
 */

int main()
{
    ConcreteAggregate *a = new ConcreteAggregate();
    (*a)[0] = 1;
    (*a)[1] = 2;
    (*a)[2] = 3;
    (*a)[3] = 4;

    Iterator_item *i = new ConcreteIterator(a);
    object item = (*i).First();
    while (!i->IsDone())
    {
        cout << i->CurentItem() << ": ����Ʊ" << endl;
        ;
        i->Next();
    }

    system("pause");
    return 0;
}
