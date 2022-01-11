#include <iostream>
#include <string>
#include <vector>
#include "Interpreter.hpp"

using namespace std;

/*
 * 解释器模式(interpreter): 给定一个语言，定义它的文法的一种表示，并定义一个解释器，这个解释器使用该语言来解释语言中的句子。
 * 如果一种特定类型的问题发生的频率足够高，那么可能就值得将该问题的各个实例表述为一个简单语言中的句子。这样就可以构建一个解释器，该解释器通过解释这些句子来解决该问题。
 *
 */

int main(int argc, char **argv)
{

    Context *context = new Context();
    vector<AbstractExpression *> list;
    list.push_back((new TerminalExpression()));
    list.push_back((new NoterminalExpression()));
    list.push_back((new TerminalExpression()));
    list.push_back((new TerminalExpression()));
    for (auto i : list)
    {
        i->Interpret(context);
    }
    
    system("pause");
    return 0;
}