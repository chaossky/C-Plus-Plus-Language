// 021. Const.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

class CData
{
public:
	int IntNum;
	mutable int TempIntNum;
public:
	CData(int iNum) : IntNum(iNum), TempIntNum(0) {}

	void SetIntNum(int iNum)
	{
		IntNum = iNum;
	}

	void PrintIntNum(void) const
	{
		printf("IntNum     : %d\n", IntNum);
		printf("TempIntNum : %d\n", TempIntNum);
		TempIntNum = IntNum; // ���� ����
	}
};

int main(void)
{
	// �Ϲ� ��ü
	CData Data1(100);
	Data1.SetIntNum(200);
	Data1.PrintIntNum();
	Data1.PrintIntNum();
	printf("-------------------\n");

	// const ��ü
	const CData Data2(100);
	Data2.PrintIntNum();
	Data2.PrintIntNum();
    return 0;
}