#include <iostream>
#include <string>
#include "Adapter.hpp"
#include "Basket_adapter.hpp"

using namespace std;

/*
 * ������ģʽ(Adapter):��һ����Ľӿ�ת���ɿͻ�ϣ��������һ���ӿڡ�Adapterģʽʹ��ԭ�����ڽӿڲ����ݶ�����һ��������Щ�����һ����
 * �����ݵ����ݺ���Ϊ����ȷ�����ӿڲ���ʱ������Ӧ�ÿ���ʹ����������Ŀ����ʹ���Ʒ�Χ֮���һ��ԭ�ж�����ĳ���ӿ�ƥ�䡣
 * ������ģʽ��ҪӦ����ϣ������һЩ�ִ���࣬���ǽӿ����븴�û���Ҫ��һ�µ������
 */

int main()
{
    Target *target = new Adapter();
    target->Request();
    delete target;

    Player *b = new Forwards("�͵ٶ�");
    b->Attack();
    Player *m = new Guards("��˸��׵�");
    m->Attack();
    Player *ym = new Translater("Ҧ��");
    ym->Defence();

    delete b, m, ym;
    system("pause");
    return 0;
}
