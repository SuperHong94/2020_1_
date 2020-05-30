#include <iostream>
#include <vector>
#include <random>
#include <set>
#include <unordered_set>
#include <chrono>
#include <algorithm>
using namespace std;

const int NUM = 10000000;
const int TNUM = 100;

default_random_engine dre;
normal_distribution<> nd(0, 1.0);

size_t equalCnt = 0;
size_t lessCnt = 0;
class Test
{
	int n;
public:
	Test() = default;
	Test(int n) :n{ n } {}
	int GetNum() const { return n; };

	bool operator==(const Test& rhs) const {
		equalCnt++;
		return n == rhs.n;
	}
	bool operator<(const Test& rhs) const {
		lessCnt++;
		return n < rhs.n;
	}

};

template<>
struct hash<Test>
{
	size_t operator()(const Test& rhs) const {
		return hash<int>()(rhs.GetNum());
	}
};


Test tnums[TNUM];


int main()
{

	uniform_int_distribution<> uid(0, NUM);

	for (Test& t : tnums)
		t = uid(dre);



	vector<Test> v;
	v.reserve(NUM);
	double d{};
	for (int i = 0; i < NUM; ++i) {
		d = nd(dre);
		d = clamp(d, -5.0, 5.0);
		d += 5;
		d *= NUM / 10;
		v.emplace_back(d);
	}

	multiset<Test> s{ v.begin(),v.end() };
	unordered_multiset<Test> us{ v.begin(),v.end() };

	{
		cout << endl;
		equalCnt = 0;
		lessCnt = 0;
		cout << "벡터 찾기\n";
		auto start = chrono::steady_clock::now();
		for (const auto& t : tnums)
			find(v.begin(), v.end(), t);
		cout << chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start).count() << "밀리초 걸림\n";
		cout << "== 횟수: " << equalCnt << endl;
		cout << "< 횟수: " << lessCnt << endl;

	}

	{
		cout << endl;
		equalCnt = 0;
		lessCnt = 0;
		cout << "멀티셋 찾기\n";
		auto start = chrono::steady_clock::now();
		for (const auto& t : tnums)
			s.find(t);
		cout << chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start).count() << "밀리초 걸림\n";
		cout << "== 횟수: " << equalCnt << endl;
		cout << "< 횟수: " << lessCnt << endl;

	}
	{
		cout << endl;
		equalCnt = 0;
		lessCnt = 0;
		cout << "언오더드멀티셋 찾기\n";
		auto start = chrono::steady_clock::now();
		for (const auto& t : tnums)
			us.find(t);
		cout << chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start).count() << "밀리초 걸림\n";
		cout << "== 횟수: " << equalCnt << endl;
		cout << "< 횟수: " << lessCnt << endl;

	}


}