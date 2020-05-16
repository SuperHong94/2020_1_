/*
객체를 살펴본다.

*/


//#include <iostream>
//#include <random>
//#include <fstream>
//
//using namespace std;
////random_device rd;
////default_random_engine dre(rd());
//std::default_random_engine dre;
//std::uniform_int_distribution<int> uidAge{ 1,15 };
//std::uniform_int_distribution<int> uidName{ 'a','z' };
//
//
//
//class Dog {
//	std::string name;
//	int age;
//public:
//	Dog() {
//		age = uidAge(dre);
//		for (int i = 0; i < 15; ++i)
//			name += uidName(dre);
//	}
//	void show()const {
//		std::cout << name << "-" << age << std::endl;
//	}
//};
//
////Dog 1000마리를 생성하라.
////Dog 1000마리를 "Dog천마리"에 저장하라.
//int main()
//{
//	Dog dogs[1000];
//	std::ofstream out("Dog천마리",ios::binary);
//	out.write((char*)dogs, 1000 * sizeof(Dog));
//
//	for (const Dog& dog : dogs)
//		dog.show();
//
//	
//	/*ofstream out("Dog천마리.txt", std::ios::binary);
//
//	out.write()*/
//}

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <string>
using namespace std;


class Dog {

	std::string name{};
	int age{};

public:
	void show()const {
		std::cout << name << "-" << age << std::endl;
	}
};
//
////하드에 "Dog천마리"파일이 있다..
////vector에 읽어와서 화면에 show()로 출력하라.
int main()
{
	ifstream in("Dog천마리", ios::binary);
	if (!in) {
		cout << "파일을 열 수 없음";
	}
	vector<Dog> v;
	//cout << v.max_size() << endl; //최대 담을 수 있는 원소 수
	//v.reserve(1000); //메모리를 그크기많큼 잡는다.
	//v.resize(1000);
	//in.read((char*)v.data(), 28000);
	//cout << v.size() << endl;
	//v[3].show();

	//
	//cout << typeid(v[0]).name() << endl;
	//cout << typeid(v.data()[0]).name() << endl;
	//cout << v.size() << endl;
	/*for (int i = 0; i < 1000; ++i)  //reserve로 했을때
		v.data()[i].show();*/

		//for (const Dog& dog : v)  //resize로 해서 가능
		//	dog.show();

}


//#include <iostream>
//#include <string>
//#include <fstream>
//#include <algorithm>
//#include <vector>
//#include <string>
//using namespace std;
////
////
//class Dog {
//
//	std::string name{};
//	int age{};
//
//public:
//	void show()const {
//		std::cout << name << "-" << age << std::endl;
//	}
//	/*bool operator<(const Dog& rhs)
//	{
//		return this->name < rhs.name;
//	}*/
//	string_view getName() const
//	{
//		return this->name;
//	}
//};
////
//////하드에 "Dog천마리"파일이 있다..
//////vector에 읽어와라
//////이름오름차순으로 정렬해서 화면에show()로 출력하라.
//int main()
//{
//	ifstream in("Dog천마리", ios::binary);
//	if (!in) {
//		cout << "파일을 열 수 없음";
//	}
//	vector<Dog> v;
//	vector<Dog> v;
//
//	v.resize(1000);
//	in.read((char*)v.data(), 28000);
//
//	sort(v.begin(), v.end(), [](const Dog& a, const Dog& b) {
//		return a.getName() < b.getName();
//		});
//
//	for (const Dog& dog : v)  //resize로 해서 가능
//		dog.show();
//
//}


//
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <string>
#include <set>
#include <functional>
using namespace std;

//
class Dog {

	std::string name{};
	int age{};

public:
	void show()const {
		std::cout << name << "-" << age << std::endl;
	}
	/*bool operator<(const Dog& rhs)  //첫번째 정렬방법
	{
		return this->name < rhs.name;
	}*/
	string_view getName() const
	{
		return name;
	}
	int getAge() const
	{
		return age;
	}
};




//두번째
//template<>
//struct less<Dog>
//{
//	operator()(Dog a, Dog b)
//};
//하드에 "Dog천마리"파일이 있다..
//set<Dog>로 읽어와라
//set의 정렬 기준은 나이 오름차순
bool ageComp(const Dog& a, const Dog& b) {
	return a.getAge() < b.getAge();
}
int main()
{
	ifstream in("Dog천마리", ios::binary);
	if (!in) {
		cout << "파일을 열 수 없음";
	}

	multiset<Dog,function<bool(const Dog& a, const Dog& b)>> s(ageComp); //세번째 정렬기준을 직접 알려주기   function:모든 호출타입을 하나로 해주는 템플릿 ,  리턴타입도 구분
													//함수이름알려줌
	Dog dog;
	for (int i = 0; i < 1000; ++i) {
		in.read((char*)&dog, sizeof(Dog));
		s.insert(dog);
		
	}

	for (const Dog& dog : s)  
		dog.show();

}