// 6. NewDelete.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//
#include "stdafx.h"

#define SAFEDELETEARRAY(PTR) delete[](PTR); PTR = NULL
#define SAFEDELETE(PTR) delete(PTR); PTR = NULL

#pragma pack(push, 1)
typedef struct CUSTOMERINFO
{
	char Name[10]; // �� �̸�
	int  Age;      // �� ����
	int  PhoneNum; // �� �ڵ��� ��ȣ
}CUSTOMERINFO, *PCUSTOMERINFO, **PPCUSTOMERINFO;
#pragma pack(pop)

struct B
{
	int n;
	double j;
	B(int a, double b)
	{
		n = a;
		j = b;
	}
};

int main()
{
	// 5��
	PPCUSTOMERINFO ppCustomerList = new PCUSTOMERINFO[5];

	// 8��
	for (int i = 0; i < 5; ++i)
	{
		ppCustomerList[i] = new CUSTOMERINFO[8];
	}

	printf("�Ҵ�� ũ�� : %d����Ʈ\n", _msize(ppCustomerList[0]) * 5);
	ppCustomerList[4][7].Age = 30;
	printf("ppCustomerList[4][7].Age : %d\n", ppCustomerList[4][7].Age);

	for (int i = 0; i < 5; ++i)
	{
		SAFEDELETE(ppCustomerList[i]);
	}
	SAFEDELETE(ppCustomerList);
	return 0;
}