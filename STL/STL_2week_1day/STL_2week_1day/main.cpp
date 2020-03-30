//����ð� ���� -----------

//3�� ����
//#include <iostream>
//#include <thread>
//using namespace std;
//int main()
//{
//	cout << "����" <<endl;
//
//	this_thread::sleep_for(3s);
//
//	cout << "3�ʰ� ����" << endl;
//
//}


//������ 3�ʰɸ����� �˾ƺ���
//#include <iostream>
//#include <thread>
//#include <chrono>
//using namespace std;
//int main()
//{
//	cout << "����" <<endl;
//
//	chrono::steady_clock::time_point start = chrono::steady_clock::now(); //�ð����� ��´�.
//	this_thread::sleep_for(3s);
//	chrono::steady_clock::time_point end = chrono::steady_clock::now();// �ð����� �ٽ� ��´�.
//
//	chrono::duration<double> duration = end - start; //�ð� ������ ���
//	chrono::duration<double> d = chrono::duration_cast<chrono::seconds>(duration); //ǥ���ϰ� ���� ������ ������ ��ȯ�Ѵ�.
//
//
//	cout << d.count() << "�ʰ� �ɸ�" << endl;
//
//
//	cout << "3�ʰ� ����" << endl;
//
//}


//���� �ڵ� c++����� �̿��ؼ� �ִ��� �����ϰ� ����
//#include <iostream>
//#include <thread>
//#include <chrono>
//using namespace std;
//int main()
//{
//	cout << "����" << endl;
//	using namespace std::chrono;
//	auto start = steady_clock::now(); //�ð����� ��´�.
//
//	this_thread::sleep_for(3000ms);   //3�ʸ� ���� �ڵ�
//
//	auto d = duration_cast<milliseconds>(steady_clock::now() - start);
//
//	cout << d.count() << "�и��ʰ� �ɸ�" << endl;
//
//
//
//}


//sort()�Լ��� �Ÿ��� �ð� 
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
//	auto start = chrono::steady_clock::now(); //�ð����� ��´�.
//
//	sort(begin(data), end(data));
//	auto d = chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start);
//
//	cout << d.count() << "�и��ʰ� �ɸ�" << endl;
//
//
//
//}


//---------------


//���ø� ���׸� ���α׷���-----

//���ø��� ���� �����Լ�
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
//	//chage<string>(a,b);  //���� ����
//	cout << a << b << "���̷���" << endl;
//}
//
//template <typename T>
//void change(T& a, T& b)
//{
//	T t{ a };
//	a = b;
//	b = t;
//}

//Array ���ø�

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