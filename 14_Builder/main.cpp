#include <iostream>
#include <string>
#include <memory>
#include "Builder.hpp"

using namespace std;

/*
 * ������ģʽ��builder������һ�����Ӷ���Ĺ��������ı�ʾ���룬ʹ��ͬ���Ĺ������̿��Դ�����ͬ�ı�ʾ
 * �������ʹ���˽�����ģʽ����ô�û���ֻ��Ҫָ����Ҫ��������;Ϳ��Եõ����ǣ������彨��Ĺ��̺�ϸ�ھ�����Ҫ֪����
 * ������ģʽ���ڵ��������Ӷ�����㷨Ӧ�ö����ڸö������ɲ����Լ����ǵ�װ�䷽ʽʱ���õ�ģʽ��
 */

int main(int argc, char **argv)
{

    Director *director = new Director();
    Builder *b1 = new ConcreteBuilder1();
    Builder *b2 = new ConcreteBuilder2();

    director->Construct(b1);
    Product *p1 = b1->GetResult();
    p1->show();

    director->Construct(b2);
    Product *p2 = b2->GetResult();
    p2->show();
    delete director, b1, b2, p1;

    system("pause");
    return 0;
}