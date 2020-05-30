//#include <iostream>	
//#include <random>
//#include <vector>
//#include <chrono>
//#include <algorithm>
//#include <set>
//#include <unordered_set>
//using namespace std;
//
//const size_t NUM = 1000000;
//
//const size_t TNUM = 1000;
//
//static int equalNum = 0;
//static int lessNum = 0;
//
//
//
//
//class Test {
//	int n;
//public:
//	Test() = default;
//	Test(int n) :n{ n } {}
//	bool operator <(const Test& rhs)const {
//		lessNum++;
//		return n < rhs.n;
//	}
//	bool operator ==(const Test& rhs)const {
//		equalNum++;
//		return n == rhs.n;
//	}
//	
//	int GetNum() const
//	{
//		return n;
//	}
//	friend ostream& operator<<(ostream& os,const Test& rhs){
//		os << rhs.n;
//		return os;
//	}
//	
//};
//template<>
//struct hash<Test> {
//	size_t operator()(const Test& t)const {
//		return hash<int>()(t.GetNum());
//	}
//};
//
//Test findingNums[TNUM];  ///ã���� TNUM������ŭ �־�� �迭
//
//default_random_engine dre;
//normal_distribution<> nd{ 0.0,1.0f };
//
//
//int main()
//{
//	vector<Test> v;
//	v.reserve(NUM); //��ü ���ڿ� ���ֱ�
//	for (int i = 0; i < NUM; ++i) {
//		double d = nd(dre);
//
//		d = clamp(d, -5.0, 5.0);
//		d += 5;  //[0~10]
//		d *= NUM / 10; //[0~NUM]
//		v.emplace_back(d);  
//	}
//
//	uniform_int_distribution<> uid(0, NUM);
//
//	for (Test& t : findingNums) { //ã�� ���ڹ迭�� ���ֱ�
//		int d = uid(dre);
//		t = d;
//	}
//	multiset<Test> s{ v.begin(),v.end() };
//	unordered_multiset<Test> us{ v.begin(),v.end() };
//
//
//	cout << "���� ���� - " << v.size() << endl;
//	cout << "��Ƽ�� ���� - " << s.size() << endl;
//	cout << "������� ��Ƽ�� ����-" << us.size() << endl;
//	cout << "ã������ ������ ����- " << TNUM << endl;
//
//	
//	{
//		equalNum = 0;
//		lessNum = 0;
//		cout << endl;
//		cout << "vector ã��" << endl;
//
//		chrono::steady_clock::time_point start = chrono::steady_clock::now();
//		for (const auto& d : findingNums){
//			find(v.begin(), v.end(), d);
//		}
//		std::cout << chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now() - start).count() << "����ũ���� �ɸ�" << endl;
//		std::cout << " < Ƚ��- " << lessNum << endl;
//		std::cout << "== Ƚ��- " << equalNum << endl;
//	}
//
//
//	{
//		cout << endl;
//		cout << "multiset ã��" << endl;
//
//		equalNum = 0;
//		lessNum = 0;
//		chrono::steady_clock::time_point start = chrono::steady_clock::now();
//		for (const auto& d : findingNums){
//			s.find(d);
//		}
//		std::cout << chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now() - start).count() << "����ũ���� �ɸ�" << endl;
//		std::cout << " < Ƚ��- " << lessNum << endl;
//	}
//
//
//	
//
//	{
//		cout << endl;
//		cout << "Unordered_multiset ã��" << endl;
//		equalNum = 0;
//		lessNum = 0;
//		chrono::steady_clock::time_point start = chrono::steady_clock::now();
//		for (const Test& n : findingNums) {
//			us.find(n);
//		}
//		std::cout << chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now() - start).count() << "����ũ���� �ɸ�" << endl;
//		std::cout << "== Ƚ��- " << equalNum << endl;
//		std::cout << " < Ƚ��- " << lessNum << endl;
//
//	}
//
//}
