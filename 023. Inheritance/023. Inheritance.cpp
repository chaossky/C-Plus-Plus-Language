// 023. Inheritance.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

#define SAFEDELETEARRAY(PTR) delete[](PTR); PTR = nullptr
#define SAFEDELETE(PTR) delete(PTR); PTR = nullptr

class CHuman
{
protected:
	char *Name;
	int Age;
public:
	CHuman(void) : Name(new char[1]), Age(0) {}
	CHuman(const char *szName, int iAge) :
		Name(new char[strlen(szName) + 1]), Age(iAge) {strcpy(Name, szName);}
	~CHuman(void) {SAFEDELETEARRAY(Name);}
};

class CPolice : public CHuman
{
private:
	int Rank;
public:
	CPolice(const char *szName, int iAge, int iRank) :
		CHuman(szName, iAge), Rank(iRank) {}
	void PrintInfo(void) const
	{
		printf("�̸� : %s\n", Name);
		printf("���� : %d\n", Age);
		printf("��� : %d\n", Rank);
	}
	void Action(void) const {printf("���������� �ٹ��Ѵ�.\n");}
};

class CStudent : public CHuman
{
private:
	int Grade;
public:
	CStudent(const char *szName, int iAge, int iGrade) :
		CHuman(szName, iAge), Grade(iGrade) {}
	void PrintInfo(void) const
	{
		printf("�̸� : %s\n", Name);
		printf("���� : %d\n", Age);
		printf("�г� : %d\n", Grade);
	}
	void Action(void) const {printf("�б����� �����Ѵ�.\n");}
};

class CProgrammer : public CHuman
{
private:
	int AvailableLanguage;
public:
	CProgrammer(const char *szName, int iAge, int iAvailableLanguage) :
		CHuman(szName, iAge), AvailableLanguage(iAvailableLanguage) {}
	void PrintInfo(void) const
	{
		printf("�̸� : %s\n", Name);
		printf("���� : %d\n", Age);
		printf("��� : %d\n", AvailableLanguage);
	}
	void Action(void) const {printf("���α׷��� �����.\n");}
};

int main(void)
{
	CPolice Police("��ȣö", 32, 2);
	Police.PrintInfo();
	Police.Action();
	printf("\n");

	CStudent Student("������", 18, 2);
	Student.PrintInfo();
	Student.Action();
	printf("\n");

	CProgrammer Programmer("Ű����", 29, 5);
	Programmer.PrintInfo();
	Programmer.Action();
	return 0;
}