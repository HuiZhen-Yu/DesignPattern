#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

//�׷�
class LeiFen
{
public:
    void Sweep()
    {
        cout << "ɨ��" << endl;
    }

    void Wash()
    {
        cout << "ϴ�·�" << endl;
    }

    void BuyRice()
    {
        cout << "����" << endl;
    }
};

//ѧ�׷�Ĵ�ѧ����̳��׷�
class Undergraduate : public LeiFen
{
};

//����־Ը��
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

//�׷湤��
class IFactory
{
public:
    virtual LeiFen *createdLeiFeng() = 0;
};

//ѧ�׷�Ĵ�ѧ������
class UndergraduateFactory : public IFactory
{
public:
    LeiFen *createdLeiFeng() override
    {
        return new Undergraduate();
    }
};

//����־Ը�߹���
class VolunteerFactory : public IFactory
{
public:
    LeiFen *createdLeiFeng() override
    {
        return new Volunteer();
    }
};