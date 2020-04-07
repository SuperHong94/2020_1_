#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <random>
using namespace std;
int gid{};
default_random_engine dre;
uniform_int_distribution<int> uidAge(1, 12);
uniform_int_distribution<int> uidName('a', 'z');
uniform_int_distribution<int> uidNameLen(3, 15);
class  Dog {
	string name;
	int age;
	int id;

public:
	Dog();
	Dog(string, int);
	friend ostream& operator<<(ostream& os, const Dog& dog);
	friend bool operator<(const Dog& a, const Dog& b);
};

ostream& operator<<(ostream& os, const Dog& dog)
{
	cout << dog.name << ", " << dog.age << ", " << dog.id << endl;
	return os;
}

bool operator<(const Dog& a, const Dog& b)
{
	if (a.name < b.name)
		return true;
	else
		return false;
}
Dog::Dog() :id{ ++gid } {
	int len = uidNameLen(dre);
	for (int i = 0; i < len; ++i)
		name += uidName(dre);
	age = uidAge(dre);
}

Dog::Dog(string s, int dogAge) :name{ s }, age{ dogAge }, id{ ++gid }
{
}
Dog dogs[1'0000];
int main()
{
	ifstream in("Dog만마리", ios::binary);
	if (!in)
		cout << "Dog만마리" << "을 열지 못했습니다." << endl;
	in.read((char*)&dogs, sizeof(Dog) * 1'0000);  //문제1
	sort(begin(dogs), end(dogs), [](Dog a, Dog b) { //문제2
		return a < b;
		});

	cout << dogs[9999] << endl;
}


//문제3번 정답
//zzzanmlwpa, 12, 9807