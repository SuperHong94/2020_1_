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
//		cout << "�ʹ� �� �̸��̴�. �ٽ��Է�: ";
//		cin >> s;
//	}
//	name = s;
//}
//int main()
//{
//	cout << "Dog�� �޸� ũ��: " << sizeof(Dog) << endl;
//	Dog dog{ "�����",3 };
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
//	//Dog 1'0000 ��ü�� ������ ���Ͽ� ����Ѵ�.
//	ofstream out("Dog������", ios::binary);
//	for (int i = 0; i < 1'0000; ++i) {
//		Dog d;
//		out.write((char*)&d, sizeof(Dog));
//	}
//
//}