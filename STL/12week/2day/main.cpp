/*
const vs constexpr

constexpr ���ϰ��� ������ Ÿ�ӿ� ������ �� �־� ������ ���¿��� ����� �� �� �ִ�.

print->find->find_if->copy
//4�� 26�� �������뿡 �ݺ��� ���� ��������
*/

//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <iterator>
//#include "String.h"
//using namespace std;
//
//template<class Init, class Pre>
//bool my_all_of(Init b, Init e, Pre p)
//{
//	//���� �˻��� ������ ���Ҵٸ�
//		//b�� ����Ű�� �ִ� ���� ������ �����ϴ��� p���� �����.
//	/*for (; b != e; ++b)
//		if (!p(*b))
//			return false;
//	return true;*/
//	/*while (b != e) {
//		if (!p(*b))
//			return false;
//		++b;
//	}
//	return true;*/
//	for (; b != e; ++b)
//		if (!(p(*b)))
//			return false;
//	return true;
//}
//
//
//template <class InIt, class OutIt>
//OutIt my_copy(InIt b, InIt e, OutIt d)  //��ǲ�� ������ͷ�����
//{
//	/*while (b != e){
//		*d++=*b++;
//	}
//	return d;*/
//	for (; b != e; ++b, ++d)
//		*d = *b;  // ==d.operator*() = b.operator*(); �ٽ� ���۷����Ͱ� �Լ��ϱ� ���� ����� �� �� �־�!
//	
//
//	//d.operator*() { //�� ����
//	//	v2.push_back(*b);
//	//}
//	return d;
//}
//



//int main()
//{
//	//vector<int> v{ 2,4,6,-8,0,10};
//	////v�� ��� Ȧ������ �˰� �ʹ�.
//	//auto p = find_if(v.begin(), v.end(), [](int n) {return 7 < n; });
//	//cout<<"7���� ū ������ ��ġ��: "<<p-v.begin()<<endl;
//	//bool result=my_all_of(v.begin(), v.end(), [](int n) {
//	//	return n & 1;
//	//	});
//	//cout << "v�� ��� ���Ұ� Ȧ���ΰ�? " << boolalpha << result << endl;
//
//	//search end���� �Ǵµ�
//	//��ġ�� find�� ���̴� ������ ����
//	/*vector<int> v{ 1,3,5,7,9,1,3,5,7,9,5,7,9,7,8 };
//	int a[]={5, 7, 9};
//	auto p=search(v.begin(), v.end(), begin(a), end(a));
//	cout << distance(v.begin(), p) << endl;*/
//	//������ ã������ Search�� ã��!
//
//
//	/*vector<int> v{ 1,3,5,7,9,1,3,5,7,9,5,7,9,7,8 };
//	int a[] = { 2,4,6,8 };
//	auto p = find_first_of(v.begin(), v.end(), begin(a), end(a));
//	cout << distance(v.begin(), p) << endl;*/
//
//
//	//copy
//	//vector<int> v{ 1,2,3,4,5,6,7,8,9,10 };
//
//	//v�� ��� ���Ҹ� �ٸ� ���� v2�� copy�϶�
//	//vector<int> v2(10);
//	//v2.reserve(v.size());
//	//copy(v.begin(), v.end(), v2.begin());
//	///*for (int n : v2)
//	//	cout << n << ' ';*/
//	//for (int i = 0; i < 10; ++i)
//	//	cout << v2[i] << endl;
//	//cout << endl;
//
//
//	//�̰��� �������α׷��ϱ�?
//	//vector<int> v2(10);
//	//copy(v.begin(), v.end(), v2.begin());
//	//for (int i = 0; i < 10; ++i)
//	//	cout << v2[i] << endl;
//	//cout << endl;
//
//	//�ذ���
//	//vector<int> v2;
//	//v2.reserve(v.size());
//	////copy(v.begin(), v.end(), v2.begin());
//	//copy(v.begin(), v.end(), back_inserter(v2)); 
//	//for (int i = 0; i < 10; ++i)
//	//	cout << v2[i] << endl;
//	//cout << endl;
//
//
//	//myCopy �غ���
//	vector<int> v{ 1,2,3,4,5,6,7,8,9,10 };
//	vector<int> v2;
//	my_copy(v.begin(), v.end(), back_inserter(v2));
//	my_copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
//	cout << endl;
//
//	//copy(v.begin(), v.end(), v2.begin());
//
//}


//template<class T>
//T add(T v1, T v2)
//{
//	//T�� ���� �� �ֱ�� �ұ�?  ���ø����󿡼��� �Լ��� ���� ���޵��� ���� ���Ҽ��ִ� ������ �����ؾߵ�
//	//Ÿ���� ���ǿ� �´��� �˻��� ���� �ʹ�. 
//	//���� �� �ֳ�?
//	cout << is_arithmetic<T>() << endl; //���� �� ������(������갡������ ���) true 1�� ���´�.
//	return v1 + v2;
//}
//
//class Dog
//{
//
//};
//int main()
//{
//	/*String s{ "ascadsafg" };
//
//	String s2;
//	s2.reserve(s.size());
//	my_copy(s.begin(), s.end(),back_inserter(s2));*/
//	//my_copy(s.begin(), s.end(), ostream_iterator<char>(cout, " - "));
//
//	//copy�� ������ ����?
//	//vector<int> v{ 1,2,3,4,5,6,8,9,10 };
//	//copy(++v.begin(), --v.end(), v.begin());
//
//	//for (int i = 0; i < v.size(); ++i)
//	//	cout << v[i] << ' ';
//
//
//	//���� 
//	cout<<add(1, 2) << endl; //3
//	//add<const char*>("1", "2");
//	//add(Dog(), Dog());
//	cout << add<string>("1"s, "2"s) << endl;//12
//
//}