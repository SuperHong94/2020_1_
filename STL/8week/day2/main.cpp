//�ڵ� 8-5: ��ȭ�� ����  ����Ʈ�� ����	C2676	���� '<': 'const _Ty'��(��) �� �����ڸ� �������� �ʰų� �̸� ���ǵ� �����ڿ� ���Ǵ� ���������� ��ȯ�� �������� �ʽ��ϴ�. ���ذ�!
//����� 3����
/*
1. less<String>�� �����Ѵ�.
2. ȣ�Ⱑ��Ÿ���� ���� �����Ѵ�.
3. String�� < �����ڸ� �����ε��Ѵ�.

*/
//#include <iostream>
//#include <map>
//#include "String.h"
//
//using namespace std;
//int main()
//{
//	map<String, String> movies;
//
//	movies.insert(make_pair("�͹̳�����2", "���ӽ� ī�޷�"));
//	movies.insert(movies.begin(), pair<String, String>("�μ���", "ũ�������� ���"));
//	
//	movies.emplace("�����", "����ȣ");
//	
//	movies["�������:�������"] = "�ȼҴ� ���, �� ���";
//	movies["ũ���������� �Ǹ�"] = "�� ��ư";
//	movies.insert_or_assign("�λ��� �Ƹ��ٿ�", "�κ����� ���ϴ�");
//	movies.try_emplace(movies.end(), "���ũ Ż��", "����ũ �ٶ�Ʈ");
//
//	for (auto [����, ����] : movies)
//		cout << ���� << " - " << ���� << endl;
//	
//	
//}


//1�� ���  less<String>�� �����Ѵ�.

//#include <iostream>
//#include <map>
//#include "String.h"
//
//using namespace std;
//
//template<>
//struct less<String>
//{
//	bool operator()(const String& a, const String& b)const {
//		return a.getString() < b.getString();
//	}
//};
//int main()
//{
//	map<String, String> movies;
//
//	movies.insert(make_pair("�͹̳�����2", "���ӽ� ī�޷�"));
//	movies.insert(movies.begin(), pair<String, String>("�μ���", "ũ�������� ���"));
//
//	movies.emplace("�����", "����ȣ");
//
//	movies["�������:�������"] = "�ȼҴ� ���, �� ���";
//	movies["ũ���������� �Ǹ�"] = "�� ��ư";
//	movies.insert_or_assign("�λ��� �Ƹ��ٿ�", "�κ����� ���ϴ�");
//	movies.try_emplace(movies.end(), "���ũ Ż��", "����ũ �ٶ�Ʈ");
//
//	for (auto [����, ����] : movies)
//		cout << ���� << " - " << ���� << endl;
//
//
//}

//2�� ���


//#include <iostream>
//#include <map>
//#include <functional> //����߰�
//#include "String.h"
//using namespace std;
//
//
//bool StringCmp(const String& a, const String& b) {
//	return a.getString() < b.getString();
//}
////bool StringCmp(const String& a, const String& b) {
////	return a.size() < b.size();
////}
//int main()
//{
//	map<String, String,function<bool(const String&,const String&)>> movies(StringCmp);
//
//	movies.insert(make_pair("�͹̳�����2", "���ӽ� ī�޷�"));
//	movies.insert(movies.begin(), pair<String, String>("�μ���", "ũ�������� ���"));
//	
//	movies.emplace("�����", "����ȣ");
//	
//	movies["�������:�������"] = "�ȼҴ� ���, �� ���";
//	movies["ũ���������� �Ǹ�"] = "�� ��ư";
//	movies.insert_or_assign("�λ��� �Ƹ��ٿ�", "�κ����� ���ϴ�");
//	movies.try_emplace(movies.end(), "���ũ Ż��", "����ũ �ٶ�Ʈ");
//
//	for (auto [����, ����] : movies)
//		cout << ���� << " - " << ���� << endl;
//	
//	
//}


//3��° ��� String�� < �����ڸ� ����
#include <iostream>
#include <map>
#include "String.h"

using namespace std;
int main()
{
	map<String, String> movies;

	movies.insert(make_pair("�͹̳�����2", "���ӽ� ī�޷�"));
	movies.insert(movies.begin(), pair<String, String>("�μ���", "ũ�������� ���"));
	
	movies.emplace("�����", "����ȣ");
	
	movies["�������:�������"] = "�ȼҴ� ���, �� ���";
	movies["ũ���������� �Ǹ�"] = "�� ��ư";
	movies.insert_or_assign("�λ��� �Ƹ��ٿ�", "�κ����� ���ϴ�");
	movies.try_emplace(movies.end(), "���ũ Ż��", "����ũ �ٶ�Ʈ");

	for (auto [����, ����] : movies)
		cout << ���� << " - " << ���� << endl;
	
	
}