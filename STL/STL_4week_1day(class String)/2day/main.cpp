// 키보드로 입력한 단어를 오름차순으로 정렬
//#include <iostream>
//#include <vector>
//#include <string>
//#include <iterator>
//#include <algorithm>
//
//using namespace std;
//
//int main()
//{
//	/*vector<string> v;
//
//	string s;
//	
//	while (cin >> s) {
//		
//		v.push_back(s);
//	}
//	std::cout << "입력 완료\n";
//	sort(begin(v), end(v));
//	cout << "정렬 결과 출력\n";
//	for (auto d : v)
//		cout << d << '\t';
//	cout << '\n';*/
//
//	//다른 버전
//	cout << "단어 입력 종료는 컨트롤z\n";
//	vector<string> v{ istream_iterator<string>(cin),istream_iterator<string>() };
//	sort(begin(v), end(v));
//	copy(begin(v), end(v), ostream_iterator<string>(cout, "\t"));
//
//}

//pdf 8페이지

//#include <iostream>
//#include "String.h"
//
//using namespace std;
//int main()
//{
//	String s{ "COVID-19" };
//	auto a = make_unique<String>( "COVID-19" );
//	int n{ 2020 };
//	cout << "s가 저장한내용: " << static_cast<void*>(&n) << endl;
//	cout << "s가 저장한내용: " << *a << endl;
//}

//array 예제

//#include <iostream>
//#include <array>
//
//using namespace std;
//
//int main()
//{
//	array<int, 100'0000> a;
//	cout << sizeof(a) << endl;
//	/*for (int i = 0; i < a.size(); ++i)
//		a[i] = i;*/
//}

//