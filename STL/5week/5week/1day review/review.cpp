//#include <iostream>
//#include <string>
//using namespace std;
//void f(int a, double b, string c)
//{
//	cout << "string 주소: " << &c << ", " << "크기: " << sizeof(c) << '\n';
//	cout << "double 주소: " << &b << ", " << "크기: " << sizeof(b) << '\n';
//	cout << "int 주소: " << &a << ", " << "크기: " << sizeof(a) << '\n';
//}
//void rf(string c, double b, int a)
//{
//	cout << "int 주소: " << &a << ", " << "크기: " << sizeof(a) << '\n';
//	cout << "double 주소: " << &b << ", " << "크기: " << sizeof(b) << '\n';
//	cout << "string 주소: " << &c << ", " << "크기: " << sizeof(c) << '\n';
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
//	cout << "HEAP에 할당한 int의 값" << endl;
//	for (int i = 0; i < 3; ++i)
//		cout << p[i] << endl;
//	cout << endl;
//	cout << "p의 주소:" << &p << endl;
//	cout << "p의 크기: " << sizeof(p) << endl;
//
//	int n{ 1 };
//	cout << "n의 주소: " << &n << endl;
//	cout << endl;
//	for (int i = 0; i < 3; ++i)
//		cout << "p["<<i<<"]의 주소: " << &p[i] << endl;
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
	cout << "vector v의 주소: " << &v << endl;
	cout << "비교를 위한 int의 주소: " << &n << endl;
	cout << "원소의 갯수" << v.size() << endl;
	cout << "원소가 저장된 메모리" << v.data() << endl;
	cout << "재할당하지 않고 담을 수 있는 갯수: " << v.capacity() << endl;
	cout << "vector v의 크기: " << sizeof(vector<int>) << "바이트\n	";

}