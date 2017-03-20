// 035. MemberPointer.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

class CParent
{
protected:
	int Child;
public:
	CParent(void) : Child(1) {}
	virtual ~CParent(void) {}
	virtual void PrintInfo(void) { printf("���� �θ��!\n"); }
	int GetChild(void) { return Child; } // ������ ��ӵ�
};

class CChild : public CParent
{
private:
	int PocketMoney;
public:
	using CParent::Child;
	CChild(void) : PocketMoney(10000) {}
	virtual ~CChild(void) {}
	virtual void PrintInfo(void) { printf("���� �ڽ��̴�!\n"); }
	int GetPocketMoney(void) { return PocketMoney; } // �ڽ� Ŭ���� ���� �Լ�!
};

int main(void)
{
	CParent Parent;
	CChild Child;
	printf("%d\n", Child.Child); // �ű�
	return 0;
}