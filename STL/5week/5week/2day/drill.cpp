#include <iostream>
#include <vector>
#include "String.h"
using namespace std;
int main()
{
	cout << sizeof(String) << endl;
	vector<String> v;
	v.reserve(4);
	v.emplace_back("일본");
	v.emplace_back("코로나");
	v.emplace_back("신규확진");
	v.emplace_back("700명");
	std::cout << v.capacity() << endl;
	cout << &v << endl;
	cout << &v[0] << endl;
	cout <<"벡터갯수"<< v.size() << endl;
	cout << "----------------" << endl;
	cout << "원소를 추가하기전" << endl;
	v.emplace_back("PANDEMIC");
	cout << "원소를 추가한 후" << endl;
	cout << &v << endl;
	cout << &v[0] << endl;
	cout << &v[4] << endl;
	cout << "----------------" << endl;
	std::cout << v.capacity() << endl;

}