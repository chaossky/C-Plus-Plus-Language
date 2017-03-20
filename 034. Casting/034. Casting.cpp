// 034. Casting.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

class CParent
{
public:
	CParent(void) { printf("�θ� ������ ȣ��!\n"); }
	virtual ~CParent(void) { printf("�θ� �Ҹ��� ȣ��!\n"); }
	virtual void PrintInfo(void) { printf("���� �θ��!\n"); }
};

class CChild : public CParent
{
private:
	int PocketMoney;
public:
	CChild(void) : PocketMoney(10000) { printf("�ڽ� ������ ȣ��!\n"); }
	virtual ~CChild(void) { printf("�ڽ� �Ҹ��� ȣ��!\n"); }
	virtual void PrintInfo(void) { printf("���� �ڽ��̴�!\n"); }
	void PrintPocketMoney(void) { printf("���� �뵷 : %d��\n", PocketMoney); }
};

void Action(CParent *pParent)
{
	pParent->PrintInfo();
	CChild *pTemp = dynamic_cast<CChild *>(pParent);
	if (pTemp == nullptr)
	{
		printf("�θ�� �뵷�� �����ϴ�...\n");
	}
	else
	{
		pTemp->PrintPocketMoney();
	}
}

int main(void)
{
	int iNum = 10;
	double* pNum = reinterpret_cast<double *>(&iNum); // int ������ �ѱ��
	printf("iNum  : %d\n", iNum);
	printf("*pNum : %d\n\n", *(int *)pNum);

	// ������ �� ���� ����
	iNum = 200;
	printf("iNum  : %d\n", iNum);
	printf("*pNum : %d\n\n", *(int *)pNum);

	// ������ ����Ű�� �����ʹ� �� ���� �Ұ���
	//*pNum = 20;
	//printf("iNum  : %d\n", iNum);
	//printf("*pNum : %d\n", *(int *)pNum);

	// �̷��� ���ڿ͵� ��ȯ ����
	int *pAddress = reinterpret_cast<int *>(0x12345678);
	return 0;
}