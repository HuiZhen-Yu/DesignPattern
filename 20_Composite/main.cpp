#include <iostream>
#include <string>
#include "Composite.hpp"
#include "Com_item.hpp"

using namespace std;

/*
 * 组合模式(Composite)，将对象组合成树形结构以表示'部分整体的层次结构'。组合模式使得用户对单个对象和组合对象的使用具有一致性。
 * 整体和部分可以一致对待问题
 * 透明方式与安全方式：
 * 透明方式：Leaf中也有add和remove，在Component中声明所有用来管理子对象的方法，其中包括add，remove等等。这样实现Component接口的所有子类都具备了Add和Remove。这样做的好处是叶节点和直接点对于外界没有区别，他们具备完全一致的行为接口。问题是leaf中的add和remove实现是没有意义的
 * 安全方式：在component中不去声明add和remove方法，那么子类的leaf就不需要实现它，而是在Composite声明所有用来管理子类对象的方法，不够透明，客户端调用带来不变，需要判断
 * 当需求中是体现部分与整体的层次的时候，以及你希望用户可以忽略组合对象与单个对象的不同，统一的使用组合结构中的所有对象的时候，就应该考虑使用组合对象。
 * 
 * 好处：
 * 基本对象可以被组合成更加复杂的组合对象，而这个组合对象又可以被组合，这样不断地递归下去，客户代码中，任何用到基本对象的地方都可以使用组合对象了。
 */

int main()
{
    Composite *root = new Composite("root");
    root->Add(new Leaf("Leaf A"));
    root->Add(new Leaf("Leaf B"));

    Composite *comp = new Composite("Composite X");
    comp->Add(new Leaf("Leaf XA"));
    comp->Add(new Leaf("Leaf Xb"));

    root->Add(comp);

    Composite *comp2 = new Composite("Composite XY");
    comp2->Add(new Leaf("Leaf XYA"));
    comp2->Add(new Leaf("Leaf XYB"));
    comp->Add(comp2);

    root->Add(new Leaf("Leaf C"));
    Leaf *leaf = new Leaf("Leaf D");
    root->Add(leaf);
    // root->Remove(leaf);

    root->Display(1);
    delete root;
    // delete comp;
    // delete comp2;
    // delete leaf;
    // delete leaf, comp2, comp, root;

    ConcreteCompany *root1 = new ConcreteCompany("北京总公司");
    root1->Add(new HRDepartment("总公司人力资源部"));
    root1->Add(new FinanceDepartment("总公司财务部"));

    ConcreteCompany *comp_sh = new ConcreteCompany("上海华东分公司");
    comp_sh->Add(new HRDepartment("华东分公司人力资源部"));
    comp_sh->Add(new FinanceDepartment("华东分公司财务部"));
    root1->Add(comp_sh);

    ConcreteCompany *comp_nj = new ConcreteCompany("南京办事处");
    comp_nj->Add(new HRDepartment("南京办事处人力资源部"));
    comp_nj->Add(new FinanceDepartment("南京办事处财务部"));
    comp_sh->Add(comp_nj);

    ConcreteCompany *comp_hz = new ConcreteCompany("杭州办事处");
    comp_hz->Add(new HRDepartment("杭州办事处人力资源部"));
    comp_hz->Add(new FinanceDepartment("杭州办事处财务部"));
    comp_sh->Add(comp_hz);
    cout<<"\n"<<"结构图:"<<endl;
    root1->Display(1);

    cout<<"\n"<<"职责："<<endl;
    root1->LineofDuty();
    delete root1;
    
    system("pause");
    return 0;
}