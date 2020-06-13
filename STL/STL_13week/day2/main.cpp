///*
//6.12금요일
//
//1. 인자에 따라 구현되는 알고리즘 함수
//2. String 컨테이너가 삽입반복자를 지원하도록 추가 코딩
//
//*/
//
//#include <iostream>
//#include <list>
//#include <set>
//using namespace std;
//
////고전적인 방법
////template<class Iter>
////typename iterator_traits<Iter>::difference_type  //타입이라고 알려주기
////my_distance(Iter b, Iter e, random_access_iterator_tag)
////{
////	return e - b;
////}
////
////
////template<class Iter>
////typename iterator_traits<Iter>::difference_type  //타입이라고 알려주기
////my_distance(Iter b, Iter e, forward_iterator_tag)
////{
////	int cnt{ 0 };
////	while (b != e) {
////		++cnt;
////		++b;
////	}
////	return cnt;
////
////}
//
//template<class Iter>
//typename iterator_traits<Iter>::difference_type  //타입이라고 알려주기
//my_distance(Iter b, Iter e)
//{
//	if constexpr(is_same_v<iterator_traits<Iter>::iterator_category, random_access_iterator_tag>) {  //constexpr if 컴파일할때 조건을 판단할 수 있다면 사용할 수 있다.
//		return e - b;
//	}
//	else {
//		int cnt{ 0 };
//		while (b != e) {
//			++cnt;
//			++b;
//		}
//		return cnt;
//	}
//
//	//고전적인 방법 꼬리표 붙이기 기법
//	//return my_distance(b, e, iterator_traits<Iter>::iterator_category());
//
//}
//
////
////
//////template<>
//////ptrdiff_t my_distance(bidirectional_iterator_tag b, bidirectional_iterator_tag e)
//////{
//////	return e - b;
//////}
////int main()
////{
////	int a[] = { 1,2,3,4,5 };
////
////
////	cout << my_distance(begin(a), end(a)) << endl;//몇칸 가야 만날수 있니
////	cout << my_distance(end(a), begin(a)) << endl;//몇칸 가야 만날수 있니
////
////
////
////	list<int> lst{ 1,2,3,4,5 };
////	cout << my_distance(lst.begin(), lst.end()) << endl;
////	//cout << my_distance(lst.end(), lst.begin()) << endl; 무의미
////
////	set<int> s{ 1,2,3,4,5 };
////	cout << my_distance(s.begin(), s.end()) << endl;
////	//cout << my_distance(s.end(), s.begin()) << endl; 무의미
////}
//
//
//
//
////----String 수정
//#include <iostream>
//#include <string>
//#include <iterator>
//#include "String.h"
//using namespace std;
//template<class In, class Out>
//Out my_copy(In b, In e, Out d)
//{
//	while (b != e) {
//		*d = *b;
//		++b;
//		++d;
//	}
//	return d;
//}
//
//
//
//class BACK_inserter {
//	String cont;
//public:
//	explicit BACK_inserter(String& container) :cont{ container } {}
//
//
//	//*d=*b;
//	BACK_inserter& operator*() {
//		return *this;
//	}
//	void operator++() {
//
//	};
//	void operator=(char c) {
//		cout << "원래는" << c << "를 push_back(c) 해야 함" << endl;
//	}
//};
//
//
//int main()
//{
//	String s;
//	//my_copy(istream_iterator<char>{cin}, {}, BACK_inserter(s)); //컨트롤 +Z 누를 때 까지
//	copy(istream_iterator<char>{cin}, {}, BACK_inserter(s)); //컨트롤 +Z 누를 때 까지
//
//	cout << "입력하신 글자수는 " << s.size() << endl;
//	cout << s << endl;
//
//}