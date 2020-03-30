
//사람이 읽을필요가 있는 값 vs 그냥 정수값
//#include <iostream>
//#include <string>
//
//int main()
//{
//	int num = 0B0111'1111'1111'1111'1111'1111'1111'1111;
//
//	std::cout << sizeof(num) << "바이트" << '\n';
//	std::cout << num << '\n';
//
//	std::string s{ std::to_string(num) };
//	std::cout << "num을 글자로 저장하려 면" << sizeof(s) << "바이트가 필요합니다." << '\n';
//}


//메모리의 값 그대로 저장하기----------------

//텍스트모드로 저장
//#include <iostream>
//#include <random>
//#include <fstream>
//using namespace std;
//
//int main()
//{
//	default_random_engine dre;
//	uniform_int_distribution<int> uid;
//	ofstream out("정수 1000개.txt");
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
//	ofstream out("정수 1000개.txt",ios::binary);
//
//	int n;
//
//	for (int i = 0; i < 1000; ++i) {
//		n = uid(dre);
//		out.write((char*)&n, sizeof(n));
//	}
//}
//--------------------

//파일읽기---------

//#include <iostream>
//#include <fstream>
//#include <limits>
//
//int main()
//{
//	std::ifstream in("정수 1000개.txt", std::ios::binary);
//
//	int n;
//	int max{ std::numeric_limits<int>::min() };
//
//	for (int i = 0; i < 1000; ++i) {
//		in.read((char*)&n, sizeof(n));
//		if (max < n)
//			max = n;
//	}
//	std::cout << " 가장 큰 값" << max << '\n';
//}
//---------------------


//정렬-------------

//정수 읽기
//#include <iostream>
//#include <fstream>
//#include <iomanip>
//
//int main()
//{
//	std::ifstream in("정수 1000개.txt", std::ios::binary);
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
//	std::ifstream in("정수 1000개.txt", std::ios::binary);
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


//qsort- 람다 활용
//#include <iostream>
//#include <fstream>
//#include <iomanip>
//
//
//int main()
//{
//	std::ifstream in("정수 1000개.txt", std::ios::binary);
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


//qsort- c++스타일
//#include <iostream>
//#include <fstream>
//#include <iomanip>
//#include <algorithm>
//
//
//int main()
//{
//	std::ifstream in("정수 1000개.txt", std::ios::binary);
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


