//#include <iostream>
//#include <string>
//using namespace std;
//void f(int a, double b, string c)
//{
//	cout << "string �ּ�: " << &c << ", " << "ũ��: " << sizeof(c) << '\n';
//	cout << "double �ּ�: " << &b << ", " << "ũ��: " << sizeof(b) << '\n';
//	cout << "int �ּ�: " << &a << ", " << "ũ��: " << sizeof(a) << '\n';
//}
//void rf(string c, double b, int a)
//{
//	cout << "int �ּ�: " << &a << ", " << "ũ��: " << sizeof(a) << '\n';
//	cout << "double �ּ�: " << &b << ", " << "ũ��: " << sizeof(b) << '\n';
//	cout << "string �ּ�: " << &c << ", " << "ũ��: " << sizeof(c) << '\n';
//}
//int main()
//{
//	int a{ 1 };
//	double b{ 2 };
//	string c{ "3" };
//
//	f(a, b, c);
//	cout << "\n\n";
//	rf(c, b, a);
//
//}

//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int* p;
//	p = new int[3]{ 1,2,3 };
//	cout << "HEAP�� �Ҵ��� int�� ��" << endl;
//	for (int i = 0; i < 3; ++i)
//		cout << p[i] << endl;
//	cout << endl;
//	cout << "p�� �ּ�:" << &p << endl;
//	cout << "p�� ũ��: " << sizeof(p) << endl;
//
//	int n{ 1 };
//	cout << "n�� �ּ�: " << &n << endl;
//	cout << endl;
//	for (int i = 0; i < 3; ++i)
//		cout << "p["<<i<<"]�� �ּ�: " << &p[i] << endl;
//	delete[] p;
//}

#include <iostream>
#include <vector>
#include "String.h"

using namespace std;
int main()
{
	vector<int> v{1,2,3,4};
	int n;
	cout << "vector v�� �ּ�: " << &v << endl;
	cout << "�񱳸� ���� int�� �ּ�: " << &n << endl;
	cout << "������ ����" << v.size() << endl;
	cout << "���Ұ� ����� �޸�" << v.data() << endl;
	cout << "���Ҵ����� �ʰ� ���� �� �ִ� ����: " << v.capacity() << endl;
	cout << "vector v�� ũ��: " << sizeof(vector<int>) << "����Ʈ\n	";

}