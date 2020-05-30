#include <iostream>
#include <iterator>
#include <unordered_set>
#include <random>
#include <tchar.h>
#include "String.h"
using namespace std;
template<>
struct hash<String> {
	size_t operator()(const String& s) const {
		return hash<string>()(s.getString());
	}
};



int main()
{
	/*hash<int> h;
	std::cout << h.operator()(5) << endl;
	cout << h(5) << endl;
	cout << hash<int>()(5) << endl;*/


	//initializer_list<int> t = { 1,2,3,4,5,6,7,8 };
	//unordered_set<int> us = t;
	//unordered_set<int> us = { 1,2,3,4,5,6,7,8,9 };

	/*cout << "버킷수" << us.bucket_count() << std::endl;
	for (auto d : us)
		cout << d << endl;

	for (int i = 0; i < us.bucket_count(); ++i) {
		cout << i << " - ";
		for (auto p = us.begin(i); p != us.end(i); ++p)
			cout << *p;
		cout << endl;

	}*/


	unordered_set<String> us{ "나는","광대","나를" };
	while (true) {
		String s;
		cin >> s;
		if (us.find(s) != us.end())
			cout << s << "찾았다";
		else
			cout << "못찾았다" << endl;
		cout << endl;
	}



	//const int NUM = 1000;

	//default_random_engine dre;
	//normal_distribution nd{ 0.0, 1.0 };

	//vector<int> v;
	//v.reserve(NUM);

	//for (int i = 0; i < NUM; ++i) {

	//	double d = nd(dre);

	//	d = clamp(d, -5.0, 5.0);
	//	d += 0.5;
	//	d *= 100;
	//	v.push_back(d);
	//}
	//for (int d : v)
	//	cout << d << ' ';

}
