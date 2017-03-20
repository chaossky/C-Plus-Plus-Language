// DefaultParameter.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

enum DYNAMIC_ALLOCATION {DA_NONE, DA_ACTIVATE};

void *SwitchDynamicAllocation(enum DYNAMIC_ALLOCATION eSelect = DA_NONE, int iDataSize = 0);

int main(void)
{
	char Location[100];
	void *pResult;

	pResult = SwitchDynamicAllocation();

	pResult = SwitchDynamicAllocation(DA_ACTIVATE, 4);
	if (pResult != NULL)
	{
		free(pResult);
	}
	return 0;
}

void *SwitchDynamicAllocation(enum DYNAMIC_ALLOCATION eSelect /*= DA_NONE*/, int iDataSize /*= 0*/)
{
	int iCount;

	if (eSelect == DA_NONE)
	{
		printf("���� �Ҵ��� �������� �ʾҽ��ϴ�.\n");
		printf("-------------------------------------------------------\n");
		return NULL;
	}

	printf("�Ҵ��� ������ �Է��ϼ���(���� �Ҵ� ũ�� ���� : %d) : ", iDataSize);
	scanf("%d", &iCount);

	void *pResult = malloc(iDataSize * iCount);
	printf("%d���� �Ҵ��߽��ϴ�. �Ҵ�� ũ�� %d����Ʈ\n", iCount, _msize(pResult));
	printf("-------------------------------------------------------\n");
	return pResult;
}