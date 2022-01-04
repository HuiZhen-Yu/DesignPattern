#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

//产品类，由多个部件构成
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
        cout << "\n产品 创建 ------" << endl;
        for (auto a : *parts)
            cout << a;
        cout << endl;
    }
    ~Product()
    {
        delete parts;
    }
};

//抽象建造者类，确定产品由两个部件PartA和PartB组成，并成名一个得到产品建造后的方法GetResult
class Builder
{
public:
    virtual void BuildPartA() = 0;
    virtual void BuildPartB() = 0;
    virtual Product *GetResult() = 0;
    virtual ~Builder() = default;
};

//具体的建造者
class ConcreteBuilder1 : public Builder
{
private:
    Product *product = new Product();

public:
    void BuildPartA() override
    {
        product->Add("部件A");
    }
    void BuildPartB() override
    {
        product->Add("部件B");
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

//具体的建造者
class ConcreteBuilder2 : public Builder
{
private:
    Product *product = new Product();

public:
    void BuildPartA() override
    {
        product->Add("部件X");
    }
    void BuildPartB() override
    {
        product->Add("部件Y");
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

//指挥类
class Director
{
public:
    void Construct(Builder *builder)
    {
        builder->BuildPartA();
        builder->BuildPartB();
    }
};