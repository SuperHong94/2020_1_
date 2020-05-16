////코드 8-1: map에 원소 추가
//
//#include <iostream>
//#include <iomanip>
//#include <string>
//#include <map>
//using namespace std;
//
//enum class Gender { Boy, Girl, Hibrid };
//string Genders[]{ "보이그룹","걸그룹","혼성그룹" };
//
//class IdolGroup {
//	string groupName;
//	Gender gender;
//	int year;
//	int num;
//	string member;
//public:
//	explicit IdolGroup(string gn, Gender g, int y, int n, string m) :groupName{ gn }, gender{ g }, year{ y }, num{ n }, member{ m }{}
//	void show() const {
//		cout << "이름:" << left << setw(14) << groupName << setw(8) << Genders[static_cast<int>(gender)] << ", " << year << "년, " << num << "명, 멤버-" << member << endl;
//
//	}
//};
//
//int main()
//{
//	map<string, IdolGroup> idolGroups;
//	idolGroups.insert(pair<string, IdolGroup>("펄 시스터즈", IdolGroup("펄 시스터즈", Gender::Girl, 1968, 2, "배인순")));
//	idolGroups.insert(make_pair("송골매", IdolGroup("송골매", Gender::Boy, 1979, 6, "배철수")));
//	auto koyote = make_pair("코요태",
//		IdolGroup("코요태", Gender::Hibrid, 1998, 3, "김종민 신지 빽가"));
//	idolGroups.insert(idolGroups.begin(), koyote);
//	idolGroups.emplace("마마무", IdolGroup("마마무", Gender::Girl, 2015, 4, "솔라 문별 휘인 화사"));
//	idolGroups.insert_or_assign("있지", IdolGroup("있지", Gender::Girl, 2019, 5, "예지 리아 류진 채령 유리"));
//	idolGroups.insert_or_assign("있지", IdolGroup("있지", Gender::Girl, 2019, 5, "예지 리아 류진 채령 유나"));
//	//idolGroups.insert(make_pair("있지", IdolGroup("있지", Gender::Girl, 2019, 5, "예지 리아 류진 채령 유s나")));
//
//	//순회 하며 출력
//
//	for (const auto& ig : idolGroups)
//		ig.second.show();
//
//}


//코드 8-2: map에서 원소 찾기

//코드 8-1: map에 원소 추가  //실습문제 해결 완료!

//#include <iostream>
//#include <iomanip>
//#include <iterator>
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <map>
//using namespace std;
//
//enum class Gender { Boy, Girl, Hibrid };
//string Genders[]{ "보이그룹","걸그룹","혼성그룹" };
//
//class IdolGroup {
//	string groupName;
//	Gender gender;
//	int year;
//	int num;
//	string member;
//public:
//	explicit IdolGroup(string gn, Gender g, int y, int n, string m) :groupName{ gn }, gender{ g }, year{ y }, num{ n }, member{ m }{}
//	void show() const {
//		cout << "이름:" << left << setw(14) << groupName << setw(8) << Genders[static_cast<int>(gender)] << ", " << year << "년, " << num << "명, 멤버-" << member << endl;
//
//	}
//	bool operator<(IdolGroup& b)
//	{
//		return this->year < b.year;
//	}
//	int getYear() const
//	{
//		return year;
//	}
//};
//
//int main()
//{
//	map<string, IdolGroup> idolGroups;
//	idolGroups.insert(pair<string, IdolGroup>("펄 시스터즈", IdolGroup("펄 시스터즈", Gender::Girl, 1968, 2, "배인순")));
//	idolGroups.insert(make_pair("송골매", IdolGroup("송골매", Gender::Boy, 1979, 6, "배철수")));
//	auto koyote = make_pair("코요태",
//		IdolGroup("코요태", Gender::Hibrid, 1998, 3, "김종민 신지 빽가"));
//	idolGroups.insert(idolGroups.begin(), koyote);
//	idolGroups.emplace("마마무", IdolGroup("마마무", Gender::Girl, 2015, 4, "솔라 문별 휘인 화사"));
//	idolGroups.insert_or_assign("있지", IdolGroup("있지", Gender::Girl, 2019, 5, "예지 리아 류진 채령 유나"));
//
//	cout << "*** 아이돌 척척박사 ***" << endl;
//	/*while (true) {
//		cout << "궁금하신 그룹의 이름을 입력해 주세요: ";
//		string name;
//		cin >> name;
//		
//		auto p = idolGroups.find(name);
//		if (p != idolGroups.end())
//			p->second.show();
//		else
//			cout << name << "-없는 그룹입니다." << endl;
//
//		cout << endl;
//	}*/
//
//	vector< pair<string, IdolGroup>> v;
//	map<string, IdolGroup>::iterator iter;
//
//	for (iter = idolGroups.begin(); iter != idolGroups.end(); ++iter) {
//		v.push_back(make_pair(iter->first, iter->second));
//	}
//	sort(v.begin(), v.end(), [](pair<string,IdolGroup> a,  pair<string, IdolGroup> b) {
//		return a.second.getYear() < b.second.getYear();
//		});
//	for (const auto& ig : v)
//		ig.second.show();
//}



//code 8-3: 전화번호부
//#include <iostream>
//#include <string>
//#include <map>
//using namespace std;
//int main()
//{
//	map<string, string> phoneBook;
//	phoneBook["번호안내"] = "114";
//	//phoneBook.operator[]("번호안내")="114";
//	phoneBook["일기예보"] = "131";
//	phoneBook["교통정보"] = "1333";
//	phoneBook["전기고장신고"] = "123";
//	phoneBook["사이버테러"] = "118";
//	for (const auto& [name, number] : phoneBook)
//		cout << name << ": " << number << endl;
//}

//코드 8-4: 단어 사용횟수 출력, 실습12쪽 내스타일로한거
//#include <iostream>
//#include <map>
//#include <fstream>
//#include <string>
//using namespace std;
//
//int main()
//{
//	cout << "읽을 파일은? ";
//	string name;
//	cin >> name;
//
//	ifstream in(name);
//
//	if (!in) {
//		cout << name << "-파일 열기 실패" << endl;
//		return 0;
//	}
//	map<string, int> words;
//	string str;
//
//	while (in >> str) {
//		words[str]++;
//
//	}
//
//	//출력
//	for (const auto& [단어, 출현회수] : words)
//		cout << 단어 << ": " << 출현회수 << endl;
//}



//실습
//#include <iostream>
//#include <map>
//#include <fstream>
//#include <string>
//using namespace std;
//
//int main()
//{
//	cout << "읽을 파일은? ";
//	string name;
//	cin >> name;
//
//	ifstream in(name);
//
//	if (!in) {
//		cout << name << "-파일 열기 실패" << endl;
//		return 0;
//	}
//	map<string, int> words;
//	string str;
//
//	while (in >> str) {
//		words[str]++;
//
//	}
//	cout << name << "에는" << words.size() << "가지의 단어가 사용되었습니다" << endl;
//	//출력
//
//	string searchWord;
//	while (true) {
//		cout << "찾는 단어는?";
//		cin >> searchWord;
//		cout << endl;
//		auto p = words.find(searchWord);
//		if (p != words.end())
//			cout << searchWord << " - " << p->second;
//		else
//			cout << "없는  단어임다." << endl;
//	}
//}


//마지막 실습
#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	cout << "읽을 파일은? ";
	string name = "이상한나라의앨리스.txt";
	

	ifstream in(name);

	if (!in) {
		cout << name << "-파일 열기 실패" << endl;
		return 0;
	}
	map<string, int> words;
	string str;

	while (in >> str) {
		words[str]++;

	}
	cout << name << "에는" << words.size() << "가지의 단어가 사용되었습니다" << endl;
	//출력
	
	vector<pair<string, int>> v;
	v.reserve(6020);

	map<string, int>::iterator iter;
	for (iter = words.begin(); iter != words.end(); ++iter)
	{
		v.emplace_back(make_pair(iter->first, iter->second));
	}

	sort(v.begin(), v.end(), [](pair<string, int> a, pair<string, int> b) {
		return a.second > b.second;
		});

	for (const auto& d : v)
		cout << d.first << " - " << d.second << endl;

}
