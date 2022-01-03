#include <iostream>
#include <string>
#include <vector>
//#include "Observer_boss.hpp"
#include "Observer.hpp"

using namespace std;

/*
 * �۲���ģʽ������һ��һ�Զ��������ϵ���ö���۲��߶���ͬʱ����ĳһ������Ķ���������������״̬�����仯ʱ����֪ͨ���й۲��߶���ʹ�����ܹ��Զ������Լ���
 * �۲���ģʽ�ص㣺���Ǹ�һ��ϵͳ�ָ��һϵ���໥д�����࣬��һ���ܲ��õĸ����ã��Ǿ�����Ҫά����ض�����һ���ԣ����ǲ�ϣ��Ϊ��ά��һ���Զ�ʹ���������ϣ��������ά������չ�����ö������鷳��
 * ��һ������ĸı���Ҫͬʱ�ı����������ʱ�򣬶�������֪�������ж��ٶ����д��ı�ʱ��Ӧ�ÿ���ʹ�ù۲���ģʽ��
 * ��һ������ģ�����������棬����һ������������һ���棬��ʱ�ù۲���ģʽ���Խ������߷�װ�ڶ����Ķ����У�ʹ���Ǹ��Զ����ĸı�͸���
 * �ܵ��������۲���ģʽ�����Ĺ�����ʵ�����ڽ����ϡ�����ϵ�˫���������ڳ��󣬶����������ھ��塣�Ӷ��ǵĸ��Եı仯������Ӱ����һ�ߵı仯��
 */

int main()
{
    // Boss *huhansan = new Boss();
    // StockObserver *tongshi1 = new StockObserver("asdh", huhansan);
    // NBAObserver *tongshi2 = new NBAObserver("tonshi2", huhansan);

    // huhansan->Attach(tongshi1);
    // huhansan->Attach(tongshi2);

    // huhansan->set("huilai");
    // huhansan->Notify();
    // delete huhansan, tongshi1, tongshi2;

    ConcreteSubject *s = new ConcreteSubject();
    ConcreteObserver *cons1 = new ConcreteObserver(s, "X");
    ConcreteObserver *cons2 = new ConcreteObserver(s, "Y");
    ConcreteObserver *cons3 = new ConcreteObserver(s, "Z");

    s->Attach("X", cons1);
    s->Attach("Y", cons2);
    s->Attach("Z", cons3);

    s->set("ABC");
    s->Notify();
    delete cons1, cons2, cons3;

    system("pause");
    return 0;
}
