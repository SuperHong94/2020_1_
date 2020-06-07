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

random_device rd; //���������ְ�
default_random_engine dre(rd());
normal_distribution<> nd{ 0.0, 1.0 };
uniform_int_distribution<> uidName{ 'a','z' };
uniform_int_distribution<> uidIdLen{ 3,10 };  //id�� ���ĺ� 3���� �̻� 10���� ���Ϸ�
uniform_real_distribution<> uidChampion{ 0.0,1.0 };  // uniform_int_distribution ���� ���� uniform�ϰ�

const size_t totalNum = 10'0000; //10����

class Player
{
	string id;
	unsigned int breakout; //��Ż�� ����
	unsigned int championsLeague; //è�Ǿ𽺸��� ����
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
		d = nd(dre);  //��Ż�� ����
		d = clamp(d, -5.0, 5.0);
		d += 5.0; //[0~10]
		d *= 290588702.6; //[0~2,905,887,026]
		breakout = d;
		//cout << "è��" << ChampionCnt << id << endl;

	}
	else {
		breakout = num;
		d = nd(dre);//è�Ǿ𽺸��� ����
		d = clamp(d, -5.0, 5.0);
		d += 5.0; //[0~10]
		d *= 111267038.4; //[0~1,112,670,384]
		championsLeague = d;
		//cout << "��Ż��" << breakoutCnt << id << endl;

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
		cout << "  è�Ǿ𽺸��� ����: " << championsLeague << '\n';
	else
		cout << "  ��Ż�� ����: " << breakout << '\n';
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


bool SetRandomBool(bool isChampion);
void InitSave(const string_view fname);
bool breakoutComp(const Player& a, const Player& b);
bool championsLeagueComp(const Player& a, const Player& b);
void SeasonStart(vector<Player>& v);
void findPlayer(vector<Player>& v);
double rankPercentPrint(double d);
void Save(string_view fname, vector<Player>& v); //�����Լ�
int main()
{
	const string_view fname = "�÷��̾�10����.bin";


	vector<Player> v;
	v.resize(totalNum);
	ifstream in(fname, ios::binary);
	ifstream in1(fname, ios::binary);
	if (!in) {

		InitSave(fname);
		cout << "������ ��� ���� ����� �����߽��ϴ�. �ٽý������ּ���!" << endl;
		return 0;
	}

	in.read((char*)v.data(), sizeof(Player) * totalNum);  //���ͷ� �о� �´�.
	cout << "���� ��ü �÷��̾� ��: " << totalNum << " �о�� �÷��̾� ��: " << v.size() << endl;
	cout << "�������� �б� �Ϸ�!" << endl;

	/*for (const auto& d : v)
		cout << d.GetId() << "- è������: " << d.GetChampionsLeague() << ", ��Ż������: " << d.GetBreakout() << endl;*/

	int menu = 0;
	cout << "\n\n�޴��� �������ּ��� (1. ���ο� ���� ���� 2.�÷��̾� �˻� 3. ���� �� ����)\n";
	while (cin >> menu) {
			
		switch (menu)
		{
		case 1:
			SeasonStart(v);
			cout << "\n\n�޴��� �������ּ��� (1. ���ο� ���� ���� 2.�÷��̾� �˻� 3. ���� �� ����)\n";
			break;
		case 2:
			findPlayer(v);
			cout << "\n\n�޴��� �������ּ��� (1. ���ο� ���� ���� 2.�÷��̾� �˻� 3. ���� �� ����)\n";
			break;
		case 3:
			Save(fname, v);
			cout << "���� �Ϸ�! �����մϴ�." << endl;
			return 0;
		default:
			cout << "�ùٸ� �޴��� �������ּ��� (1. ���ο� ���� ���� 2.�÷��̾� �˻�)\n";
			break;
		}
	}
	cout << "�߸��� Ű�Է����� ��������� �����ϰ� �����մϴ�." << endl;
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
	Player::breakoutCnt = 0;  //ī��Ʈ 0���� ����
	bool isChampion = false;
	double d{};
	for (auto& p : v) {
		isChampion = SetRandomBool(isChampion);
		p.SetIsChampion(isChampion);
		if (p.GetIsChampion()) {  //è�Ǿ𸮱�
			d = nd(dre);
			d = clamp(d, -5.0, 5.0);
			d += 5.0; //[0~10]
			d *= 111267038.4; //[0~1,112,670,384]
			Player::ChampionCnt++;
			if (d > p.GetChampionsLeague())
				p.SetScore(d);
		}
		else { //��Ż��
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

	cout <<"��Ż�� �÷��̾� ��: "<< Player::breakoutCnt << endl;
	cout<<"è�Ǿ𽺸��� �÷��̾� ��: " << Player::ChampionCnt << endl;

	cout << "�� ������ �Ϸ��Ͽ����ϴ�." << endl;
}


double rankPercentPrint(double d)
{
	return (d / (double)totalNum) * 100.0;
}
void findPlayer(vector<Player>& v)
{
	multiset<Player, function<bool(const Player& a, const Player& b)>> champions(championsLeagueComp);  //è�Ǿ𽺸��� �÷��̾�� ������ ���ؼ� multiset�� �ֱ�
	multiset<Player, function<bool(const Player& a, const Player& b)>> breakOuts(breakoutComp);  //��Ż��  �÷��̾��
	bool isFind = false;
	for (const auto& p : v) {
		breakOuts.emplace(p);
		champions.emplace(p);
	}
	//for (const auto& d : breakOuts)  //�� ���ĵǾ����� Ȯ�ο�
	//	cout << d.GetId() << "- è������: " << d.GetChampionsLeague() << ", ��Ż������: " << d.GetBreakout() << endl;


	auto firstChamp = champions.begin().operator*();
	auto lastChamp = prev(champions.end(), 1).operator*();
	cout << "--------------------------------------------------------" << endl;
	cout << "���� è�Ǿ𽺸��� 1��: " << firstChamp.GetId() << " ���� :" << firstChamp.GetChampionsLeague() << endl;
	cout << "���� è�Ǿ𽺸��� �õ�: " << lastChamp.GetId() << " ���� :" << lastChamp.GetChampionsLeague() << endl;

	auto firstBreak = breakOuts.begin().operator*();
	auto lastBreak = prev(breakOuts.end(), 1).operator*();
	cout << "\n���� ��Ż�� 1��: " << firstBreak.GetId() << " ���� :" << firstBreak.GetBreakout() << endl;
	cout << "���� ��Ż�� �õ�: " << lastBreak.GetId() << " ���� :" << lastBreak.GetBreakout() << endl << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << endl;
	cout << endl;
	string name{};
	cout << "ã�� �÷��̾� �̸��� �Է��ϼ���: ";
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
				cout << "        " << (*iter_decrement).GetId() << ' ' << it << "�� ���� " << rankPercentPrint(it) << "%" << " ���� " << (*iter_decrement).GetChampionsLeague() << endl;
			cout << "è�Ǿ𽺸��� " << (*iter++).GetId() << ' ' << it + 1 << "�� ���� " << rankPercentPrint(it + 1) << "%" << " ���� " << (*iter).GetChampionsLeague() << endl;
			if (iter_increment != breakOuts.end())
				cout << "       " << (*iter_increment).GetId() << ' ' << it + 2 << "�� ���� " << rankPercentPrint(it + 2) << "%" << " ���� " << (*iter_increment).GetChampionsLeague() << endl;
		}
		else {
			cout << "���� �÷��̾� �Դϴ�.\n";
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
				cout << "      " << (*iter_decrement).GetId() << ' ' << it << "�� ���� " << rankPercentPrint(it) << "%" << " ���� " << (*iter_decrement).GetBreakout() << endl;
			cout << "��Ż�� " << (*(iter)).GetId() << ' ' << it + 1 << "�� ���� " << rankPercentPrint(it + 1) << "%" << " ���� " << (*iter).GetBreakout() << endl;
			if (iter_increment != breakOuts.end())
				cout << "      " << (*iter_increment).GetId() << ' ' << it + 2 << "�� ���� " << rankPercentPrint(it + 2) << "%" << " ���� " << (*iter_increment).GetBreakout() << endl;
		}
	}




}
bool championsLeagueComp(const Player& a, const Player& b)
{
	return a.GetChampionsLeague() > b.GetChampionsLeague();  //������������ ����
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
			d = clamp(d, -5.0, 5.0);
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
	for (const auto& p : s)   //���Ͽ� ����
	{
		out.write((char*)&p, sizeof(Player));
	}
}