//2�� 1���� ------------------------------------------
//#include <iostream>
//#include <fstream>
//#include <random>
//#include <iomanip>
//#include <algorithm>
//
//
//int main()
//{
//	const int size = 10'000'000; //1000���� 
//	/*std::default_random_engine dre;
//	std::uniform_int_distribution<int> uid;
//
//	std::ofstream out("���� 1000����.txt",std::ios::binary);
//
//
//	int n;
//
//	for (int i = 0; i < size; ++i) {
//		n = uid(dre);
//		out.write((char*)&n, sizeof(n));
//	}
//
//	std::cout << "���Ͼ��� �Ϸ�!" << '\n';
//	*/
//
//
//	std::ifstream in("���� 1000����.txt", std::ios::binary);
//
//	// ���� �ʹ�Ŀ�� �迭�� �ȵǾ �����Ҵ��� �߽��ϴ�. ���� ���û���� ������ �� ������ ���ٸ��� �غ��ҽ��ϴ�.
//	int* data = new int[size];
//	in.read((char*)data, sizeof(int) * size);  //���� 1��
//	std::sort(data, data + size, [](int a, int b) {  //���� 2��
//		return a < b; });//�� ��° ���ڴ� �迭 ���ּҸ� �־����ϴ�. �����Ҵ��� ����ϴ� ������ begin�� end�� ����� �ȵǾ����ϴ�.
//
//	/*for (int i = 0; i < size; ++i)   //(Ȯ�ο�)��±��� �ð��� �ɸ����� ���ĵ� �� ��¿� �����߽��ϴ�.
//		std::cout << std::setw(20) << std::left << data[i];*/
//
//	std::ofstream out("���� 1000����.data", std::ios::binary);  //���� 1000���� ���� �Ǿ����ϴ�.
//	int n;
//
//	for (int i = 0; i < size; ++i) { //���۰� �����𸣴� ������� for���� ����� �Ͽ����ϴ�.
//		n = data[i];
//		out.write((char*)&n, sizeof(n)); //���� 3��
//	}
//
//	std::cout << "���Ͼ��� �Ϸ�!" << '\n';  //�ð��� �ɸ��� ������ �Ǿ����ϴ�.
//
//
//
//
//	delete[] data;
//}
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

//1�� ������ �ؼ� 100�� ¥��-----------------
//#include <iostream>
//#include <fstream>
//#include <algorithm>
//using namespace std;
//int n[1000'0000]; //���� ��������̴�. new�� �ſ� Ư���Ѱ� ���α׷� ȿ������ �����غ��� �� �����ִ°��� ����.
//int main()
//{
//	//���������� ���� 1mb�������ξ���. 
//	ifstream in("����1000����.data", ios::binary);
//	in.read((char*)&n, sizeof(int) * 1000'0000);
//	sort(begin(n), end(n), [](int a, int b) {
//		return a < b;
//		});
//
//	//for (int i = 0; i < 10; ++i) //�տ� 10�� ���
//	//	cout << n[i] << endl;
//	//for (int i = 1000'0000 - 10; i < 1000'0000; ++i) //�ڿ� 10��
//	//	cout << n[i] << endl;
//	
//	ofstream out("����1000��������.data", ios::binary);
//	out.write((char*)&n, sizeof(int) * 1000'0000);
//}
//-------------------

//1�� ������ �ؼ� �����Ҵ�ver-----------------
//ũ�⸦ �� �� ����. ������ ���߿� �� �� �ִ°��

//#include <iostream>
//#include <fstream>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//	ifstream in("����1000����.data", ios::binary);
//	int* p=new int[1000'0000];  //'[]'�迭��ȣ�� ���°��� �޸𸮰� ���������� �پ������� �ǹ��Ѵ�.
//	in.read((char*)p, sizeof(int) * 1000'0000);
//
//	//begin(p)�� ���� �ֳ��ϸ� ���⼭ p�� ��ǥ���� POD(Plain Old Data)Ÿ���� �����̴�. �� p���� �ʴ� ������ ����? �ϸ� ����� ���� ����.
//
//	//C++ �˰����� ����, �ݺ��� ����
//	sort(p, p + 1000'0000); //int�� ���������� ���� ���ʿ����.
//
//
//	
//	ofstream out("����1000��������.data", ios::binary);
//	out.write((char*)p, sizeof(int) * 1000'0000);
//}

/*
��������, ��(free store), ���������� �޸� �����ؼ� �˱�
���� �ӵ��� �ʿ��� �������� ����� ����ȵ� �����ϸ� �Ⱦ����ִ� ��Ȳ�� ����.
*/

//------------------------

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



//2�� ���� ���� �ؼ�
// const ����� �ǹ�

//2�� 2����
////���� 1��
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
	Array<int> a(10); //��Ÿ�Կ��� 10���ΰ��� ����

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
////���ø�
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
//	Array<string, 10> a;// �����ϴܰ迡�� a�� 10����� Ȯ���ϴ°��̴�.
//	for (int i = 0; i < 10; ++i)
//		a[i] = "string"s + to_string(i);
//
//	for (int i = 0; i < 10; ++i)
//		cout << a[i] << '\n';
//}



///�߰� ������ �����Ұ�
/*
��������,��������,���� �޸� ����
�Ҹ��ڿ��� ��? virtual�� �ٿ��� �ϳ�

*/

