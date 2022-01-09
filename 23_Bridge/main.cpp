#include <iostream>
#include <string>
#include "phone_item.hpp"

using namespace std;
/*
 * �ܶ�ʱ��̳л�����鷳���������ļ̳й�ϵ���ڱ���ʱ�Ͷ����ˣ������޷�������ʱ�ı�Ӹ���̳е�ʵ�֡�
 * �����ʵ�������ĸ����зǳ����ܵ�������ϵ�������ڸ���ʵ���е��κα仯��Ȼ�ᵼ�����෢���仯��������Ҫ��������ʱ������̳�������ʵ�ֲ��ʺϽ���µ����⣬���������д�����������ʵ����滻��
 * �ϳɷ���ԭ��(CAPR):����ʹ�úϳ�/�ۺϣ�������Ҫʹ����ļ̳С�
 * �ϳ�(Composition,�����)�;ۺ�(Aggregation)���ǹ������������ࡣ
 * �ۺϱ�ʾһ������'ӵ��'��ϵ���������ϸ�Ĳ��ֺ�����Ĺ�ϵ�����ֺ��������������һ����������������ǲ��ֺ����ᣬ������������ͬ�����������Ⱥ�ǾۺϹ�ϵ��,����ʹ�ö���ĺϳ�/�ۺϽ��������㱣��ÿ���౻��װ�����������ڵ��������ϣ����������̳в�λᱣ�ֽ�С��ģ�����Ҳ�̫��������Ϊ���ɿ��Ƶ���Ȼ���
 */

/*
 * �Ž�ģʽ(Bridge):������Ĳ���������ʵ�ֲ��ַ��룬�����Ƕ����Զ����ı仯��
 * 
 */
int main()
{
    HandsetBrand *ab = nullptr;
    ab = new HandsetBrandN();

    ab->SetHandsetSoft(new HandsetGame());
    ab->Run();

    ab->SetHandsetSoft(new HandsetAddressList());
    ab->Run();

    HandsetBrand *ab2 = new HandsetBrandM();
    ab2->SetHandsetSoft(new HandsetGame());
    ab2->Run();
    ab2->SetHandsetSoft(new HandsetAddressList());
    ab2->Run();

    delete ab;
    delete ab2;

    system("pause");
    return 0;
}