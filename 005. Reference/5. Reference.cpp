// 5. Reference.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

typedef struct DATA
{
	double dNum;
	int NumList[20];
}DATA;

typedef void(*pFunc)(DATA &);

void CallByReference1(DATA &rData)
{
	rData.dNum = 20.36;
}

void CallByReference2(DATA &rData)
{
	rData.dNum = 40.36;
}

int main()
{
	DATA Data;
	pFunc pSelect = CallByReference1;
	pSelect(Data);
	pSelect = CallByReference2; // �Լ� �����ʹ� ���� ����
	pSelect(Data);
	printf("Data.dNum : %.2f\n", Data.dNum);
	return 0;
}