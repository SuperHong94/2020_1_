//#include <iostream>
//#include <string>
//using namespace std;
//int gid{};
//class  Dog {
//	string name;
//	int age;
//	int id;
//
//public:
//	Dog(string, int);
//	friend ostream& operator<<(ostream& os, const Dog& dog);
//};
//
//ostream& operator<<(ostream& os, const Dog& dog)
//{
//	cout << dog.name << ", " << dog.age << ", " << dog.id << endl;
//	return os;
//}
//Dog::Dog(string s, int dogAge) :age{ dogAge }, id{ ++gid }
//{
//	while (s.length() > 15) {
//		cout << "너무 긴 이름이다. 다시입력: ";
//		cin >> s;
//	}
//	name = s;
//}
//int main()
//{
//	cout << "Dog의 메모리 크기: " << sizeof(Dog) << endl;
//	Dog dog{ "댕댕이",3 };
//	cout << dog << endl;
//}


//#include <iostream>
//#include <fstream>
//#include <string>
//#include <random>
//using namespace std;
//int gid{};
//default_random_engine dre;
//uniform_int_distribution<int> uidAge(1, 12);
//uniform_int_distribution<int> uidName('a', 'z');
//uniform_int_distribution<int> uidNameLen(3, 15);
//class  Dog {
//	string name;
//	int age;
//	int id;
//
//public:
//	Dog();
//	Dog(string, int);
//	friend ostream& operator<<(ostream& os, const Dog& dog);
//};
//
//ostream& operator<<(ostream& os, const Dog& dog)
//{
//	cout << dog.name << ", " << dog.age << ", " << dog.id << endl;
//	return os;
//}
//Dog::Dog() :id{ ++gid } {
//	int len = uidNameLen(dre);
//	for (int i = 0; i < len; ++i)
//		name += uidName(dre);
//	age = uidAge(dre);
//}
//
//Dog::Dog(string s, int dogAge) :name{ s },age { dogAge }, id{ ++gid }
//{
//}
//int main()
//{
//	/*Dog dogs[100];
//	for (const Dog& dog : dogs)
//		cout << dog << endl;*/
//
//	//Dog 1'0000 객체의 정보를 파일에 기록한다.
//	ofstream out("Dog만마리", ios::binary);
//	for (int i = 0; i < 1'0000; ++i) {
//		Dog d;
//		out.write((char*)&d, sizeof(Dog));
//	}
//
//}