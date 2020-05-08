//#include <iostream>
//#include <forward_list>
//#include <list>
//#include <deque>
//#include <array>
//#include <vector>
//#include <iterator>
//#include "String.h"
//using namespace std;
//
//template <typename T>
//void showCategory(const T&);
//
//int main()
//{
//	istream_iterator<char> in_iter;
//	ostream_iterator<short> out_iter{ cout };
//	forward_list<int>::iterator f_iter;
//	deque<double>::iterator deque_iter;
//	array<String, 0>::iterator array_iter;
//	vector<char>::iterator v_iter;
//	String* a;
//	showCategory(in_iter);
//	showCategory(out_iter);
//	showCategory(f_iter);
//	showCategory(deque_iter);
//	showCategory(array_iter);
//	showCategory(a);
//}
//
//template <typename T>
//void showCategory(const T& t)
//{
//	cout << typeid(iterator_traits<T>::iterator_category).name() << endl;
//}

//#include <iostream>
//#include <algorithm>
//#include "String1.h"
//using namespace std;
//
//int main()
//{
//	String str{ "the quick brown fox jumps over the lazy dog" };
//
//	using a = String;
//	
//	sort(str.begin(), str.end());
//	for (auto d : str)
//		cout << d;
//	cout << endl;
//
//}


#include <iostream>
#include <algorithm>
#include "String1.h"
using namespace std;

int main()
{
	String str{ "the quick brown fox jumps over the lazy dog" };

	sort(str.begin(), str.end());

	for (auto d : str)
		cout << d;
	cout << '\n';
}
