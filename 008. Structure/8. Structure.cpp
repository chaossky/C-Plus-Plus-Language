// 8. Structure.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

struct PRODUCTINFO
{
	char Name[20];
	int  Price;
	void PrintInfo(void);
};
typedef PRODUCTINFO *PPRODUCTINFO;

// �Ҽ��� ������ ::���� �����ϸ� ��
void PRODUCTINFO::PrintInfo(void)
{
	printf("�̸� : %12s\n", this->Name);
	printf("���� : %11d��\n", this->Price);
}

int main(void)
{
	PRODUCTINFO Lego = { "�з��Ͼ� ����", 8000000 };
	Lego.PrintInfo();
	return 0;
}
