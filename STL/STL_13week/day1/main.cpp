/*
6월 26일 시험
정렬 관련 알고리즘을 구분할 수 있다.

nth_element-> partial_sort->sort->stable_sort

정렬되어 있는 범위를 검색하는 방법
binary_search

*/

//#include <iostream>
//#include <algorithm>
//#include <iterator>
//#include <random>
//#include <numeric>
//
//using namespace std;
//
//int main()
//{
//	int a[100];		//정수 100개
//	iota(begin(a), end(a), 1);  //[1,100]으로 채운다.
//
//
//	shuffle(begin(a), end(a), mt19937()); //mt19937()==dre;
//	//copy(begin(a), end(a), ostream_iterator<int>{cout, "\t"});
//
//
//	//홀수와 짝수로 구분하여 출려하라 -partition
//	
//	//내가 한거랑 교수님한거 똑같다.
//	auto it = partition(begin(a), end(a), [](int i) {
//		return i & 1;
//		});
//	cout << "\n홀수입니다." << endl;
//	copy(begin(a), it, ostream_iterator<int>{cout, "\t"});
//	cout << "\n짝수입니다. " << endl;
//	copy(it, end(a), ostream_iterator<int>{cout, "\t"});
//
//	
//}



//--


//#include <iostream>
//#include <algorithm>
//#include <iterator>
//#include <random>
//#include <numeric>
//#include <string>
//#include "String.h"
//
//using namespace std;
//
//mt19937 dre;
//uniform_int_distribution<> uidAge{ 12,60 };
//uniform_int_distribution<> uidName{ 'a','z' };
//uniform_int_distribution<> uidLen{ 3,10 };
//
//struct Player {
//	int age;
//	String name;
//	Player() {
//		age = uidAge(dre);
//		for (int i = 0; i < uidLen(dre); ++i)
//			name += uidName(dre);
//	}
//
//	void show()const {
//		cout << age << " " << name << endl;
//	}
//
//	bool operator<(const Player& rhs)const { //비교함수니깐 const 붙여야된다!
//		return age < rhs.age;
//	}
//
//};
//
//ostream& operator<<(ostream& os, const Player& p) 
//{
//	os << p.age << "  " << p.name << endl;
//	return os;
//}
//
//
//
//
//int main()
//{
//	Player players[100];
//
//	for (const Player& p : players)
//		p.show();
//
//	////플레이어 100명이 있는데 
//	////젊은 애들 30명만 뽑아봐!  뽑은 30명의 순서는 상관안한다.
//	//nth_element(begin(players), begin(players) + 30, end(players));
//
//	//cout << "------구분" << endl;
//	//for (int i = 0; i < 30; ++i)
//	//	players[i].show();
//
//
//	//----
//
//	//플레이어 100명이 있는데 
//	//젊은 '순서대로' 30명만 뽑아봐!  뽑은 30명의 순서는 상관안한다.
//	/*partial_sort(begin(players), begin(players) + 100, end(players));
//
//	cout << "------구분" << endl;
//	copy(begin(players), begin(players) + 100, ostream_iterator<Player>(cout, "\n"));*/
//
//
//	//--
//	//플레이어 100명이 있는데 
//	//나이는 오름차순 나이가 같다면 이름도 오름차순으로 정렬하라
//	//stable_sort
//	sort(begin(players), end(players), [](const Player& lhs, const Player& rhs) {
//		return lhs.name < lhs.name;
//		});
//	stable_sort(begin(players), end(players));
//
//	cout << "------구분" << endl;
//	copy(begin(players), end(players), ostream_iterator<Player>(cout, "\n"));
//
//
//
//}


//----------- 이상한 나라의 앨리스
#include <iostream>
#include <algorithm>
#include <iterator>
#include <random>
#include <numeric>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
	ifstream in("이상한나라의앨리스.txt");
	char c;
	in >> c >> c >> c; //BOM 건너뜀
	vector<string> v{ istream_iterator<string>{in},{} };

	//v를 오름차순 정렬한다.
	sort(v.begin(), v.end());

	//원하는 단어가 v에 있는지 알려주세요. 영원히
	//while (true)
	//{
	//	cout << "단어를 입력하세요: ";
	//	string word;
	//	cin >> word;

	//	//0점 정답
	//	/*auto p = find(v.begin(), v.end(), word);
	//	if (p != v.end())
	//		cout << word << "를 찾았습니다." << endl;
	//	else
	//		cout << "없는 단어 입니다." << endl;*/

	//	//정렬되어있으면이걸 쓴다.
	//	bool b=binary_search(v.begin(), v.end(), word);
	//	if (b)
	//		cout << word << "찾음" << endl;
	//	else
	//		cout << "없다." << endl;

	//}


	//[문제] 원하는 단어가 있니?
	//있다면 몇개나 있니?
	//[변형된 문제] 어떤 단어를 사전에 추가하려고 한다.
	//어디에 추가하면 되겠니? (정렬 순서가 깨지면 안된다.)
	//copy(v.begin(), v.begin() + 1'00000, ostream_iterator<string>(cout, "  "));

	while (true)
	{
		cout << "단어를 입력하세요: ";
		string word;
		cin >> word;
		auto [low, high]=equal_range(v.begin(), v.end(), word);  //하한선 상한선반환
		if (low == high)
			cout << "사전에 없는 단어 입니다." << endl;
		else
			cout<<word<<"는 " << high - low << "개가 있습니다." << endl;

		cout << "정렬을 깨지 않고 삽입되는 위치입니다." << endl;
		copy(low - 1, high + 1, ostream_iterator<string>(cout, " "));
		cout << endl;

	}

}


/*
다음주 강의 제목 constexpr if와 tag dispatching 
copy( , back_insert(String))
dog<-->god 애너그램
*/