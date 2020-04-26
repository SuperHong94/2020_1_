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
//	//file �б�
//	ifstream in(file);
//	if (!in) {
//		cout << file << "���� �б� ����!" << endl;
//		return 0;
//	}
//	ofstream out("STL Wiki �빮��.txt");
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


//STL Wiki.txt ������ �Ųٷ� ����϶�.
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
//	//file �б�
//	ifstream in(file);
//	if (!in) {
//		cout << file << "���� �б� ����!" << endl;
//		return 0;
//	}
//	ofstream out("STL Wiki �빮��.txt");
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
//	//file �б�
//	ifstream in(file);
//	if (!in) {
//		cout << file << "���� �б� ����!" << endl;
//		return 0;
//	}
//	vector<char> v;
//	v.reserve(2000);
//	ofstream out("STL Wiki �빮��.txt");
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


//�ǽ� 1
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
//	//file �б�
//	ifstream in(file);
//	if (!in) {
//		cout << file << "���� �б� ����!" << endl;
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

//�ǽ�2
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
//	//file �б�
//	ifstream in(file);
//	if (!in) {
//		cout << file << "���� �б� ����!" << endl;
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

//�ǽ� 3
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
//	//file �б�
//	ifstream in(file);
//	if (!in) {
//		cout << file << "���� �б� ����!" << endl;
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


//�ǽ� 4
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
//	//file �б�
//	ifstream in(file);
//	if (!in) {
//		cout << file << "���� �б� ����!" << endl;
//		return 0;
//	}
//	vector<string> v{ istream_iterator<string>(in),istream_iterator<string>() };
//
//	sort(v.begin(), v.end());
//	for (auto& d : v)
//		cout << d << ' ';
//	cout << endl;
//}


//�ǽ� 5
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
//	//file �б�
//	ifstream in(file);
//	if (!in) {
//		cout << file << "���� �б� ����!" << endl;
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

//�ǽ� 6
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
//	//file �б�
//	ifstream in(file);
//	if (!in) {
//		cout << file << "���� �б� ����!" << endl;
//		return 0;
//	}
//	vector<string> v{ istream_iterator<string>(in),istream_iterator<string>() };
//	int num = count(v.begin(), v.end(), "the");
//	/*for (auto& d : v)
//		cout << d << ' ';
//	cout << endl;*/
//	cout << num << endl;
//}

//�ǽ�7
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
//	//file �б�
//	ifstream in(file);
//	if (!in) {
//		cout << file << "���� �б� ����!" << endl;
//		return 0;
//	}
//	list<string> v{ istream_iterator<string>(in),istream_iterator<string>() };
//
//	ofstream out("STL Wiki���� 5���ڷ� �� �ܾ�.txt");
//	for (auto& d : v) {
//		if (d.size() == 5)
//			out << d << ' ';
//	}
//	cout << endl;
//}

//����
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
	//file �б�
	ifstream in(file);
	if (!in) {
		cout << file << "���� �б� ����!" << endl;
		return 0;
	}

	vector<char> v{ istreambuf_iterator<char>(in),istreambuf_iterator<char>() };
	ofstream out("STL Wiki �ܾ� ����.txt");

	int index = 0;
	for (int i = 0; i < v.size(); ++i) {
		if (v[i] == ' ') {
			for (int j = i - 1; j >= index; --j) {
				out << v[j];
			}
			index = i + 1;
			out << " ";
		}
		if (v[i] == '\n') {
			for (int j = i - 1; j >= index; --j) {
				out << v[j];
			}
			index = i + 1;
			out << '\n';
		}

		
	}
	cout << endl;
}

