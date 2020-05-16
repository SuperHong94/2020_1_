
//다음주 화요일 시험
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
//	string_view 스트링24바이트이기에 string_view임
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
//	cout<<"파일크기"<<std::filesystem::file_size("main.cpp") << endl;
//
//	save("main.cpp");
//}
/*

in>>c에서 >>는 formattedIO 서식화된 입출력 (글자만 입력)   시간엄청많을때 사용
in.get() 한바이트씩 읽기
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

//Dog 1000마리를 생성하라.

int main()
{
	Dog dogs[1000];
	for (const Dog& dog : dogs)
		dog.show();

}