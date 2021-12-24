#include <iostream>
#include <string>
#include <stdexcept>
#include "calculator.h"


using namespace std;



int main()
{
	try 
	{
		OPeration *oper;
		OperationFactory opfac;
		//oper = opfac.createOperate("/");
		//oper->setNumA(1);
		//oper->setNumB(0);
		//double result = oper->GetResult();
		//cout << "result = " << result << endl;
		//delete oper;

		cout << "����������� + - * / �е�һ����" << endl;
		string opera;
		cin >> opera;
		if (opera != "+" && opera != "-" && opera != "*" && opera != "/")
		{
			throw runtime_error("��������ȷ�Ĳ���������");
		}
		oper = opfac.createOperate(opera);

		double num_A, num_B;
		cout << "�������һ������" << endl;
		cin >> num_A;
		oper->setNumA(num_A);

		cout << "������ڶ�������" << endl;
		cin >> num_B;
		oper->setNumB(num_B);

		double result = oper->GetResult();
		cout << "result = " << result << endl;
		delete oper;
	}
	catch (runtime_error err)
	{
		cerr << err.what() << endl;
	}
	catch (range_error err)
	{
		cout << err.what() << endl;
	}

	return 0;
}