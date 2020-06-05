#include <iostream>
#include <vector>
#include <algorithm>
#include "String.h"
using namespace std;

template<class InIt,class Pre>
bool my_all_of(InIt b, InIt e, Pre pre)
{
	for (; b != e; ++b)
		if (!pre(*b))
			return false;
	return true;
}

template<class InIt, class OutIt>
OutIt my_copy(InIt b, InIt e, OutIt d)
{
	for (; b != e; ++b, ++d)
		*d = *b;

	return d;
}


int main()
{
	//모두 홀수인지 알기
	vector<int> v{ 1,10,5,7,3,5,7,3,5,7,3,5,7,3,5,710 };
	cout << boolalpha << my_all_of(v.begin(), v.end(), [](int a) {
		return a & 1;
		}) << endl;

	int a[] = { 3,5,7 };

	cout << search(v.begin(), v.end(), begin(a), end(a)) - v.begin() << endl;
	cout << find_end(v.begin(), v.end(), begin(a), end(a)) - v.begin() << endl;
	cout << find_first_of(v.begin(), v.end(), begin(a), end(a)) - v.begin() << endl;


	//resize, v2(v.size()); back_Insert(
	vector<int> v2;
	v2.reserve(v.size());
	//copy(v.begin(), v.end(), v2.begin());
	//my_copy(v.begin(), v.end(),ostream_iterator<int>(cout," "));
	my_copy(v.begin(), v.end(),back_inserter(v2));

	for (const int& d : v2)
		cout << d << " ";
	cout << endl;
	cout << "------------\n";
	String s{ "aksldldkd!" };
	String s2;
	my_copy(s.begin(), s.end(), ostream_iterator<char>(cout," "));
	cout << *(s.begin()) << endl;

}