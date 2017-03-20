// 028. Virtual.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

class CParent
{
public:
	CParent(void) { printf("�θ� ������\n"); }
	virtual ~CParent(void) { printf("�θ� �Ҹ���\n"); }
};

class CChild : public CParent
{
public:
	CChild(void) { printf("�ڽ� ������\n"); }
	virtual ~CChild(void) { printf("�ڽ� �Ҹ���\n"); }
};

void CheckDestructor(CParent *pRoot)
{
	delete pRoot;
}

int main(void)
{
	printf("CParent ������ �Ҹ�\n");
	CParent *pParent = new CParent;
	CheckDestructor(pParent);
	printf("\n");

	printf("CChild ������ �Ҹ�\n");
	pParent = new CChild;
	CheckDestructor(pParent);
	return 0;
}


























