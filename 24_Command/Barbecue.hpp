#ifndef BARBECUE_H_
#define BARBECUE_H_

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Barbecuer
{
public:
    //������
    void BakeMutton()
    {
        cout << "�����⴮����" << endl;
    }

    //���a��
    void BakeChickenWing()
    {
        cout << "���a�ᣡ��" << endl;
    }
};

class Command
{
protected:
    Barbecuer *receiver;

public:
    Command(Barbecuer *receiver)
        : receiver(receiver)
    {
    }
    virtual void ExcuteCommand() = 0;
    virtual ~Command() {}
};

class BakeMuttonCommand : public Command
{
public:
    BakeMuttonCommand(Barbecuer *receiver)
        : Command(receiver)
    {
    }
    void ExcuteCommand() override
    {
        receiver->BakeMutton();
    }
};

class BakeChickenWingCommand : public Command
{
public:
    BakeChickenWingCommand(Barbecuer *receiver)
        : Command(receiver)
    {
    }
    void ExcuteCommand() override
    {
        receiver->BakeChickenWing();
    }
};

class waiter
{
private:
    vector<string> comand_names;
    map<string, Command *> comands;

public:
    void SetOrder(Command *command)
    {
        //��һ��ָ��
    }
    void CancelOrder(Command * command)
    {
        //��һ��ָ��
    }
    void Notify() 
    {
        //֪ͨȫ��ָ��
    }
};
#endif