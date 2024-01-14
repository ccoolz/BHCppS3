#include <iostream>
#include <stdio.h>
using std::cout;
using std::endl;

const int global_const_cpp = 1;	//C++�У�ȫ��const������û���ڴ�ģ���1��ϸ����

void Test1()
{
	//�����������Ż������1���ñ�����const���εı�����ֵ
	int a = 10;
	const int b = a;
	int* p = (int*)&b;
	*p = 100;
	cout << "b = " << b << endl;
	cout << "*p_b = " << *p << endl;
	//b�����������޸ĺ��100�������Ǳ������Ż������Ӧ�������10��˵��������û�ж�������������Ż�
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
	//�����������Ż������2���Զ������������
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

	const int local_const_cpp = 10;	//ջ�������Ա�����޸�
	//local_const_cpp = 20;
	int* p_cpp2 = (int*)(&local_const_cpp);
	*p_cpp2 = 20;
	cout << "local_const_cpp = " << local_const_cpp << endl;
	cout << "*p_cpp2 = " << (*p_cpp2) << endl;

	extern int x;
	cout << "x = " << x << endl;
	/*extern const int y;
	cout << y;*/

	/* ��1 */
	cout << global_const_cpp << endl;
	//C++Ϊ�����Ч�ʣ��ڱ���׶α�����������������滻������Ĵ��룬����г����۵�
	cout << 1 << endl; //�������ô������£�
	//1.��ʡ�ڴ棬����������ڴ�ֱ���Ż���
	//2.ֱ�Ӵ�ӡ���ֱ�Ѱַ�������ٴ�ӡֵ��Ȼ�������ٶ�
	//��Ȼconst�������ɱ䣬��ô��Ϊ�������ڴ���Ǳ���׶ξͽ��й̶���ֵ�滻��Ȼ�Ǹ��õ�

	//volatile�ؼ�����һ���޶�����������һ�������ڳ����п��Ա������Ķ����޸�,�����ùؼ��֣����������ٶԸñ����Ĵ�������Ż�������ֱ�Ӵ������ڵ��ڴ��ж�ȡֵ
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