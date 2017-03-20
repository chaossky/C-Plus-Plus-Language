// 014. ConversionConstructors.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

class CAttackBuff
{
public:
	int PlusAttack;
public:
	CAttackBuff(int iPlusAttack)
	{
		PlusAttack = iPlusAttack;
	}

	int GetPlusAttack(void)
	{
		return PlusAttack;
	}
};

class CMonster
{
private:
	int Attack;
public:
	CMonster(int iAttack)
	{
		Attack = iAttack;
	}

	explicit CMonster(CAttackBuff &rAttackBuff)
	{
		Attack = rAttackBuff.GetPlusAttack();
	}

	void PrintInfo(void)
	{
		printf("������ ���ݷ� : %d\n", Attack);
	}
};

int main(void)
{
	CMonster Monster1(100);
	Monster1.PrintInfo();

	CMonster Monster2(CAttackBuff(500));
	Monster2.PrintInfo();
    return 0;
}