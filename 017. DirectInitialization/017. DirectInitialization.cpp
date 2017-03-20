// 017. DirectInitialization.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

class CPosition
{
private:
	int X, Y;
public:
	CPosition(int iX, int iY)
	{
		X = iX;
		Y = iY;
	}

	int GetPosX(void)
	{
		return X;
	}

	int GetPosY(void)
	{
		return Y;
	}

	void PrintPos(void)
	{
		printf("��ǥ : (%3d, %3d)\n", X, Y);
	}
};

class CRectangle
{
private:
	CPosition LeftTop = {0, 0};
	CPosition RightBottom = {0, 0};
public:
	CRectangle(void)
	{

	}

	CRectangle(int iLeft, int iTop, int iRight, int iBottom)
		: LeftTop(iLeft, iTop), RightBottom(iRight, iBottom)
	{

	}

	void PrintPos(void)
	{
		printf("���� ��   : (%3d, %3d)\n", LeftTop.GetPosX(), LeftTop.GetPosY());
		printf("������ �� : (%3d, %3d)\n", RightBottom.GetPosX(), RightBottom.GetPosY());
	}
};

int main(void)
{
	CRectangle Rectangle1;
	Rectangle1.PrintPos();
	printf("-----------------------\n");

	CRectangle Rectangle2(100, 150, 250, 30);
	Rectangle2.PrintPos();
    return 0;
}