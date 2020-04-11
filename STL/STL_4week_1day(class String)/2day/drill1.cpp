//#include <iostream>
//#include <array>
//#include "String.h"
//
//using namespace std;
//
//int main()
//{
//	array<String, 5>words{ "corona","virus","world","crisis","pandemic" };
//	cout << words[0] << endl;
//	auto p = words.begin();
//	cout << sizeof(String) << '\n';
//	cout << *p << endl;
//
//	++p;
//	cout << *p << endl;
//	for (int i = 0; i < words.size(); ++i)
//		cout << words[i] << " ";
//	cout << endl;
//
//	for (auto p = words.begin(); p != words.end(); ++p)
//		cout << *p << " ";
//	cout << endl;
//
//	for (const String& word : words) {
//		
//		cout << word<<"аж╪р :"<<&word << " ";
//	}
//	cout << endl;
//}