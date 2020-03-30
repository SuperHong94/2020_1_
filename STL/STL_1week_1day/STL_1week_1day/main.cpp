//#include <iostream>
//using namespace std;
//class X //클래스 정의
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
//void change(X& a, X& b); //함수 선언
//
//int main()
//{
//	X a{ 1 };
//	X b{ 2 };
//	change(a, b);
//	cout << a << ", " << b << endl;
//}
//
//void change(X& a, X& b) //함수 정의
//{
//	X temp = a;
//	a = b;
//	b = temp;
//}

//교수님 스타일
//답중에서 가장간결한것을 선택해라
#include <iostream>
using namespace std;
class X {
public:
	X(int n): n{n}{}
	
	/*friend ostream& operator<<(ostream* os, const X& x)프랜드함수는 선언만한거고 밖에 존재하는 전역함수이다. 그러므로   여기함수정의를 클래스내부에서 하면 난샌스다.
	{
		os << x.n << endl;
		return os;
	}*/

	friend ostream& operator<<(ostream& os, const X& x);
	
private:
	int n;
};
void change(X&, X&);


ostream& operator<<(ostream& os, const X& x) //정의는 전역함수로
{ //전역함수
	os << x.n << endl;
	return os;
}
int main()
{
	X a{ 1 };  //유니버셜 이니셜라이저   X a{1}과 X a=1과 다르다.
	X b{ 2 };
	change(a, b);
	cout << a << ", " << b << endl;
}

void change(X& a, X& b)
{
	X temp{ a }; //복사생성자
	a = b;	   //대입연산자.
	b = temp;
}