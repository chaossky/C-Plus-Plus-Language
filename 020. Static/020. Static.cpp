// 020. Static.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

#define RANDOMIZE() srand((unsigned int)time(nullptr))
#define RANDOM(NUM) rand() % (NUM)
#define BOREDER() printf("----------------------------------------------\n")
#define SAFEDELETEARRAY(PTR) delete[](PTR); PTR = nullptr
#define SAFEDELETE(PTR) delete(PTR); PTR = nullptr

class CEnemy
{
private:
	static int EnemyCount;
	static int EnemyIndex;
	static int EnemyMax;
	static int EnemyLevel;
	static int EnemyNowHP;
	int HP, MAXHP;
public:
	CEnemy(void)
	{
		HP = MAXHP = EnemyNowHP;
		EnemyCount++;
		EnemyIndex++;
	}

	~CEnemy(void)
	{
		EnemyCount--;
	}

	static void InitEnemy(void)
	{
		EnemyCount = 0;
		EnemyIndex = -1;
		EnemyMax   = 9;
		EnemyLevel = 1;
		EnemyNowHP = 100;
	}

	static int GetEnemyIndex(void)
	{
		return EnemyIndex;
	}

	static int GetEnemyCount(void)
	{
		return EnemyCount;
	}

	static int GetEnemyMax(void)
	{
		return EnemyMax;
	}

	static void IncreaseLevel(void)
	{
		EnemyLevel++;
		EnemyNowHP += EnemyLevel * 120;
	}

	void IncreaseHP(void)
	{
		HP += EnemyLevel * 120;
		MAXHP += EnemyLevel * 120;
	}

	int DecreaseHP(void)
	{
		HP -= EnemyLevel * 70;
		if (HP <= 0)
		{
			return -1;
		}
		return 1;
	}

	static void PrintEnemyCount(void)
	{
		printf("���� ������ �� : %d��\n", EnemyCount);
	}

	static void PrintEnemyLevel(void)
	{
		printf("���� �� ���� : %d\n", EnemyLevel);
	}

	void PrintEnmeyHP(int iEnemyIndex) const
	{
		printf("%d��° �� HP : (%3d/%3d)\n", iEnemyIndex + 1, HP, MAXHP);
	}
};
int CEnemy::EnemyCount;
int CEnemy::EnemyIndex;
int CEnemy::EnemyMax;
int CEnemy::EnemyLevel;
int CEnemy::EnemyNowHP;

int main(void)
{
	int iSelect = 0;
	char cInput;
	CEnemy **EnemyList;

	CEnemy::InitEnemy();
	RANDOMIZE();

	EnemyList = new CEnemy*[CEnemy::GetEnemyMax()];
	for (int i = 0; i < CEnemy::GetEnemyMax(); ++i)
	{
		EnemyList[i] = nullptr;
	}

	printf("1. �� ���� | 2. �� ���� ���� | 3. �� ���� ��� | 4. �� ���� | 5. ȭ�� ����\n");
	while (true)
	{
		if (kbhit() != 0)
		{
			cInput = getch();
			switch (cInput)
			{
			case '1':
				if (CEnemy::GetEnemyCount() == CEnemy::GetEnemyMax()
					|| CEnemy::GetEnemyIndex() == CEnemy::GetEnemyMax() - 1)
				{
					printf("�� �̻� ���� ������ �� �����ϴ�!\n");
					BOREDER();
					break;
				}

				EnemyList[CEnemy::GetEnemyIndex()] = new CEnemy;
				CEnemy::PrintEnemyCount();
				printf("�� ����!\n");
				BOREDER();
				break;
			case '2':
				CEnemy::IncreaseLevel();
				CEnemy::PrintEnemyLevel();
				for (int i = 0; i < CEnemy::GetEnemyMax(); ++i)
				{
					if (EnemyList[i] != nullptr)
					{
						EnemyList[i]->IncreaseHP();
					}
				}
				printf("�� ���� ����!\n");
				BOREDER();
				break;
			case '3':
				if (CEnemy::GetEnemyCount() == 0)
				{
					printf("���� �����ϴ�!\n");
					BOREDER();
					break;
				}

				for (int i = 0; i < CEnemy::GetEnemyMax(); ++i)
				{
					if (EnemyList[i] != nullptr)
					{
						EnemyList[i]->PrintEnmeyHP(i);
					}
				}
				BOREDER();
				break;
			case '4':
				if (CEnemy::GetEnemyCount() == 0)
				{
					printf("���� �����ϴ�!\n");
					BOREDER();
					break;
				}

				iSelect = RANDOM(CEnemy::GetEnemyIndex() + 1);
				if (EnemyList[iSelect] != nullptr)
				{
					if (EnemyList[iSelect]->DecreaseHP() == -1)
					{
						SAFEDELETE(EnemyList[iSelect]);
						printf("%d��° �� ����!\n", iSelect + 1);
						CEnemy::PrintEnemyCount();
					}
					else
					{
						printf("%d��° �� HP ����!\n", iSelect + 1);
					}
				}
				else
				{
					printf("���� ����!\n");
				}
				BOREDER();
				break;
			case '5':
				system("cls");
				printf("1. �� ���� | 2. �� ���� ���� | 3. �� ���� ��� | 4. �� ���� | 5. ȭ�� ����\n");
				break;
			default:
				printf("�߸��� �Է��Դϴ�.\n");
				break;
			}
		}
	}

	for (int i = 0; i < CEnemy::GetEnemyMax(); ++i)
	{
		SAFEDELETE(EnemyList[i]);
	}
	SAFEDELETEARRAY(EnemyList);
    return 0;
}