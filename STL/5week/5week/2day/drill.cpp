#include <iostream>
#include <vector>
#include "String.h"
using namespace std;
int main()
{
	cout << sizeof(String) << endl;
	vector<String> v;
	v.reserve(4);
	v.emplace_back("�Ϻ�");
	v.emplace_back("�ڷγ�");
	v.emplace_back("�ű�Ȯ��");
	v.emplace_back("700��");
	std::cout << v.capacity() << endl;
	cout << &v << endl;
	cout << &v[0] << endl;
	cout <<"���Ͱ���"<< v.size() << endl;
	cout << "----------------" << endl;
	cout << "���Ҹ� �߰��ϱ���" << endl;
	v.emplace_back("PANDEMIC");
	cout << "���Ҹ� �߰��� ��" << endl;
	cout << &v << endl;
	cout << &v[0] << endl;
	cout << &v[4] << endl;
	cout << "----------------" << endl;
	std::cout << v.capacity() << endl;

}