////��������
//#include <iostream>
//#include <random>
//#include <fstream>
//using namespace std;
//
//int main()
//{
//	default_random_engine dre;
//	uniform_int_distribution uid(0,10);
//	ofstream out("����1000��", ios::binary);
//	
//	int n{};
//	for (int i = 0; i < 1'000; ++i) {
//		n = uid(dre);
//		cout << n;
//		out.write((char*)&n, sizeof(n));
//	}
//	ifstream in("����1000��", ios::binary);
//	int a[1000];
//	in.read((char*)&a, sizeof(int) * 1000);
//
//	for (int& d : a)
//		cout << d;
//}