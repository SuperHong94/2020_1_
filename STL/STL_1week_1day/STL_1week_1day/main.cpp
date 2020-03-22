#include <iostream>
using namespace std;
class X //클래스 정의
{
public:
	X(int a) :value(a)
	{
	}
	~X() {};
	friend ostream& operator<<(ostream& os, const X& x)
	{
		os << x.value;
		return os;
	}

private:
	int value;
};



void change(X& a, X& b); //함수 선언

int main()
{
	X a{ 1 };
	X b{ 2 };
	change(a, b);
	cout << a << ", " << b << endl;
}

void change(X& a, X& b) //함수 정의
{
	X temp = a;
	a = b;
	b = temp;
}