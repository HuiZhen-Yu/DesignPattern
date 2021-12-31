#include <iostream>
#include <string>
#include "Prototype.hpp"
#include "Resume.hpp"
using namespace std;

/*
 * ԭ��ģʽ��Prototype������ԭ��ʵ��ָ��������������࣬����ͨ��������Щԭ�ʹ����µĶ���
 * ԭ��ģʽ��ʵ���Ǵ�һ�������ڴ�������һ���ɶ��ƵĶ��󣬶��Ҳ���Ҫ֪���κδ�����ϸ��
 * һ���ڳ�ʼ������Ϣ�������仯������£���¡����õķ������⼴�����˶��󴴽���ϸ�ڣ��ֶ����ܴ������ˣ����������ǲ������³�ʼ�����󣬶��Ƕ�̬�Ļ�ö�������ʱ��״̬
 */

/*
* ǳ��������ƣ�C#�е�MenberwiseClone()������������������ֶ���ֵ���͵ģ���Ը��ֶ�ִ����λ���ƣ�����ֶ����������ͣ��������õ����������õĶ���
* ���ԭʼ�����丱������ͬһ����
* ǳ���ƣ������ƶ�������б�����������ԭ���ĵĶ�����ͬ��ֵ�������еĶ�������������ö���Ȼָ��ԭ���Ķ���
* ��ƣ������ö���ı���ָ���ƹ����¶��󣬶�����ԭ�еı����õĶ���
*/
int main(int argc, char **argv)
{
    ConcretePrototype1 *p1 = new ConcretePrototype1("I");
    ConcretePrototype1 *c1 = (ConcretePrototype1 *)p1->Clone();
    cout << "Cloned: {0}" << c1->get() << endl;

    Resume *a = new Resume("����");
    a->SetPersonalInfo("male", "29");
    a->SetWorkExperience("1998-2000", "xxxx");

    //ֻ��Ҫ����clone�����Ϳ���ʵ���¼��������ɣ����ҿ������޸��¼�����ϸ��
    Resume *b = (Resume *)a->Clone();
    b->SetWorkExperience("1998-2006", "yyyy");

    Resume *c = (Resume *)a->Clone();
    c->SetPersonalInfo("female", "24");

    a->Display();
    b->Display();
    c->Display();

    delete a, b, c;

    string name;
    cin >> name;

    return 0;
}