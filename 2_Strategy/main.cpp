#include <iostream>
#include "cash_item.h"

/* 
* �̳�����������ģʽ ��strategy��
* �������㷨���壬�ֱ��װ��������֮���໥�滻����ģʽ���㷨�ı䷨����Ӱ�쵽ʹ���㷨�Ŀͻ�
* ����ģʽ��һ�ֶ���һϵ���㷨�ķ������Ӹ����Ͽ������е��㷨�����ͬ�Ĺ�����ֻ��ʵ�ֲ�ͬ������������ͬ�ķ�ʽ�������е��㷨�������˸����㷨��ʹ���㷨��֮������
* ����ģʽ��strategy����Ϊcontext������һϵ�еĿ����õ��㷨����Ϊ���̳���������������Щ�㷨�еĹ�������
* �ŵ㣺���˵�Ԫ���ԣ���Ϊÿ���㷨�����Լ����࣬����ͨ���Լ��Ľӿڵ�������
*/

/* ����ģʽ��򵥹������ */
using namespace std;


int main()
{
	double totalPrices = 0.0;

	/* N B R */
	CashContext csuper = CashContext("B");
	totalPrices = csuper.GetResult(200.0 * 3);
	cout << totalPrices << endl;

	return 0;
}

