#include <iostream>
#include <string>
#include "Singlenton.hpp"

using namespace std;

/*
 * ����ģʽ(Singleton)����֤һ�������һ��ʵ�������ṩһ����������ȫ�ַ��ʵ㣻
 * ͨ�����ǿ�����һ��ȫ�ֱ���ʹ��һ�����󱻷��ʣ��������ܷ�ֹ��ʵ�����������һ����õİ취���ǣ����������𱣴�����Ψһʵ����
 * �������Ա�֤����������ʵ�����Ա����������ҿ����ṩһ�����ʸ�ʵ���İ취��
 */

int main()
{
    Singleton::getInstance(); //����Ψһ��һ��ʵ��
    system("pause");
    return 0;
}