#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

//��Ʒ�࣬�ɶ����������
class Product
{
private:
    vector<string> *parts = new vector<string>();

public:
    void Add(const string &part)
    {
        parts->push_back(part);
    }
    void show()
    {
        cout << "\n��Ʒ ���� ------" << endl;
        for (auto a : *parts)
            cout << a;
        cout << endl;
    }
    ~Product()
    {
        delete parts;
    }
};

//���������࣬ȷ����Ʒ����������PartA��PartB��ɣ�������һ���õ���Ʒ�����ķ���GetResult
class Builder
{
public:
    virtual void BuildPartA() = 0;
    virtual void BuildPartB() = 0;
    virtual Product *GetResult() = 0;
    virtual ~Builder() = default;
};

//����Ľ�����
class ConcreteBuilder1 : public Builder
{
private:
    Product *product = new Product();

public:
    void BuildPartA() override
    {
        product->Add("����A");
    }
    void BuildPartB() override
    {
        product->Add("����B");
    }
    Product *GetResult() override
    {
        return product;
    }
    ~ConcreteBuilder1()
    {
        delete product;
    }
};

//����Ľ�����
class ConcreteBuilder2 : public Builder
{
private:
    Product *product = new Product();

public:
    void BuildPartA() override
    {
        product->Add("����X");
    }
    void BuildPartB() override
    {
        product->Add("����Y");
    }
    Product *GetResult() override
    {
        return product;
    }
    ~ConcreteBuilder2()
    {
        delete product;
    }
};

//ָ����
class Director
{
public:
    void Construct(Builder *builder)
    {
        builder->BuildPartA();
        builder->BuildPartB();
    }
};