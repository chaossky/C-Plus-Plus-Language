// 016. MoveConstructors.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include <iostream>
#include "stdafx.h"

#define SAFEDELETE(PTR) delete PTR; PTR = nullptr
#define SAFEDELETEARRAY(PTR) delete[] PTR; PTR = nullptr

class CData
{
private:
	int *NumList;
	int Size;
public:
	explicit CData(int iSize)
	{
		Size = iSize;
		NumList = new int[Size];
		printf("��ȯ ������ ȣ��\n");
	}

	CData(const CData& rData)
	{
		NumList = new int[rData.Size];
		printf("���� ������ ȣ��\n");
	}

	// �̵� ������ => �Ű������� �ӽ� ��ü
	CData(CData&& rData)
	{
		NumList = rData.NumList;
		rData.NumList = nullptr;
		printf("�̵� ������ ȣ��\n");
	}

	~CData(void)
	{
		SAFEDELETEARRAY(NumList);
		printf("�Ҹ��� ȣ��\n");
	}

	//int V()
	//{
	//	return NumList[4] = 200;
	//}

	//CData &operator=(const CData &B)
	//{
	//	printf("����\n");
	//	NumList = new int[B.Size];
	//	Size = B.Size;
	//	return *this;
	//}
};

CData CreateData(int iSize)
{
	CData NewData(iSize);
	if (iSize > 10)
	{
		return NewData;
	}
	return NewData;
}

int main(void)
{
	CData Data1(100);
	CData Data2 = (CData &&)Data1;
	return 0;
}