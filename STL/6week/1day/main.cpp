////forward_list의 제일 뒤에 원소를 삽입한다.
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
//	cout << "관찰 메시지 없음" << endl;
//	cout << endl;
//
//	cout << "forward_list가 담을 수 있는 최대 원소 개수:	" << numbers.max_size() << endl;
//	cout << "forward_list의 원소 출력" << endl;
//	for (auto& number : numbers)
//		cout << number << ' ';
//	cout << endl;
//	cout << endl;
//}

//list에서 remove로 원소 제거하기

//#include <iostream>
//#include <list>
//#include <algorithm>
//#include "String.h"
//using namespace std;
//
//int main()
//{
//	list<String> words{ "공무원","고강도","거리두기","한주","더..","교실","수업은","시기상조" };
//
//	//여기서 고강도 제거
//	for (auto i = words.cbegin(); i != words.cend(); ++i)
//		cout <<*i << endl;
//
//	words.erase(remove(words.begin(), words.end(), String("고강도")), words.end());
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
//	cout << "0을 제거한 후 numbers의 원소 수: " << numbers.size() << endl;
//	for (auto i = numbers.cbegin(); i != numbers.cend(); ++i)
//		cout << *i << ' ';
//	cout << endl;
//
//}

//list의 splice와 merge
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
//	cout << "---컨테이너의 원소 출력---" << endl;
//	print("odd", odd);
//	print("even", even);
//	print("num", num);
//
//	//odd와 even을 num에 merge한다.
//	num.merge(odd);
//	num.merge(even);
//
//	cout << endl << "----merge 결과 ----" << endl;
//	print("odd", odd);
//	print("even", even);
//	print("num", num);
//
//	list<int> part;
//	part.splice(part.begin(), num, ++num.begin(), ----num.end());
//	cout << endl << "----splice 결과 ----" << endl;
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

//list의 sort와 unique

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
	cout << "---컨테이너의 원소 출력---	" << endl;
	print("words: ", words);
	words.sort([](const String& a, const String& b) {
		if (a.size() == b.size())
			return a.getString() < b.getString();
		else
			return a.size() == b.size();
		});
	//words.sort();

	cout << endl << "---sort결과---" << endl;
	print("words: ", words);


	//인접한 중복원소를 제거한다.
	words.unique();
	cout << endl << "---unique 결과---" << endl;
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