//#/*include <iostream>
//#include <vector>
//#include "String.h"
//using namespace std;
//int main()
//{
//	vector<String> v{ "�Ϻ�","�ڷγ�","�ű�Ȯ��","700��" };
//	cout << "vetor v�� �ּ�: " << &v << endl;
//	cout << "������ ����: " << v.size() << endl;
//	cout << "���Ҵ����� �ʰ� ���� �� �ִ� ����: " << v.capacity() << endl;
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
////	v.emplace_back("�Ϻ�");
////	v.emplace_back("�ڷγ�");
////	v.emplace_back("�ű�Ȯ��");
////	v.emplace_back("700��");
////	cout << "vetor v�� �ּ�: " << &v << endl;
////	cout << "������ ����: " << v.size() << endl;
////	cout << "���Ҵ����� �ʰ� ���� �� �ִ� ����: " << v.capacity() << endl;
////	cout << "������������ �����մϴ�." << endl;
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
////	v.emplace_back("�Ϻ�");
////	v.emplace_back("�ڷγ�");
////	v.emplace_back("�ű�Ȯ��");
////	v.emplace_back("700��");
////	cout << &v << endl;
////	cout << &v[0]<< endl;
////	cout << "----------------" << endl;
////	cout << "���Ҹ� �߰��ϱ���" << endl;
////	v.emplace_back("PANDEMIC");
////	cout << "���Ҹ� �߰��� ��" << endl;
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
//	//auto i=remove(v.begin(), v.end(), 3); //����3 ����
//	//v.erase(i);
//	//v.erase(remove(v.begin(), v.end(), 3));
//
//	//Ȧ�� ����
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
////	ofstream out("���� ����");
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
////	/*ifstream in("���� ����");
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
//	news.push_back(String{ "��, ���� �������� ���ܰ���" });
//	news.push_front(String{ "��, ���͸� �˻翡 ������ ���� ����" });
//
//	news.emplace_back("�Ϻ� ������ ���� ���� �ܰ�");
//	news.emplace_back("��, ������ ��޻��� �ʹ� �ʾ�..");
//	cout << "�����޽��� off" << endl;
//	cout << endl;
//	cout << "deque�� ����� ��� ���� ���" << endl;
//	cout << endl;
//	for (const String& s : news)
//		cout << s << endl;
//	cout << endl;
//	//���� �� ������������ ����
//	sort(news.begin(), news.end(), [](const String& a, const String& b) {
//		return a.size() < b.size();
//		});
//
//	//��� ���
//	cout << "���� �� ������������ ����\n\n";
//	for (int i = 0; i < news.size(); ++i)
//		cout << news[i] << endl;
//	cout << endl;
//	//����� �ݴ�� ���
//	cout << "���� �� �������� ����" << endl;
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
//		cout << "���� ��: " << this << endl;
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
//	cout << "������ �ּҸ� ����Ѵ�.\n";
//	for (auto&& test : d)
//		test.show();
//	cout << endl;
//
//	cout << endl;
//	cout << "���ʿ� ���Ҹ� �߰��� �� �ּҸ� ����Ѵ�." << endl;
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
//	cout << "���� ��\n";
//	for (const auto& d : v)
//		cout << d << endl;
//	cout << "����" << endl;
//	v.erase(remove_if(v.begin(), v.end(), [](String& a) {
//		return a.getString() == "cc";
//		}),v.end());
//	for (const auto& d : v)
//		cout << d << endl;
//}