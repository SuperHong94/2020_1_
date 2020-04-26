////forward_list�� ���� �ڿ� ���Ҹ� �����Ѵ�.
//#include <iostream>
//#include <forward_list>
//#include "String.h"
//using namespace std;
//
//int main()
//{
//	forward_list<String> numbers{ "1","22","333" };
//	auto bb = numbers.before_begin();
//	numbers.insert_after(bb, "0");
//	
//	numbers.emplace_front("-1");
//
//	int size = distance(numbers.cbegin(), numbers.cend());
//	forward_list<String>::iterator p{ numbers.begin() };
//
//	advance(p, size - 1);
//	auto last = numbers.emplace_after(p, "4444");
//
//	last = numbers.emplace_after(last, "55555");
//
//	cout << "���� �޽��� ����" << endl;
//	cout << endl;
//
//	cout << "forward_list�� ���� �� �ִ� �ִ� ���� ����:	" << numbers.max_size() << endl;
//	cout << "forward_list�� ���� ���" << endl;
//	for (auto& number : numbers)
//		cout << number << ' ';
//	cout << endl;
//	cout << endl;
//}

//list���� remove�� ���� �����ϱ�

//#include <iostream>
//#include <list>
//#include <algorithm>
//#include "String.h"
//using namespace std;
//
//int main()
//{
//	list<String> words{ "������","����","�Ÿ��α�","����","��..","����","������","�ñ����" };
//
//	//���⼭ ���� ����
//	for (auto i = words.cbegin(); i != words.cend(); ++i)
//		cout <<*i << endl;
//
//	words.erase(remove(words.begin(), words.end(), String("����")), words.end());
//
//	for (auto i = words.cbegin(); i != words.cend(); ++i)
//		cout << *i << endl;
//}

//
//#include <iostream>
//#include <list>
//#include <algorithm>
//#include <random>
//
//using namespace std;
//
//int main()
//{
//	default_random_engine dre;
//	uniform_int_distribution<> uid{ 0,10 };
//
//	list<int> numbers;
//
//	for (int i = 0; i < 100; ++i)
//		numbers.emplace_back(uid(dre));
//
//	for (auto i = numbers.cbegin(); i != numbers.cend(); ++i)
//		cout << *i << ' ';
//	cout << endl;
//
//	numbers.remove(0);
//	cout << endl;
//	cout << "0�� ������ �� numbers�� ���� ��: " << numbers.size() << endl;
//	for (auto i = numbers.cbegin(); i != numbers.cend(); ++i)
//		cout << *i << ' ';
//	cout << endl;
//
//}

//list�� splice�� merge
//#include <iostream>
//#include <list>
//#include <algorithm>
//#include <string>
//using namespace std;
//
//void print(string name, list<int>& cont);
//
//int main()
//{
//	list<int> odd{ 5,1,3,9,7 };
//	list<int> even{ 2,6,10,4,8 };
//	list<int> num;
//
//	cout << "---�����̳��� ���� ���---" << endl;
//	print("odd", odd);
//	print("even", even);
//	print("num", num);
//
//	//odd�� even�� num�� merge�Ѵ�.
//	num.merge(odd);
//	num.merge(even);
//
//	cout << endl << "----merge ��� ----" << endl;
//	print("odd", odd);
//	print("even", even);
//	print("num", num);
//
//	list<int> part;
//	part.splice(part.begin(), num, ++num.begin(), ----num.end());
//	cout << endl << "----splice ��� ----" << endl;
//	print("num", num);
//	print("part", part);
//	
//}
//
//void print(string name, list<int>& cont)
//{
//	cout << name<<": ";
//	for (int n : cont)
//		cout << n << ' ';
//	cout << endl;
//}

//list�� sort�� unique

#include <iostream>
#include <list>	
#include <string>
#include "String.h"
using namespace std;

template<class T>
void print(string name, T& cont);

int main()
{
	list<String> words{ "1","3","5","7","9","2","4","5","6","8","10","3","3" };
	//list<int> words{ 1,3,5,7,9,2,4,5,6,8,10,3,3 };
	cout << "---�����̳��� ���� ���---	" << endl;
	print("words: ", words);
	words.sort([](const String& a, const String& b) {
		if (a.size() == b.size())
			return a.getString() < b.getString();
		else
			return a.size() == b.size();
		});
	//words.sort();

	cout << endl << "---sort���---" << endl;
	print("words: ", words);


	//������ �ߺ����Ҹ� �����Ѵ�.
	words.unique();
	cout << endl << "---unique ���---" << endl;
	print("words: ", words);


}

template<class T>
void print(string name, T& cont)
{
	cout << name;
	for (auto& n : cont)
		cout << n << ' ';
	cout << endl;
}