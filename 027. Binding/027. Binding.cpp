// 027. Binding.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

class CParent
{
public:
	void Talk(void) { printf("���� �θ��!\n"); }
};

class CChild : public CParent
{
private:
	int PocketMoney; // �뵷
public:
	CChild(void) : PocketMoney(10000) {}
	void Talk(void) { printf("���� �ڽ��̴�!\n"); }
	void Talk(int iNum) { printf("���� %d��° �ڽ��̴�!\n", iNum); }
	void ShowPocketMoney(void) { printf("�뵷 : %d��\n", PocketMoney); }
};

void WhoIsTalkingNow(CParent *pRoot, int iSelect)
{
	(iSelect == 1) ? (pRoot->Talk()) : (((CChild *)pRoot)->Talk());
	printf("\n");
}

int main(void)
{
	CParent Parent;
	CChild Child;
	WhoIsTalkingNow(&Parent, 1);
	WhoIsTalkingNow(&Child, 2);
	return 0;
}