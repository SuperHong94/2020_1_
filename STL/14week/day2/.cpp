#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iterator>
#include <fstream>
using namespace std;


//struct PS :pair<string, string> {
//	PS(string s) :pair(s, s) {
//		sort(first.begin(), first.end());
//	}
//};
struct PS : pair<string, string> {
	PS(string s) :pair(s, s) {
		sort(first.begin(), first.end());
	}
};
int main()
{
	
	vector<PS> v;

	ifstream in("단어들.txt");
	//vector<string> v{ istream_iterator<string>{in},{} };
	copy(istream_iterator<string>{in}, {}, back_inserter(v));

	sort(v.begin(), v.end(), [](const PS& a, const PS& b) {
		return a.first < b.first;
		});
	//단어 쌍을 first기준으로 wjdfufgksek.
	sort(v.begin(), v.end(), [](const PS& a, const PS& b) {
		return a.first < b.first;
		});
	//[문제] 사전에 존재하는 모든 애너그램 쌍을 화면에 출력하라

	while (true) {
		//현재 위치의 원소와 다음 원소가 같은 걸 찾자.
	}
}