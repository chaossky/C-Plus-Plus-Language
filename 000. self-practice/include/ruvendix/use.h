
// <������Ʈ �̸�>_<�ҽ� ������ ���>_<�ҽ� ������ �̸�>
// ������Ʈ �̸�    : self-practice
// �ҽ� ������ ��� : ruvendix/
// �ҽ� ������ �̸� : use.h
#ifndef SELF_PRACTICE_RUVENDIX_USE_H_
#define SELF_PRACTICE_RUVENDIX_USE_H_

// ���� ���� ���! ��� ������ ���Խ��Ѷ�!
#include "test_code.h"

// ��� ���Ͽ��� �̸� �ִ� namespace�� ���!
namespace self_practice
{
class Test; // ���� ����
class Use
{
// Ŭ������ ���� ������ ������
// public -> protected -> private!
public:
	// �̷��� �ʵ�(��� ����)�� �����ͷ�
	// �̿��Ϸ��� ���� ������ �̿����� ����!
	Test *test_ptr_;

	Test test_;
	Use() : test_(10) // �����ڿ��� �ʵ带 �ʱ�ȭ!
	{
		// �����ڿ����� ������ �۾��� ���� ����!
	}

	// �Ҹ��ڴ� ��ӵ� ���ɼ��� ������
	// ���� �Լ��� ������!
	virtual ~Use()
	{

	}

	// const�� ���������� Ȱ���϶�!
	inline void ShowGuide() const
	{
		printf("10�� ���ϴ� �ζ��� �Լ��� ������!\n");
		printf("�̷��� Ŭ���� �ȿ��� ���� inline�� ������ �ʾƵ�\n");
		printf("�ζ��� �Լ��� �ȴ�!\n");
	}

	// �Ű������� �Է� -> ��� ������ ������!
	const int AddNum(const int num1, const int num2, int *result_ptr) const
	{
		*result_ptr = num1 + num2;
		return *result_ptr;
	}
protected:
private:
	DISALLOW_COPY_AND_ASSIGN(Use)
};
} // namespace self_practice

namespace self_practice
{
class TestClass
{
public:
	static int object_count_;
	TestClass();

	// ���� �Լ� ���! static �޼���!
	static void NowObjectCount()
	{
		printf("���� ������ ��ü�� �� : %d\n", object_count_);
	}
private:
	// ��� Ŭ����
	class MemberClass
	{
	public:
		void Show()
		{
			printf("��� Ŭ���� ȣ��!\n");
		}
	};
};
int TestClass::object_count_ = 0;
} // namespace self_practice �̷��� ǥ��!

 // �ܺο��� �Լ��� �����Ϸ���
 // �ݵ�� namespace�� ��ġ���Ѿ� ��!
namespace self_practice
{
TestClass::TestClass()
{
	printf("������ ȣ��!\n");
	object_count_++;

	// ��� Ŭ���� �̿��ϱ�!
	MemberClass member_class_;
	member_class_.Show();
}
} // namespace self_practice �̷��� ǥ��!

#endif