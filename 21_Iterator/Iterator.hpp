#ifndef ITERATOR_H_
#define ITERATOR_H_

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>

using std::cout;
using std::endl;
using std::list;
using std::map;
using std::string;
using std::vector;

typedef int object;

class Iterator_item
{
public:
    virtual object First() = 0;
    virtual object Next() = 0;
    virtual bool IsDone() = 0;
    virtual object CurentItem() = 0;
};

class Aggregate
{
public:
    virtual Iterator_item *CreateIterator() = 0;
};

class ConcreteIterator;
class ConcreteAggregate : public Aggregate
{
private:
    vector<object> items;

public:
    Iterator_item *CreateIterator() override
    {
        return new ConcreteIterator(this);
    }
    int count()
    {
        return items.size();
    }
    object &operator[](int index)
    {
        return this->items[index];
    }
};

class ConcreteIterator : public Iterator_item
{

private:
    ConcreteAggregate *aggregate;
    int current = 0;

public:
    ConcreteIterator(ConcreteAggregate *aggregate)
        : aggregate(aggregate)
    {
    }
    object First() override
    {
        return aggregate->operator[](0);
    }
    object Next() override
    {
        object ret = 0;
        current++;
        if (current < aggregate->count())
        {
            ret = aggregate->operator[](current);
        }
        return ret;
    }
    bool IsDone() override
    {
        return current >= aggregate->count() ? true : false;
    }
    object CurentItem() override
    {
        return aggregate->operator[](current);
    }
};

#endif