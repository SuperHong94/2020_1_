//2주 1일차 ------------------------------------------
//#include <iostream>
//#include <fstream>
//#include <random>
//#include <iomanip>
//#include <algorithm>
//
//
//int main()
//{
//	const int size = 10'000'000; //1000만개 
//	/*std::default_random_engine dre;
//	std::uniform_int_distribution<int> uid;
//
//	std::ofstream out("정수 1000만개.txt",std::ios::binary);
//
//
//	int n;
//
//	for (int i = 0; i < size; ++i) {
//		n = uid(dre);
//		out.write((char*)&n, sizeof(n));
//	}
//
//	std::cout << "파일쓰기 완료!" << '\n';
//	*/
//
//
//	std::ifstream in("정수 1000만개.txt", std::ios::binary);
//
//	// 값이 너무커서 배열로 안되어서 동적할당을 했습니다. 물론 스택사이즈를 수정할 수 있지만 색다르게 해보았습니다.
//	int* data = new int[size];
//	in.read((char*)data, sizeof(int) * size);  //문제 1번
//	std::sort(data, data + size, [](int a, int b) {  //문제 2번
//		return a < b; });//두 번째 인자는 배열 끝주소를 주었습니다. 동적할당을 사용하니 기존의 begin과 end가 사용이 안되었습니다.
//
//	/*for (int i = 0; i < size; ++i)   //(확인용)출력까지 시간이 걸리지만 정렬된 값 출력에 성공했습니다.
//		std::cout << std::setw(20) << std::left << data[i];*/
//
//	std::ofstream out("정수 1000만개.data", std::ios::binary);  //정수 1000만개 정렬 되었습니다.
//	int n;
//
//	for (int i = 0; i < size; ++i) { //시작과 끝을모르니 범위기반 for문을 못사용 하였습니다.
//		n = data[i];
//		out.write((char*)&n, sizeof(n)); //문제 3번
//	}
//
//	std::cout << "파일쓰기 완료!" << '\n';  //시간이 걸리긴 하지만 되었습니다.
//
//
//
//
//	delete[] data;
//}
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

//1번 교수님 해설 100점 짜리-----------------
//#include <iostream>
//#include <fstream>
//#include <algorithm>
//using namespace std;
//int n[1000'0000]; //가장 빠른방법이다. new는 매우 특수한것 프로그램 효율성을 생각해보면 안 쓸수있는것이 좋다.
//int main()
//{
//	//지역변수는 보통 1mb안쪽으로쓴다. 
//	ifstream in("정수1000만개.data", ios::binary);
//	in.read((char*)&n, sizeof(int) * 1000'0000);
//	sort(begin(n), end(n), [](int a, int b) {
//		return a < b;
//		});
//
//	//for (int i = 0; i < 10; ++i) //앞에 10개 출력
//	//	cout << n[i] << endl;
//	//for (int i = 1000'0000 - 10; i < 1000'0000; ++i) //뒤에 10개
//	//	cout << n[i] << endl;
//	
//	ofstream out("정수1000만개정렬.data", ios::binary);
//	out.write((char*)&n, sizeof(int) * 1000'0000);
//}
//-------------------

//1번 교수님 해설 동적할당ver-----------------
//크기를 알 수 없다. 정보를 나중에 알 수 있는경우

//#include <iostream>
//#include <fstream>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//	ifstream in("정수1000만개.data", ios::binary);
//	int* p=new int[1000'0000];  //'[]'배열기호를 쓰는것은 메모리가 물리적으로 붙어있음을 의미한다.
//	in.read((char*)p, sizeof(int) * 1000'0000);
//
//	//begin(p)는 못함 왜냐하면 여기서 p는 대표적인 POD(Plain Old Data)타입의 일종이다. 즉 p에게 너는 시작이 어디니? 하면 대답할 말이 없다.
//
//	//C++ 알고리즘의 범위, 반복자 범위
//	sort(p, p + 1000'0000); //int형 오름차순은 람다 쓸필요없다.
//
//
//	
//	ofstream out("정수1000만개정렬.data", ios::binary);
//	out.write((char*)p, sizeof(int) * 1000'0000);
//}

/*
젼역변수, 힙(free store), 지역변수의 메모리 구분해서 알기
힙은 속도가 필요한 곳에서는 절대로 쓰면안됨 가능하면 안쓸수있는 상황이 좋다.
*/

//------------------------

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



//2일 강의 과제 해설
// const 멤버의 의미

//2주 2일차
////문제 1번
#include <iostream>
using namespace std;

template <typename T>
class Array {
	size_t num{ 0 };
	int* data{ nullptr };
public:
	explicit Array(size_t n) :num{ n }, data{ new int[num] }{};
	virtual ~Array() {
		delete[] data;
	}
	Array(const Array&) = delete;
	Array& operator=(const Array&) = delete;
	T operator[](int idx)const {
		if (idx<0 || idx>size - 1)
			throw out_of_range("index out of range");
		return data[idx];
	}
	T& operator[](int idx) {
		if (idx<0 || idx>size - 1)
			throw out_of_range("index out of range");
		return data[idx];
	}
};

int main()
{
	Array<int> a(10); //런타입에서 10개인것을 결정

	for (int i = 0; i < 10; ++i)
		a[i] = i;
	for (int i = 0; i < 10; ++i)
		cout << a[i] << ' ';
	cout << endl;

}
//---------------------------
//
////----
//
////템플릿
//
//#include <iostream>
//#include <string>
//using namespace std;
//
//template <typename T, int N>
//class Array {
//	T data[N];
//public:
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
//	Array<string, 10> a;// 컴파일단계에서 a는 10개라고 확신하는것이다.
//	for (int i = 0; i < 10; ++i)
//		a[i] = "string"s + to_string(i);
//
//	for (int i = 0; i < 10; ++i)
//		cout << a[i] << '\n';
//}



///추가 적으로 공부할것
/*
전역변수,지역변수,힙의 메모리 구분
소멸자에는 왜? virtual을 붙여야 하나

*/

