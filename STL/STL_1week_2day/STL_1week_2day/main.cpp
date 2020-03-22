//#include <iostream>
//#include <fstream> //파일 입출력 기능
//#include <string>
//void save(std::string);// 하드디스크에 저장
//
//
//int main()
//{
//	save("main.cpp");
//}
//
//void save(std::string s)
//{
//	//1. 내용을 읽을 파일을 연다. ->"소스.cpp"
//	std::ifstream in(s);
//	//읽은 내용을 저장할 파일을 연다. ->"강의저장.txt"
//	std::ofstream out("강의저장.txt",std::ios::app); //std::ios::app덧붙이기 모드
//	//소스.cpp의 모든 내용을 읽어 강의저장.txt 파일에 기록한다.
//	int c;
//	while ((c = in.get()) != EOF)
//		out << (char)c;
//	out << '\n' << '\n';
//	std::cout << "main.cpp를 강의저장.txt에 저장하였습니다." << std::endl;
//}

#include <iostream>
#include <random>
#include <fstream>

using namespace std;
int main()
{
	std::default_random_engine dre;
	
	std::uniform_int_distribution<int> uid;
	std::ofstream out("정수1000개.txt",ios::binary);
	for (int i = 0; i < 1000; ++i){
		int v = uid(dre);
		out.write(reinterpret_cast<const char*>(&v), sizeof(int));
	}
	out.close();
	


	
	ifstream in("정수1000개.txt",ios::binary);
	int* m=new int[1000];
	int i{ 0 };
	int min = INT_MIN;


	in.read((char*)m, sizeof(int)*1000);
	for (int i = 0; i < 1000; ++i)
	{
		cout <<i<<"---"<< m[i] << '\n';
	}
	cout << sizeof("100");
	delete[] m;
}