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
//	//f(1);//�Ϲ�ȣ��
//	//(*f)(2);//�Լ��̸��� �Լ��� ���۹����� ����Ű�� ������
//	//void* p = f((int)1); //�Լ��� ���۹����� �����Ϳ� ����
//	void (*func)(int) = f;
//	f(555.111f);
//	func(55.111f);
//	//cout << "�Լ� f�� �ּ�: " << p << endl;
//	int n{};
//	cout << "������ �ּ�: " << &n << endl; //������ �޶� �ּҰ� ���� ���� �� ����
//
//	//(*(void(*)(int))p)(3);		//�ּ� p�� �Լ��� �ٲ� ���� 3���� ȣ�� 
//}


//#include <iostream>	
//#include <cmath>
//#include <thread>
//using namespace std;
//
////sin� ���
//int main()
//{
//	double rad{ 2 * 3.1416 };
//	int val;
//	int freq;
//	
//	cout << "���ļ��� �Է��ϼ���(Hz) ��õ���� 10 -";
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
//		cout << "a �� dŰ�� �������� ";
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
//	cout << "����" << endl;
//}
//
//void slide()
//{
//	cout << "�����̵�" << endl;
//}

//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//	auto a=[]() {
//		cout << "�ȳ�";
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
//	cout << n << " ��¥ �׳� �Լ�" << endl;
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
//void(*fp)(int) = f; //�Լ� ������
//
//auto lambda = [](int n) {
//	cout << n << "- �̸� ���� �Լ� ����." << endl;
//};
//
//int main()
//{
//	function<void(int)> func;
//	cout << typeid(func).name() << endl;  //func�� function ��ü�̴�.
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
//	Dog() { cout << "����" << endl; }
//	~Dog() { cout << "�Ҹ�" << endl; }
//	void show() {
//		cout << "Dog�Դϴٸ�" << endl;
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
	Dog() { cout << "����" << endl; }
	~Dog() { cout << "�Ҹ�" << endl; }
	void show() {
		cout << "Dog�Դϴٸ�" << endl;
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