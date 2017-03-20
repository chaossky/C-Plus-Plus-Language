// 7. Nullptr.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

#define SAFEDELETEARRAY(PTR) delete[](PTR); PTR = nullptr
#define SAFEDELETE(PTR) delete(PTR); PTR = nullptr

#pragma pack(push, 1)
typedef struct PLAYERINFO
{
	char Name[10];  // ĳ���� �̸�
	int  Level;     // ĳ���� ����
	int  HP, HPMAX; // ĳ���� ü��
	int  MP, MPMAX; // ĳ���� ����
}PLAYERINFO, *PPLAYERINFO;
#pragma pack(pop)

int main(void)
{
	PPLAYERINFO Player = new PLAYERINFO{"���", 16, 200, 200, 100, 100};

	printf("�÷��̾ ���� ���Դϴ�.\n");
	printf("------------------------------------------------------\n");
	printf("ĳ���� �̸� : %10s \t ĳ���� ���� : %2d\n",
		Player->Name, Player->Level);
	printf("ĳ���� ü�� : %6d/%d \t ĳ���� ���� : %3d/%d\n",
		Player->HP, Player->HPMAX, Player->MP, Player->MPMAX);
	printf("------------------------------------------------------\n");

	int iSelect;
	printf("� ����ġ�� �������? (1. ������ | 2. ����): ");
	scanf("%d", &iSelect);

	if (iSelect == 2)
	{
		SAFEDELETE(Player);
	}

	if (Player == nullptr)
	{
		printf("��ġ�� �����ؼ� �÷��̾ �׾����ϴ�...\n");
	}
	else
	{
		printf("��ġ�� ������ �����߽��ϴ�! ^^\n");
	}
	return 0;
}