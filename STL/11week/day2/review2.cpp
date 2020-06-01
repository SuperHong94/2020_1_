//#include <iostream>
//#include <vector>
//#include <random>
//#include <set>
//#include <unordered_set>
//#include <chrono>
//#include <algorithm>
//using namespace std;
//
//const int NUM = 10000000;
//const int TNUM = 100;
//
//default_random_engine dre;
//normal_distribution<> nd(0, 1.0);
//
//size_t equalCnt = 0;
//size_t lessCnt = 0;
//class Test
//{
//	int n;
//public:
//	Test() = default;
//	Test(int n) :n{ n } {}
//	int GetNum() const { return n; };
//
//	bool operator==(const Test& rhs) const {
//		equalCnt++;
//		return n == rhs.n;
//	}
//	bool operator<(const Test& rhs) const {
//		lessCnt++;
//		return n < rhs.n;
//	}
//
//};
//
//template<>
//struct hash<Test>
//{
//	size_t operator()(const Test& rhs) const {
//		return hash<int>()(rhs.GetNum());
//	}
//};
//
//
//Test tnums[TNUM];
//
//
//int main()
//{
//
//	uniform_int_distribution<> uid(0, NUM);
//
//	for (Test& t : tnums)
//		t = uid(dre);
//
//
//
//	vector<Test> v;
//	v.reserve(NUM);
//	double d{};
//	for (int i = 0; i < NUM; ++i) {
//		d = nd(dre);
//		d = clamp(d, -5.0, 5.0);
//		d += 5;
//		d *= NUM / 10;
//		v.emplace_back(d);
//	}
//
//	multiset<Test> s{ v.begin(),v.end() };
//	unordered_multiset<Test> us{ v.begin(),v.end() };
//
//	{
//		cout << endl;
//		equalCnt = 0;
//		lessCnt = 0;
//		cout << "���� ã��\n";
//		auto start = chrono::steady_clock::now();
//		for (const auto& t : tnums)
//			find(v.begin(), v.end(), t);
//		cout << chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start).count() << "�и��� �ɸ�\n";
//		cout << "== Ƚ��: " << equalCnt << endl;
//		cout << "< Ƚ��: " << lessCnt << endl;
//
//	}
//
//	{
//		cout << endl;
//		equalCnt = 0;
//		lessCnt = 0;
//		cout << "��Ƽ�� ã��\n";
//		auto start = chrono::steady_clock::now();
//		for (const auto& t : tnums)
//			s.find(t);
//		cout << chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start).count() << "�и��� �ɸ�\n";
//		cout << "== Ƚ��: " << equalCnt << endl;
//		cout << "< Ƚ��: " << lessCnt << endl;
//
//	}
//	{
//		cout << endl;
//		equalCnt = 0;
//		lessCnt = 0;
//		cout << "��������Ƽ�� ã��\n";
//		auto start = chrono::steady_clock::now();
//		for (const auto& t : tnums)
//			us.find(t);
//		cout << chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start).count() << "�и��� �ɸ�\n";
//		cout << "== Ƚ��: " << equalCnt << endl;
//		cout << "< Ƚ��: " << lessCnt << endl;
//
//	}
//
//
//}


#include <iostream>
#include <set>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <random>
#include <chrono>
using namespace std;

default_random_engine dre ;
normal_distribution<> nd(0.0, 1.0);

const int NUM = 100'0;
const int TNUM = 10;


class Test {
	int num;
	static int ex;
public:
	static long long lessCnt;
	static long long equalCnt;
	Test() = default;
	Test(int n) :num{ n } {}
	int GetNum() const { return num; }

	bool operator==(const Test& rhs)const {
		equalCnt++;
		return num == rhs.num;
	}
	bool operator<(const Test& rhs)const {
		lessCnt++;
		return num < rhs.num;
	}
};

long long Test::equalCnt = 0;
long long Test::lessCnt = 0;
template<>
struct hash<Test>
{
	size_t operator()(const Test& rhs)const {
		return hash<int>()(rhs.GetNum());
	}
};

Test tnums[TNUM];

int main()
{
	vector<Test> v;
	v.reserve(NUM);
	double d{};
	for (int i = 0; i < NUM; ++i) {
		d = nd(dre);
		d = clamp(d, -5.0, 5.0);
		d += 5.0;
		d *= NUM / 10;
		v.emplace_back(d);
	}
	multiset<Test> s{ v.begin(),v.end() };
	unordered_multiset<Test> us{ v.begin(),v.end() };

	uniform_int_distribution<> uid(0, NUM-1);

	for (int i = 0; i < TNUM; ++i)
		tnums[i] = v[uid(dre)];
	cout << "������ ������: " << v.size() << endl;
	cout << "���� ����: " << s.size() << endl;
	cout << "������� ���� ����: " << us.size() << endl;


	{//���� ã��
		cout << "\n���� ã��" << endl;
		Test::equalCnt = 0;
		Test::lessCnt = 0;
		chrono::steady_clock::time_point start = chrono::steady_clock::now();
		for (int i = 0; i < TNUM; ++i)
			find(v.begin(), v.end(), tnums[i]);
		cout << chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start).count()<<"�и��� �ɸ�" << endl;
		cout << "==Ƚ��: " << Test::equalCnt << endl;
		
		cout << "<Ƚ��: " << Test::lessCnt << endl;
	}

	{
		cout << "\n��Ƽ�� ã��" << endl;
		Test::equalCnt = 0;
		Test::lessCnt = 0;
		auto start = chrono::steady_clock::now();
		for (const Test& t : tnums)
			s.find(t);
		cout << chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start).count() << "�и��� �ɸ�" << endl;
		cout << "==Ƚ��: " << Test::equalCnt << endl;
		cout << "<Ƚ��: " << Test::lessCnt << endl;
	}

	{
		cout << "\n��������� ��Ƽ�� ã��" << endl;
		Test::equalCnt = 0;
		Test::lessCnt = 0;
		auto start = chrono::steady_clock::now();
		for (const Test& t : tnums)
			us.find(t);
		cout << chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start).count() << "�и��� �ɸ�" << endl;
		cout << "==Ƚ��: " << Test::equalCnt << endl;
		cout << "<Ƚ��: " << Test::lessCnt << endl;
	}
} 