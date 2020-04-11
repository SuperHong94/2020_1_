
//day2 page1
//#include <iostream>
//#include <array>
//#include <algorithm>
//#include "String.h"
//using namespace std;
//
//int main()
//{
//	array<String, 5>words{ "corona","virus","world","crisis","pandemic" };
//	cout << "-정렬하기 전 array<String,5>의 내용-" << endl;
//	for (int i = 0; i < words.size(); ++i)
//		cout << words[i] << " ";
//	cout << endl;
//	cout << endl;
//
//	sort(words.begin(), words.end(), [](const String& a, const String& b) {
//		return a.getString() < b.getString();
//		});
//	cout << "정렬 후 array<String,5>의 내용-" << endl;
//	for (int i = 0; i < words.size(); ++i)
//		cout << words[i] << " ";
//	cout << endl;
//}

//p3
//#include <iostream>
//#include <array>
//#include <algorithm>
//#include "String.h"
//using namespace std;
//
//int main()
//{
//	array<String, 5>words{ "New","York","schools","dropping","Zoom" };
//	cout << "-정렬하기 전 array<String,5>의 내용-" << endl;
//	for (int i = 0; i < words.size(); ++i)
//		cout << words[i] << " ";
//	cout << endl;
//	cout << endl;
//
//	sort(words.begin(), words.end(), [](const String& a, const String& b) {
//		return a.getString() < b.getString();
//		});
//	cout << "정렬 후 array<String,5>의 내용-" << endl;
//	for (int i = 0; i < words.size(); ++i)
//		cout << words[i] << " ";
//	cout << endl;
//}


//p4

//#include <iostream>
//#include <array>
//#include <algorithm>
//#include "String.h"
//using namespace std;
//
//int main()
//{
//	array<String, 16>words{ "Anger", "as", "Japanese", "Prime", "Minister offers", "two",
//		"cloth", "masks", "per", "family", "while", "refusing", "to", "declare", "coronavirus", "emergency" };
//	cout << "-정렬하기 전 array<String,5>의 내용-" << endl;
//	for (int i = 0; i < words.size(); ++i)
//		cout << words[i] << " ";
//	cout << endl;
//	cout << endl;
//
//	for (int i = 0; i < words.size(); ++i) {
//		sort(&words[i][0], &words[i][words[i].size()], [](char a, char b) {
//			return a < b;
//			});
//
//	}
//	cout << "정렬 후 array<String,5>의 내용-" << endl;
//	for (int i = 0; i < words.size(); ++i)
//		cout << words[i] << " ";
//	cout << endl;
//	/*String a{ "Prime" };
//	for (int i = 0; i < a.size(); ++i)
//		cout << a[i] << " "<<typeid(a[i]).name()<<" ";
//	cout << '\n';
//	sort(&a[0],&a[a.size()], [](char c, char b) {
//		return c < b;
//		});
//	for (int i = 0; i < a.size(); ++i)
//		cout << a[i] << " ";
//	cout << '\n';*/
//}


//p6
//
//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main()
//{
//	vector<int> v{ 1,2,3,4,5 };
//	v.push_back(6);
//	for (auto d : v)
//		cout << d << " ";
//	cout << endl;
//	cout << "백터 객체의 크기: " << sizeof(v) << endl;
//	cout << "벡터의 원소 수: " << v.size() << endl;
//	cout << "현재 벡터가 담을 수 있는 원소의 갯수" << v.capacity() << endl;
//	cout << "이 시스템에서 vector<int>가 담을 수 있는 최대 원소 수- " << v.max_size() << endl;
//}


//p8
//#include <iostream>
//#include <vector>
//#include <thread>
//using namespace std;
//
//int main()
//{
//	vector<int> v;
//	v.reserve(200);
//	int capacity{ -1 };
//	int i{};
//
//	while (true) {
//		v.push_back(++i);
//		cout << i << " ";
//		this_thread::sleep_for(100ms);
//
//		if (capacity != v.capacity()) {
//			cout << endl;
//			cout << "원소 수: " << v.size() << endl;
//			cout << "메모리 재할당 후 담을 수 있는 원소의 갯수 " << v.capacity() << endl;
//			cout << "\n\n";
//			capacity = v.capacity();
//			cout << "원소 추가-";
//		}
//	}
//}



//p10
#include <iostream>
#include <vector>
#include "String.h"
using namespace std;

int main()
{
	vector<String> v;
	v.reserve(2);
	v.emplace_back("코로나");
	cout << "원소추가------------\n";
	v.emplace_back("바이러스");

}