#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <numeric>
#include <iterator>
#include <set>
#include <string>
#include <map>
using namespace std;


template<class InIter, class T>
T myAccumulate(InIter beg, InIter end, T initVal)
{
	cout << "accumulate 구현" << endl;
	while (beg != end) {
		initVal += *beg;
		++beg;
	}
	return initVal;
}
int main()
{
	ifstream in("중간시험정수.txt");
	//vector<int> v{ istream_iterator<int> {in}, istream_iterator<int>{} };
	vector<int> v;
	int n{};
	while (in >> n) {
		v.push_back(n);
	}
	cout << v.size() << endl;

	auto [min, max] = minmax_element(v.begin(), v.end());
	cout << typeid(min).name() << endl;
	cout << *min << '-' << *max << endl;

	for (int d : v)
		cout << d << '\n';
	/*pair<vector<int>::iterator, vector<int>::iterator> p= minmax_element(v.begin(), v.end());
	cout << *(p.first) <<'-' <<*(p.second) << endl;*/


	long long sum0 = myAccumulate(v.begin(), v.end(), (long long)0);
	long long sum1 = accumulate(v.begin(), v.end(),0.0);
	cout << sum0 << endl;
	cout << sum1 << endl;
	//cout << static_cast<long long>((double)sum0 / v.size()) << endl;

	/*sort(v.begin(), v.end());
	auto a = adjacent_find(v.begin(), v.end());
	for (int i = 0; i < v.size() - 1; ++i) {
		if (v[i] == v[i + 1]){
			cout << "같은숫자-" << v[i] << endl;
			break;
		}
	}*/
	//cout << "같은 숫자-" << *a << endl;

	//set<int> s;
	//for (int i :v) {
	//	if(!s.insert(i).second){
	//		cout << "같은숫자-" <<i << endl;
	//		break;
	//	}
	//}


	/*int a[10]{};
	string str;
	for (int n : v) {
		str = to_string(n);
		for (char c : str)
			a[c - '0']++;
	}
	for (int i = 0; i < 10; ++i)
		cout << i << " - " << a[i] << endl;*/


	//map<char, int> m;
	//string str;
	//for (int n : v) {
	//	str = to_string(n);
	//	for (char c : str) {
	//		m[c]++;
	//	}
	//}

	//for (auto& [숫자, 개수] : m)
	//	cout << 숫자 << " - " << 개수 << endl;
}