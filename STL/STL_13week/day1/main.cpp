/*
6�� 26�� ����
���� ���� �˰����� ������ �� �ִ�.

nth_element-> partial_sort->sort->stable_sort

���ĵǾ� �ִ� ������ �˻��ϴ� ���
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
//	int a[100];		//���� 100��
//	iota(begin(a), end(a), 1);  //[1,100]���� ä���.
//
//
//	shuffle(begin(a), end(a), mt19937()); //mt19937()==dre;
//	//copy(begin(a), end(a), ostream_iterator<int>{cout, "\t"});
//
//
//	//Ȧ���� ¦���� �����Ͽ� ����϶� -partition
//	
//	//���� �ѰŶ� �������Ѱ� �Ȱ���.
//	auto it = partition(begin(a), end(a), [](int i) {
//		return i & 1;
//		});
//	cout << "\nȦ���Դϴ�." << endl;
//	copy(begin(a), it, ostream_iterator<int>{cout, "\t"});
//	cout << "\n¦���Դϴ�. " << endl;
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
//	bool operator<(const Player& rhs)const { //���Լ��ϱ� const �ٿ��ߵȴ�!
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
//	////�÷��̾� 100���� �ִµ� 
//	////���� �ֵ� 30�� �̾ƺ�!  ���� 30���� ������ ������Ѵ�.
//	//nth_element(begin(players), begin(players) + 30, end(players));
//
//	//cout << "------����" << endl;
//	//for (int i = 0; i < 30; ++i)
//	//	players[i].show();
//
//
//	//----
//
//	//�÷��̾� 100���� �ִµ� 
//	//���� '�������' 30�� �̾ƺ�!  ���� 30���� ������ ������Ѵ�.
//	/*partial_sort(begin(players), begin(players) + 100, end(players));
//
//	cout << "------����" << endl;
//	copy(begin(players), begin(players) + 100, ostream_iterator<Player>(cout, "\n"));*/
//
//
//	//--
//	//�÷��̾� 100���� �ִµ� 
//	//���̴� �������� ���̰� ���ٸ� �̸��� ������������ �����϶�
//	//stable_sort
//	sort(begin(players), end(players), [](const Player& lhs, const Player& rhs) {
//		return lhs.name < lhs.name;
//		});
//	stable_sort(begin(players), end(players));
//
//	cout << "------����" << endl;
//	copy(begin(players), end(players), ostream_iterator<Player>(cout, "\n"));
//
//
//
//}


//----------- �̻��� ������ �ٸ���
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
	ifstream in("�̻��ѳ����Ǿٸ���.txt");
	char c;
	in >> c >> c >> c; //BOM �ǳʶ�
	vector<string> v{ istream_iterator<string>{in},{} };

	//v�� �������� �����Ѵ�.
	sort(v.begin(), v.end());

	//���ϴ� �ܾ v�� �ִ��� �˷��ּ���. ������
	//while (true)
	//{
	//	cout << "�ܾ �Է��ϼ���: ";
	//	string word;
	//	cin >> word;

	//	//0�� ����
	//	/*auto p = find(v.begin(), v.end(), word);
	//	if (p != v.end())
	//		cout << word << "�� ã�ҽ��ϴ�." << endl;
	//	else
	//		cout << "���� �ܾ� �Դϴ�." << endl;*/

	//	//���ĵǾ��������̰� ����.
	//	bool b=binary_search(v.begin(), v.end(), word);
	//	if (b)
	//		cout << word << "ã��" << endl;
	//	else
	//		cout << "����." << endl;

	//}


	//[����] ���ϴ� �ܾ �ִ�?
	//�ִٸ� ��� �ִ�?
	//[������ ����] � �ܾ ������ �߰��Ϸ��� �Ѵ�.
	//��� �߰��ϸ� �ǰڴ�? (���� ������ ������ �ȵȴ�.)
	//copy(v.begin(), v.begin() + 1'00000, ostream_iterator<string>(cout, "  "));

	while (true)
	{
		cout << "�ܾ �Է��ϼ���: ";
		string word;
		cin >> word;
		auto [low, high]=equal_range(v.begin(), v.end(), word);  //���Ѽ� ���Ѽ���ȯ
		if (low == high)
			cout << "������ ���� �ܾ� �Դϴ�." << endl;
		else
			cout<<word<<"�� " << high - low << "���� �ֽ��ϴ�." << endl;

		cout << "������ ���� �ʰ� ���ԵǴ� ��ġ�Դϴ�." << endl;
		copy(low - 1, high + 1, ostream_iterator<string>(cout, " "));
		cout << endl;

	}

}


/*
������ ���� ���� constexpr if�� tag dispatching 
copy( , back_insert(String))
dog<-->god �ֳʱ׷�
*/