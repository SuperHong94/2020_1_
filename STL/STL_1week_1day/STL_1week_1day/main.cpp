#include <iostream>
using namespace std;
class X //Ŭ���� ����
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



void change(X& a, X& b); //�Լ� ����

int main()
{
	X a{ 1 };
	X b{ 2 };
	change(a, b);
	cout << a << ", " << b << endl;
}

void change(X& a, X& b) //�Լ� ����
{
	X temp = a;
	a = b;
	b = temp;
}