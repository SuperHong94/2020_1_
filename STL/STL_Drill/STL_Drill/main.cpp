#include <iostream>
#include <string>	
#include <algorithm>
#include <random>
#include <vector>
#include <set>
#include <fstream>
#include <filesystem>
using namespace std;

random_device rd; //더욱랜덤성있게
default_random_engine dre(rd());
normal_distribution<> nd{ 0.0, 1.0 };
uniform_int_distribution<> uidName{ 'a','z' };
uniform_int_distribution<> uidIdLen{ 3,10 };  //id는 알파벳 3글자 이상 10글자 이하로
uniform_real_distribution<> uidChampion{ 0.0,1.0 };  // uniform_int_distribution 보다 더욱 uniform하게

const size_t totalNum = 10000; //10만개

class Player
{
	string id;
	unsigned int breakout; //떼탈출 점수
	unsigned int championsLeague; //챔피언스리그 점수
	bool isChampion;
public:
	static size_t ChampionCnt;
	static size_t breakoutCnt;
	static size_t testCnt;
	Player() = default;
	Player(bool isChampion, unsigned int num);
	bool GetIsChampion() const;
	string GetId() const;
	void show()const;
};
bool Player::GetIsChampion()const
{
	return isChampion;
}
Player::Player(bool c, unsigned int num) :isChampion{ c }
{
	for (int i = 0; i < uidIdLen(dre); ++i)
		id += uidName(dre);

	if (isChampion) {
		championsLeague = num;

		//cout << "챔스" << ChampionCnt << id << endl;

	}
	else {
		breakout = num;
		//cout << "떼탈출" << breakoutCnt << id << endl;

	}
}

string Player::GetId() const
{
	return id;
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
size_t Player::testCnt = 0;

void Player::show()const
{
	cout << id;
	if (isChampion)
		cout << "  챔피언스리그 점수: " << championsLeague << " 확인용 개수: "<<testCnt++<<'\n';
	else
		cout << "  떼탈출 점수: " << breakout << '\n';
}

bool SetRandomBool(bool isChampion);
void InitSave(const string_view fname);
int main()
{
	const string_view fname = "플레이어10만명.bin";
	vector<Player> v;
	v.resize(totalNum);
	ifstream in(fname, ios::binary);
	if (!in) {
		InitSave(fname);
	}
	else {
		in.read((char*)v.data(), sizeof(Player) * totalNum);  //파일에서 읽기
		cout << v.size() << endl;  //전체 개수 확인

		//떼탈출 참가자와 챔피언스리그 참가자 수 

		int i = 0;
		for (const auto& p : v) {
			cout << i++ << " - ";
			p.show();
		}
	}
	//데이터에 탈출과 챔피언이 1:1로 잘 나누어져 있는지 확인하기위한코드
	auto championsCnt = count_if(v.begin(), v.end(), [](const Player& p) {
		return p.GetIsChampion();
		});
	auto escapeCnt = count_if(v.begin(), v.end(), [](const Player& p) {
		return !(p.GetIsChampion());
		});
	cout << championsCnt << endl;
	cout << escapeCnt << endl;


}


bool SetRandomBool(bool isChampion)
{
	
	if (uidChampion(dre) < 0.5){
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
			d = clamp(d, -5.0, 50.0);
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
			if(s.emplace(Player(isChampion, d)).second)
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
	int i = 0;
	cout << s.size() << endl;
	cout << Player::ChampionCnt << endl;
	cout << Player::breakoutCnt << endl;
	for (const auto& p : s)   //파일에 쓰기
	{
		out.write((char*)&p, sizeof(Player));
	}
}