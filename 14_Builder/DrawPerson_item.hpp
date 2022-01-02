#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Graphics
{
public:
    void DrawSomething(const string &something)
    {
        cout << something << endl;
    }
};

class PersonBuilder
{
protected:
    Graphics *g;

public:
    PersonBuilder(Graphics *g) : g(g) {}
    virtual void BuildHead() = 0;
    virtual void BuildBody() = 0;
    virtual void BuildArmLeft() = 0;
    virtual void BuildArmRight() = 0;
    virtual void BuildLegLeft() = 0;
    virtual void BuildLegRight() = 0;
};

class PersonThinBuilder : public PersonBuilder
{
public:
    PersonThinBuilder(Graphics *g) : PersonBuilder(g)
    {
    }
    void BuildHead() override
    {
        g->DrawSomething("Draw Thin Person's Head");
    }
    void BuildBody() override
    {
        g->DrawSomething("Draw Thin Person's Body");
    }
    void BuildArmLeft() override
    {
        g->DrawSomething("Draw Thin Person's Arm Left");
    }
    void BuildArmRight() override
    {
        g->DrawSomething("Draw Thin Person's Arm Right");
    }
    void BuildLegLeft() override
    {
        g->DrawSomething("Draw Thin Person's Leg Left");
    }
    void BuildLegRight() override
    {
        g->DrawSomething("Draw Thin Person's Leg Right");
    }
};

class PersonDirector
{
private:
    PersonBuilder *pb;

public:
    PersonDirector(PersonBuilder *pbr) : pb(pbr)
    {
    }
    void CreatePerson()
    {
        pb->BuildHead();
        pb->BuildBody();
        pb->BuildArmLeft();
        pb->BuildArmRight();
        pb->BuildLegLeft();
        pb->BuildLegRight();
    }
};

