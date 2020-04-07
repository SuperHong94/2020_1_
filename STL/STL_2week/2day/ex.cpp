//#include <iostream>
//using namespace std;
//
//void f(int n)
//{
//	cout << n << endl;
//}
//void f(double n)
//{
//	cout << n << endl;
//}
//int main()
//{
//	//f(1);//일반호출
//	//(*f)(2);//함수이름은 함수의 시작번지를 가리키는 포인터
//	//void* p = f((int)1); //함수의 시작번지를 포인터에 저장
//	void (*func)(int) = f;
//	f(555.111f);
//	func(55.111f);
//	//cout << "함수 f의 주소: " << p << endl;
//	int n{};
//	cout << "스택의 주소: " << &n << endl; //영역이 달라 주소가 많이 차이 날 것임
//
//	//(*(void(*)(int))p)(3);		//주소 p를 함수로 바꿔 인자 3으로 호출 
//}


//#include <iostream>	
//#include <cmath>
//#include <thread>
//using namespace std;
//
////sin곡선 출력
//int main()
//{
//	double rad{ 2 * 3.1416 };
//	int val;
//	int freq;
//	
//	cout << "주파수를 입려하세요(Hz) 추천값은 10 -";
//	cin >> freq;
//
//	double inc = 1. / freq;
//
//	while (true)
//	{
//		val = sin(rad) * 39 + 39;
//		for (int i = 0; i < val; ++i)
//			cout << ' ';
//		cout << '*' << endl;
//		rad += inc;
//		this_thread::sleep_for(33ms);
//	}
//}


//#include <iostream>
//using namespace std;
//
//void jump();
//void slide();
//void (*func1)() = jump;
//void (*func2)() = slide;
//
//int main()
//{
//	char key;
//	bool flag{ false };
//	while (true) {
//		cout << "a 나 d키를 누르세요 ";
//		cin >> key;
//		switch (key)
//		{
//		case 'a':
//			func1();
//			break;
//		case 'c':
//		{
//			auto temp{ func1 };
//			func1 = func2;
//			func2 = temp;
//		}
//		break;
//		case 'd':
//			func2();
//			break;
//		case 'q':
//			flag = false;
//			break;
//		default:
//			break;
//		}
//	}
//}
//
//void jump()
//{
//	cout << "점프" << endl;
//}
//
//void slide()
//{
//	cout << "슬라이드" << endl;
//}

//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//	auto a=[]() {
//		cout << "안녕";
//	};
//
//	a();
//}


//#include <iostream>
//#include <functional>
//using namespace std;
//
//void f(int n)
//{
//	cout << n << " 진짜 그냥 함수" << endl;
//
//}
//class Dog {
//public:
//	void operator()(int n)
//	{
//		cout << n << " funtion object" << endl;
//	}
//};
//
//void(*fp)(int) = f; //함수 포인터
//
//auto lambda = [](int n) {
//	cout << n << "- 이름 없는 함수 람다." << endl;
//};
//
//int main()
//{
//	function<void(int)> func;
//	cout << typeid(func).name() << endl;  //func는 function 객체이다.
//	
//	func = f;
//	func(1);
//
//	func = Dog();
//	func(2);
//
//	func = fp;
//	func(3);
//
//	func = lambda;
//	func(4);
//
//}


//#include <iostream>
//using namespace std;
//
//class Dog {
//	int n;
//public:
//	Dog() { cout << "생성" << endl; }
//	~Dog() { cout << "소멸" << endl; }
//	void show() {
//		cout << "Dog입니다만" << endl;
//	}
//};
//
//void f(Dog*);
//
//int main()
//{
//	Dog* p = new Dog;
//	p->show();
//	f(p);
//	delete p;
//}
//
//void f(Dog* pDog)
//{
//	pDog->show();
//	delete pDog;
//}

#include <iostream>
#include <memory>
using namespace std;

class Dog {
	int n;
public:
	Dog() { cout << "생성" << endl; }
	~Dog() { cout << "소멸" << endl; }
	void show() {
		cout << "Dog입니다만" << endl;
	}
};

void f(unique_ptr<Dog>);

int main()
{
	unique_ptr<Dog> p{ new Dog };
	p->show();
	cout << sizeof(p) << endl;
	f(move(p));
	//f(p);
	//delete p;
}

void f(unique_ptr<Dog> pDog)
{
	pDog->show();
}