

//distance 함수 만들기
#include <iostream>
#include <iterator>
#include <fstream>	
#include <list>
#include <set>
#include <algorithm>
#include <string>
using namespace std;


template<class Initer>
typename iterator_traits<Initer>::difference_type
my_distance(Initer b, Initer e, random_access_iterator_tag)
{
	return e - b;
}


template<class Initer>
typename iterator_traits<Initer>::difference_type
my_distance(Initer b, Initer e, forward_iterator_tag)
{
	int c{};
	while (b++ != e)
		c++;

	return c;
}



template<class Initer>
typename iterator_traits<Initer>::difference_type 
my_distance(Initer b, Initer e)
{
	/*if constexpr (is_same_v<iterator_traits<Initer>::iterator_category, random_access_iterator_tag>)
		return e - b;
	else {
		int d = 0;
		while (b++ != e)
			d++;
		return d;
	}*/

	return my_distance(b, e, iterator_traits<Initer>::iterator_category());

}


int main()
{

	int a[] = { 1,2,4,3,45 };
	auto p = my_distance(begin(a), end(a));
	cout << p << " 타입: " << typeid(p).name() << endl;


	list<int> lst{ begin(a),end(a) };
	auto p1 = my_distance(begin(lst), end(lst));
	cout << p1 << " 타입: " << typeid(p1).name() << endl;

	set<int> s = { 1,2,3,4,8192,39329,392,392,392 };
	auto p2 = distance(begin(s), end(s));
	cout << p2 << " 타입: " << typeid(p2).name() << endl;

}

