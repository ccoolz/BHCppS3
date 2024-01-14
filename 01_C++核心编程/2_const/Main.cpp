#include <iostream>
#include <stdio.h>
using std::cout;
using std::endl;

const int global_const_cpp = 1;	//C++中，全局const变量是没有内存的，例1详细解释

void Test1()
{
	//编译器不能优化的情况1：用变量给const修饰的变量赋值
	int a = 10;
	const int b = a;
	int* p = (int*)&b;
	*p = 100;
	cout << "b = " << b << endl;
	cout << "*p_b = " << *p << endl;
	//b的输出结果是修改后的100，而不是编译器优化情况下应该输出的10，说明编译器没有对这种情况进行优化
}

struct Maker
{
	int a;

	Maker()
	{
		a = 10;
	}
};

void Test2()
{
	//编译器不能优化的情况2：自定义的数据类型
	const Maker ma;
	int* p = (int*)&ma.a;
	*p = 100;
	cout << "ma.a = " << ma.a << endl;
	cout << "*p_ma.a = " << *p << endl;
}

int main()
{
	//global_const_cpp = 2;
	/*int* p_cpp1 = (int*)(&global_const_cpp);
	*p_cpp1 = 2;
	cout << (*p_cpp1) << endl;*/

	const int local_const_cpp = 10;	//栈区，可以被间接修改
	//local_const_cpp = 20;
	int* p_cpp2 = (int*)(&local_const_cpp);
	*p_cpp2 = 20;
	cout << "local_const_cpp = " << local_const_cpp << endl;
	cout << "*p_cpp2 = " << (*p_cpp2) << endl;

	extern int x;
	cout << "x = " << x << endl;
	/*extern const int y;
	cout << y;*/

	/* 例1 */
	cout << global_const_cpp << endl;
	//C++为了提高效率，在编译阶段编译器会把上述代码替换成下面的代码，术语叫常量折叠
	cout << 1 << endl; //有两个好处，如下：
	//1.节省内存，这个变量的内存直接优化掉
	//2.直接打印数字比寻址变量后再打印值显然能提升速度
	//既然const变量不可变，那么不为它分配内存而是编译阶段就进行固定数值替换显然是更好的

	//volatile关键字是一种限定符用来声明一个对象在程序中可以被语句外的东西修改,遇到该关键字，编译器不再对该变量的代码进行优化，而是直接从它所在的内存中读取值
	volatile const int local_vola_const = 100;
	int* p_cpp3 = (int*)(&local_vola_const);
	*p_cpp3 = 200;
	cout << "local_vola_const = " << local_vola_const << endl;
	cout << "*p_cpp3 = " << (*p_cpp3) << endl;

	cout << "\n func_test1: \n";
	Test1();

	cout << "\n func_test2: \n";
	Test2();

	return 0;
}