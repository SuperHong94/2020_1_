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
//	cout << "HEAP에 할당한 int의 값" << endl;
//	for (int i = 0; i < 3; ++i)
//		cout << p[i] << endl;
//	cout << endl;
//	cout << "p의 주소: " << &p << endl;
//	cout << "p의 크기: " << sizeof(p) << "바이트" << endl;
//
//	//비교를 위한 int
//	int n{ 2020 };
//	cout << "n의 주소: " << &n << endl;
//	cout << endl;
//	for (int i = 0; i < 3; ++i)
//		cout << "p[i]의 주소: " << &p[i] << endl;
//	delete[] p;
//}
//
//void f(int i, double d, string s)
//{
//	cout << "int 주소: " << &i << ", 크기: " << sizeof(i) << "바이트" << endl;
//	cout << "double주소: " << &d << ", 크기: " << sizeof(d) << "바이트" << endl;
//	cout << "string주소: " << &s << ", 크기: " << sizeof(s) << "바이트" << endl;
//}
//
//void reverse_f(string s, double d, int i)
//{
//	cout << "string주소: " << &s << ", 크기: " << sizeof(s) << "바이트" << endl;
//	cout << "double주소: " << &d << ", 크기: " << sizeof(d) << "바이트" << endl;
//	cout << "int 주소: " << &i << ", 크기: " << sizeof(i) << "바이트" << endl;
//}


//#include <iostream>
//#include "String.h"
//using namespace std;
//
//int main()
//{
//	String s{ "힘내라 대한민국!" };
//	cout << "s의 크기: " << sizeof(s) << "바이트" << endl;
//	cout << "s의 번지: " << &s << endl;
//
//	int n{ 2020 };
//	cout << "n의 번지: " << &n << endl;
//
//	cout << endl;
//	cout << "s가 할당한 메모리의 번지: " << static_cast<void*>(&s[0]) << endl;
//	int* p = new int{ 777 };	//HEAP 비교를 위한 번지
//	cout << "HEAP의 번지: " << p << endl;
//	cout << "p의 번지: " << &p << endl;
//}

//#include <iostream>
//#include "String.h"
//using namespace std;
//
//int main()
//{
//	String* s = new String{ "힘내라 대한민국" };
//	cout << s << endl;
//	cout << &s << endl;
//	cout << static_cast<void*>(&s[0]) << '\n';
//	int n{ 2020 };
//	cout << "n주소: " << &n << '\n';
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