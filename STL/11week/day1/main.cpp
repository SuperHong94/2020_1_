//////------------------
/////*
////2020 5 26 ȭ����
////
////unordered_set/map
////1. ������ ���ٴ� �ǹ̴�?
////2. �޸� ������ ȭ�鿡 ����� ����.
////3.String�� �������� �����̳��� ���Ұ� �Ƿ���? ���ø� Ư��ȭ
////
////�����̳��� ã�� �Ƿ��� ������ ����.
////*/
//////-----------------
//////
////#include <iostream>  
////#include <unordered_set>      //order ����(��������)  unorder ������ ����.
////
////using namespace std;
////
////int main()
////{
////	hash<int> a;
////	std::cout << a.operator()(5) << std::endl; //operator() ȣ�Ⱑ���ϴ� 
////	std::cout << a(6) << std::endl;  // a.operator()(6)�̰ſ� ����.
////	cout << hash<int>()(5) << std::endl;
////}
//
////
//////unordered_set
////#include <iostream>  
////#include <unordered_set>      //order ����(��������)  unorder ������ ����.
////#include <thread>
////#include <string>
////using namespace std;
////
////int main()
////{
//	//initializer_list<int> t = { 1, 2, 3, 4, 5, 6, 7, 8 };  //t�� initializer_list<int> �ʱ�ȭ�� ��� ���Ұ� ����� �𸦶� ����Ѵ�.				
//	//unordered_set<int> us = { t };
//	//unordered_set<int> us{ 1, 2, 3, 4, 5, 6, 7, 8 };
//
//	//cout << "��Ŷ�� ����" << us.bucket_count() << "- ";
//	//for (int i : us)
//	//	cout<< i << " ";
//	//cout << endl;
//
//	////�����߰�
//	//us.insert(9);
//
//	//cout << "��Ŷ�� ����" << us.bucket_count() << "- ";
//	//for (int i : us)
//	//	cout << i << " ";
//	//cout << endl;
//
//	//
//	//int n{ 9 };
//	//while (true) {
//	//	cout << "��Ŷ�� ����" << us.bucket_count() << "- ";
//	//	for (int i : us)
//	//		cout<< i << " ";
//	//	cout << endl;
//
//	//	//�����߰�
//	//	us.insert(n+=7);  //���ڱ� ������ ��ȯ��?
//	//	this_thread::sleep_for(200ms);
//
//	//}
////
////	unordered_set<int> us{ 1,2,3,4,5,6,7,8 };
////	for (int i = 0; i < us.bucket_count(); ++i) {
////		cout << "[" << i << "] ";
////		if (us.bucket_size(i)) {//i���� ��Ŷ���� �����ִ�?
////			for (auto p = us.begin(i); p != us.end(i); ++p)//i��° �ݺ���
////				cout << "--->" << *p;
////			cout << endl;
////		}
////		else
////			cout << endl;
////	}
////
//
//
////	//��Ƽ��
//	//unordered_multiset<int> us{ 1,2,3,4,4,4,7,8,4};
//
//	//cout <<"���� 4���� �־�� �� ��Ŷ-"<< hash<int>()(4) % 64 << endl;
//	//for (int i = 0; i < us.bucket_count(); ++i) {
//	//	cout << "[" << i << "] ";
//	//	if (us.bucket_size(i)) {//i���� ��Ŷ���� �����ִ�?
//	//		for (auto p = us.begin(i); p != us.end(i); ++p)//i��° �ݺ���
//	//			cout << "--->" << *p;
//	//		
//	//	}
//	//	cout << endl;
//	//}
////	unordered_multiset<string> us{ "����","����","����","����","��ƴ޶�" };
////
////	for (int i = 0; i < us.bucket_count(); ++i) {
////		cout << "[" << i << "] ";
////		if (us.bucket_size(i)) {//i���� ��Ŷ���� �����ִ�?
////			for (auto p = us.begin(i); p != us.end(i); ++p)//i��° �ݺ���
////				cout << "--->" << *p;
////
////		}
////		cout << endl;
////	}
////	/*
////	�ؽ����鶧 �߿����� ���� bucket_count�� �ø�����?
////	*/
////}
//
//
////String���� ����.
////���2����
///*
// Ư��ȭ
// funtion() ���
//*/
//#include <iostream>
//#include <unordered_set>
//#include <string>	
//#include "String.h"
//using namespace std;
////
//////Ư��ȭ
//template<>
//struct hash<String> {
//	size_t operator()(const String& s) const {
//		return hash<string>()(s.getString());
//	}
//};
////
////int main() {
////	unordered_multiset<String> us{ "����","����","����","����","��ƴ޶�" };
////	//set<String> us{ "����","����","����","����","��ƴ޶�" };
////
////	for (int i = 0; i < us.bucket_count(); ++i) {
////		cout << "[" << i << "] ";
////		if (us.bucket_size(i)) {//i���� ��Ŷ���� �����ִ�?
////			for (auto p = us.begin(i); p != us.end(i); ++p)//i��° �ݺ���
////				cout << "--->" << *p;
////
////		}
////		cout << endl;
////	}
////
////}
//
//
////ã��
////int main() {
////	unordered_multiset<String> us{ "����","����","����","����","��ƴ޶�" };
////	//�������� ���� ã�Ƶ帳�ϴ�.
////	String a = "�Ƹ���";
////	std::cout << a << std::endl;
////	while (true) {
////		cout << "ã�� ���Ҹ� �Է��ϼ���: ";
////		/*string s;
////		cin >> s;
////		String S(s.c_str());*/
////		String s;
////		cin >> s;
////		std::cout << s << std::endl;
////
////		if (us.find(s) != us.end()) {
////			cout << s << "�� ã�ҽ��ϴ�." << endl;
////		}
////		else {
////			cout << "�׷� ���Ҵ� �����!" << endl;
////		}
////	}
////}
//
//
//
////���� NUM���� �����Ѵ�. -���Ժ���[0~1000'0000]�� ����  ����� 500��
//
////����
////��
////��������
//
//#include <iostream>
//#include <random>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
////using NUM = const int//�̰� �־ȵ���?
//
//const int NUM{ 1000'0000 };
//
//default_random_engine dre;
//normal_distribution<> nd{0.0,1.0};    //[-5,5]
//
//int main()
//{
//	vector<int> v;
//	v.reserve(NUM);
//	for (int i = 0; i < NUM; ++i){
//		double d=nd(dre);  ////�̰��� -5~+5 
//
//		//Ŭ����--------
//		/*if (d < -5.0)
//			d = 5.0f;
//		if (5.0f < d)
//			d = 5.0;*/
//		//----------
//		//[-5.0,5.0]
//		d=clamp(d, -5.0, 5.0); //d�� -5.0���� 5.0���� ������
//		d += 5.0; //[0,10]
//		//d *= 100'0000;  //[0,1000'0000];
//
//		v.push_back(d);
//	}
//
//	for (auto d : v)
//		cout << d <<' ';
//
//
//}