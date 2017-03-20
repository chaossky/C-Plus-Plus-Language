// 9. Class.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

#define SAFEDELETE(PTR) delete PTR; PTR = nullptr
#define SAFEDELETEARRAY(PTR) delete[] PTR; PTR = nullptr

#pragma pack(push, 1)
class CAR
{
private:
	char Model[13];
	int  Price;
	int  Wheel;
public:
	void InputInfo(const char *szModel, int iPrice, int iWheel)
	{
		strcpy(Model, szModel);
		Price = iPrice;
		Wheel = iWheel;
	}

	void PrintInfo(void)
	{
		printf("���� : %10s\n", Model);
		printf("���� : %8d��\n", Price);
		printf("���� : %8d��\n", Wheel);
	}
};
#pragma pack(pop)

typedef CAR *PCAR;

int main(void)
{
	int iLength = 10;
	PCAR CarList = new CAR[iLength];
	memset(CarList, 0, sizeof(CAR) * iLength);

	PCAR(&rCarList) = CarList;
	printf("CAR �迭�� ũ�� : %d����Ʈ\n", sizeof(CAR) * iLength);
	printf("---------------------------\n");

	rCarList[6].InputInfo("�ƿ��", 63000000, 4);
	rCarList[6].PrintInfo();
	printf("---------------------------\n");
	SAFEDELETEARRAY(rCarList);
	return 0;
}