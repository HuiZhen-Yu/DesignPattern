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
    int vit; //生命力
    int atk; //攻击力
    int def; //防御力

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
    //状态显示
    void StateDisplay()
    {

        cout << "角色当前状态：" << endl;
        cout << "体力：" << vit << endl;
        cout << "攻击力：" << atk << endl;
        cout << "防御力：" << def << endl;
        cout << endl;
    }
    //得到初始状态
    void GetInitState()
    {
        vit = 100;
        atk = 100;
        def = 100;
    }
    //战斗
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