#include <iostream>
#include <string>	
#include <algorithm>
#include <random>
#include <vector>
#include <set>
#include <fstream>
#include <filesystem>
using namespace std;

random_device rd; //���������ְ�
default_random_engine dre(rd());
normal_distribution<> nd{ 0.0, 1.0 };
uniform_int_distribution<> uidName{ 'a','z' };
uniform_int_distribution<> uidIdLen{ 3,10 };  //id�� ���ĺ� 3���� �̻� 10���� ���Ϸ�
uniform_real_distribution<> uidChampion{ 0.0,1.0 };  // uniform_int_distribution ���� ���� uniform�ϰ�

const size_t totalNum = 10000; //10����

class Player
{
	string id;
	unsigned int breakout; //��Ż�� ����
	unsigned int championsLeague; //è�Ǿ𽺸��� ����
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

		//cout << "è��" << ChampionCnt << id << endl;

	}
	else {
		breakout = num;
		//cout << "��Ż��" << breakoutCnt << id << endl;

	}
}

string Player::GetId() const
{
	return id;
}


template<>  //set������ ���ø� Ư��ȭ
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
		cout << "  è�Ǿ𽺸��� ����: " << championsLeague << " Ȯ�ο� ����: "<<testCnt++<<'\n';
	else
		cout << "  ��Ż�� ����: " << breakout << '\n';
}

bool SetRandomBool(bool isChampion);
void InitSave(const string_view fname);
int main()
{
	const string_view fname = "�÷��̾�10����.bin";
	vector<Player> v;
	v.resize(totalNum);
	ifstream in(fname, ios::binary);
	if (!in) {
		InitSave(fname);
	}
	else {
		in.read((char*)v.data(), sizeof(Player) * totalNum);  //���Ͽ��� �б�
		cout << v.size() << endl;  //��ü ���� Ȯ��

		//��Ż�� �����ڿ� è�Ǿ𽺸��� ������ �� 

		int i = 0;
		for (const auto& p : v) {
			cout << i++ << " - ";
			p.show();
		}
	}
	//�����Ϳ� Ż��� è�Ǿ��� 1:1�� �� �������� �ִ��� Ȯ���ϱ������ڵ�
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

	//��Ȯ�ϰ� ������ ������ ���ؼ�
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
	set<Player> s;  //�ߺ��Ǵ� �÷��̾ ���� set�����̳� Ȱ��
	ofstream out(fileName, ios::binary);

	while (s.size() < totalNum) {
		isChampion = SetRandomBool(isChampion);
		
		
		if (isChampion) {  //è�Ǿ𽺸���
			d = nd(dre);
			d = clamp(d, -5.0, 50.0);
			d += 5.0; //[0~10]
			d *= 111267038.4; //[0~1,112,670,384]
			if (s.emplace(Player(isChampion, d)).second)
				Player::ChampionCnt++;

		}
		else { //��Ż��
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
	for (const auto& p : s)   //���Ͽ� ����
	{
		out.write((char*)&p, sizeof(Player));
	}
}