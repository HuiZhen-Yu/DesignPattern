#include <iostream>
#include <string>
#include "Game_save.hpp"
#include "Memento.hpp"

using namespace std;

/*
 * ����¼ģʽ(Memonto):�ڲ��ƻ���װ�Ե�ǰ���£�����һ�������ڲ���״̬�����ڸö���֮�Ᵽ�����״̬�������Ժ�Ϳɽ��ö���ָ���ԭ�ȱ����״̬��
 * �����ĳ��ϵͳ����������ģʽʱ����Ҫʵ������ĳ������ܣ���ô����ģʽ�������ñ���¼ģʽ���洢���ܳ�����״̬��
 */

int main()
{
    Originator *o = new Originator();
    o->set_state("On");
    o->show();

    Caretaker *c = new Caretaker();
    c->set_memento(o->CreateMemento());

    o->set_state("Off");
    o->show();

    o->set_memento(c->get_memento());
    o->show();
    delete o, c;

    GameRole *lixiaoyao = new GameRole();
    lixiaoyao->GetInitState();
    lixiaoyao->StateDisplay();

    //�������
    RoleStateCaretaker *stateAdmin = new RoleStateCaretaker();
    stateAdmin->set(lixiaoyao->SaveState());

    lixiaoyao->Fight();
    lixiaoyao->StateDisplay();

    lixiaoyao->RecoveryState(stateAdmin->get());
    lixiaoyao->StateDisplay();
    delete lixiaoyao, stateAdmin;

    system("pause");
    return 0;
}