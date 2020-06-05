/*
const vs constexpr

constexpr 리턴값이 컴파일 타임에 결졍될 수 있어 컴파일 상태에서 결과를 알 수 있다.

print->find->find_if->copy
//4월 26일 수업내용에 반복자 관련 내용있음
*/

//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <iterator>
//#include "String.h"
//using namespace std;
//
//template<class Init, class Pre>
//bool my_all_of(Init b, Init e, Pre p)
//{
//	//아직 검사할 구간이 남았다면
//		//b가 가리키고 있는 값이 조건을 만족하는지 p에게 물어본다.
//	/*for (; b != e; ++b)
//		if (!p(*b))
//			return false;
//	return true;*/
//	/*while (b != e) {
//		if (!p(*b))
//			return false;
//		++b;
//	}
//	return true;*/
//	for (; b != e; ++b)
//		if (!(p(*b)))
//			return false;
//	return true;
//}
//
//
//template <class InIt, class OutIt>
//OutIt my_copy(InIt b, InIt e, OutIt d)  //인풋과 출력이터레이터
//{
//	/*while (b != e){
//		*d++=*b++;
//	}
//	return d;*/
//	for (; b != e; ++b, ++d)
//		*d = *b;  // ==d.operator*() = b.operator*(); 핵심 오퍼레이터가 함수니깐 내가 맘대로 할 수 있어!
//	
//
//	//d.operator*() { //의 내용
//	//	v2.push_back(*b);
//	//}
//	return d;
//}
//



//int main()
//{
//	//vector<int> v{ 2,4,6,-8,0,10};
//	////v가 모두 홀수인지 알고 싶다.
//	//auto p = find_if(v.begin(), v.end(), [](int n) {return 7 < n; });
//	//cout<<"7보다 큰 원소의 위치는: "<<p-v.begin()<<endl;
//	//bool result=my_all_of(v.begin(), v.end(), [](int n) {
//	//	return n & 1;
//	//	});
//	//cout << "v의 모든 원소가 홀수인가? " << boolalpha << result << endl;
//
//	//search end여야 되는데
//	//서치와 find의 차이는 범위의 차이
//	/*vector<int> v{ 1,3,5,7,9,1,3,5,7,9,5,7,9,7,8 };
//	int a[]={5, 7, 9};
//	auto p=search(v.begin(), v.end(), begin(a), end(a));
//	cout << distance(v.begin(), p) << endl;*/
//	//구간을 찾을떄는 Search로 찾자!
//
//
//	/*vector<int> v{ 1,3,5,7,9,1,3,5,7,9,5,7,9,7,8 };
//	int a[] = { 2,4,6,8 };
//	auto p = find_first_of(v.begin(), v.end(), begin(a), end(a));
//	cout << distance(v.begin(), p) << endl;*/
//
//
//	//copy
//	//vector<int> v{ 1,2,3,4,5,6,7,8,9,10 };
//
//	//v의 모든 원소를 다른 벡터 v2로 copy하라
//	//vector<int> v2(10);
//	//v2.reserve(v.size());
//	//copy(v.begin(), v.end(), v2.begin());
//	///*for (int n : v2)
//	//	cout << n << ' ';*/
//	//for (int i = 0; i < 10; ++i)
//	//	cout << v2[i] << endl;
//	//cout << endl;
//
//
//	//이것이 좋은프로그램일까?
//	//vector<int> v2(10);
//	//copy(v.begin(), v.end(), v2.begin());
//	//for (int i = 0; i < 10; ++i)
//	//	cout << v2[i] << endl;
//	//cout << endl;
//
//	//해결방법
//	//vector<int> v2;
//	//v2.reserve(v.size());
//	////copy(v.begin(), v.end(), v2.begin());
//	//copy(v.begin(), v.end(), back_inserter(v2)); 
//	//for (int i = 0; i < 10; ++i)
//	//	cout << v2[i] << endl;
//	//cout << endl;
//
//
//	//myCopy 해보기
//	vector<int> v{ 1,2,3,4,5,6,7,8,9,10 };
//	vector<int> v2;
//	my_copy(v.begin(), v.end(), back_inserter(v2));
//	my_copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
//	cout << endl;
//
//	//copy(v.begin(), v.end(), v2.begin());
//
//}


//template<class T>
//T add(T v1, T v2)
//{
//	//T를 더할 수 있기는 할까?  템플릿세상에서는 함수에 뭐가 전달될지 몰라 더할수있는 조건을 만족해야됨
//	//타입이 조건에 맞는지 검사해 보고 싶다. 
//	//더할 수 있나?
//	cout << is_arithmetic<T>() << endl; //더할 수 있으면(산술연산가능한지 물어봄) true 1이 나온다.
//	return v1 + v2;
//}
//
//class Dog
//{
//
//};
//int main()
//{
//	/*String s{ "ascadsafg" };
//
//	String s2;
//	s2.reserve(s.size());
//	my_copy(s.begin(), s.end(),back_inserter(s2));*/
//	//my_copy(s.begin(), s.end(), ostream_iterator<char>(cout, " - "));
//
//	//copy가 원본을 수정?
//	//vector<int> v{ 1,2,3,4,5,6,8,9,10 };
//	//copy(++v.begin(), --v.end(), v.begin());
//
//	//for (int i = 0; i < v.size(); ++i)
//	//	cout << v[i] << ' ';
//
//
//	//문제 
//	cout<<add(1, 2) << endl; //3
//	//add<const char*>("1", "2");
//	//add(Dog(), Dog());
//	cout << add<string>("1"s, "2"s) << endl;//12
//
//}