// 038. IOstream.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

// ǥ�� ����� ��Ʈ���� ���� �ڵ�
#include <iostream>
#include <fstream> // ���� ����¿� �ʿ��� ��� ����
using namespace std;

int main(void)
{
	ofstream WriteFile;
	WriteFile.open("Today.txt", ios_base::out); // �÷��׸� �̿�
	WriteFile << "���� ��¥ : " << endl << 20170308 << endl; // endl�� ����
	WriteFile.close();

	int iDate;
	char Buffer[128];
	ifstream ReadFile("Today.txt"); // �����ڸ� �̿�, �÷��״� �⺻ �÷���
	
	try
	{
		if (ReadFile.is_open() == true) // ���� ��Ʈ���� ���ȴ��� Ȯ��
		{
			cout << "���� �б� ����!" << endl;
			ReadFile.getline(Buffer, sizeof(char) * 128); // ���鵵 �б� ����
			ReadFile >> iDate;
			cout << Buffer << iDate << endl;
			ReadFile.close();
		}
		else
		{
			throw false;
		}
	}
	catch (bool)
	{
		cout << "���� �б� ����!" << endl;
	}
	return 0;
}