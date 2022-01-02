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
        cout << "��ϵͳ����һ" << endl;
    }
};

class SubSystemTwo
{
public:
    void MehodTwo()
    {
        cout << "��ϵͳ������" << endl;
    }
};

class SubSystemThree
{
public:
    void MehodThree()
    {
        cout << "��ϵͳ������" << endl;
    }
};

class SubSystemFour
{
public:
    void MehodFour()
    {
        cout << "��ϵͳ������" << endl;
    }
};

//�����
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
        cout << "\n ������A() -------" << endl;
        one->MehodOne();
        two->MehodTwo();
        three->MehodThree();
        four->MehodFour();
    }

    void MethodB()
    {
        cout << "\n ������B() -------" << endl;
        two->MehodTwo();
        three->MehodThree();
    }
    
    ~Facade()
    {
        delete one, two, three, four;
    }
};
