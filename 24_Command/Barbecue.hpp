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
    //烤羊肉
    void BakeMutton()
    {
        cout << "烤羊肉串！！" << endl;
    }

    //烤鷄翅
    void BakeChickenWing()
    {
        cout << "烤鷄翅！！" << endl;
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
        //加一个指令
    }
    void CancelOrder(Command * command)
    {
        //减一个指令
    }
    void Notify() 
    {
        //通知全部指令
    }
};
#endif