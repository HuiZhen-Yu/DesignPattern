#ifndef FLYWEIGHT_H__
#define FLYWEIGHT_H

#include <iostream>
#include <string>
#include <map>

using namespace std;

class Flyweight
{
public:
    virtual void Operation(int extrinsicstate) = 0;
    virtual ~Flyweight() = default;
};

class ConcreteFlyweight : public Flyweight
{
public:
    void Operation(int extrinsicstate) override
    {
        cout << "具体Flyweight：" << extrinsicstate << endl;
    }
};

class UnsharedConcreteFlyweight : public Flyweight
{
public:
    void Operation(int extrinsicstate) override
    {
        cout << "不共享的具体Flyweight：" << extrinsicstate << endl;
    }
};

class FlyweightFactory
{
private:
    map<string, Flyweight *> flyweights;

public:
    FlyweightFactory()
    {
        flyweights.insert(pair<string, Flyweight *>("X", new ConcreteFlyweight()));
        flyweights.insert(pair<string, Flyweight *>("Y", new ConcreteFlyweight()));
        flyweights.insert(pair<string, Flyweight *>("Z", new ConcreteFlyweight()));
    }
    Flyweight *GetFlyweight(string key)
    {
        return flyweights[key];
    }
};
#endif