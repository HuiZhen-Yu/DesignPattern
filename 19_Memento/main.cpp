#include <iostream>
#include <string>
#include "Game_save.hpp"
#include "Memento.hpp"

using namespace std;

/*
 * 备忘录模式(Memonto):在不破坏分装性的前提下，捕获一个对象内部的状态，并在该对象之外保存这个状态。这样以后就可将该对象恢复到原先保存的状态。
 * 如果在某个系统中适用命令模式时，需要实现命令的撤销功能，那么命令模式可以适用备忘录模式来存储可能撤销的状态。
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

    //保存进度
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