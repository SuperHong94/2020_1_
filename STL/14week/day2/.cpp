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

	ifstream in("�ܾ��.txt");
	//vector<string> v{ istream_iterator<string>{in},{} };
	copy(istream_iterator<string>{in}, {}, back_inserter(v));

	sort(v.begin(), v.end(), [](const PS& a, const PS& b) {
		return a.first < b.first;
		});
	//�ܾ� ���� first�������� wjdfufgksek.
	sort(v.begin(), v.end(), [](const PS& a, const PS& b) {
		return a.first < b.first;
		});
	//[����] ������ �����ϴ� ��� �ֳʱ׷� ���� ȭ�鿡 ����϶�

	while (true) {
		//���� ��ġ�� ���ҿ� ���� ���Ұ� ���� �� ã��.
	}
}