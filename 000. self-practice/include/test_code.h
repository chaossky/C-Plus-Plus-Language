
// <������Ʈ �̸�>_<�ҽ� ������ ���>_<�ҽ� ������ �̸�>
#ifndef SELF_PRACTICE_TEST_CODE_H_
#define SELF_PRACTICE_TEST_CODE_H_

#include <iostream>

namespace self_practice
{
class Test
{
public:
	// ������ ����
	Test() : Test{ 0 } { }
	
	// ��ȯ �����ڿ��� ������ explicit�� ���!
	explicit Test(const int test_int) : test_int_(test_int)
	{ 

	}

	// std::initializer_list�� �̿��ϸ�
	// �߰�ȣ �ʱ�ȭ�� �����ϴ�!
	Test(std::initializer_list<int> test_int)
	{

	}

	void Show() { printf("������\n"); }
protected:
private:
	int test_int_; // �ʵ�� _�� �ϳ� �� ����!

	// ���� ������ �� ���� �����ڸ�
	// ������� �ʴ´ٸ� �̷��� private���� ���ƶ�!
	DISALLOW_COPY_AND_ASSIGN(Test)
};
} // namespace self_practice

namespace self_practice
{
// abstract�� �߻� Ŭ������� ǥ��
class Parent abstract
{
public:
	// Parent()�� �ʱ�ȭ��
	// explicit Parent(const int test_int)�� ���!
	// �̰� �ٷ� ������ ����! (Constructors Delegation)
	Parent() : Parent(0) { }
	explicit Parent(const int test_int)
		: test_int_(test_int) { }
	virtual ~Parent() { }

	// ���� �Լ�
	virtual void Talk() const abstract
	{
		printf("���� �θ��!\n");
	}

	// �̷� �� abstract�� ���� ���� ���� �Լ��� ���
	// ������ �ڽ� Ŭ�������� �������̵��� �ؾ� ��!
	virtual void Action() const abstract;
private:
	int test_int_;
};

// ����� public ���!
// final => ��� ���� ����!
class Child final : public Parent
{
public:
	// �ڽ� Ŭ������ �θ� Ŭ������
	// �����ڸ� ���� ��ó�� �۵�!
	// �̰� �ٷ� ������ ���! (Constructors Inheritance)
	using Parent::Parent;
	virtual ~Child() { }

	// ���� �Լ�
	// override => �������̵� �޼����� ǥ��
	// final => �������̵� ����
	virtual void Talk() const override final
	{
		printf("���� �ڽ��̴�!\n");
	}

	virtual void Action() const override final
	{
		printf("���ƴٴ���!\n");
	}

	// ������ �����ε� ��� ���� �Լ�!
	void CopyField(Child *child_ptr)
	{
		child_ptr->test_char_ = test_char_;
	}

	void Show()
	{
		printf("%c\n", test_char_);
	}

	// ���� ���� ���� ���� �Լ�
	char get_test_char_()
	{
		return test_char_;
	}
	void set_test_char_(const char &test_char)
	{
		test_char_ = test_char;
	}
private:
	// ���� ���� ���� �ʵ�� private����!
	char test_char_ = '\0'; // ������ ��� ������ ������ ����!
};

// POD ����ü
// ����ü�� �Ϲ� ������ �̸� ��Ģ�� ����!
struct Coordinates
{
	int x, y;
};

// C++ ��Ÿ���� ����ü
struct Object
{
	// �ʵ�
	Coordinates obj_pos;
	int obj_code;
	static int obj_count;
	
	// �޼���
	Coordinates get_obj_pos() const
	{
		return obj_pos;
	}

	// ������ �Ű������� const�� �ٿ���!
	void set_obj_pos(const int &x, const int &y)
	{
		obj_pos.x = x;
		obj_pos.y = y;
	}
};
int Object::obj_count = 0;

} // namespace self_practice

namespace self_practice
{
class TestOrder
{
public:
	typedef int *IntPtr;
	enum class EnumClass
	{
		kOne, kTwo
	};
	static const int kObjectCount;
	TestOrder() { }
	virtual ~TestOrder() { }
	static const int get_kObjectCount() { return kObjectCount; }
	int test_int_;
protected:
private:
	friend void TestFunction();
	DISALLOW_COPY_AND_ASSIGN(TestOrder)
};
} // namespace self_practice

void self_practice::TestFunction()
{

}
#endif