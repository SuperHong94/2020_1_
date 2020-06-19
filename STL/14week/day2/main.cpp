
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
	ifstream in("단어들.txt");
	//vector<string> v{ istream_iterator<string>{in},{} };
	copy(istream_iterator<string>{in}, {}, back_inserter(v));


	//단어 쌍을 first기준으로 wjdfufgksek.
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
	//	cout << "단어를 입력하세요: ";
	//	string word;
	//	cin >> word;

	////	sort(word.begin(), word.end());
	//	//cout << "정렬한단어" << word << endl;

	//	//auto n=binary_search(v.begin(), v.end(), PS(word), [](const PS& a, const PS& b) {  //있냐 없냐 만 빠르게 알려줌
	//	//	return a.first < b.first;
	//	//	});
	//	//cout << "있는 단어니" << n << endl;

	//
	//	//word의 애너그램들을 모두 찾아 출력하자.
	//	//1. word를 정렬한다.
	//	//2. 사전의 first 값이 word와 같은 것들을 모두 찾는다.
	//	auto [하한,상한]=equal_range(v.begin(), v.end(), PS(word), [](const PS& a, const PS& b) {
	//		return a.first < b.first;
	//		});
	//
	//	//3. 찾은 단어들의 second 값을 출력한다.
	//	if (상한 == 하한){
	//		cout << "없는 단어 입니다." << endl;
	//		continue;
	//	
	//	}
	//	cout << "[" << 상한 - 하한 << "]- ";
	//	for (auto i = 하한; i < 상한; ++i)
	//		cout << i->second << " ";
	//	cout << endl;
	//}


	//for (auto i = 31000; i < 31200; ++i)
	//{
	//	cout << v[i].first << " - " << v[i].second << endl;
	//}
	//[문제]사전에 있는 모든 애너그램을 찾기

	//문제 사전에 존재하는 모든 애너그램 쌍을 개수 내림차순으로 졍렬후 
	//"애너그램 쌍 길이 내림차순 정렬.txt
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

	ofstream out{ "애너그램 쌍 내림차순.txt" };


	vector < vector<string>> vv;

	while (true) {
		//b=현재 위치의 원소와 다음 원소가 같은 것을 찾자.

		b = adjacent_find(b, v.end(), [](const PS& a, const PS& b) {
			return a.first == b.first;
			});
		if (b == v.end())
			break;
		//e=b+1부터 나와 다음것이 달라지는 위치를 찾는다.

		auto e = find_if_not(b + 1, v.end(), [b](const PS& a) { //람다 캡쳐 (&원본 변수이름 가져온다.)
			return a.first == b->first;
			});
		//[b,e)는 애너그램 쌍이 된다.
		// 쌍을 컨테이너에 저장
		vector<string>vs{ b,e };
		vv.push_back(vs);
		/*out << "[" << ++cnt << "]" << " (" << e - b << ")";
		copy(b, e, ostream_iterator<PS>{out, "  "});
		out << endl;*/
		//다시 찾아나갈 위치는 b=e;
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
