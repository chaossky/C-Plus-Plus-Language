// 031. ClassTemplate.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "MyData.hpp"

int main(void)
{
	CMyData<int> Data(100);
	printf("Data : %d\n", Data.GetData());
	return 0;
}