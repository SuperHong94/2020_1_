
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
#include <iostream>
#include <string>
using namespace std;

template <typename T,size_t N>
class Array {
	size_t num{ 0 };
	T* data{ nullptr };
public:
	Array() :num{ N }, data{ new T[num] }{};
	~Array() {
		delete[] data;
	}
	Array(const Array&) = delete;
	Array& operator=(const Array&) = delete;

	T operator[](int idx)const {
		return data[idx];
	}
	T& operator[](int idx) {
		return data[idx];
	}
};

int main()
{
	Array<string,10> a;
	for (int i = 0; i < 10; ++i)
		a[i] = "string"s+to_string(i);

	for (int i = 0; i < 10; ++i)
		cout << a[i] << '\n'; 
}