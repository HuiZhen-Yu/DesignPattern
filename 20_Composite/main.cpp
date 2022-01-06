#include <iostream>
#include <string>
#include "Composite.hpp"
#include "Com_item.hpp"

using namespace std;

/*
 * ���ģʽ(Composite)����������ϳ����νṹ�Ա�ʾ'��������Ĳ�νṹ'�����ģʽʹ���û��Ե����������϶����ʹ�þ���һ���ԡ�
 * ����Ͳ��ֿ���һ�¶Դ�����
 * ͸����ʽ�밲ȫ��ʽ��
 * ͸����ʽ��Leaf��Ҳ��add��remove����Component�������������������Ӷ���ķ��������а���add��remove�ȵȡ�����ʵ��Component�ӿڵ��������඼�߱���Add��Remove���������ĺô���Ҷ�ڵ��ֱ�ӵ�������û���������Ǿ߱���ȫһ�µ���Ϊ�ӿڡ�������leaf�е�add��removeʵ����û�������
 * ��ȫ��ʽ����component�в�ȥ����add��remove��������ô�����leaf�Ͳ���Ҫʵ������������Composite�����������������������ķ���������͸�����ͻ��˵��ô������䣬��Ҫ�ж�
 * �������������ֲ���������Ĳ�ε�ʱ���Լ���ϣ���û����Ժ�����϶����뵥������Ĳ�ͬ��ͳһ��ʹ����Ͻṹ�е����ж����ʱ�򣬾�Ӧ�ÿ���ʹ����϶���
 * 
 * �ô���
 * ����������Ա���ϳɸ��Ӹ��ӵ���϶��󣬶������϶����ֿ��Ա���ϣ��������ϵصݹ���ȥ���ͻ������У��κ��õ���������ĵط�������ʹ����϶����ˡ�
 */

int main()
{
    Composite *root = new Composite("root");
    root->Add(new Leaf("Leaf A"));
    root->Add(new Leaf("Leaf B"));

    Composite *comp = new Composite("Composite X");
    comp->Add(new Leaf("Leaf XA"));
    comp->Add(new Leaf("Leaf Xb"));

    root->Add(comp);

    Composite *comp2 = new Composite("Composite XY");
    comp2->Add(new Leaf("Leaf XYA"));
    comp2->Add(new Leaf("Leaf XYB"));
    comp->Add(comp2);

    root->Add(new Leaf("Leaf C"));
    Leaf *leaf = new Leaf("Leaf D");
    root->Add(leaf);
    // root->Remove(leaf);

    root->Display(1);
    delete root;
    // delete comp;
    // delete comp2;
    // delete leaf;
    // delete leaf, comp2, comp, root;

    ConcreteCompany *root1 = new ConcreteCompany("�����ܹ�˾");
    root1->Add(new HRDepartment("�ܹ�˾������Դ��"));
    root1->Add(new FinanceDepartment("�ܹ�˾����"));

    ConcreteCompany *comp_sh = new ConcreteCompany("�Ϻ������ֹ�˾");
    comp_sh->Add(new HRDepartment("�����ֹ�˾������Դ��"));
    comp_sh->Add(new FinanceDepartment("�����ֹ�˾����"));
    root1->Add(comp_sh);

    ConcreteCompany *comp_nj = new ConcreteCompany("�Ͼ����´�");
    comp_nj->Add(new HRDepartment("�Ͼ����´�������Դ��"));
    comp_nj->Add(new FinanceDepartment("�Ͼ����´�����"));
    comp_sh->Add(comp_nj);

    ConcreteCompany *comp_hz = new ConcreteCompany("���ݰ��´�");
    comp_hz->Add(new HRDepartment("���ݰ��´�������Դ��"));
    comp_hz->Add(new FinanceDepartment("���ݰ��´�����"));
    comp_sh->Add(comp_hz);
    cout<<"\n"<<"�ṹͼ:"<<endl;
    root1->Display(1);

    cout<<"\n"<<"ְ��"<<endl;
    root1->LineofDuty();
    delete root1;
    
    system("pause");
    return 0;
}