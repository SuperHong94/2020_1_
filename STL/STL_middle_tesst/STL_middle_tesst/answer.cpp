///*
//20.5.22 �ݿ���
//
////�߰���� ��Ȯ��
//
//*/
//
//#include <iostream>
//#include <fstream>
//#include <iterator>
//#include <vector>
//#include <algorithm>
//#include <string>
//#include <set>
//#include <map>
//using namespace std;
//
//int main()
//{
//	ifstream in("�߰���������.txt");
//	//1����
//	vector<int> v{ istream_iterator<int>{in},{} };  //{}�ʱ�ȭ�� ����Ʈ //Ŭ������ �̷��� �Ǵ°�ó���غ���.
//	cout << "����������-" << v.size() << endl;
//
//
//	// 2�� ã��Ƿ�
//	//const auto [min,max]=minmax_element(v.begin(),v.end())
//	//pair<vector<int>::iterator,vector<int>::iterator> [min,max]=minmax_element(v.begin(),v.end())
//	//auto p = minmax_element(v.begin(), v.end());
//
//	const auto [min, max] = minmax_element(v.begin(), v.end());
//	cout << *min << ' ' << *max;
//	cout << endl;
//
//
//	//3�� 
//	long long sum = 0;
//	for (int n : v)
//		sum += n;
//	cout << "���- " << (long long)((double)sum / v.size()) << endl;
//
//	//4��
//	/*�����ϸ�
//		1 2 3 4 5 5 6 7 8 �̷��Ե�*/
//		//set(�ߺ��ȵ�)�� �־ set�� �ź��ϴ°��� ã�´�.
//
//		//4-1 sort�� �Ѵ�.
//		//sort(v.begin(), v.end());
//		///*for(int i=0;i<v.size()-1;++i)
//		//	if (v[i] == v[i + 1]) {
//		//		cout << "���� ��-" << v[i] << endl;
//		//		break;
//		//	}*/
//		//auto p = adjacent_find(v.begin(), v.end());
//		//cout << "���� ��-" << *p << endl;
//
//		//4-2 set�� ���
//	//set<int> s;
//	//for (int n : v) {
//	//	/*auto [��ġ, ��������] = s.insert(n);
//	//	if (�������� == false){
//	//		cout << "�ߺ��� ��-" << n << endl;
//	//		break;
//
//	//	}*/
//	//	if (!s.insert(n).second) {
//	//		cout << "�ߺ��� ��-" << n << endl;
//	//		break;
//	//	}
//	//}
//
//	//5��
//	//in.seekg(ios::beg); ///�ʱ���ġ��
//	/*map<char, int> m;
//	char c;
//	while (in >> c) {
//		m[c]++;
//	}*/
//	//map<char, int> m;
//	int a[10]{};
//	string str;
//	for (int n : v) {
//		str = to_string(n);
//		for (char c : str)
//			a[c - '0']++;
//	}
//
//	for (int i = 0; i < 10; ++i)
//		cout << i << '-' << a[i] << endl;
//
//	/*for (const auto [����, ����] : m)
//		cout << ���� << ' ' << ���� << endl;*/
//
//	//unoderedMap ���廡�� ã�´�.O(1)-> �޸𸮸� ���
//
//
//}