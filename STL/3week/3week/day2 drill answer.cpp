//--------------------
//3주 2일차
#include <iostream>
#include <functional>
#include <memory>
using namespace std;

class Dog {
	int n;
public:
	Dog() { cout << this << " 생성" << endl; }
	~Dog() { cout << this << "소멸" << endl; }
	void show() {
		cout << "Dog입니다만" << endl;
	}
};


int main()
{
	
	//정답
	unique_ptr<Dog, function<void(Dog*)>> dogs2{ new Dog[3],[](Dog* p) {
	delete[] p;
	} };

	//위 문법이 어렵기에 이렇게쓰는거임
	unique_ptr<Dog[]> dogs2{ new Dog[3]};
}