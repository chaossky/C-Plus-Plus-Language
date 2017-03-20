// 023. Inheritance.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

class CData
{
protected:
	int IntNum;
public:
	CData(void) : IntNum(10) {}
	void PrintData(void) const {printf("IntNum : %d\n", IntNum);}
};

class CNewData : public CData
{
private:
	int IntNum;
public:
	CNewData(void) : IntNum(20) {}
	void PrintData(void) const
	{
		printf("IntNum           : %d\n", IntNum);
		printf("CNewData::IntNum : %d\n", CNewData::IntNum);
		printf("CData::IntNum    : %d\n", CData::IntNum);
	}
};

int main(void)
{
	CNewData NewData;
	NewData.PrintData();
	return 0;
}