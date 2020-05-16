////�ڵ� 8-1: map�� ���� �߰�
//
//#include <iostream>
//#include <iomanip>
//#include <string>
//#include <map>
//using namespace std;
//
//enum class Gender { Boy, Girl, Hibrid };
//string Genders[]{ "���̱׷�","�ɱ׷�","ȥ���׷�" };
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
//		cout << "�̸�:" << left << setw(14) << groupName << setw(8) << Genders[static_cast<int>(gender)] << ", " << year << "��, " << num << "��, ���-" << member << endl;
//
//	}
//};
//
//int main()
//{
//	map<string, IdolGroup> idolGroups;
//	idolGroups.insert(pair<string, IdolGroup>("�� �ý�����", IdolGroup("�� �ý�����", Gender::Girl, 1968, 2, "���μ�")));
//	idolGroups.insert(make_pair("�۰��", IdolGroup("�۰��", Gender::Boy, 1979, 6, "��ö��")));
//	auto koyote = make_pair("�ڿ���",
//		IdolGroup("�ڿ���", Gender::Hibrid, 1998, 3, "������ ���� ����"));
//	idolGroups.insert(idolGroups.begin(), koyote);
//	idolGroups.emplace("������", IdolGroup("������", Gender::Girl, 2015, 4, "�ֶ� ���� ���� ȭ��"));
//	idolGroups.insert_or_assign("����", IdolGroup("����", Gender::Girl, 2019, 5, "���� ���� ���� ä�� ����"));
//	idolGroups.insert_or_assign("����", IdolGroup("����", Gender::Girl, 2019, 5, "���� ���� ���� ä�� ����"));
//	//idolGroups.insert(make_pair("����", IdolGroup("����", Gender::Girl, 2019, 5, "���� ���� ���� ä�� ��s��")));
//
//	//��ȸ �ϸ� ���
//
//	for (const auto& ig : idolGroups)
//		ig.second.show();
//
//}


//�ڵ� 8-2: map���� ���� ã��

//�ڵ� 8-1: map�� ���� �߰�  //�ǽ����� �ذ� �Ϸ�!

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
//string Genders[]{ "���̱׷�","�ɱ׷�","ȥ���׷�" };
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
//		cout << "�̸�:" << left << setw(14) << groupName << setw(8) << Genders[static_cast<int>(gender)] << ", " << year << "��, " << num << "��, ���-" << member << endl;
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
//	idolGroups.insert(pair<string, IdolGroup>("�� �ý�����", IdolGroup("�� �ý�����", Gender::Girl, 1968, 2, "���μ�")));
//	idolGroups.insert(make_pair("�۰��", IdolGroup("�۰��", Gender::Boy, 1979, 6, "��ö��")));
//	auto koyote = make_pair("�ڿ���",
//		IdolGroup("�ڿ���", Gender::Hibrid, 1998, 3, "������ ���� ����"));
//	idolGroups.insert(idolGroups.begin(), koyote);
//	idolGroups.emplace("������", IdolGroup("������", Gender::Girl, 2015, 4, "�ֶ� ���� ���� ȭ��"));
//	idolGroups.insert_or_assign("����", IdolGroup("����", Gender::Girl, 2019, 5, "���� ���� ���� ä�� ����"));
//
//	cout << "*** ���̵� ôô�ڻ� ***" << endl;
//	/*while (true) {
//		cout << "�ñ��Ͻ� �׷��� �̸��� �Է��� �ּ���: ";
//		string name;
//		cin >> name;
//		
//		auto p = idolGroups.find(name);
//		if (p != idolGroups.end())
//			p->second.show();
//		else
//			cout << name << "-���� �׷��Դϴ�." << endl;
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



//code 8-3: ��ȭ��ȣ��
//#include <iostream>
//#include <string>
//#include <map>
//using namespace std;
//int main()
//{
//	map<string, string> phoneBook;
//	phoneBook["��ȣ�ȳ�"] = "114";
//	//phoneBook.operator[]("��ȣ�ȳ�")="114";
//	phoneBook["�ϱ⿹��"] = "131";
//	phoneBook["��������"] = "1333";
//	phoneBook["�������Ű�"] = "123";
//	phoneBook["���̹��׷�"] = "118";
//	for (const auto& [name, number] : phoneBook)
//		cout << name << ": " << number << endl;
//}

//�ڵ� 8-4: �ܾ� ���Ƚ�� ���, �ǽ�12�� ����Ÿ�Ϸ��Ѱ�
//#include <iostream>
//#include <map>
//#include <fstream>
//#include <string>
//using namespace std;
//
//int main()
//{
//	cout << "���� ������? ";
//	string name;
//	cin >> name;
//
//	ifstream in(name);
//
//	if (!in) {
//		cout << name << "-���� ���� ����" << endl;
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
//	//���
//	for (const auto& [�ܾ�, ����ȸ��] : words)
//		cout << �ܾ� << ": " << ����ȸ�� << endl;
//}



//�ǽ�
//#include <iostream>
//#include <map>
//#include <fstream>
//#include <string>
//using namespace std;
//
//int main()
//{
//	cout << "���� ������? ";
//	string name;
//	cin >> name;
//
//	ifstream in(name);
//
//	if (!in) {
//		cout << name << "-���� ���� ����" << endl;
//		return 0;
//	}
//	map<string, int> words;
//	string str;
//
//	while (in >> str) {
//		words[str]++;
//
//	}
//	cout << name << "����" << words.size() << "������ �ܾ ���Ǿ����ϴ�" << endl;
//	//���
//
//	string searchWord;
//	while (true) {
//		cout << "ã�� �ܾ��?";
//		cin >> searchWord;
//		cout << endl;
//		auto p = words.find(searchWord);
//		if (p != words.end())
//			cout << searchWord << " - " << p->second;
//		else
//			cout << "����  �ܾ��Ӵ�." << endl;
//	}
//}


//������ �ǽ�
#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	cout << "���� ������? ";
	string name = "�̻��ѳ����Ǿٸ���.txt";
	

	ifstream in(name);

	if (!in) {
		cout << name << "-���� ���� ����" << endl;
		return 0;
	}
	map<string, int> words;
	string str;

	while (in >> str) {
		words[str]++;

	}
	cout << name << "����" << words.size() << "������ �ܾ ���Ǿ����ϴ�" << endl;
	//���
	
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
