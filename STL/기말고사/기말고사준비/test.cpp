#include <iostream>
#include <algorithm>	
#include <iterator>
#include <fstream>
#include <random>
using namespace std;

void makeData();
int main()
{
	makeData();

	ifstream in{ "숫자백만개.txt" };
	vector<char> v{ istream_iterator<char>{in},{} };
	cout << v.size() << endl;

	int a[10]{};
	for (int i = 0; i < 10; ++i) {
		a[i] = count(v.begin(), v.end(), i + '0');
		cout << a[i] << endl;
	}
	cout << endl;
	sort(v.begin(), v.end());

	int b[10]{};
	for (int i = 0; i < 10; ++i) {
		auto [low, high] = equal_range(v.begin(), v.end(), i + '0');
		b[i] = high - low;
		cout << b[i] << endl;
	}

	cout << equal(begin(a), end(a), begin(b)) << endl;
	//--다음문제
	/*shuffle(v.begin(), v.end(), mt19937());
	for (int i = 0; i < 50; ++i)
		cout << v[i];
	cout << endl;
	co
	for (int i = 0; i < 50; ++i)
		cout << v[i];
}*/
}
void makeData()
{
	uniform_int_distribution<int> uid{ 0,9 };
	mt19937 re;
	ofstream out{ "숫자백만개.txt" };
	for (int i = 0; i < 100'0000; ++i)
		out << uid(re);
}