#ifndef PHONE_ITEM_H_
#define PHONE_ITEM_H_

#include <iostream>
#include <string>

using namespace std;

//�ֻ����
class HandsetSoft
{
public:
    virtual void Run() = 0;
    virtual ~HandsetSoft() {}
};

//�ֻ���Ϸ
class HandsetGame : public HandsetSoft
{
public:
    void Run() override
    {
        cout << "�����ֻ���Ϸ����" << endl;
    }
};

//�ֻ�ͨѶ¼
class HandsetAddressList : public HandsetSoft
{
public:
    void Run() override
    {
        cout << "�����ֻ�ͨѶ¼����" << endl;
    }
};

//�ֻ�Ʒ��
class HandsetBrand
{
protected:
    HandsetSoft *soft;
    //�����ֻ����
public:
    void SetHandsetSoft(HandsetSoft *soft)
    {
        this->soft = soft;
    }
    virtual void Run() = 0;
    virtual ~HandsetBrand()
    {
        delete this->soft;
    }
};

//Ʒ��NƷ��M������
class HandsetBrandN : public HandsetBrand
{
public:
    void Run() override
    {
        cout<<"�ֻ�N����  ";
        soft->Run();
    }
    
};

class HandsetBrandM : public HandsetBrand
{
public:
    void Run() override
    {
        cout<<"�ֻ�M����  ";
        soft->Run();
    }
};

#endif // !PHONE_ITEM_H_