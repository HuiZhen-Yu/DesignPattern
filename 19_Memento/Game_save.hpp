#ifndef GAME_SAVE_H_
#define GAME_SAVE_H_

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class RoleStateMemento
{
private:
    int vit;
    int atk;
    int def;

public:
    RoleStateMemento(int vit_o, int atk_o, int def_o)
        : vit(vit_o), atk(atk_o), def(def_o)
    {
    }
    int get_vit() const
    {
        return vit;
    }
    void set_vit(int value)
    {
        vit = value;
    }
    int get_atk() const
    {
        return atk;
    }
    void set_atk(int value)
    {
        atk = value;
    }
    int get_def() const
    {
        return def;
    }
    void set_def(int value)
    {
        def = value;
    }
};

class GameRole
{
private:
    int vit; //������
    int atk; //������
    int def; //������

public:
    int get_vit() const
    {
        return vit;
    }
    void set_vit(int value)
    {
        vit = value;
    }
    int get_atk() const
    {
        return atk;
    }
    void set_atk(int value)
    {
        atk = value;
    }
    int get_def() const
    {
        return def;
    }
    void set_def(int value)
    {
        def = value;
    }
    //״̬��ʾ
    void StateDisplay()
    {

        cout << "��ɫ��ǰ״̬��" << endl;
        cout << "������" << vit << endl;
        cout << "��������" << atk << endl;
        cout << "��������" << def << endl;
        cout << endl;
    }
    //�õ���ʼ״̬
    void GetInitState()
    {
        vit = 100;
        atk = 100;
        def = 100;
    }
    //ս��
    void Fight()
    {
        vit = 0;
        atk = 0;
        def = 0;
    }
    RoleStateMemento *SaveState()
    {
        return (new RoleStateMemento(vit, atk, def));
    }
    void RecoveryState(RoleStateMemento *memento)
    {
        vit = memento->get_vit();
        atk = memento->get_atk();
        def = memento->get_def();
    }
};

class RoleStateCaretaker
{
private:
    RoleStateMemento *memento;

public:
    RoleStateMemento *get()
    {
        return memento;
    }
    void set(RoleStateMemento *value)
    {
        delete memento;
        memento = value;
    }
};
#endif