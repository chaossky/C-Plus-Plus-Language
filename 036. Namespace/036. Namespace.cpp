// 036. Namespace.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

//#include "stdafx.h"

#include <iostream>  // ǥ�� ����� Ŭ����
using namespace std; // ǥ�� �̸� ���� using ����

class MyClass
{
protected:
	int A;
public:
	int GetChild2(void) { return A; }
};
class CParent : public MyClass
{
protected:
	int Child;
public:
	CParent(void) : Child(1) {}
	virtual ~CParent(void) {}
	virtual void PrintInfo(void) { cout << "���� �θ��!" << endl; }
	int GetChild(void) { return Child; }
};

class CChild : public CParent
{
private:
	int PocketMoney;
public:
	using CParent::Child; // using���� �θ� Ŭ�������� ����
	using MyClass::A; // using���� �θ� Ŭ�������� ����
	CChild(void) : PocketMoney(10000) {}
	virtual ~CChild(void) {}
	virtual void PrintInfo(void) { cout << "���� �ڽ��̴�!" << endl; }
	int GetPocketMoney(void) { return PocketMoney; }
};

int main(void)
{
	CParent Parent;
	CChild Child;
	
	// protected�� ���� �Ұ���!
	//Parent.Child; 

	// protected���� using ������ public�� �����Ƿ� ���� ����!
	// �ڽ� Ŭ������ �ڽ��� ��ӹ��� ������ public���� ����Ѵٰ� �߱� ������
	// ���� ����� �������� �����Ӱ� �̿� ����!
	Child.Child = 3;
	printf("�ڽ� �� : %d\n", Child.GetChild());

	Child.A = 32;
	printf("�ڽ� �� : %d\n", Child.GetChild2());
    return 0;
}