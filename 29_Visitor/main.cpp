#include <iostream>
#include <string>
#include <map>
#include "Person_item.hpp"

using namespace std;

/*
 * ������ģʽ(visitor)����ʾһ��������ĳ����ں��еĸ�Ԫ�صĲ�������ʹ������ڲ��ı��Ԫ�ص����ǰ���¶�����������ЩԪ�ص��²�����
 * ����ģʽ���������ݽṹ����ȶ���ϵͳ���������ݽṹ�������ڽṹ�ϵĲ����������Ͻ��ѿ���ʹ�ò������Ͽ���������ɵ��ݻ���
 * ȱ�㣺ʹ�����µ����ݽṹ��������ˡ�
 */

int main(int argc, char **argv)
{

    ObjectStructure *o = new ObjectStructure();
    o->Attach("1", new Man());
    o->Attach("2", new Women());

    Success *v1 = new Success();
    o->Display(v1);

    Failing *v2 = new Failing();
    o->Display(v2);

    Amativeness *v3 = new Amativeness();
    ;
    o->Display(v3);

    delete o;

    system("pause");
    return 0;
}