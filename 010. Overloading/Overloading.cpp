// 010. Overloading.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

#define SAFEDELETE(PTR) delete PTR; PTR = nullptr
#define SAFEDELETEARRAY(PTR) delete[] PTR; PTR = nullptr

// ����ü�� �ڷḸ ��Ƴ��� �� ���
struct SCORE
{
	int Kor;
	int Eng;
	int Math;
};

// Ŭ������ C�� �տ� ���̴� �� ����
class CStudent
{
private:
	char Name[10];
	SCORE Score;
public:
	void InputInfo(const char *szName, int iKor, int iEng, int iMath)
	{
		strcpy(Name, szName);
		Score.Kor = iKor;
		Score.Eng = iEng;
		Score.Math = iMath;
	}

	void PrintInfo(void)
	{
		printf("�̸�        : %s\n", Name);
		printf("��� ����   : %4d��\n", Score.Kor);
		printf("�ܱ��� ���� : %4d��\n", Score.Eng);
		printf("���� ����   : %4d��\n", Score.Math);
	}

	// ������ �и��ؼ� ���ϴ� ���(����)
	void AddExtraPoint(int iKor, int iEng, int iMath)
	{
		Score.Kor  += iKor;
		Score.Eng  += iEng;
		Score.Math += iMath;
	}

	// ������ �и��ؼ� ���ϴ� ���(�Ǽ�)
	void AddExtraPoint(double dKor, double dEng, double dMath)
	{
		Score.Kor  += (int)dKor;
		Score.Eng  += (int)dEng;
		Score.Math += (int)dMath;
	}

	// ������ ���±�� ���ϴ� ���
	void AddExtraPoint(SCORE ExtraPoint)
	{
		Score.Kor  += ExtraPoint.Kor;
		Score.Eng  += ExtraPoint.Eng;
		Score.Math += ExtraPoint.Math;
	}
};

typedef CStudent *PCStudent;

int main(void)
{
	PCStudent pStudentList = new CStudent[4];

	pStudentList[0].InputInfo("���̼�", 80, 76, 64);
	pStudentList[1].InputInfo("������", 92, 89, 99);
	pStudentList[2].InputInfo("��ȣ��", 88, 74, 70);
	pStudentList[3].InputInfo("���ƿ�", 79, 99, 85);

	for (int i = 0; i < 4; ++i)
	{
		printf("--------------------\n");
		pStudentList[i].PrintInfo();
	}
	printf("--------------------\n");

	SAFEDELETEARRAY(pStudentList);
    return 0;
}