
//������ ȭ���� ����
//#include<iostream>
//#include <algorithm>
//#include <string>
//#include <fstream>
//#include <chrono>
//#include "String.h"
//using namespace std;
//int main()
//{
//	String a{ "12345676rdkna;sd" };
//	String b{ "12345676rdkna;sd" };
//	sort(a.begin(), a.end());
//	sort(b.begin(), b.end());
//	cout << a << endl;
//	cout << b << endl;
//
//	/*
//	string
//	string_view ��Ʈ��24����Ʈ�̱⿡ string_view��
//	*/
//}
//

//
//#include <iostream>
//#include <filesystem>
//#include "String.h"
//#include "save.h"
//using namespace std;
//int main()
//{
//	cout<<"����ũ��"<<std::filesystem::file_size("main.cpp") << endl;
//
//	save("main.cpp");
//}
/*

in>>c���� >>�� formattedIO ����ȭ�� ����� (���ڸ� �Է�)   �ð���û������ ���
in.get() �ѹ���Ʈ�� �б�
DMA(Direct Memory Access)
*/

#include <iostream>
#include <random>
#include <filesystem>
#include "String.h"
#include "save.h"

using namespace std;

//random_device rd;
//default_random_engine dre(rd());
default_random_engine dre();
uniform_int_distribution<int> uidAge{ 1,15 };
uniform_int_distribution<int> uidName{'a','z'};
class Dog {
	string name;
	int age;
public:
	Dog() {
		age = uidAge(dre);
		for (int i = 0; i < 15; ++i)
			name += uidName(dre);
	}
	void show()const {
		cout << name << "-" << age << endl;
	}
};

//Dog 1000������ �����϶�.

int main()
{
	Dog dogs[1000];
	for (const Dog& dog : dogs)
		dog.show();

}