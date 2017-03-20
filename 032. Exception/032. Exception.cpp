// 032. Exception.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include <exception> // set_terminate()
#include "stdafx.h"

enum EErrorCode
{
	ERRORDEFAULT,
	ERRORNEGATIVE,
	ERRORDIVISORZERO
};

// ���� ���� => "�̷��̷� ���� ��ü�� �߻��� �Ŵ�"��� �˸��� ��
void CheckDivisorZero(int iDivisor) throw (EErrorCode, int)
{
	if (iDivisor == 0)
	{
		throw ERRORDIVISORZERO;
	}
}

void KnownError(void)
{
	printf("���� ���������� �𸣰����� ��ư ������ �߻��߽��ϴ�!\n");
}

int main(void)
{
	try
	{
		set_terminate(KnownError);
		CheckDivisorZero(0);
	}
	catch (int)
	{
		printf("����δ� ���� �ʽ��ϴ�\n");
	}
	return 0;
}