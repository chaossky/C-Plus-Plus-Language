#pragma once

// .h + .cpp = .hpp
template <typename T>
class CMyData
{
private:
	T Data;
public:
	CMyData(void);
	explicit CMyData(T tData);
	virtual ~CMyData(void);
	T GetData(void);
};

#pragma region CMyData ����
template <typename T>
CMyData<T>::CMyData(void) { printf("������ ȣ��!\n"); }

template <typename T>
CMyData<T>::CMyData(T tData) : Data(tData) { printf("������ ȣ��!\n"); }

template <typename T>
CMyData<T>::~CMyData(void) { printf("�Ҹ��� ȣ��!\n"); }

template <typename T>
T CMyData<T>::GetData(void) { return Data; }
#pragma endregion