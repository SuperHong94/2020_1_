//#include <iostream>
//#include <string>
//using namespace std;
//void f(int i, double d, string s);
//
//void reverse_f(string s, double d, int i);
//
//int main()
//{
//	/*int i{ 1 };
//	double d{ 2 };
//	string s{ "3" };
//	f(i, d, s);
//
//
//
//	reverse_f(s, d, i);*/
//
//	//cout << &a[0] << ' ' << &a[1] << '\n';
//
//	int* p;
//	p = new int[3]{ 1,2,3 };
//	cout << "HEAP�� �Ҵ��� int�� ��" << endl;
//	for (int i = 0; i < 3; ++i)
//		cout << p[i] << endl;
//	cout << endl;
//	cout << "p�� �ּ�: " << &p << endl;
//	cout << "p�� ũ��: " << sizeof(p) << "����Ʈ" << endl;
//
//	//�񱳸� ���� int
//	int n{ 2020 };
//	cout << "n�� �ּ�: " << &n << endl;
//	cout << endl;
//	for (int i = 0; i < 3; ++i)
//		cout << "p[i]�� �ּ�: " << &p[i] << endl;
//	delete[] p;
//}
//
//void f(int i, double d, string s)
//{
//	cout << "int �ּ�: " << &i << ", ũ��: " << sizeof(i) << "����Ʈ" << endl;
//	cout << "double�ּ�: " << &d << ", ũ��: " << sizeof(d) << "����Ʈ" << endl;
//	cout << "string�ּ�: " << &s << ", ũ��: " << sizeof(s) << "����Ʈ" << endl;
//}
//
//void reverse_f(string s, double d, int i)
//{
//	cout << "string�ּ�: " << &s << ", ũ��: " << sizeof(s) << "����Ʈ" << endl;
//	cout << "double�ּ�: " << &d << ", ũ��: " << sizeof(d) << "����Ʈ" << endl;
//	cout << "int �ּ�: " << &i << ", ũ��: " << sizeof(i) << "����Ʈ" << endl;
//}


//#include <iostream>
//#include "String.h"
//using namespace std;
//
//int main()
//{
//	String s{ "������ ���ѹα�!" };
//	cout << "s�� ũ��: " << sizeof(s) << "����Ʈ" << endl;
//	cout << "s�� ����: " << &s << endl;
//
//	int n{ 2020 };
//	cout << "n�� ����: " << &n << endl;
//
//	cout << endl;
//	cout << "s�� �Ҵ��� �޸��� ����: " << static_cast<void*>(&s[0]) << endl;
//	int* p = new int{ 777 };	//HEAP �񱳸� ���� ����
//	cout << "HEAP�� ����: " << p << endl;
//	cout << "p�� ����: " << &p << endl;
//}

//#include <iostream>
//#include "String.h"
//using namespace std;
//
//int main()
//{
//	String* s = new String{ "������ ���ѹα�" };
//	cout << s << endl;
//	cout << &s << endl;
//	cout << static_cast<void*>(&s[0]) << '\n';
//	int n{ 2020 };
//	cout << "n�ּ�: " << &n << '\n';
//	int* p = new int[3];
//
//	cout << p << endl;
//	cout << &p << endl;
//	
//}
//
#include <iostream>
#include <string>
#include "String.h"
using namespace std;
int main()
{
	int i{ 1 };
	double d{ 2 };
	std::string s{ "3" };

	cout << &i << endl;
	cout << &d << endl;
	cout << &s << endl;

}