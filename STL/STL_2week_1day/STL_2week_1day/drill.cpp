//2주 1일차 ------------------------------------------
#include <iostream>
#include <fstream>
#include <random>
#include <iomanip>
#include <algorithm>


int main()
{
	const int size = 10'000'000; //1000만개 
	/*std::default_random_engine dre;
	std::uniform_int_distribution<int> uid;

	std::ofstream out("정수 1000만개.txt",std::ios::binary);


	int n;

	for (int i = 0; i < size; ++i) {
		n = uid(dre);
		out.write((char*)&n, sizeof(n));
	}

	std::cout << "파일쓰기 완료!" << '\n';
	*/


	std::ifstream in("정수 1000만개.txt", std::ios::binary);

	// 값이 너무커서 배열로 안되어서 동적할당을 했습니다. 물론 스택사이즈를 수정할 수 있지만 색다르게 해보았습니다.
	int* data = new int[size];
	in.read((char*)data, sizeof(int) * size);  //문제 1번
	std::sort(data, data + size, [](int a, int b) {  //문제 2번
		return a < b; });//두 번째 인자는 배열 끝주소를 주었습니다. 동적할당을 사용하니 기존의 begin과 end가 사용이 안되었습니다.

	/*for (int i = 0; i < size; ++i)   //(확인용)출력까지 시간이 걸리지만 정렬된 값 출력에 성공했습니다.
		std::cout << std::setw(20) << std::left << data[i];*/

	std::ofstream out("정수 1000만개.data", std::ios::binary);  //정수 1000만개 정렬 되었습니다.
	int n;

	for (int i = 0; i < size; ++i) { //시작과 끝을모르니 범위기반 for문을 못사용 하였습니다.
		n = data[i];
		out.write((char*)&n, sizeof(n)); //문제 3번
	}

	std::cout << "파일쓰기 완료!" << '\n';  //시간이 걸리긴 하지만 되었습니다.




	delete[] data;
}
//왜 begin에 동적할당배열의 시작주소가 안들어갈까요?
//어떻게하면 동적할당 배열에 시작주소와 끝을 알려줄수 있을까요?


//---------------------------------------


//----------------
//2주 2일차
////문제 1번
//#include <iostream>
//using namespace std;
//
//template <typename T>
//class Array {
//	size_t num{ 0 };
//	int* data{ nullptr };
//public:
//	explicit Array(size_t n) :num{ n }, data{ new int[num] }{};
//	~Array() {
//		delete[] data;
//	}
//	Array(const Array&) = delete;
//	Array& operator=(const Array&) = delete;
//
//	int operator[](int idx)const {
//		return data[idx];
//	}
//	int& operator[](int idx) {
//		return data[idx];
//	}
//};
//
//int main()
//{
//	Array<int> a(10);
//
//	for (int i = 0; i < 10; ++i)
//		a[i] = i;
//	for (int i = 0; i < 10; ++i)
//		cout << a[i] << ' ';
//	cout << endl;
//
//}
///---------------------------


//문제 2번----------------
//#include <iostream>
//#include <string>
//using namespace std;
//
//template <typename T, size_t N>
//class Array {
//	size_t num{ 0 };
//	T* data{ nullptr };
//public:
//	Array() :num{ N }, data{ new T[num] }{};
//	~Array() {
//		delete[] data;
//	}
//	Array(const Array&) = delete;
//	Array& operator=(const Array&) = delete;
//
//	T operator[](int idx)const {
//		return data[idx];
//	}
//	T& operator[](int idx) {
//		return data[idx];
//	}
//};
//
//int main()
//{
//	Array<string, 10> a;
//	for (int i = 0; i < 10; ++i)
//		a[i] = "string"s + to_string(i);
//
//	for (int i = 0; i < 10; ++i)
//		cout << a[i] << '\n';
//}