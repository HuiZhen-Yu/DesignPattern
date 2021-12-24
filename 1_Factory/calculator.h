#pragma once

#include <stdexcept>
#include <iostream>
#include <string>
#include <memory>

using std::string;

class OPeration
{
public:
	OPeration() = default;
	~OPeration() = default;
	double getNumA() const
	{	return _numberA;	}

	void setNumA(double value)
	{	_numberA = value;	}

	double getNumB() const
	{	return _numberB;	}

	void setNumB(double value)
	{	_numberB = value;	}

	virtual double GetResult() = 0;

protected:
	double _numberA = 0;
	double _numberB = 0;
};

class OperationAdd : public OPeration
{
public:
	OperationAdd() = default;
	~OperationAdd() = default;

	double GetResult() override
	{
		double result = 0;
		result = _numberA + _numberB;
		return result;
	}
private:

};

class OperationSub : public OPeration
{
public:
	OperationSub() = default;
	~OperationSub() = default;

	double GetResult() override
	{
		double result = 0;
		result = _numberA - _numberB;
		return result;
	}
private:

};

class OperationMul : public OPeration
{
public:
	OperationMul() = default;
	~OperationMul() = default;

	double GetResult() override
	{
		double result = 0;
		result = _numberA * _numberB;
		return result;
	}
private:

};

class OperationDiv : public OPeration
{
public:
	OperationDiv() = default;
	~OperationDiv() = default;

	double GetResult() override
	{
		double result = 0;
		if (_numberB == 0)
		{
			throw std::range_error(" 除数不能为0！！！ ");
		}
		result = _numberA / _numberB;
		return result;
	}
private:

};

class OperationFactory
{
public:
	OperationFactory() = default;
	~OperationFactory() = default;

	OPeration*  createOperate(string operate)
	{
		OPeration *oper = nullptr;
		switch (*operate.c_str())
		{
		case '+':
			oper = new OperationAdd();
			break;
		case '-':
			oper = new OperationSub();
			break;
		case '*':
			oper = new OperationMul();
			break;
		case '/':
			oper = new OperationDiv();
			break;
		}
		return oper;
	}
private:

};

