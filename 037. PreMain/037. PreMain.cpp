// 037. PreMain.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

class CGameManager
{
private:
	char *Resoultion;
	bool bFileIntegrity;
	bool bSystemSpecifications;
	bool bResult;
public:
	CGameManager(void)
	{ 
		printf("������ ȣ��!\n");
		Resoultion = "1920 * 1080";
		bFileIntegrity = true;
		bSystemSpecifications = false;
		if (bFileIntegrity == true && bSystemSpecifications == true)
		{
			bResult = true;
		}
		else
		{
			bResult = false;
		}
	}
	virtual ~CGameManager(void) { printf("�Ҹ��� ȣ��!\n"); }
public:
	bool GetResult(void) { return bResult; }
	void ShowGameManagerInfo(void)
	{
		cout << "�ػ� : " << Resoultion << endl;
		if (bFileIntegrity == true) { cout << "���� �˻� ����!" << endl; }
		else { cout << "���� �˻� ����!" << endl; }
		if (bSystemSpecifications == true) { cout << "����� ����մϴ�!" << endl; }
		else { cout << "����� �����մϴ�!" << endl; }
	}
};
CGameManager g_GameManager;
bool g_bInitResult = g_GameManager.GetResult(); // �Լ��� �ʱ�ȭ ����!

int main(void)
{
	printf("main() ������ �ʱ�ȭ ����!\n\n");
	g_GameManager.ShowGameManagerInfo();
	printf("�ʱ�ȭ ��� : %d\n\n", g_bInitResult);
    return 0;
}