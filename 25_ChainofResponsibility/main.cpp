#include <iostream>
#include <string>
#include <vector>
#include "ChainofResponsibility.hpp"

using namespace std;

/*
 * 职责链模式(Chain of Responsibility): 使多个对象都有机会处理请求，从而避免请求地发送者和接收者之间地耦合关系。将这个对象连城一条链，并沿着这条链传递该请求，知道有一个对象处理它为止。
 * 当客户提交一个请求地时候，亲求使沿着链传递知道有一个ConcreteHandler对象负责处理它
 * 这使得接收者和发送者都没有对方明确地信息，且链中地对象自己也并不知道链地结构。结果是职责链可简化对象地相互连接，他们仅需要保持一个指向后继者地引用，而不需要保持他所有的候选接受者的引用
 * 我们可以随时增加或者修改处理一个请求的结构，增强了给对象指派职责的灵活性。
 * 注意：当一个请求极有可能到了链的末端都得不到很好的处理，或者因为没有正确配置而得不到处理。
 */

int main(int argc, char **argv)
{
    Handler *h1 = new ConcreteHandler1();
    Handler *h2 = new ConcreteHandler2();
    Handler *h3 = new ConcreteHandler3();

    h1->SetSuccessor(h2);
    h2->SetSuccessor(h3);

    vector<int> requests = {2, 5, 14, 22, 18, 2, 27, 20};
    for (auto i : requests)
    {
        h1->HandleRequest(i);
    }
    delete h1;
    system("pause");
    return 0;
}