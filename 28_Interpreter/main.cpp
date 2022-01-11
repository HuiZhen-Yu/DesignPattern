#include <iostream>
#include <string>
#include <vector>
#include "Interpreter.hpp"

using namespace std;

/*
 * ������ģʽ(interpreter): ����һ�����ԣ����������ķ���һ�ֱ�ʾ��������һ�������������������ʹ�ø����������������еľ��ӡ�
 * ���һ���ض����͵����ⷢ����Ƶ���㹻�ߣ���ô���ܾ�ֵ�ý�������ĸ���ʵ������Ϊһ���������еľ��ӡ������Ϳ��Թ���һ�����������ý�����ͨ��������Щ��������������⡣
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