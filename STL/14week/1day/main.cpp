/*
6.16 ������


2. String �����̳ʰ� ���Թݺ��ڸ� �����ϵ��� �߰� �ڵ�

e-class���� "�ܾ��.txt"�� �ٿ�޾� vector�� �о� �ּ���


#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

class Test {
	char c;
public:
	Test() = default;
	void operator++() {};
	Test operator*() { return *this; }
	Test& operator=(const Test& rhs) { return *this; }
	void operator=(char c) {};
};


int main()
{

	Test a; //<-�ݺ���
	copy(istream_iterator<char>{cin}, {}, a); //��Ʈ�� +Z ���� �� ����


}
*/


//
//#include <iostream>
//#include <string>
//#include <iterator>
//#include "String.h"
//using namespace std;
//template<class In, class Out>
//Out my_copy(In b, In e, Out d)
//{
//	while (b != e) {
//		*d = *b;
//		++b;
//		++d;
//	}
//	return d;
//}
//
//
//
//class BACK_inserter {
//	String& cont;
//public:
//	explicit BACK_inserter(String& container) :cont{ container } {}
//
//
//	//*d=*b;
//	//(operator*()).operator=(char);
//	BACK_inserter& operator*() {
//		return *this;
//	}
//	void operator++() {};
//
//	void operator=(char c) {
//		//cout << "������" << c << "�� push_back(c) �ؾ� ��" << endl; 
//		cont.push_back(c);
//	}
//	BACK_inserter& operator=(const BACK_inserter& rhs) {
//		return *this;
//	}
//};
//
//
//int main()
//{
//	String s; //�츮�� ���� �����̳�
//
//	copy(istream_iterator<char>{cin}, {}, BACK_inserter(s)); //��Ʈ�� +Z ���� �� ����
//
//	cout << "�Է��Ͻ� ���ڼ��� " << s.size() << endl;
//	cout << s << endl;
//
//}



//�ֳʱ׷�
//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <string>
//#include <iterator>
//#include <fstream>
//using namespace std;
//
//
//
//struct PS :pair<string, string> {
//	PS(string s):pair(s,s){
//		sort(first.begin(), first.end());
//	}
//};
//
//
//
//
//int main()
//{
//	vector<string> v;
//	ifstream in("�ܾ��.txt");
//	//vector<string> v{ istream_iterator<string>{in},{} };
//	copy(istream_iterator<string>{in}, {}, back_inserter(v));
//
//
//	//�ܾ �Է¹޾� anagram�� ã������
//	//������ ���� �ܾ�� ���ٰ� �������
//	//������ ������ ��� anagramdm�� ȭ�鿡 ����Ѵ�.
//
//
//	
//
//	for (int i = 0; i < 20; ++i)
//		cout << v[i] << endl;
//
//
//
//	//�ܾ �ʹ� ��� �ȵ�
//	//while (true) {
//	//	cout << "�ܾ �Է��ϼ���: ";
//	//	string word;
//	//	cin >> word;
//	//	//������ ������ �������.
//	//	sort(word.begin(), word.end());
//	//	//word�� ������ �ִ��� �˻��ϸ� �ȴ�.
//	//	do {
//	//		/if (binary_search(v.begin(), v.end(), word))
//	//			cout << word << " �ִ�." << endl;
//	//		cout << word << '\r';
//	//	} while (next_permutation(word.begin(), word.end()));
//	//	cout << endl;
//	//}
//	
//
//	/*
//	���ĵ� �������� ����
//	*/
//	while (true) {
//
//
//	}
//}
//
//



/*
//�� �ܾ� 20���� ��󳻺���.
	nth_element(v.begin(), v.begin() + 20, v.end(), [](const string& a, const string& b) {
		return a.size() > b.size();
		});
dichlorodiphenyltrichloroethane
cyclotrimethylenetrinitramine
trinitrophenylmethylnitramine
hydroxydehydrocorticosterone
antidisestablishmentarianism
electroencephalographically
hydroxydesoxycorticosterone
microspectrophotometrically
antidisestablishmentarian
regeneratoryregeneratress
demethylchlortetracycline
immunoelectrophoretically
microspectrophotometrical
electroencephalographical
philosophicopsychological
superincomprehensibleness
tetraiodophenolphthalein
formaldehydesulphoxylate
microelectrophoretically
disestablishmentarianism




	*/





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
};




int main()
{
	vector<PS> v;
	ifstream in("�ܾ��.txt");
	//vector<string> v{ istream_iterator<string>{in},{} };
	copy(istream_iterator<string>{in}, {}, back_inserter(v));


	//�ܾ� ���� first�������� wjdfufgksek.
	sort(v.begin(), v.end(), [](const PS& a, const PS& b) {
		return a.first < b.first;
		});

	for (int i = 0; i < 2'0000; i < 20'0100; ++i)
	{
		auto [����, ����] = v[i];
		cout << ���� << ", " << ���� << endl;
	}

}


