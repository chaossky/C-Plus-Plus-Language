// 026. Overriding.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

class CParent
{
public:
	void Talk(void) { printf("���� �θ��!\n"); }
};

class CChild : public CParent
{
public:
	// �������̵�
	void Talk(void) { printf("���� �ڽ��̴�!\n"); }

	// �����ε�
	void Talk(int iNum) { printf("���� %d��° �ڽ��̴�!\n", iNum); }
};

int main(void)
{
	CParent Parent;
	printf("CParent�� �޼��� ȣ��!\n");
	Parent.Talk();
	Parent.CParent::Talk();
	printf("\n");

	printf("CChild�� �޼��� ȣ��!\n");
	CChild Child;
	Child.Talk();
	Child.Talk(1);
	Child.CParent::Talk();
	Child.CChild::Talk();
	Child.CChild::Talk(1);
	return 0;
}