#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

//雷锋
class LeiFen
{
public:
    void Sweep()
    {
        cout << "扫地" << endl;
    }

    void Wash()
    {
        cout << "洗衣服" << endl;
    }

    void BuyRice()
    {
        cout << "买米" << endl;
    }
};

//学雷锋的大学生类继承雷锋
class Undergraduate : public LeiFen
{
};

//社区志愿者
class Volunteer : public LeiFen
{
};

class SimpleFactory
{
public:
    static LeiFen *CreateLeiFeng(const string &typ)
    {
        LeiFen *result = nullptr;
        switch (*typ.c_str())
        {
        case 'S':
            result = new Undergraduate();
            break;
        case 'V':
            result = new Volunteer();
            break;
        }
        return result;
    }
};

//雷锋工厂
class IFactory
{
public:
    virtual LeiFen *createdLeiFeng() = 0;
};

//学雷锋的大学生工厂
class UndergraduateFactory : public IFactory
{
public:
    LeiFen *createdLeiFeng() override
    {
        return new Undergraduate();
    }
};

//社区志愿者工厂
class VolunteerFactory : public IFactory
{
public:
    LeiFen *createdLeiFeng() override
    {
        return new Volunteer();
    }
};