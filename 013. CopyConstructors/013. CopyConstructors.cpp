// 013. CopyConstructors.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

#define SAFEDELETE(PTR) delete PTR; PTR = nullptr
#define SAFEDELETEARRAY(PTR) delete[] PTR; PTR = nullptr

class CMonster
{
private:
	char *Name;
	int  Level;
	int  HP, HPMAX;
public:
	CMonster(void) {}

	CMonster(const char *szName, int iLevel, int iHPMAX)
	{
		// ���� ���� ����
		Name = new char[strlen(szName) + 1];
		strcpy(Name, szName);
		Level = iLevel;
		HP = HPMAX = iHPMAX;
	}

	CMonster(const CMonster &rStudent)
	{
		// ���� ���� ����
		Name = new char[strlen(rStudent.Name) + 1];
		strcpy(Name, rStudent.Name);
		Level = rStudent.Level;
		HP = HPMAX = rStudent.HPMAX;
	}

	~CMonster(void)
	{
		SAFEDELETEARRAY(Name);
	}

	void SetInfo(const char *szName, int iLevel, int iHPMAX)
	{
		// ���� ���� ����
		Name = new char[strlen(szName) + 1];
		strcpy(Name, szName);
		Level = iLevel;
		HP = HPMAX = iHPMAX;
	}

	void PrintInfo(void)
	{
		printf("���� �̸� : %s\n", Name);
		printf("���� ���� : %d\n", Level);
		printf("���� ü�� : %d/%d\n", HP, HPMAX);
	}
};

typedef CMonster *PCMonster;

int main(void)
{
	// ���� ��ü �迭 ����
	// �����ε��� ������ ȣ��
	PCMonster MonsterList =
		new CMonster[3]{CMonster("���� ���", 12, 500)};

	// SetInfo() ȣ��
	MonsterList[1].SetInfo("�ν��� ���", 9, 420);

	// ���� ������ ȣ��
	MonsterList[2] = MonsterList[0];

	for (int i = 0; i < 3; ++i)
	{
		MonsterList[i].PrintInfo();
		printf("-------------------------\n");
	}
    return 0;
}