// 012. Destructors.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

#define SAFEDELETE(PTR) delete PTR; PTR = nullptr
#define SAFEDELETEARRAY(PTR) delete[] PTR; PTR = nullptr

//class CStudent
//{
//private:
//	char *Name;
//	int  Grade;
//public:
//	CStudent(const char *szName, int iGrade)
//	{
//		Name = new char[strlen(szName) + 1]; // ���� ���� ����
//		strcpy(Name, szName);
//		Grade = iGrade;
//	}
//
//	~CStudent(void)
//	{
//		SAFEDELETEARRAY(Name);
//	}
//
//	void PrintInfo(void)
//	{
//		printf("�л� �̸� : %s\n", Name);
//		printf("�л� �г� : %d�г�\n", Grade);
//	}
//};

//typedef CStudent *PCStudent;

int main(void)
{
	//// ��ü �迭 �ʱ�ȭ
	//PCStudent StudentList =
	//	new CStudent[3]{CStudent("���ƿ�", 2),
	//	CStudent("�̾Ƹ�", 1), CStudent("��ö��", 2)};

	//for (int i = 0; i < 3; ++i)
	//{
	//	StudentList[i].PrintInfo();
	//	printf("------------------\n");
	//}

	//SAFEDELETEARRAY(StudentList);
    return 0;
}