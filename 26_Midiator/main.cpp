#include <iostream>
#include <string>
#include "Mediator.hpp"

using namespace std;

/*
 * �н���ģʽ(Mediator): ��һ���н��������װһЩ�еĶ��󽻻����н���ʹ��������Ҫ��ʾ���໥���ã��Ӷ�ʹ�������ɢ�����ҿ��Զ����ĸı����ǵĽ�����
 * ȱ�㣺
 * 1. �н���ģʽ��������ϵͳ��Ӧ�ã�Ҳ��������ϵͳ�����á���ϵͳ�����˶�Զิ�ӽ���ģʽ��ʱ�򣬲�Ҫ����ʹ���н���ģʽ����Ҫ��˼���ϵͳ��������ǲ��Ǻ���
 * 2.����ConcreteMediator�����˼��л������ǾͰѽ��������Ա�Ϊ���н��ߵĸ����ԣ�����ǵ��н��߻��ñ��κ�һ��ConcreteColleague�����ӡ�
 * �ŵ㣺
 * 1. Mediator�ĳ��ּ����˸���Colleague����ϣ�ʹ�ÿ��Զ����ظı�͸��ø���Colleague���Mediator��
 * 2. ���ڰѶ������Э�������˳��󣬽��н���Ϊһ�������ĸ�������װ��һ�������У�������ע�Ķ���ʹӶ�����Ա������Ϊת�Ƶ�����֮��Ľ����������ˣ��Ǿͻ�վ��һ����۵ĽǶ�ȥ����ϵͳ��
 * 
 */

int main(int argc, char **argv)
{

    ConcreteMediator *m = new ConcreteMediator();

    ConcreteColleague1 *c1 = new ConcreteColleague1(m);
    ConcreteColleague2 *c2 = new ConcreteColleague2(m);

    m->set_c1(c1);
    m->set_c2(c2);

    c1->Send("�Թ�������");
    c2->Send("û���أ��������ͣ�");

    delete m;
    delete c1;
    delete c2;

    system("pause");
    return 0;
}