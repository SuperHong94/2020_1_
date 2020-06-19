/*
6.16 월요일


2. String 컨테이너가 삽입반복자를 지원하도록 추가 코딩

e-class에서 "단어들.txt"를 다운받아 vector에 읽어 주세요


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

	Test a; //<-반복자
	copy(istream_iterator<char>{cin}, {}, a); //컨트롤 +Z 누를 때 까지


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
//		//cout << "원래는" << c << "를 push_back(c) 해야 함" << endl; 
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
//	String s; //우리가 만든 컨테이너
//
//	copy(istream_iterator<char>{cin}, {}, BACK_inserter(s)); //컨트롤 +Z 누를 때 까지
//
//	cout << "입력하신 글자수는 " << s.size() << endl;
//	cout << s << endl;
//
//}



//애너그램
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
//	ifstream in("단어들.txt");
//	//vector<string> v{ istream_iterator<string>{in},{} };
//	copy(istream_iterator<string>{in}, {}, back_inserter(v));
//
//
//	//단어를 입력받아 anagram을 찾아주자
//	//사전에 없는 단어면 없다고 출력하자
//	//사전에 있으면 모든 anagramdm을 화면에 출력한다.
//
//
//	
//
//	for (int i = 0; i < 20; ++i)
//		cout << v[i] << endl;
//
//
//
//	//단어가 너무 길면 안됨
//	//while (true) {
//	//	cout << "단어를 입력하세요: ";
//	//	string word;
//	//	cin >> word;
//	//	//가능한 조합을 출력하자.
//	//	sort(word.begin(), word.end());
//	//	//word가 사전에 있는지 검사하면 된다.
//	//	do {
//	//		/if (binary_search(v.begin(), v.end(), word))
//	//			cout << word << " 있다." << endl;
//	//		cout << word << '\r';
//	//	} while (next_permutation(word.begin(), word.end()));
//	//	cout << endl;
//	//}
//	
//
//	/*
//	정렬된 버전으로 구성
//	*/
//	while (true) {
//
//
//	}
//}
//
//



/*
//긴 단어 20개를 골라내보자.
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
	ifstream in("단어들.txt");
	//vector<string> v{ istream_iterator<string>{in},{} };
	copy(istream_iterator<string>{in}, {}, back_inserter(v));


	//단어 쌍을 first기준으로 wjdfufgksek.
	sort(v.begin(), v.end(), [](const PS& a, const PS& b) {
		return a.first < b.first;
		});

	for (int i = 0; i < 2'0000; i < 20'0100; ++i)
	{
		auto [정렬, 원본] = v[i];
		cout << 정렬 << ", " << 원본 << endl;
	}

}


