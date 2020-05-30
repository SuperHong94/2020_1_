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
//Test findingNums[TNUM];  ///찾을수 TNUM개수만큼 넣어둔 배열
//
//default_random_engine dre;
//normal_distribution<> nd{ 0.0,1.0f };
//
//
//int main()
//{
//	vector<Test> v;
//	v.reserve(NUM); //전체 숫자에 값넣기
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
//	for (Test& t : findingNums) { //찾을 숫자배열에 값넣기
//		int d = uid(dre);
//		t = d;
//	}
//	multiset<Test> s{ v.begin(),v.end() };
//	unordered_multiset<Test> us{ v.begin(),v.end() };
//
//
//	cout << "벡터 개수 - " << v.size() << endl;
//	cout << "멀티셋 개수 - " << s.size() << endl;
//	cout << "언오더드 멀티셋 개수-" << us.size() << endl;
//	cout << "찾을려는 숫자의 개수- " << TNUM << endl;
//
//	
//	{
//		equalNum = 0;
//		lessNum = 0;
//		cout << endl;
//		cout << "vector 찾기" << endl;
//
//		chrono::steady_clock::time_point start = chrono::steady_clock::now();
//		for (const auto& d : findingNums){
//			find(v.begin(), v.end(), d);
//		}
//		std::cout << chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now() - start).count() << "마이크로초 걸림" << endl;
//		std::cout << " < 횟수- " << lessNum << endl;
//		std::cout << "== 횟수- " << equalNum << endl;
//	}
//
//
//	{
//		cout << endl;
//		cout << "multiset 찾기" << endl;
//
//		equalNum = 0;
//		lessNum = 0;
//		chrono::steady_clock::time_point start = chrono::steady_clock::now();
//		for (const auto& d : findingNums){
//			s.find(d);
//		}
//		std::cout << chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now() - start).count() << "마이크로초 걸림" << endl;
//		std::cout << " < 횟수- " << lessNum << endl;
//	}
//
//
//	
//
//	{
//		cout << endl;
//		cout << "Unordered_multiset 찾기" << endl;
//		equalNum = 0;
//		lessNum = 0;
//		chrono::steady_clock::time_point start = chrono::steady_clock::now();
//		for (const Test& n : findingNums) {
//			us.find(n);
//		}
//		std::cout << chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now() - start).count() << "마이크로초 걸림" << endl;
//		std::cout << "== 횟수- " << equalNum << endl;
//		std::cout << " < 횟수- " << lessNum << endl;
//
//	}
//
//}
