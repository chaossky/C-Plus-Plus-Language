// 030. Template.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

template <typename T>
void PrintData(const T &rData)
{
	std::cout << rData << std::endl << std::endl;
}

class CObject
{
	friend void PrintData<CObject>(const CObject &rData);
private:
	int X, Y;
	int Code;
public:
	CObject(void) : X(0), Y(0), Code(0) {}
	CObject(int iX, int iY, int iCode) : X(iX), Y(iY), Code(iCode) {}
	virtual ~CObject(void) {}
};


template <> void PrintData<CObject>(const CObject &rData)
{
	std::cout << "��ǥ : (" << rData.X << ", " << rData.Y << ")" << std::endl;
	std::cout << "��ȣ : " << rData.Code << std::endl << std::endl;
}

int main(void)
{
	CObject House(10, 20, 1);
	PrintData<CObject>(House);
	PrintData<char>('A');
	PrintData<int>(100);
	PrintData<double>(26.72);
	return 0;
}