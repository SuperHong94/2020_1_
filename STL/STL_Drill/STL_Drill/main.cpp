#include <iostream>
#include <string>	
#include <algorithm>
#include <random>
#include <vector>
#include <set>
#include <fstream>
#include <functional>
#include <filesystem>
#include <iterator>
using namespace std;

random_device rd; //더욱랜덤성있게
default_random_engine dre(rd());
normal_distribution<> nd{ 0.0, 1.0 };
uniform_int_distribution<> uidName{ 'a','z' };
uniform_int_distribution<> uidIdLen{ 3,10 };  //id는 알파벳 3글자 이상 10글자 이하로
uniform_real_distribution<> uidChampion{ 0.0,1.0 };  // uniform_int_distribution 보다 더욱 uniform하게

const size_t totalNum = 10'0000; //10만개

class Player
{
	string id;
	unsigned int breakout; //떼탈출 점수
	unsigned int championsLeague; //챔피언스리그 점수
	bool isChampion;
public:
	static size_t ChampionCnt;
	static size_t breakoutCnt;
	Player() = default;
	Player(bool isChampion, unsigned int num);
	void SetIsChampion(bool b);
	bool GetIsChampion() const;
	string GetId() const;
	void SetId(const string& name);
	unsigned int GetBreakout()const;
	unsigned int GetChampionsLeague()const;
	void SetScore(unsigned int num);
	void show()const;
	bool operator==(const string& rhs) const;
};

Player::Player(bool c, unsigned int num) :isChampion{ c }
{
	double d{};
	for (int i = 0; i < uidIdLen(dre); ++i)
		id += uidName(dre);

	//isChampion ? championsLeague = num : breakout = num;
	if (isChampion) {
		championsLeague = num;
		d = nd(dre);  //때탈출 점수
		d = clamp(d, -5.0, 5.0);
		d += 5.0; //[0~10]
		d *= 290588702.6; //[0~2,905,887,026]
		breakout = d;
		//cout << "챔스" << ChampionCnt << id << endl;

	}
	else {
		breakout = num;
		d = nd(dre);//챔피언스리그 점수
		d = clamp(d, -5.0, 5.0);
		d += 5.0; //[0~10]
		d *= 111267038.4; //[0~1,112,670,384]
		championsLeague = d;
		//cout << "떼탈출" << breakoutCnt << id << endl;

	}
}

string Player::GetId() const
{
	return id;
}
void Player::SetId(const string& name)
{
	id = name;
}
bool Player::GetIsChampion()const
{
	return isChampion;
}
void Player::SetIsChampion(bool b)
{
	isChampion = b;
}


unsigned int Player::GetBreakout()const
{
	return breakout;
}
unsigned int Player::GetChampionsLeague()const
{
	return championsLeague;
}


void Player::SetScore(unsigned int num)
{
	if (isChampion)
		championsLeague = num;
	else
		breakout = num;
}

bool Player::operator==(const string& rhs) const
{
	return id == rhs;
}



void Player::show()const
{
	cout << id;
	if (isChampion)
		cout << "  챔피언스리그 점수: " << championsLeague << '\n';
	else
		cout << "  떼탈출 점수: " << breakout << '\n';
}

template<>  //set을위한 템플릿 특수화
struct less<Player>
{
	bool operator()(const Player& a, const Player& b)const {
		return a.GetId() < b.GetId();
	}
};

size_t Player::ChampionCnt = 0;
size_t Player::breakoutCnt = 0;


bool SetRandomBool(bool isChampion);
void InitSave(const string_view fname);
bool breakoutComp(const Player& a, const Player& b);
bool championsLeagueComp(const Player& a, const Player& b);
void SeasonStart(vector<Player>& v);
void findPlayer(vector<Player>& v);
double rankPercentPrint(double d);
void Save(string_view fname, vector<Player>& v); //저장함수
int main()
{
	const string_view fname = "플레이어10만명.bin";


	vector<Player> v;
	v.resize(totalNum);
	ifstream in(fname, ios::binary);
	ifstream in1(fname, ios::binary);
	if (!in) {

		InitSave(fname);
		cout << "파일이 없어서 새로 만들고 저장했습니다. 다시시작해주세요!" << endl;
		return 0;
	}

	in.read((char*)v.data(), sizeof(Player) * totalNum);  //벡터로 읽어 온다.
	cout << "현재 전체 플레이어 수: " << totalNum << " 읽어온 플레이어 수: " << v.size() << endl;
	cout << "저장파일 읽기 완료!" << endl;

	/*for (const auto& d : v)
		cout << d.GetId() << "- 챔스점수: " << d.GetChampionsLeague() << ", 때탈출점수: " << d.GetBreakout() << endl;*/

	int menu = 0;
	cout << "\n\n메뉴를 선택해주세요 (1. 새로운 시즌 시작 2.플레이어 검색 3. 저장 후 종료)\n";
	while (cin >> menu) {
			
		switch (menu)
		{
		case 1:
			SeasonStart(v);
			cout << "\n\n메뉴를 선택해주세요 (1. 새로운 시즌 시작 2.플레이어 검색 3. 저장 후 종료)\n";
			break;
		case 2:
			findPlayer(v);
			cout << "\n\n메뉴를 선택해주세요 (1. 새로운 시즌 시작 2.플레이어 검색 3. 저장 후 종료)\n";
			break;
		case 3:
			Save(fname, v);
			cout << "저장 완료! 종료합니다." << endl;
			return 0;
		default:
			cout << "올바른 메뉴를 선택해주세요 (1. 새로운 시즌 시작 2.플레이어 검색)\n";
			break;
		}
	}
	cout << "잘못된 키입력으로 현재사항을 저장하고 종료합니다." << endl;
	Save(fname, v);




	//for (const auto& p : champions)
	//	p.show();
}
void Save(string_view fname, vector<Player>& v)
{
	ofstream out(fname, ios::binary);
	out.write((char*)v.data(), sizeof(Player) * totalNum);
}

void SeasonStart(vector<Player>& v)
{
	Player::ChampionCnt = 0;
	Player::breakoutCnt = 0;  //카운트 0으로 변경
	bool isChampion = false;
	double d{};
	for (auto& p : v) {
		isChampion = SetRandomBool(isChampion);
		p.SetIsChampion(isChampion);
		if (p.GetIsChampion()) {  //챔피언리그
			d = nd(dre);
			d = clamp(d, -5.0, 5.0);
			d += 5.0; //[0~10]
			d *= 111267038.4; //[0~1,112,670,384]
			Player::ChampionCnt++;
			if (d > p.GetChampionsLeague())
				p.SetScore(d);
		}
		else { //떼탈출
			d = nd(dre);
			d = clamp(d, -5.0, 5.0);
			d += 5.0; //[0~10]
			d *= 290588702.6; //[0~2,905,887,026]
			Player::breakoutCnt++;
			if (d > p.GetBreakout()){
				p.SetScore(d);
			}
		}
	}

	cout <<"때탈출 플레이어 수: "<< Player::breakoutCnt << endl;
	cout<<"챔피언스리그 플레이어 수: " << Player::ChampionCnt << endl;

	cout << "한 시즌을 완료하였습니다." << endl;
}


double rankPercentPrint(double d)
{
	return (d / (double)totalNum) * 100.0;
}
void findPlayer(vector<Player>& v)
{
	multiset<Player, function<bool(const Player& a, const Player& b)>> champions(championsLeagueComp);  //챔피언스리그 플레이어들 점수로 비교해서 multiset에 넣기
	multiset<Player, function<bool(const Player& a, const Player& b)>> breakOuts(breakoutComp);  //떼탈출  플레이어들
	bool isFind = false;
	for (const auto& p : v) {
		breakOuts.emplace(p);
		champions.emplace(p);
	}
	//for (const auto& d : breakOuts)  //잘 정렬되었는지 확인용
	//	cout << d.GetId() << "- 챔스점수: " << d.GetChampionsLeague() << ", 때탈출점수: " << d.GetBreakout() << endl;


	auto firstChamp = champions.begin().operator*();
	auto lastChamp = prev(champions.end(), 1).operator*();
	cout << "--------------------------------------------------------" << endl;
	cout << "현재 챔피언스리그 1등: " << firstChamp.GetId() << " 점수 :" << firstChamp.GetChampionsLeague() << endl;
	cout << "현재 챔피언스리그 꼴등: " << lastChamp.GetId() << " 점수 :" << lastChamp.GetChampionsLeague() << endl;

	auto firstBreak = breakOuts.begin().operator*();
	auto lastBreak = prev(breakOuts.end(), 1).operator*();
	cout << "\n현재 때탈출 1등: " << firstBreak.GetId() << " 점수 :" << firstBreak.GetBreakout() << endl;
	cout << "현재 때탈출 꼴등: " << lastBreak.GetId() << " 점수 :" << lastBreak.GetBreakout() << endl << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << endl;
	cout << endl;
	string name{};
	cout << "찾는 플레이어 이름을 입력하세요: ";
	cin >> name;
	double d{};

	cout.setf(ios::fixed);
	cout.precision(1);



	{
		auto iter = find(champions.begin(), champions.end(), name);
		if (iter != champions.end()) {

			auto it = distance(champions.begin(), iter);
			auto iter_decrement = prev(iter, 1);
			auto iter_increment = next(iter, 1);

			cout << endl;
			if (iter != champions.begin())
				cout << "        " << (*iter_decrement).GetId() << ' ' << it << "등 상위 " << rankPercentPrint(it) << "%" << " 점수 " << (*iter_decrement).GetChampionsLeague() << endl;
			cout << "챔피언스리그 " << (*iter++).GetId() << ' ' << it + 1 << "등 상위 " << rankPercentPrint(it + 1) << "%" << " 점수 " << (*iter).GetChampionsLeague() << endl;
			if (iter_increment != breakOuts.end())
				cout << "       " << (*iter_increment).GetId() << ' ' << it + 2 << "등 상위 " << rankPercentPrint(it + 2) << "%" << " 점수 " << (*iter_increment).GetChampionsLeague() << endl;
		}
		else {
			cout << "없는 플레이어 입니다.\n";
			return;
		}
	}
	{

		auto iter = find(breakOuts.begin(), breakOuts.end(), name);
		if (iter != breakOuts.end()) {
			cout << endl << endl;
			auto it = distance(breakOuts.begin(), iter);
			auto iter_decrement = prev(iter, 1);
			auto iter_increment = next(iter, 1);
			if (iter != breakOuts.begin())
				cout << "      " << (*iter_decrement).GetId() << ' ' << it << "등 상위 " << rankPercentPrint(it) << "%" << " 점수 " << (*iter_decrement).GetBreakout() << endl;
			cout << "때탈출 " << (*(iter)).GetId() << ' ' << it + 1 << "등 상위 " << rankPercentPrint(it + 1) << "%" << " 점수 " << (*iter).GetBreakout() << endl;
			if (iter_increment != breakOuts.end())
				cout << "      " << (*iter_increment).GetId() << ' ' << it + 2 << "등 상위 " << rankPercentPrint(it + 2) << "%" << " 점수 " << (*iter_increment).GetBreakout() << endl;
		}
	}




}
bool championsLeagueComp(const Player& a, const Player& b)
{
	return a.GetChampionsLeague() > b.GetChampionsLeague();  //내림차순으로 정렬
}
bool breakoutComp(const Player& a, const Player& b)
{
	return a.GetBreakout() > b.GetBreakout();
}


bool SetRandomBool(bool isChampion)
{

	if (uidChampion(dre) < 0.5) {
		isChampion = true;
	}
	else
		isChampion = false;

	//정확하게 반으로 나누기 위해서
	if (Player::ChampionCnt >= totalNum / 2)
		isChampion = false;

	else if (Player::breakoutCnt >= totalNum / 2)
		isChampion = true;


	return isChampion;

}

void InitSave(const string_view fileName)
{
	bool isChampion = false;
	double d{};
	set<Player> s;  //중복되는 플레이어가 없게 set컨테이너 활용
	ofstream out(fileName, ios::binary);

	while (s.size() < totalNum) {
		isChampion = SetRandomBool(isChampion);


		if (isChampion) {  //챔피언스리그
			d = nd(dre);
			d = clamp(d, -5.0, 5.0);
			d += 5.0; //[0~10]
			d *= 111267038.4; //[0~1,112,670,384]
			if (s.emplace(Player(isChampion, d)).second)
				Player::ChampionCnt++;

		}
		else { //떼탈출
			d = nd(dre);
			d = clamp(d, -5.0, 5.0);
			d += 5.0; //[0~10]
			d *= 290588702.6; //[0~2,905,887,026]
			if (s.emplace(Player(isChampion, d)).second)
				Player::breakoutCnt++;
		}
	}

	/*auto championsCnt = count_if(s.begin(), s.end(), [](const Player& p) {
		return p.GetIsChampion();
		});
	auto escapeCnt = count_if(s.begin(), s.end(), [](const Player& p) {
		return !(p.GetIsChampion());
		});
	cout << championsCnt << endl;
	cout << escapeCnt << endl;*/
	for (const auto& p : s)   //파일에 쓰기
	{
		out.write((char*)&p, sizeof(Player));
	}
}