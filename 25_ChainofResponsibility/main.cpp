#include <iostream>
#include <string>
#include <vector>
#include "ChainofResponsibility.hpp"

using namespace std;

/*
 * ְ����ģʽ(Chain of Responsibility): ʹ��������л��ᴦ�����󣬴Ӷ���������ط����ߺͽ�����֮�����Ϲ�ϵ���������������һ���������������������ݸ�����֪����һ����������Ϊֹ��
 * ���ͻ��ύһ�������ʱ������ʹ����������֪����һ��ConcreteHandler����������
 * ��ʹ�ý����ߺͷ����߶�û�жԷ���ȷ����Ϣ�������еض����Լ�Ҳ����֪�����ؽṹ�������ְ�����ɼ򻯶�����໥���ӣ����ǽ���Ҫ����һ��ָ�����ߵ����ã�������Ҫ���������еĺ�ѡ�����ߵ�����
 * ���ǿ�����ʱ���ӻ����޸Ĵ���һ������Ľṹ����ǿ�˸�����ָ��ְ�������ԡ�
 * ע�⣺��һ�������п��ܵ�������ĩ�˶��ò����ܺõĴ���������Ϊû����ȷ���ö��ò�������
 */

int main(int argc, char **argv)
{
    Handler *h1 = new ConcreteHandler1();
    Handler *h2 = new ConcreteHandler2();
    Handler *h3 = new ConcreteHandler3();

    h1->SetSuccessor(h2);
    h2->SetSuccessor(h3);

    vector<int> requests = {2, 5, 14, 22, 18, 2, 27, 20};
    for (auto i : requests)
    {
        h1->HandleRequest(i);
    }
    delete h1;
    system("pause");
    return 0;
}