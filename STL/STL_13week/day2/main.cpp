///*
//6.12�ݿ���
//
//1. ���ڿ� ���� �����Ǵ� �˰��� �Լ�
//2. String �����̳ʰ� ���Թݺ��ڸ� �����ϵ��� �߰� �ڵ�
//
//*/
//
//#include <iostream>
//#include <list>
//#include <set>
//using namespace std;
//
////�������� ���
////template<class Iter>
////typename iterator_traits<Iter>::difference_type  //Ÿ���̶�� �˷��ֱ�
////my_distance(Iter b, Iter e, random_access_iterator_tag)
////{
////	return e - b;
////}
////
////
////template<class Iter>
////typename iterator_traits<Iter>::difference_type  //Ÿ���̶�� �˷��ֱ�
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
//typename iterator_traits<Iter>::difference_type  //Ÿ���̶�� �˷��ֱ�
//my_distance(Iter b, Iter e)
//{
//	if constexpr(is_same_v<iterator_traits<Iter>::iterator_category, random_access_iterator_tag>) {  //constexpr if �������Ҷ� ������ �Ǵ��� �� �ִٸ� ����� �� �ִ�.
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
//	//�������� ��� ����ǥ ���̱� ���
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
////	cout << my_distance(begin(a), end(a)) << endl;//��ĭ ���� ������ �ִ�
////	cout << my_distance(end(a), begin(a)) << endl;//��ĭ ���� ������ �ִ�
////
////
////
////	list<int> lst{ 1,2,3,4,5 };
////	cout << my_distance(lst.begin(), lst.end()) << endl;
////	//cout << my_distance(lst.end(), lst.begin()) << endl; ���ǹ�
////
////	set<int> s{ 1,2,3,4,5 };
////	cout << my_distance(s.begin(), s.end()) << endl;
////	//cout << my_distance(s.end(), s.begin()) << endl; ���ǹ�
////}
//
//
//
//
////----String ����
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
//		cout << "������" << c << "�� push_back(c) �ؾ� ��" << endl;
//	}
//};
//
//
//int main()
//{
//	String s;
//	//my_copy(istream_iterator<char>{cin}, {}, BACK_inserter(s)); //��Ʈ�� +Z ���� �� ����
//	copy(istream_iterator<char>{cin}, {}, BACK_inserter(s)); //��Ʈ�� +Z ���� �� ����
//
//	cout << "�Է��Ͻ� ���ڼ��� " << s.size() << endl;
//	cout << s << endl;
//
//}