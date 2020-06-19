
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <iterator>
#include <fstream>
using namespace std;



struct PS :pair<string, string> {
	PS(string s) :pair(s, s) {
		sort(first.begin(), first.end());
	}
	operator string() {
		return second;
	}
};


ostream& operator<<(ostream& os, const PS& a) {
	os << a.second;
	return os;
}



int main()
{
	vector<PS> v;
	ifstream in("�ܾ��.txt");
	//vector<string> v{ istream_iterator<string>{in},{} };
	copy(istream_iterator<string>{in}, {}, back_inserter(v));


	//�ܾ� ���� first�������� wjdfufgksek.
	sort(v.begin(), v.end(), [](const PS& a, const PS& b) {
		return a.first < b.first;
		});
	//auto p=find_if(v.begin(), v.end(), [](const PS& a) {
	//	return a.second == "apple";
	//	});

	//for (auto i = p-10; i < p+10; ++i)
	//{
	//	cout << i->first << " - " << i->second << endl;
	//}

	//while (true) {
	//	cout << "�ܾ �Է��ϼ���: ";
	//	string word;
	//	cin >> word;

	////	sort(word.begin(), word.end());
	//	//cout << "�����Ѵܾ�" << word << endl;

	//	//auto n=binary_search(v.begin(), v.end(), PS(word), [](const PS& a, const PS& b) {  //�ֳ� ���� �� ������ �˷���
	//	//	return a.first < b.first;
	//	//	});
	//	//cout << "�ִ� �ܾ��" << n << endl;

	//
	//	//word�� �ֳʱ׷����� ��� ã�� �������.
	//	//1. word�� �����Ѵ�.
	//	//2. ������ first ���� word�� ���� �͵��� ��� ã�´�.
	//	auto [����,����]=equal_range(v.begin(), v.end(), PS(word), [](const PS& a, const PS& b) {
	//		return a.first < b.first;
	//		});
	//
	//	//3. ã�� �ܾ���� second ���� ����Ѵ�.
	//	if (���� == ����){
	//		cout << "���� �ܾ� �Դϴ�." << endl;
	//		continue;
	//	
	//	}
	//	cout << "[" << ���� - ���� << "]- ";
	//	for (auto i = ����; i < ����; ++i)
	//		cout << i->second << " ";
	//	cout << endl;
	//}


	//for (auto i = 31000; i < 31200; ++i)
	//{
	//	cout << v[i].first << " - " << v[i].second << endl;
	//}
	//[����]������ �ִ� ��� �ֳʱ׷��� ã��

	//���� ������ �����ϴ� ��� �ֳʱ׷� ���� ���� ������������ ������ 
	//"�ֳʱ׷� �� ���� �������� ����.txt
	/*
	aaceginr - racinage
	aaceginr - canaigre
	aaceginr - graecian
	aaceginrss - cassegrain
	aaceginrsv - vagrancies
	aaceginrsz - zingaresca
	aaceginrtv - revacating
	aaceginst - caseating
	aaceginsuwy - causewaying
	*/
	auto b = v.begin();
	int cnt{};

	ofstream out{ "�ֳʱ׷� �� ��������.txt" };


	vector < vector<string>> vv;

	while (true) {
		//b=���� ��ġ�� ���ҿ� ���� ���Ұ� ���� ���� ã��.

		b = adjacent_find(b, v.end(), [](const PS& a, const PS& b) {
			return a.first == b.first;
			});
		if (b == v.end())
			break;
		//e=b+1���� ���� �������� �޶����� ��ġ�� ã�´�.

		auto e = find_if_not(b + 1, v.end(), [b](const PS& a) { //���� ĸ�� (&���� �����̸� �����´�.)
			return a.first == b->first;
			});
		//[b,e)�� �ֳʱ׷� ���� �ȴ�.
		// ���� �����̳ʿ� ����
		vector<string>vs{ b,e };
		vv.push_back(vs);
		/*out << "[" << ++cnt << "]" << " (" << e - b << ")";
		copy(b, e, ostream_iterator<PS>{out, "  "});
		out << endl;*/
		//�ٽ� ã�Ƴ��� ��ġ�� b=e;
		b = e;
	}


	for (auto& a : vv)
		sort(a.being(), a.end());

	sort(vv.begin(), vv.end(), [](const vector<string>& a, const vector<string>& b) {
		return a.size() > b.size();

		});

	for (int i = 0; i < vv.size(); ++i) {
		out << "[" << i + 1 << "]" << " (" << vv[i].size() << ") - ";
		copy(vv[i].begin(), vv[i].end(), ostream_iterator<string>{out, "  "});
		out << endl;
	}
}
