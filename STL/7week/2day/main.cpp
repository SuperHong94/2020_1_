//#include <iostream>
//#include "String.h"
//using namespace std;
//
//void print(String::iterator b, String::iterator e);
//int main()
//{
//	String str{ "the quick brown fox jumps over the lazy dog" };
//
//	print(str.begin(), str.end());
//}
//
//void print(String::iterator b, String::iterator e)
//{
//	while (b != e) {
//		cout << *b << ' ';
//		++b;
//	}
//	cout << endl;
//}


//print를 제네릭함수로 바꾸기

//#include <iostream>
//#include "String.h"
//using namespace std;
//
//template<class T>
//void print(T a, T b);
//int main()
//{
//	String str{ "the quick brown fox jumps over the lazy dog" };
//
//	print(str.begin(), str.end());
//}
//
//template<class T>
//void print(T b, T e)
//{
//	while (b != e) {
//		cout << *b << ' ';
//		++b;
//	}
//	cout << endl;
//}



//p3
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include "String.h"
//using namespace std;
//
//
//template<class T>
//T my_max_element(T, T);
//
//int main()
//{
//	String str{ "The quick brown fox jumps over the lazy dog" };
//	//pair<vector<int>::iterator, vector<int>::iterator>p = minmax_element(v.begin(), v.end());
//	//auto p = minmax_element(v.begin(), v.end());
//	//auto [min, max] = minmax_element(str.begin(), str.end());
//	auto p = my_max_element(str.begin(), str.end());
//	cout << ", 최대: " << *p << endl;
//}
//
//
//template<class T>
//T my_max_element(T a, T e)
//{
//	if (a == e)
//		return e;
//	//T max = a;  내가 쓴거
//
//	//while (a != e) {//내가한거
//	//	if (*max < *a)
//	//		max = a;
//	//	++a;
//	//}
//	//return max;
//
//
//
//	/*typename iterator_traits<T>::value_type max_value = *b; //교수님 1차버전
//	T max_position = b;
//	while (a != e) {
//		if (max_value < *a) {
//			max_position = b;
//			max_value = *b;
//		}
//		++b;
//	}
//	return max_position;*/
//
//	T max = a;
//	while (++a != e) {
//		if (*max < *a)
//			max = a;
//	}
//	return max;
//}


//copy

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include "String.h"
using namespace std;

template<class InIter, class OutIter>
OutIter my_copy(InIter first, InIter last, OutIter result);


class String_back_insert_iterator
{

protected:
	String* container;

public:
	typedef String container_type;
	explicit String_back_insert_iterator(String& x) : container(std::addressof(x)) {}
	String_back_insert_iterator& operator= (const char value)
	{
		container->push_back(value); return *this;
	}
	String_back_insert_iterator& operator* ()
	{
		return *this;
	}
	String_back_insert_iterator& operator++ ()
	{
		return *this;
	}
	String_back_insert_iterator operator++ (int)
	{
		return *this;
	}
};
int main()
{

	String str{ "The quick brown fox jumps over the lazy dog" };
	String s;
	vector<char> v;
	v.reserve(str.size());
	//copy(begin(str), end(str),ostream_iterator<char>(cout,"*"));
	//copy(str.begin(), str.end(), back_inserter(v));
	copy(str.begin(), str.end(), String_back_insert_iterator(s));

	//for (auto c : v)
	//	cout << c << " ";
	cout <<s <<endl;
}


template<class InIter, class OutIter>
OutIter my_copy(InIter first, InIter last, OutIter result)
{
	while (first != last) {
		*result = *first;
		++first;
		++result;
	}
	return result;
}


