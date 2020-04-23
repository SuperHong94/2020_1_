//#/*include <iostream>
//#include <vector>
//#include "String.h"
//using namespace std;
//int main()
//{
//	vector<String> v{ "일본","코로나","신규확진","700명" };
//	cout << "vetor v의 주소: " << &v << endl;
//	cout << "원소의 갯수: " << v.size() << endl;
//	cout << "재할당하지 않고 담을 수 있는 갯수: " << v.capacity() << endl;
//
//	for (const String& str : v)
//		cout << str << endl;
//}*/
////
////#include <iostream>
////#include <algorithm>
////#include <vector>
////#include "String.h"
////using namespace std;
////int main()
////{
////	vector<String> v;
////	v.reserve(4);
////	v.emplace_back("일본");
////	v.emplace_back("코로나");
////	v.emplace_back("신규확진");
////	v.emplace_back("700명");
////	cout << "vetor v의 주소: " << &v << endl;
////	cout << "원소의 갯수: " << v.size() << endl;
////	cout << "재할당하지 않고 담을 수 있는 갯수: " << v.capacity() << endl;
////	cout << "오름차순으로 정렬합니다." << endl;
////	sort(v.begin(), v.end(), [](String& a, String& b) {return a.getString() < b.getString(); });
////	for (const String& str : v)
////		cout << str << endl;
////}
//
////#include <iostream>
////#include <vector>
////#include "String.h"
////using namespace std;
////int main()
////{
////	vector<String> v;
////	v.reserve(4);
////	v.emplace_back("일본");
////	v.emplace_back("코로나");
////	v.emplace_back("신규확진");
////	v.emplace_back("700명");
////	cout << &v << endl;
////	cout << &v[0]<< endl;
////	cout << "----------------" << endl;
////	cout << "원소를 추가하기전" << endl;
////	v.emplace_back("PANDEMIC");
////	cout << "원소를 추가한 후" << endl;
////	cout << &v << endl;
////	cout << &v[0] << endl;
////	cout << "----------------" << endl;
////
////}
//
////#include <iostream>
////#include <vector>
////#include <algorithm>
////using namespace std;
////
//int main()
//{
//	vector<int> v{ 1,2,3,4,5,6,7,8,9,10 };
//	//auto i=remove(v.begin(), v.end(), 3); //숫자3 제거
//	//v.erase(i);
//	//v.erase(remove(v.begin(), v.end(), 3));
//
//	//홀수 제거
//	/*v.erase(remove_if(v.begin(), v.end(), [](int i)
//		{
//			return i&1;
//		}
//	),v.end());*/
//	erase(v, 3);
//	for (int n : v)
//		cout << n << ' ';
//	cout << endl;
//}
//
////#include <iostream>
////#include <fstream>
////#include <random>
////#include <vector>
////using namespace std;
////
////int main()
////{
////	ofstream out("정수 만개");
////	default_random_engine dre;
////	uniform_int_distribution<> uid(0, 10'0000);
////	int num = 0;
////	for (int i = 0; i < 1'0000; ++i) {
////		int a = uid(dre);
////		out << a<<" ";
////		if (a >= 0 && a < 1'0000)
////			num+=1;
////		if (i % 10 == 9){
////			out << endl;
////		}
////	}
////	cout << num << endl;
////
////
////	/*ifstream in("정수 만개");
////	vector<int> v;
////	v.reserve(1'0000);
////	int value;
////	while (in >> value)
////		v.emplace_back(value);
////	
////	int num = count_if(v.begin(), v.end(), [](int i) {
////		return i >= 0 && i < 1'0000;
////		});
////	cout << num << endl;
////	*/
////	
////
////}
//
//
////deque
//#include <iostream>
//#include <deque>
//#include <algorithm>
//#include "String.h"
//using namespace std;
//int main()
//{
//	deque<String>news;
//	news.push_back(String{ "일, 경찰 술판으로 집단감염" });
//	news.push_front(String{ "일, 엉터리 검사에 병원내 감염 속출" });
//
//	news.emplace_back("일본 전국적 감염 만연 단계");
//	news.emplace_back("일, 유권자 긴급사태 너무 늦어..");
//	cout << "관찰메시지 off" << endl;
//	cout << endl;
//	cout << "deque에 저장된 모든 원소 출력" << endl;
//	cout << endl;
//	for (const String& s : news)
//		cout << s << endl;
//	cout << endl;
//	//글자 수 오름차순으로 정렬
//	sort(news.begin(), news.end(), [](const String& a, const String& b) {
//		return a.size() < b.size();
//		});
//
//	//결과 출력
//	cout << "글자 수 오름차순으로 정렬\n\n";
//	for (int i = 0; i < news.size(); ++i)
//		cout << news[i] << endl;
//	cout << endl;
//	//결과를 반대로 출력
//	cout << "글자 수 내림차순 정렬" << endl;
//	cout << endl;
//	for (auto i = news.crbegin(); i < news.crend(); ++i)
//		cout << *i << endl;
//	cout << endl;
//}

//#include <iostream>
//#include <deque>
//#include <algorithm>
//#include "String.h"
//using namespace std;
//
//class Test {
//	int arr;
//public:
//	void show()const {
//		cout << "실험 중: " << this << endl;
//	}
//};
//
//int main()
//{
//	deque<Test>d;
//
//	for (int i = 0; i < 10; ++i)
//		d.emplace_back();
//
//	cout << "원소의 주소를 출력한다.\n";
//	for (auto&& test : d)
//		test.show();
//	cout << endl;
//
//	cout << endl;
//	cout << "앞쪽에 원소를 추가한 후 주소를 출력한다." << endl;
//	d.emplace_front();
//
//	for (int i = 0; i < d.size(); ++i)
//		d[i].show();
//}

//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include "String.h"
//using namespace std;
//int main()
//{
//	vector<String> v;
//	v.reserve(5);
//	v.emplace_back("a");
//	v.emplace_back("cc");
//	v.emplace_back("cc");
//	v.emplace_back("b");
//	v.emplace_back("cc");
//	cout << "제거 전\n";
//	for (const auto& d : v)
//		cout << d << endl;
//	cout << "제거" << endl;
//	v.erase(remove_if(v.begin(), v.end(), [](String& a) {
//		return a.getString() == "cc";
//		}),v.end());
//	for (const auto& d : v)
//		cout << d << endl;
//}