// 019. This.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

class CData
{
private:
	int Num;
public:
	explicit CData(int iNum)
	{
		Num = iNum;
	}

	CData operator+(CData rData)
	{
		rData.Num += 10;
		return rData;
	}

	CData(const CData &rData)
	{
		printf("���� ������ ȣ��\n");
	}

	CData(const CData &&rrData)
	{
		Num = rrData.Num;
		printf("�̵� ������ ȣ��\n");
	}

	void PrintNum(void)
	{
		printf("Num : %d\n", Num);
	}
};

int main(void)
{
	CData Data(10);
	CData Data2(10);
	//Data.PlusTen(Data).PrintNum();
	(Data.operator+(Data2)).PrintNum();
	Data.PrintNum();
	Data2.PrintNum();
    return 0;
}