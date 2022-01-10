#ifndef COMMAND_H_
#define COMMAND_H_

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Receiver
{
public:
    void Action()
    {
        cout << "Ö´ÐÐÇëÇó£¡£¡" << endl;
    }
    virtual ~Receiver() = default;
};

class Command
{
protected:
    Receiver *receiver;

public:
    Command(Receiver *receiver)
        : receiver(receiver)
    {
    }
    virtual void Execute() = 0;
    virtual ~Command()
    {
        delete receiver;
    }
};

class ConcreteCommand : public Command
{
public:
    ConcreteCommand(Receiver *receiver)
        : Command(receiver)
    {
    }
    void Execute() override
    {
        receiver->Action();
    }
};

class Invoker
{
private:
    Command *command;

public:
    void SetCommand(Command *command)
    {
        this->command = command;
    }
    void ExecuteCommand()
    {
        command->Execute();
    }
    ~Invoker()
    {
        delete command;
    }
};

#endif // !COMMAND_H_