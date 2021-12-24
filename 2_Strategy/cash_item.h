#pragma once

#include <memory>
#include <string>
#include <sstream>
#include <cmath>

using std::string;
using std::istringstream;

class CashSuper
{
public:
	CashSuper() = default;
	~CashSuper() = default;
	virtual double acceptCash(double money)
	{
		return money;
	}

private:

};

class CashNormal:public CashSuper
{
public:
	CashNormal() = default;
	~CashNormal() = default;

	double acceptCash(double money) override
	{
		return money;
	}
private:
	
};

class CashRebate:public CashSuper
{
public:
	CashRebate() = default;
	CashRebate(string moneyRebate)
	{
		istringstream moneyC(moneyRebate);
		moneyC >> this->moneyRebate;
	}
	~CashRebate() = default;

	double acceptCash(double money) override
	{
		return money * moneyRebate;
	}
private:
	double moneyRebate = 1.0;
};

class CashReturn :public CashSuper
{
public:
	CashReturn() = default;
	CashReturn(string moneyCondition, string moneyReturn)
	{
		istringstream moneyC(moneyCondition);
		istringstream moneyR(moneyReturn);
		moneyC >> this->moneyCondition;
		moneyR >> this->moneyReturn;
	}
	~CashReturn() = default;

	double acceptCash(double money) override
	{
		double result = money;
		if (money >= moneyCondition)
			result = money - floor(money / moneyCondition) * moneyReturn;
		return result;
	}
private:
	double moneyCondition = 1.0;
	double moneyReturn = 0.0;
};

class CashContext
{
public:
	CashContext() = default;
	CashContext(string type)
	{
		switch(*type.c_str())
		{
		case 'N':
		{
			CashNormal *cs0 = new CashNormal();
			cs = cs0;
			break;
		}
		case 'B':
		{
			CashReturn *cs1 = new CashReturn("300", "100");
			cs = cs1;
			break;
		}
		case 'R':
		{
			CashRebate *cs2 = new CashRebate("0.8");
			cs = cs2;
			break;
		}
		}
	}

	double GetResult(double money)
	{
		return cs->acceptCash(money);
	}
	~CashContext()
	{
		delete cs;
	}

private:
	CashSuper *cs = nullptr;
};

