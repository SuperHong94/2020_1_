//////------------------
/////*
////2020 5 26 화요일
////
////unordered_set/map
////1. 순서가 없다는 의미는?
////2. 메모리 구조를 화면에 출력해 본다.
////3.String이 순서없는 컨테이너의 원소가 되려면? 템플릿 특수화
////
////컨테이너의 찾기 실력을 검증해 본다.
////*/
//////-----------------
//////
////#include <iostream>  
////#include <unordered_set>      //order 순서(오름차순)  unorder 순서가 없다.
////
////using namespace std;
////
////int main()
////{
////	hash<int> a;
////	std::cout << a.operator()(5) << std::endl; //operator() 호출가능하다 
////	std::cout << a(6) << std::endl;  // a.operator()(6)이거와 같다.
////	cout << hash<int>()(5) << std::endl;
////}
//
////
//////unordered_set
////#include <iostream>  
////#include <unordered_set>      //order 순서(오름차순)  unorder 순서가 없다.
////#include <thread>
////#include <string>
////using namespace std;
////
////int main()
////{
//	//initializer_list<int> t = { 1, 2, 3, 4, 5, 6, 7, 8 };  //t는 initializer_list<int> 초기화자 목록 원소가 몇개인지 모를때 사용한다.				
//	//unordered_set<int> us = { t };
//	//unordered_set<int> us{ 1, 2, 3, 4, 5, 6, 7, 8 };
//
//	//cout << "버킷의 개수" << us.bucket_count() << "- ";
//	//for (int i : us)
//	//	cout<< i << " ";
//	//cout << endl;
//
//	////원소추가
//	//us.insert(9);
//
//	//cout << "버킷의 개수" << us.bucket_count() << "- ";
//	//for (int i : us)
//	//	cout << i << " ";
//	//cout << endl;
//
//	//
//	//int n{ 9 };
//	//while (true) {
//	//	cout << "버킷의 개수" << us.bucket_count() << "- ";
//	//	for (int i : us)
//	//		cout<< i << " ";
//	//	cout << endl;
//
//	//	//원소추가
//	//	us.insert(n+=7);  //갑자기 순서가 변환다?
//	//	this_thread::sleep_for(200ms);
//
//	//}
////
////	unordered_set<int> us{ 1,2,3,4,5,6,7,8 };
////	for (int i = 0; i < us.bucket_count(); ++i) {
////		cout << "[" << i << "] ";
////		if (us.bucket_size(i)) {//i번쨰 버킷에서 원소있니?
////			for (auto p = us.begin(i); p != us.end(i); ++p)//i번째 반복자
////				cout << "--->" << *p;
////			cout << endl;
////		}
////		else
////			cout << endl;
////	}
////
//
//
////	//멀티셋
//	//unordered_multiset<int> us{ 1,2,3,4,4,4,7,8,4};
//
//	//cout <<"원소 4가이 있어야 할 버킷-"<< hash<int>()(4) % 64 << endl;
//	//for (int i = 0; i < us.bucket_count(); ++i) {
//	//	cout << "[" << i << "] ";
//	//	if (us.bucket_size(i)) {//i번쨰 버킷에서 원소있니?
//	//		for (auto p = us.begin(i); p != us.end(i); ++p)//i번째 반복자
//	//			cout << "--->" << *p;
//	//		
//	//	}
//	//	cout << endl;
//	//}
////	unordered_multiset<string> us{ "나는","광대","나를","갖고","놀아달라" };
////
////	for (int i = 0; i < us.bucket_count(); ++i) {
////		cout << "[" << i << "] ";
////		if (us.bucket_size(i)) {//i번쨰 버킷에서 원소있니?
////			for (auto p = us.begin(i); p != us.end(i); ++p)//i번째 반복자
////				cout << "--->" << *p;
////
////		}
////		cout << endl;
////	}
////	/*
////	해쉬만들때 중요한점 언제 bucket_count를 늘리느냐?
////	*/
////}
//
//
////String으로 하자.
////방법2가지
///*
// 특수화
// funtion() 기능
//*/
//#include <iostream>
//#include <unordered_set>
//#include <string>	
//#include "String.h"
//using namespace std;
////
//////특수화
//template<>
//struct hash<String> {
//	size_t operator()(const String& s) const {
//		return hash<string>()(s.getString());
//	}
//};
////
////int main() {
////	unordered_multiset<String> us{ "나는","광대","나를","갖고","놀아달라" };
////	//set<String> us{ "나는","광대","나를","갖고","놀아달라" };
////
////	for (int i = 0; i < us.bucket_count(); ++i) {
////		cout << "[" << i << "] ";
////		if (us.bucket_size(i)) {//i번쨰 버킷에서 원소있니?
////			for (auto p = us.begin(i); p != us.end(i); ++p)//i번째 반복자
////				cout << "--->" << *p;
////
////		}
////		cout << endl;
////	}
////
////}
//
//
////찾기
////int main() {
////	unordered_multiset<String> us{ "나는","광대","나를","갖고","놀아달라" };
////	//누구보다 빨리 찾아드립니다.
////	String a = "아몰랑";
////	std::cout << a << std::endl;
////	while (true) {
////		cout << "찾을 원소를 입력하세요: ";
////		/*string s;
////		cin >> s;
////		String S(s.c_str());*/
////		String s;
////		cin >> s;
////		std::cout << s << std::endl;
////
////		if (us.find(s) != us.end()) {
////			cout << s << "를 찾았습니다." << endl;
////		}
////		else {
////			cout << "그런 원소는 없어용!" << endl;
////		}
////	}
////}
//
//
//
////정수 NUM개를 생성한다. -정규분포[0~1000'0000]로 생성  평균은 500만
//
////벡터
////셋
////언오더드셋
//
//#include <iostream>
//#include <random>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
////using NUM = const int//이거 왜안되지?
//
//const int NUM{ 1000'0000 };
//
//default_random_engine dre;
//normal_distribution<> nd{0.0,1.0};    //[-5,5]
//
//int main()
//{
//	vector<int> v;
//	v.reserve(NUM);
//	for (int i = 0; i < NUM; ++i){
//		double d=nd(dre);  ////이값은 -5~+5 
//
//		//클램핑--------
//		/*if (d < -5.0)
//			d = 5.0f;
//		if (5.0f < d)
//			d = 5.0;*/
//		//----------
//		//[-5.0,5.0]
//		d=clamp(d, -5.0, 5.0); //d를 -5.0에서 5.0으로 묶어줘
//		d += 5.0; //[0,10]
//		//d *= 100'0000;  //[0,1000'0000];
//
//		v.push_back(d);
//	}
//
//	for (auto d : v)
//		cout << d <<' ';
//
//
//}