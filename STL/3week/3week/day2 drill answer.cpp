//--------------------
//3�� 2����
#include <iostream>
#include <functional>
#include <memory>
using namespace std;

class Dog {
	int n;
public:
	Dog() { cout << this << " ����" << endl; }
	~Dog() { cout << this << "�Ҹ�" << endl; }
	void show() {
		cout << "Dog�Դϴٸ�" << endl;
	}
};


int main()
{
	
	//����
	unique_ptr<Dog, function<void(Dog*)>> dogs2{ new Dog[3],[](Dog* p) {
	delete[] p;
	} };

	//�� ������ ��Ʊ⿡ �̷��Ծ��°���
	unique_ptr<Dog[]> dogs2{ new Dog[3]};
}