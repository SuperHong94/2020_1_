//코드 7-1 : 반복자의 종류

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
//template <class T>
//void showCategory(const T&);
//int main()
//{
//	istream_iterator<char> in_iter;
//	ostream_iterator<short> out_iter{ cout };
//	forward_list<int>::iterator forward_list_iter;
//	list<float>::iterator list_iter;
//	deque<double>::iterator deque_iter;
//	array<String, 0>::iterator array_iter;
//	vector<vector<char>>::iterator vector_iter;
//	int* p;
//
//	showCategory(in_iter);
//	showCategory(out_iter);
//	showCategory(forward_list_iter);
//	showCategory(list_iter);
//	showCategory(deque_iter);
//	showCategory(array_iter);
//	showCategory(vector_iter);
//	showCategory(p);
//
//}
//
//
//template <class T>
//void showCategory(const T& t)
//{
//	cout << typeid(iterator_traits<T>::iterator_category).name() << endl;
//}

//코드 7-2: range-based for를 사용하여 String을 순회
//#include <iostream>
//#include "String.h"
//using namespace std;
//int main()
//{
//	String str{ "The quick brown fox jumps over the lazy dog" };
//	auto beg = str.begin();
//	auto end = str.end();
//	//char c;
//	/*for (; beg != end; ++beg) {
//		c = *beg;
//		cout << c << ' ';
//	}*/
//	for (auto c : str) {
//		cout << c << ' ';
//	}
//	cout << endl;
//}

//코드 7-3 : String의 멤버를 sort로 전달

//#include <iostream>
//#include <algorithm>
//#include "String.h"
//using namespace std;
//int main()
//{
//	String str{ "The quick brown fox jumps over the lazy dog" };
//	sort(str.begin(), str.end());
//
//	cout << str << endl;
//}

//p9

//#include <iostream>
//#include "String.h"
//using namespace std;
//int main()
//{
//	String str{ "The quick brown fox jumps over the lazy dog" };
//	auto beg = str.begin();
//	auto end = str.end();
//	char c;
//	for (; beg != end; ++beg) {
//		c = *beg;
//		cout << c << ' ';
//	}
//	cout << endl;
//}


//코드 7-4: 역방향 반복자로 String을 순회
//#include <iostream>
//#include "String.h"
//using namespace std;
//int main()
//{
//	String str{ "The quick brown fox jumps over the lazy dog" };
//	for (auto i = str.rbegin(); i != str.rend(); ++i)
//		cout << *i;
//	cout << endl;
//}

//코드 7-5 : String의 반복자 종류 출력

//#include  <iostream>
//#include "String.h"
//using namespace std;
//
//int main()
//{
//	cout << typeid(iterator_traits<String::iterator>::iterator_category).name() << endl;
//	//cout << typeid(iterator_traits<String*>::iterator_category).name() << endl;
//}



//p14
//#include <iostream>
//#include <algorithm>
//#include <string>
//#include "String.h"
//using namespace std;
//int main()
//{
//	String str{ "The quick brown fox jumps over the lazy dog" };
//	sort(str.begin(), str.end());
//
//	cout << str << endl;
//
//	
//}




//day1 review
