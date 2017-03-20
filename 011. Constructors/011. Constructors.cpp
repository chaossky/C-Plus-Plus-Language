// 011. Constructors.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

struct POSITON
{
	int x, y;
};

class CRectangle
{
private:
	int Left, Top, Right, Bottom;
public:
	// �⺻ ������
	CRectangle(void)
	{
		printf("�⺻ ������ ȣ��!\n");
	}

	// ��ǥ 4��
	CRectangle(int iLeft, int iTop, int iRight, int iBottom)
	{
		Left   = iLeft;
		Top    = iTop;
		Right  = iRight;
		Bottom = iBottom;
	}

	// ��ǥ ����ü 2��
	CRectangle(POSITON LeftTop, POSITON RightBottom)
	{
		Left = LeftTop.x;
		Top = LeftTop.y;
		Right = RightBottom.x;
		Bottom = RightBottom.y;
	}

	void PrintPos(void)
	{
		printf("  ����   �� ��ǥ(%2d, %2d)\n", Left, Top);
		printf("������ �Ʒ� ��ǥ(%2d, %2d)\n", Right, Bottom);
	}
};

int main(void)
{
	CRectangle Rectangle1(10, 5, 30, 8);
	printf("Rectangle1�� ��ǥ\n");
	Rectangle1.PrintPos();
	printf("\n");

	CRectangle Rectangle2(POSITON{20, 4}, POSITON{40, 12});
	printf("Rectangle2�� ��ǥ\n");
	Rectangle2.PrintPos();
    return 0;
}