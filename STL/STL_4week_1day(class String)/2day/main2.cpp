
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
//	cout << "-�����ϱ� �� array<String,5>�� ����-" << endl;
//	for (int i = 0; i < words.size(); ++i)
//		cout << words[i] << " ";
//	cout << endl;
//	cout << endl;
//
//	sort(words.begin(), words.end(), [](const String& a, const String& b) {
//		return a.getString() < b.getString();
//		});
//	cout << "���� �� array<String,5>�� ����-" << endl;
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
//	cout << "-�����ϱ� �� array<String,5>�� ����-" << endl;
//	for (int i = 0; i < words.size(); ++i)
//		cout << words[i] << " ";
//	cout << endl;
//	cout << endl;
//
//	sort(words.begin(), words.end(), [](const String& a, const String& b) {
//		return a.getString() < b.getString();
//		});
//	cout << "���� �� array<String,5>�� ����-" << endl;
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
//	cout << "-�����ϱ� �� array<String,5>�� ����-" << endl;
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
//	cout << "���� �� array<String,5>�� ����-" << endl;
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
//	cout << "���� ��ü�� ũ��: " << sizeof(v) << endl;
//	cout << "������ ���� ��: " << v.size() << endl;
//	cout << "���� ���Ͱ� ���� �� �ִ� ������ ����" << v.capacity() << endl;
//	cout << "�� �ý��ۿ��� vector<int>�� ���� �� �ִ� �ִ� ���� ��- " << v.max_size() << endl;
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
//			cout << "���� ��: " << v.size() << endl;
//			cout << "�޸� ���Ҵ� �� ���� �� �ִ� ������ ���� " << v.capacity() << endl;
//			cout << "\n\n";
//			capacity = v.capacity();
//			cout << "���� �߰�-";
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
	v.emplace_back("�ڷγ�");
	cout << "�����߰�------------\n";
	v.emplace_back("���̷���");

}