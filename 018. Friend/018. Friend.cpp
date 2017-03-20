// 018. Friend.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

struct CBaseAbility
{
	int HP, HPMAX;
	int MP, MPMAX;
	int Strength, Dexterity;
};

class CPlayer; // �Լ��� ���� ���� ����� ����
class CManager
{
	friend CPlayer;
private:
	int NowMapCode;
public:
	explicit CManager(int iNowMapCode) : NowMapCode(iNowMapCode) {}
	void PrintPlayerAbility(CPlayer &rPlayer);
};

class CPlayer
{
	friend CManager;
private:
	CBaseAbility BaseAbility;
public:
	CPlayer(int iHP, int iMP, int iStr, int iDex)
	{
		BaseAbility.HP = BaseAbility.HPMAX = iHP;
		BaseAbility.MP = BaseAbility.MPMAX = iMP;
		BaseAbility.Strength = iStr;
		BaseAbility.Dexterity = iDex;
	}

	void PrintNowMapCode(CManager &Manager)
	{
		printf("���� �� �ڵ� : %05d\n", Manager.NowMapCode);
	}
};

void CManager::PrintPlayerAbility(CPlayer &rPlayer)
{
	printf("------------\n");
	printf("��ü�� ����\n");
	printf("------------\n");
	printf("ü�� : %d/%d\n", rPlayer.BaseAbility.HP, rPlayer.BaseAbility.HPMAX);
	printf("���� : %d/%d\n", rPlayer.BaseAbility.MP, rPlayer.BaseAbility.MPMAX);
	printf("��   : %d\n", rPlayer.BaseAbility.Strength);
	printf("��ø : %d\n", rPlayer.BaseAbility.Dexterity);
}

int main(void)
{
	CPlayer Player(100, 50, 6, 4);
	CManager Manager(5);
	Player.PrintNowMapCode(Manager);
	Manager.PrintPlayerAbility(Player);
	return 0;
}