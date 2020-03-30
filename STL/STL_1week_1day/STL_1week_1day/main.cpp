//#include <iostream>
//using namespace std;
//class X //Ŭ���� ����
//{
//public:
//	X(int a) :value(a)
//	{
//	}
//	~X() {};
//	friend ostream& operator<<(ostream& os, const X& x)
//	{
//		os << x.value;
//		return os;
//	}
//
//private:
//	int value;
//};
//
//
//
//void change(X& a, X& b); //�Լ� ����
//
//int main()
//{
//	X a{ 1 };
//	X b{ 2 };
//	change(a, b);
//	cout << a << ", " << b << endl;
//}
//
//void change(X& a, X& b) //�Լ� ����
//{
//	X temp = a;
//	a = b;
//	b = temp;
//}

//������ ��Ÿ��
//���߿��� ���尣���Ѱ��� �����ض�
#include <iostream>
using namespace std;
class X {
public:
	X(int n): n{n}{}
	
	/*friend ostream& operator<<(ostream* os, const X& x)�������Լ��� �����ѰŰ� �ۿ� �����ϴ� �����Լ��̴�. �׷��Ƿ�   �����Լ����Ǹ� Ŭ�������ο��� �ϸ� ��������.
	{
		os << x.n << endl;
		return os;
	}*/

	friend ostream& operator<<(ostream& os, const X& x);
	
private:
	int n;
};
void change(X&, X&);


ostream& operator<<(ostream& os, const X& x) //���Ǵ� �����Լ���
{ //�����Լ�
	os << x.n << endl;
	return os;
}
int main()
{
	X a{ 1 };  //���Ϲ��� �̴ϼȶ�����   X a{1}�� X a=1�� �ٸ���.
	X b{ 2 };
	change(a, b);
	cout << a << ", " << b << endl;
}

void change(X& a, X& b)
{
	X temp{ a }; //���������
	a = b;	   //���Կ�����.
	b = temp;
}