/*
��ü�� ���캻��.

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
////Dog 1000������ �����϶�.
////Dog 1000������ "Dogõ����"�� �����϶�.
//int main()
//{
//	Dog dogs[1000];
//	std::ofstream out("Dogõ����",ios::binary);
//	out.write((char*)dogs, 1000 * sizeof(Dog));
//
//	for (const Dog& dog : dogs)
//		dog.show();
//
//	
//	/*ofstream out("Dogõ����.txt", std::ios::binary);
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
////�ϵ忡 "Dogõ����"������ �ִ�..
////vector�� �о�ͼ� ȭ�鿡 show()�� ����϶�.
int main()
{
	ifstream in("Dogõ����", ios::binary);
	if (!in) {
		cout << "������ �� �� ����";
	}
	vector<Dog> v;
	//cout << v.max_size() << endl; //�ִ� ���� �� �ִ� ���� ��
	//v.reserve(1000); //�޸𸮸� ��ũ�⸹ŭ ��´�.
	//v.resize(1000);
	//in.read((char*)v.data(), 28000);
	//cout << v.size() << endl;
	//v[3].show();

	//
	//cout << typeid(v[0]).name() << endl;
	//cout << typeid(v.data()[0]).name() << endl;
	//cout << v.size() << endl;
	/*for (int i = 0; i < 1000; ++i)  //reserve�� ������
		v.data()[i].show();*/

		//for (const Dog& dog : v)  //resize�� �ؼ� ����
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
//////�ϵ忡 "Dogõ����"������ �ִ�..
//////vector�� �о�Ͷ�
//////�̸������������� �����ؼ� ȭ�鿡show()�� ����϶�.
//int main()
//{
//	ifstream in("Dogõ����", ios::binary);
//	if (!in) {
//		cout << "������ �� �� ����";
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
//	for (const Dog& dog : v)  //resize�� �ؼ� ����
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
	/*bool operator<(const Dog& rhs)  //ù��° ���Ĺ��
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




//�ι�°
//template<>
//struct less<Dog>
//{
//	operator()(Dog a, Dog b)
//};
//�ϵ忡 "Dogõ����"������ �ִ�..
//set<Dog>�� �о�Ͷ�
//set�� ���� ������ ���� ��������
bool ageComp(const Dog& a, const Dog& b) {
	return a.getAge() < b.getAge();
}
int main()
{
	ifstream in("Dogõ����", ios::binary);
	if (!in) {
		cout << "������ �� �� ����";
	}

	multiset<Dog,function<bool(const Dog& a, const Dog& b)>> s(ageComp); //����° ���ı����� ���� �˷��ֱ�   function:��� ȣ��Ÿ���� �ϳ��� ���ִ� ���ø� ,  ����Ÿ�Ե� ����
													//�Լ��̸��˷���
	Dog dog;
	for (int i = 0; i < 1000; ++i) {
		in.read((char*)&dog, sizeof(Dog));
		s.insert(dog);
		
	}

	for (const Dog& dog : s)  
		dog.show();

}