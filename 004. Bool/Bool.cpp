// Bool.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//
#include "stdafx.h"

int main(void)
{
	unsigned bool ubData = -10;
	signed   bool sbData = 30;
	int iNum = 36;
	double dNum = -0.5f;

	printf("ubData  : %+3d\n", ubData);
	printf("sbData  : %+3d\n", sbData);

	ubData += iNum;
	sbData += dNum;
	printf("ubData  : %+3d\n", ubData);
	printf("sbData  : %+3d\n", sbData);
	printf("~ubData : %+3d\n", ~ubData);
	printf("~sbData : %+3d\n", ~sbData);
	return 0;
}