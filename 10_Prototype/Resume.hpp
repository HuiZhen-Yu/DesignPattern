#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class ICloneable
{
public:
    ICloneable() = default;
    virtual ICloneable *Clone() = 0;
};

class Resume : public ICloneable
{
private:
    string name;
    string sex;
    string age;
    string timeArea;
    string company;

public:
    Resume() = default;
    Resume(const string &name) : name(name)
    {
    }
    //���ù�������
    void SetPersonalInfo(const string &sex, const string &age)
    {
        this->sex = sex;
        this->age = age;
    }
    //���ø�����Ϣ
    void SetWorkExperience(const string &timeArea, const string &company)
    {
        this->timeArea = timeArea;
        this->company = company;
    }
    //��ʾ
    void Display()
    {
        cout << "name: " << name << "  sex: " << sex << "  age: " << age << endl;
        cout << "����������" << timeArea << " " << company << endl;
    }

    ICloneable* Clone()
    {
        
        Resume * cc1 = nullptr;
        cc1 = new Resume(name);
        cc1->SetPersonalInfo(this->sex, this->age);
        cc1->SetWorkExperience(this->timeArea, this->company);
        return (ICloneable *)cc1;
    }
};
