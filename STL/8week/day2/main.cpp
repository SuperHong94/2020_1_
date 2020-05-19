//코드 8-5: 영화와 감독  포인트는 오류	C2676	이항 '<': 'const _Ty'이(가) 이 연산자를 정의하지 않거나 미리 정의된 연산자에 허용되는 형식으로의 변환을 정의하지 않습니다. 를해결!
//방법은 3가지
/*
1. less<String>을 정의한다.
2. 호출가능타입을 직접 정의한다.
3. String에 < 연산자를 오버로딩한다.

*/
//#include <iostream>
//#include <map>
//#include "String.h"
//
//using namespace std;
//int main()
//{
//	map<String, String> movies;
//
//	movies.insert(make_pair("터미네이터2", "제임스 카메론"));
//	movies.insert(movies.begin(), pair<String, String>("인셉션", "크리스토퍼 놀란"));
//	
//	movies.emplace("기생충", "봉준호");
//	
//	movies["어밴져스:엔드게임"] = "안소니 루소, 조 루소";
//	movies["크리스마스의 악몽"] = "팀 버튼";
//	movies.insert_or_assign("인생은 아름다워", "로베르토 베니니");
//	movies.try_emplace(movies.end(), "쇼생크 탈출", "프랭크 다라본트");
//
//	for (auto [제목, 감독] : movies)
//		cout << 제목 << " - " << 감독 << endl;
//	
//	
//}


//1번 방법  less<String>을 정의한다.

//#include <iostream>
//#include <map>
//#include "String.h"
//
//using namespace std;
//
//template<>
//struct less<String>
//{
//	bool operator()(const String& a, const String& b)const {
//		return a.getString() < b.getString();
//	}
//};
//int main()
//{
//	map<String, String> movies;
//
//	movies.insert(make_pair("터미네이터2", "제임스 카메론"));
//	movies.insert(movies.begin(), pair<String, String>("인셉션", "크리스토퍼 놀란"));
//
//	movies.emplace("기생충", "봉준호");
//
//	movies["어밴져스:엔드게임"] = "안소니 루소, 조 루소";
//	movies["크리스마스의 악몽"] = "팀 버튼";
//	movies.insert_or_assign("인생은 아름다워", "로베르토 베니니");
//	movies.try_emplace(movies.end(), "쇼생크 탈출", "프랭크 다라본트");
//
//	for (auto [제목, 감독] : movies)
//		cout << 제목 << " - " << 감독 << endl;
//
//
//}

//2번 방법


//#include <iostream>
//#include <map>
//#include <functional> //헤더추가
//#include "String.h"
//using namespace std;
//
//
//bool StringCmp(const String& a, const String& b) {
//	return a.getString() < b.getString();
//}
////bool StringCmp(const String& a, const String& b) {
////	return a.size() < b.size();
////}
//int main()
//{
//	map<String, String,function<bool(const String&,const String&)>> movies(StringCmp);
//
//	movies.insert(make_pair("터미네이터2", "제임스 카메론"));
//	movies.insert(movies.begin(), pair<String, String>("인셉션", "크리스토퍼 놀란"));
//	
//	movies.emplace("기생충", "봉준호");
//	
//	movies["어밴져스:엔드게임"] = "안소니 루소, 조 루소";
//	movies["크리스마스의 악몽"] = "팀 버튼";
//	movies.insert_or_assign("인생은 아름다워", "로베르토 베니니");
//	movies.try_emplace(movies.end(), "쇼생크 탈출", "프랭크 다라본트");
//
//	for (auto [제목, 감독] : movies)
//		cout << 제목 << " - " << 감독 << endl;
//	
//	
//}


//3번째 방법 String에 < 연산자를 정의
//#include <iostream>
//#include <map>
//#include "String.h"
//
//using namespace std;
//int main()
//{
//	map<String, String> movies;
//
//	movies.insert(make_pair("터미네이터2", "제임스 카메론"));
//	movies.insert(movies.begin(), pair<String, String>("인셉션", "크리스토퍼 놀란"));
//	
//	movies.emplace("기생충", "봉준호");
//	
//	movies["어밴져스:엔드게임"] = "안소니 루소, 조 루소";
//	movies["크리스마스의 악몽"] = "팀 버튼";
//	movies.insert_or_assign("인생은 아름다워", "로베르토 베니니");
//	movies.try_emplace(movies.end(), "쇼생크 탈출", "프랭크 다라본트");
//
//	for (auto [제목, 감독] : movies)
//		cout << 제목 << " - " << 감독 << endl;
//	
//	
//}


//multimap
//
//#include <iostream>
//#include <map>
//#include "String.h"
//
//using namespace std;
//
//int main()
//{
//	multimap<String, String> movies;
//
//	movies.insert(make_pair("터미네이터2", "제임스 카메론"));
//	movies.insert(movies.begin(), pair<String, String>("인셉션", "크리스토퍼 놀란"));
//
//	movies.emplace("기생충", "봉준호");
//	movies.emplace("크리스마스의 악몽", "팀버튼");
//
//	movies.emplace("인생은 아름다워", "로베르토 베니니");
//	movies.emplace("쇼생크 탈출", "프랭크 다라본트");
//
//	for (auto [제목, 감독] : movies)
//		cout << 제목 << "-" << 감독 << endl;
//}

//#include <iostream>
//#include <map>
//#include <set>
//#include <fstream>
//#include <string>
//
//using namespace std;
//
//int main()
//{
//	string name = "이상한나라의앨리스.txt";
//
//	ifstream in(name);
//	if (!in) cout << "파일열기 실패" << endl;
//
//	map<char, int > alpha;
//
//	char c{};
//	while (in >> c) {
//		if (isalpha(c)) {
//			alpha[tolower(c)]++;
//		}
//	}
//
//	cout << "사용된 알파벳의 종류 - " << alpha.size() << '\n';
//	int count = 0;
//	for (auto i = alpha.begin(); i != alpha.end(); ++i)
//		count += i->second;
//	cout << "사용된 알파벳의 개수 - " << count << '\n';
//	for (auto& [단어, 숫자] : alpha)
//		cout << 단어 << " - " << 숫자 << '\n';
//
//}

//코드 8-6:로또 번호 생성기

#include <iostream>
#include <set>
#include <random>
using namespace std;

int main()
{
	random_device rd;
	default_random_engine dre{ rd() };
	uniform_int_distribution uid{ 1,45 };

	set<int> s;

	while (s.size() < 6)
		s.insert(uid(dre));

	cout << "이번 주 당첨번호: ";
	for (auto& d : s)
		cout << d << ' ';
	cout << endl;
}