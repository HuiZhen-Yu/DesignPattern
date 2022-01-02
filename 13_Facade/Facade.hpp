#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class SubSystemOne
{
public:
    void MehodOne()
    {
        cout << "子系统方法一" << endl;
    }
};

class SubSystemTwo
{
public:
    void MehodTwo()
    {
        cout << "子系统方法二" << endl;
    }
};

class SubSystemThree
{
public:
    void MehodThree()
    {
        cout << "子系统方法三" << endl;
    }
};

class SubSystemFour
{
public:
    void MehodFour()
    {
        cout << "子系统方法四" << endl;
    }
};

//外观类
class Facade
{
public:
    SubSystemOne *one = nullptr;
    SubSystemTwo *two = nullptr;
    SubSystemThree *three = nullptr;
    SubSystemFour *four = nullptr;

    Facade()
    {
        one = new SubSystemOne;
        two = new SubSystemTwo;
        three = new SubSystemThree;
        four = new SubSystemFour;
    }

    void MethodA()
    {
        cout << "\n 方法组A() -------" << endl;
        one->MehodOne();
        two->MehodTwo();
        three->MehodThree();
        four->MehodFour();
    }

    void MethodB()
    {
        cout << "\n 方法组B() -------" << endl;
        two->MehodTwo();
        three->MehodThree();
    }
    
    ~Facade()
    {
        delete one, two, three, four;
    }
};
