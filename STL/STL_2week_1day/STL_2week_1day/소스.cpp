
//����� �����ʿ䰡 �ִ� �� vs �׳� ������
//#include <iostream>
//#include <string>
//
//int main()
//{
//	int num = 0B0111'1111'1111'1111'1111'1111'1111'1111;
//
//	std::cout << sizeof(num) << "����Ʈ" << '\n';
//	std::cout << num << '\n';
//
//	std::string s{ std::to_string(num) };
//	std::cout << "num�� ���ڷ� �����Ϸ� ��" << sizeof(s) << "����Ʈ�� �ʿ��մϴ�." << '\n';
//}


//�޸��� �� �״�� �����ϱ�----------------

//�ؽ�Ʈ���� ����
//#include <iostream>
//#include <random>
//#include <fstream>
//using namespace std;
//
//int main()
//{
//	default_random_engine dre;
//	uniform_int_distribution<int> uid;
//	ofstream out("���� 1000��.txt");
//
//	int n;
//
//	for (int i = 0; i < 1000; ++i){
//		n=uid(dre);
//		out.write((char*)&n, sizeof(n));
//	}
//}


//#include <iostream>
//#include <random>
//#include <fstream>
//using namespace std;
//
//int main()
//{
//	default_random_engine dre;
//	uniform_int_distribution<int> uid;
//	ofstream out("���� 1000��.txt",ios::binary);
//
//	int n;
//
//	for (int i = 0; i < 1000; ++i) {
//		n = uid(dre);
//		out.write((char*)&n, sizeof(n));
//	}
//}
//--------------------

//�����б�---------

//#include <iostream>
//#include <fstream>
//#include <limits>
//
//int main()
//{
//	std::ifstream in("���� 1000��.txt", std::ios::binary);
//
//	int n;
//	int max{ std::numeric_limits<int>::min() };
//
//	for (int i = 0; i < 1000; ++i) {
//		in.read((char*)&n, sizeof(n));
//		if (max < n)
//			max = n;
//	}
//	std::cout << " ���� ū ��" << max << '\n';
//}
//---------------------


//����-------------

//���� �б�
//#include <iostream>
//#include <fstream>
//#include <iomanip>
//
//int main()
//{
//	std::ifstream in("���� 1000��.txt", std::ios::binary);
//
//	int data[1'000];
//
//	in.read((char*)&data, sizeof(int)*1000);
//	/*for (int i = 0; i < 1000; ++i) {
//		
//		if (max < n)
//			max = n;
//	}*/
//	for (int n : data)
//		std::cout << std::setw(20)<<std::left <<n;
//	
//}



//qsort
//#include <iostream>
//#include <fstream>
//#include <iomanip>
//
//int comapreFunc(const void* a, const void* b);
//int main()
//{
//	std::ifstream in("���� 1000��.txt", std::ios::binary);
//
//	int data[1'000];
//
//	in.read((char*)&data, sizeof(int) * 1000);
//	qsort(data, 1'000, sizeof(int), comapreFunc);
//
//	for (int n : data)
//		std::cout << std::setw(20) << std::left << n;
//
//}
//
//
//int comapreFunc(const void* a, const void* b)
//{
//	int num1 = *static_cast<const int*>(a);
//	int num2 = *static_cast<const int*>(b);
//	return num1 - num2;
//}


//qsort- ���� Ȱ��
//#include <iostream>
//#include <fstream>
//#include <iomanip>
//
//
//int main()
//{
//	std::ifstream in("���� 1000��.txt", std::ios::binary);
//
//	int data[1'000];
//
//	in.read((char*)&data, sizeof(int) * 1000);
//	qsort(data, 1'000, sizeof(int), [](const void* a, const void* b) {
//		return *(static_cast<int const*>(a)) - *(static_cast<int const*>(b)); });
//
//	for (int n : data)
//		std::cout << std::setw(20) << std::left << n;
//
//}


//qsort- c++��Ÿ��
//#include <iostream>
//#include <fstream>
//#include <iomanip>
//#include <algorithm>
//
//
//int main()
//{
//	std::ifstream in("���� 1000��.txt", std::ios::binary);
//
//	int data[1'000];
//
//	in.read((char*)&data, sizeof(int) * 1000);
//	std::sort(std::begin(data), std::end(data), [](int a, int b) {
//		return a < b; });
//
//	for (int n : data)
//		std::cout << std::setw(20) << std::left << n;
//
//}


