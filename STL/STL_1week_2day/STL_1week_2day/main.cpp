//#include <iostream>
//#include <fstream> //���� ����� ���
//#include <string>
//void save(std::string);// �ϵ��ũ�� ����
//
//
//int main()
//{
//	save("main.cpp");
//}
//
//void save(std::string s)
//{
//	//1. ������ ���� ������ ����. ->"�ҽ�.cpp"
//	std::ifstream in(s);
//	//���� ������ ������ ������ ����. ->"��������.txt"
//	std::ofstream out("��������.txt",std::ios::app); //std::ios::app�����̱� ���
//	//�ҽ�.cpp�� ��� ������ �о� ��������.txt ���Ͽ� ����Ѵ�.
//	int c;
//	while ((c = in.get()) != EOF)
//		out << (char)c;
//	out << '\n' << '\n';
//	std::cout << "main.cpp�� ��������.txt�� �����Ͽ����ϴ�." << std::endl;
//}

#include <iostream>
#include <random>
#include <fstream>

using namespace std;
int main()
{
	std::default_random_engine dre;
	
	std::uniform_int_distribution<int> uid;
	std::ofstream out("����1000��.txt",ios::binary);
	for (int i = 0; i < 1000; ++i){
		int v = uid(dre);
		out.write(reinterpret_cast<const char*>(&v), sizeof(int));
	}
	out.close();
	


	
	ifstream in("����1000��.txt",ios::binary);
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