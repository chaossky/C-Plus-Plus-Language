// 033. Typeid.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include <typeinfo>
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

	// ���� ���ε� ����
	printf("Ŭ������ �̸� : %s\n", typeid(*pParent).name());

	if (typeid(*pParent) == typeid(CParent))
	{
		printf("�θ�� �뵷�� �����ϴ�...\n");
	}
	else
	{
		((CChild *)pParent)->PrintPocketMoney();
	}
}

int main(void)
{
	CParent Parent;
	printf("�θ� Ŭ������ �̸� : %s\n", typeid(Parent).name());
	printf("�θ� Ŭ������ ��ȣ : %s\n\n", typeid(Parent).raw_name());
	
	CChild Child;
	printf("�ڽ� Ŭ������ �̸� : %s\n", typeid(Child).name());
	printf("�ڽ� Ŭ������ ��ȣ : %s\n\n", typeid(Child).raw_name());

	try
	{
		Action(&Parent);
		printf("\n");
		Action(&Child);
		printf("\n");
	}
	catch (std::bad_typeid &rError)
	{
		printf("���� ���� : %s\n\n", rError.what());
	}
    return 0;
}