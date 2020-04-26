//#include <iostream>
//#include <fstream>
//#include <string>
//#include "String.h"
//
//using namespace std;
//
//string file{ "STL Wiki.txt"s };
//int main()
//{
//	//file 읽기
//	ifstream in(file);
//	if (!in) {
//		cout << file << "파일 읽기 실패!" << endl;
//		return 0;
//	}
//	ofstream out("STL Wiki 대문자.txt");
//	int ch;
//	while ((ch = in.get()) != EOF) {
//		/*if (isalpha(ch)) {
//			if (islower(ch))
//				ch -= 0X20;
//		}*/
//		ch = toupper(ch);
//		out.put(ch);
//	}
//
//}


//STL Wiki.txt 파일을 거꾸로 출력하라.
//#include <iostream>
//#include <fstream>
//#include <string>
//#include "String.h"
//
//using namespace std;
//
//string file{ "STL Wiki.txt"s };
//int main()
//{
//	//file 읽기
//	ifstream in(file);
//	if (!in) {
//		cout << file << "파일 읽기 실패!" << endl;
//		return 0;
//	}
//	ofstream out("STL Wiki 대문자.txt");
//	string s;
//	while (!in.eof()) {
//		s += in.get();
//	
//	}
//	
//	for (auto i = s.rbegin(); i != s.rend(); ++i)
//		cout << *i;
//	cout << endl;
//
//}



//#include <iostream>
//#include <fstream>
//#include <vector>
//#include <string>
//#include "String.h"
//
//using namespace std;
//
//string file{ "STL Wiki.txt"s };
//int main()
//{
//	//file 읽기
//	ifstream in(file);
//	if (!in) {
//		cout << file << "파일 읽기 실패!" << endl;
//		return 0;
//	}
//	vector<char> v;
//	v.reserve(2000);
//	ofstream out("STL Wiki 대문자.txt");
//	string s;
//	while (!in.eof()) {
//		v.emplace_back(in.get());
//
//	}
//
//	for (auto& d : v)
//		cout << d;
//	cout << '\n';
//
//}


//실습 1
//#include <iostream>
//#include <fstream>
//#include <iterator>
//#include <vector>
//#include <algorithm>
//#include <string>
//#include "String.h"
//
//using namespace std;
//
//string file{ "STL Wiki.txt"s };
//int main()
//{
//	//file 읽기
//	ifstream in(file);
//	if (!in) {
//		cout << file << "파일 읽기 실패!" << endl;
//		return 0;
//	}
//	vector<char> v{ istreambuf_iterator<char>(in),istreambuf_iterator<char>() };
//
//	v.erase(remove(v.begin(),v.end(),'e'), v.end());
//	for (auto& d : v)
//		cout << d;
//	cout << '\n';
//
//}

//실습2
//#include <iostream>
//#include <fstream>
//#include <iterator>
//#include <vector>
//#include <algorithm>
//#include <string>
//#include "String.h"
//
//using namespace std;
//
//string file{ "STL Wiki.txt"s };
//int main()
//{
//	//file 읽기
//	ifstream in(file);
//	if (!in) {
//		cout << file << "파일 읽기 실패!" << endl;
//		return 0;
//	}
//	vector<string> v{ istream_iterator<string>(in),istream_iterator<string>() };
//
//	for (auto& d : v)
//		cout << d << ' ';
//	cout << '\n';
//	cout << v.size() << endl;
//
//
//
//}

//실습 3
//#include <iostream>
//#include <fstream>
//#include <iterator>
//#include <vector>
//#include <algorithm>
//#include <string>
//#include "String.h"
//
//using namespace std;
//
//string file{ "STL Wiki.txt"s };
//int main()
//{
//	//file 읽기
//	ifstream in(file);
//	if (!in) {
//		cout << file << "파일 읽기 실패!" << endl;
//		return 0;
//	}
//	vector<string> v{ istream_iterator<string>(in),istream_iterator<string>() };
//
//	for (int i = 0; i < v.size(); ++i) {
//		for (int j = v[i].size()-1; j >= 0; --j)
//			cout << v[i][j];
//		cout << ' ';
//	}
//	cout << endl;
//}


//실습 4
//#include <iostream>
//#include <fstream>
//#include <iterator>
//#include <vector>
//#include <algorithm>
//#include <string>
//#include "String.h"
//
//using namespace std;
//
//string file{ "STL Wiki.txt"s };
//int main()
//{
//	//file 읽기
//	ifstream in(file);
//	if (!in) {
//		cout << file << "파일 읽기 실패!" << endl;
//		return 0;
//	}
//	vector<string> v{ istream_iterator<string>(in),istream_iterator<string>() };
//
//	sort(v.begin(), v.end());
//	for (auto& d : v)
//		cout << d << ' ';
//	cout << endl;
//}


//실습 5
//#include <iostream>
//#include <fstream>
//#include <iterator>
//#include <vector>
//#include <algorithm>
//#include <string>
//#include "String.h"
//
//using namespace std;
//
//string file{ "STL Wiki.txt"s };
//int main()
//{
//	//file 읽기
//	ifstream in(file);
//	if (!in) {
//		cout << file << "파일 읽기 실패!" << endl;
//		return 0;
//	}
//	vector<string> v{ istream_iterator<string>(in),istream_iterator<string>() };
//	sort(v.begin(), v.end(), [](const string& a, const string& b){
//		return a.size() < b.size();
//		});
//	for (auto& d : v)
//		cout << d << ' ';
//	cout << endl;
//}

//실습 6
//#include <iostream>
//#include <fstream>
//#include <iterator>
//#include <vector>
//#include <algorithm>
//#include <string>
//#include "String.h"
//
//using namespace std;
//
//string file{ "STL Wiki.txt"s };
//int main()
//{
//	//file 읽기
//	ifstream in(file);
//	if (!in) {
//		cout << file << "파일 읽기 실패!" << endl;
//		return 0;
//	}
//	vector<string> v{ istream_iterator<string>(in),istream_iterator<string>() };
//	int num = count(v.begin(), v.end(), "the");
//	/*for (auto& d : v)
//		cout << d << ' ';
//	cout << endl;*/
//	cout << num << endl;
//}

//실습7
//#include <iostream>
//#include <fstream>
//#include <iterator>
//#include <list>
//#include <algorithm>
//#include <string>
//#include "String.h"
//
//using namespace std;
//
//string file{ "STL Wiki.txt"s };
//int main()
//{
//	//file 읽기
//	ifstream in(file);
//	if (!in) {
//		cout << file << "파일 읽기 실패!" << endl;
//		return 0;
//	}
//	list<string> v{ istream_iterator<string>(in),istream_iterator<string>() };
//
//	ofstream out("STL Wiki에서 5글자로 된 단어.txt");
//	for (auto& d : v) {
//		if (d.size() == 5)
//			out << d << ' ';
//	}
//	cout << endl;
//}

//도전
#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <string>
#include "String.h"

using namespace std;

string file{ "STL Wiki.txt"s };
int main()
{
	//file 읽기
	ifstream in(file);
	if (!in) {
		cout << file << "파일 읽기 실패!" << endl;
		return 0;
	}

	string temp;
	string s;
	string ss;
	vector<string> v;
	v.reserve(850);
	while (!in.eof()) {
		//char a = char(in.get());
		//if (a != ' ')
		//	temp += a;
		//else {
		//	a = char(in.get());
		//	if (a == '\n') {
		//		temp +=a;
		//		v.emplace_back(temp);
		//	}
		//	else {
		//		//in.putback(a);
		//		v.emplace_back(temp);
		//	}
		//	temp = "";
		//}
		std::getline(in, temp);
		for (int i = 0; i < temp.size(); ++i) {
			if (temp[i] != ' ') {
				s += temp[i];
			}
			else {
				for (auto i = s.crbegin(); i != s.crend(); ++i){
					cout << *i;
					ss += *i;
				}
				cout << " ";
				ss += " ";
				s = "";
			}
		}
		cout << '\n';
		ss += " \n";


	}
	/*for (auto d : v)
		cout << d << ' ';
	cout << endl;*/
	/*for (int i = 0; i < v.size(); ++i) {
		for (int j = v[i].size() - 1; j >= 0; --j)
			cout << v[i][j];
		cout << ' ';
	}*/
	ofstream out("되나.txt");
	out << ss;

	cout << endl;
}

