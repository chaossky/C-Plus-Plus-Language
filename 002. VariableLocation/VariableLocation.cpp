// VariableLocation.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

#define Pause() system("pause")
#define Clear() system("cls")

int main()
{
	int iStart, iEnd, iSum;

	while (1)
	{
		iSum = 0;
		printf("������ ���� ������ �� ������ �Է��ϼ��� : ");
		scanf("%d %d", &iStart, &iEnd);

		for (int i = iStart; i <= iEnd; ++i)
		{
			iSum += i;
		}
		printf("%d���� %d������ ���� %d�Դϴ�.\n", iStart, iEnd, iSum);
		Pause();
		Clear();
	}
    return 0;
}