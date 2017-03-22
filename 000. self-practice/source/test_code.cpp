/*
 * test_code.cpp
 *
 *       Copyright (c) Ruvendix. ��� ���۱��� ���ο��� �ֽ��ϴ�.
 *
 * �� ������ ���� �ڵ� ���̵带 �����ϱ� ���� �����Դϴ�.
 * C++11 �̻��� ����鵵 ���ԵǾ��ֽ��ϴ�.
 *
 */

// ���� ������ �� ���� ���� �����ڸ�
// ��ȿȭ��Ű�� ��ũ�� �Լ�
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
  TypeName(const TypeName&) { }            \
  void operator=(const TypeName&) { }

#include "test_code.h" // ���� �۾� ���� ��� ����
#include <assert.h>    // C ���̺귯��
#include <inttypes.h>  // C ���̺귯��
#include <math.h>      // C ���̺귯��
#include <time.h>      // C ���̺귯�� => ���ĺ� ���� ����
#include <iostream>    // C++ ���̺귯��
#include <list>        // C++ ���̺귯��
#include <map>         // C++ ���̺귯��
#include <memory>      // C++ ���̺귯��
#include <vector>      // C++ ���̺귯�� => ���ĺ� ���� ����

// ���Ǻ� �������� �ش� �׸� �� �Ʒ��� ��ġ
#ifdef _DEBUG
#include <string>
#endif

#include "Screen.h"       // �ܺ� ���̺귯��
#include "ruvendix/Use.h" // ���� ������Ʈ�� ��� ����

// ���� �Լ� ��� �̸� ����
// namespace�� Ȱ���϶�!
namespace
{
	void SafeDelete(void *dynamic_ptr)
	{
		delete dynamic_ptr;
		dynamic_ptr = nullptr; // C++11
		printf("�� �޸� ����!\n");
	}
} // namespace �̸� ����

// ������ Ÿ�� �� ����� ����!
// C++14 �̻�
constexpr inline int ArrayLength()
{
	return 10;
}

void ExitOrDie()
{
	exit(EXIT_SUCCESS);
}

template <typename T>
class Complex {};

int main(void)
{
	// initializer_list�� �̿��� �ʱ�ȭ
	// =�� �ᵵ �ǰ� �� �ᵵ ��!
	self_practice::Test test{ 100 };
	std::vector<int> vec_num{ 1, 2, 3 };

	// auto_test1�� initializer_list<double>
	auto auto_test1 = { 2.62 };

	// auto_test2�� double
	auto auto_test2 = double{ 2.62 };

	// ��ø ���ø��� >> �����ڿ��� ȥ���� ���ϱ� ����
	// > > �̷��� �ۼ��ϴ� �� ����!
	std::map<int, Complex<int> > map_complex;

	// ���� �ִ� map�� �ݺ��ڸ� �̿��Ϸ���?
	std::map<int, Complex<int> >::iterator iter
		= map_complex.begin();

	// �׳� auto�� �̿��ϸ�?
	auto auto_iter = map_complex.begin();

	int num_list[ArrayLength()]; // �̰� ����!
	for (int i = 0; i < 10; ++i)
	{
		num_list[i] = i;
		printf("%d ", i);
	}
	printf("\n");

	const int *num_list_ptr = num_list;
	printf("num_list�� ũ�� : %d\n", sizeof(num_list));

	// 32��Ʈ�� 64��Ʈ���� ȣȯ�Ǵ� ���� ����!
	intptr_t test_int;
	printf("\ntest_int : ");
	scanf("%" SCNdPTR, &test_int);
	printf("test_int : %" PRIdPTR "\n\n", test_int);

	self_practice::TestClass *test_class_ptr
		= new self_practice::TestClass;

	printf("\n");
	test_class_ptr->NowObjectCount();

	printf("\n");
	::SafeDelete(reinterpret_cast<void *>(test_class_ptr));

	// if�� �� ���̸� �̷��� ǥ���϶�!
	if (true) printf("\n�� �����ϱ�!\n\n");

	// �ݺ��ڴ� �̷��� �ݺ��� �ȿ��� �����϶�!
	// ����ִ� for�� �̷��� ǥ���϶�!
	// �ݺ��ڴ� ���� ���� �����ڸ� ����϶�!
	for (int i = 0; i < 10; ++i)
	{ 
		continue;
	}

	// ����ִ� while���� �̷��� ǥ���϶�!
	int i = 0;
	while (++i < 10) continue;

	self_practice::Child child1;
	self_practice::Child child2;
	child1.CopyField(&child2);

	// std::unique_ptr�� Ȱ���϶�!
	std::unique_ptr<self_practice::Child> test_child1(new self_practice::Child);

	// test_child1�� �ٸ� �����Ϳ� �ּҸ� �ѱ� �� ����!
	//std::unique_ptr<self_practice::Child> test_child2(test_child1);
	
	printf("test_child1�� �ּ� : %p\n\n", test_child1);

	// test_child1�� �ٸ� �����Ϳ� �ּҸ� �̵���ų ���� ����!
	std::unique_ptr<self_practice::Child> test_child2(std::move(test_child1));
	printf("test_child1�� �ּ� : %p\n", test_child1);
	printf("test_child2�� �ּ� : %p\n", test_child2);
	return 0;
}