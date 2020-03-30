//실행시간 측정 -----------

//3초 측정
//#include <iostream>
//#include <thread>
//using namespace std;
//int main()
//{
//	cout << "시작" <<endl;
//
//	this_thread::sleep_for(3s);
//
//	cout << "3초가 지남" << endl;
//
//}


//실제로 3초걸리는지 알아보기
//#include <iostream>
//#include <thread>
//#include <chrono>
//using namespace std;
//int main()
//{
//	cout << "시작" <<endl;
//
//	chrono::steady_clock::time_point start = chrono::steady_clock::now(); //시간값을 얻는다.
//	this_thread::sleep_for(3s);
//	chrono::steady_clock::time_point end = chrono::steady_clock::now();// 시간값을 다시 얻는다.
//
//	chrono::duration<double> duration = end - start; //시간 간격을 잰다
//	chrono::duration<double> d = chrono::duration_cast<chrono::seconds>(duration); //표현하고 싶은 단위로 간격을 변환한다.
//
//
//	cout << d.count() << "초가 걸림" << endl;
//
//
//	cout << "3초가 지남" << endl;
//
//}


//위의 코드 c++기능을 이용해서 최대한 간단하게 수정
//#include <iostream>
//#include <thread>
//#include <chrono>
//using namespace std;
//int main()
//{
//	cout << "시작" << endl;
//	using namespace std::chrono;
//	auto start = steady_clock::now(); //시간값을 얻는다.
//
//	this_thread::sleep_for(3000ms);   //3초를 쉬는 코드
//
//	auto d = duration_cast<milliseconds>(steady_clock::now() - start);
//
//	cout << d.count() << "밀리초가 걸림" << endl;
//
//
//
//}


//sort()함수가 거리는 시간 
//#include <iostream>
//#include <algorithm>
//#include <chrono>
//#include <random>
//
//using namespace std;
//int main()
//{
//	default_random_engine dre;
//	uniform_int_distribution<int> uid;
//
//	int data[10'000];
//	for (int& d : data)
//		d = uid(dre);
//
//	auto start = chrono::steady_clock::now(); //시간값을 얻는다.
//
//	sort(begin(data), end(data));
//	auto d = chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start);
//
//	cout << d.count() << "밀리초가 걸림" << endl;
//
//
//
//}


//---------------


//템플릿 제네릭 프로그래밍-----

//템플릿을 통한 스왑함수
//
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//template <typename T>
//void change(T&, T&);
//
//int main()
//{
//	string a{ "19"s };
//	string b{ "corona" };
//
//	change(a, b);
//	//chage<string>(a,b);  //정식 사용법
//	cout << a << b << "바이러스" << endl;
//}
//
//template <typename T>
//void change(T& a, T& b)
//{
//	T t{ a };
//	a = b;
//	b = t;
//}

//Array 템플릿

#include <iostream>
class Array {
	size_t num{ 0 };
	int* data{ nullptr };
public:
	explicit Array(size_t n) :num{ n }, data{ new int[num] }{};
	~Array() {
		delete[] data;
	}
	Array(const Array&) = delete;
	Array& operator=(const Array&) = delete;

	int operator[](int idx)const {
		return data[idx];
	}
	int& operator[](int idx) {
		return data[idx];
	}
};
int main()
{
	Array a(10);
	for (int i = 0; i < 10; ++i)
		a[i] = i;
	for (int i = 0; i < 10; ++i)
		std::cout << a[i] << ' ';
	std::cout << '\n';
}