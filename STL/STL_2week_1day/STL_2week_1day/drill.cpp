//2�� 1���� ------------------------------------------
#include <iostream>
#include <fstream>
#include <random>
#include <iomanip>
#include <algorithm>


int main()
{
	const int size = 10'000'000; //1000���� 
	/*std::default_random_engine dre;
	std::uniform_int_distribution<int> uid;

	std::ofstream out("���� 1000����.txt",std::ios::binary);


	int n;

	for (int i = 0; i < size; ++i) {
		n = uid(dre);
		out.write((char*)&n, sizeof(n));
	}

	std::cout << "���Ͼ��� �Ϸ�!" << '\n';
	*/


	std::ifstream in("���� 1000����.txt", std::ios::binary);

	// ���� �ʹ�Ŀ�� �迭�� �ȵǾ �����Ҵ��� �߽��ϴ�. ���� ���û���� ������ �� ������ ���ٸ��� �غ��ҽ��ϴ�.
	int* data = new int[size];
	in.read((char*)data, sizeof(int) * size);  //���� 1��
	std::sort(data, data + size, [](int a, int b) {  //���� 2��
		return a < b; });//�� ��° ���ڴ� �迭 ���ּҸ� �־����ϴ�. �����Ҵ��� ����ϴ� ������ begin�� end�� ����� �ȵǾ����ϴ�.

	/*for (int i = 0; i < size; ++i)   //(Ȯ�ο�)��±��� �ð��� �ɸ����� ���ĵ� �� ��¿� �����߽��ϴ�.
		std::cout << std::setw(20) << std::left << data[i];*/

	std::ofstream out("���� 1000����.data", std::ios::binary);  //���� 1000���� ���� �Ǿ����ϴ�.
	int n;

	for (int i = 0; i < size; ++i) { //���۰� �����𸣴� ������� for���� ����� �Ͽ����ϴ�.
		n = data[i];
		out.write((char*)&n, sizeof(n)); //���� 3��
	}

	std::cout << "���Ͼ��� �Ϸ�!" << '\n';  //�ð��� �ɸ��� ������ �Ǿ����ϴ�.




	delete[] data;
}
//�� begin�� �����Ҵ�迭�� �����ּҰ� �ȵ����?
//����ϸ� �����Ҵ� �迭�� �����ּҿ� ���� �˷��ټ� �������?


//---------------------------------------


//----------------
//2�� 2����
////���� 1��
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


//���� 2��----------------
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