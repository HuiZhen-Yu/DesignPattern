#ifndef PHONE_ITEM_H_
#define PHONE_ITEM_H_

#include <iostream>
#include <string>

using namespace std;

//手机软件
class HandsetSoft
{
public:
    virtual void Run() = 0;
    virtual ~HandsetSoft() {}
};

//手机游戏
class HandsetGame : public HandsetSoft
{
public:
    void Run() override
    {
        cout << "运行手机游戏！！" << endl;
    }
};

//手机通讯录
class HandsetAddressList : public HandsetSoft
{
public:
    void Run() override
    {
        cout << "运行手机通讯录！！" << endl;
    }
};

//手机品牌
class HandsetBrand
{
protected:
    HandsetSoft *soft;
    //设置手机软件
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

//品牌N品牌M具体类
class HandsetBrandN : public HandsetBrand
{
public:
    void Run() override
    {
        cout<<"手机N开机  ";
        soft->Run();
    }
    
};

class HandsetBrandM : public HandsetBrand
{
public:
    void Run() override
    {
        cout<<"手机M开机  ";
        soft->Run();
    }
};

#endif // !PHONE_ITEM_H_