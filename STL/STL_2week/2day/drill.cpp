#include <iostream>
#include <memory>
using namespace std;

class Dog {
	int n;
public:
	Dog() { cout <<this <<" 생성" << endl; }
	~Dog() { cout<<this << "소멸" << endl; }
	void show() {
		cout << "Dog입니다만" << endl;
	}
};


int main()
{
	{
		auto dog = make_unique<Dog>();
	}

	//문제2
	auto dogs = make_unique<Dog[]>(5);  
	//또는 아래와같이
	unique_ptr<Dog[]> dogs2{ new Dog[3] };
	
	Dog* p = new Dog[10];
	delete p;
}

//문제 1
/*unique_ptr<Dog> dogs{ new Dog[3] };
이 부분을 해결해야 된다.
이문제는 소멸이 dogs를 가리키는 첫주소를 먼저 해제하기때문에 그렇다. 
그러면 왜 첫주소를 먼저 해제시킬까?
문제 코드의 <>안을 보면 Dog만 되어있다. 생성은 되어도 소멸에서 문제가 발생한다.
소멸자에서 메모리 해제타입을 배열이 아닌 포인터가 가리키고있는 주소로 알고 있기에 발생한다. 따라서
<>안을 <Dog[]>이렇게 배열이라고 알려주어야 한다.
마치 Dog* p=new Dog[10]을 delete[] Dog로 해제하는것이 아니라 delete로만 해제하는것과 비슷하다.
*/


