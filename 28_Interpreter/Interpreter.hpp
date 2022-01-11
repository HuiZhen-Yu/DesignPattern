#ifndef INTERPRETER_H__
#define INTERPRETER_H__

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Context
{
private:
    string input;
    string output;

public:
    string get_input()
    {
        return input;
    }
    void set_input(string input)
    {
        this->input = input;
    }
    string get_output()
    {
        return output;
    }
    void set_output(string output)
    {
        this->output = output;
    }
};

class AbstractExpression
{
public:
    virtual void Interpret(Context *context) = 0;
    virtual ~AbstractExpression() = default;
};

class TerminalExpression : public AbstractExpression
{
public:
    void Interpret(Context *context) override
    {
        cout << "ÖÕ¶Ë½âÊÍÆ÷" << endl;
    }
};

class NoterminalExpression : public AbstractExpression
{
public:
    void Interpret(Context *context) override
    {
        cout << "·ÇÖÕ¶Ë½âÊÍÆ÷" << endl;
    }
};

#endif