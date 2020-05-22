///*
//20.5.22 금용일
//
////중간고사 답확인
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
//	ifstream in("중간시험정수.txt");
//	//1번답
//	vector<int> v{ istream_iterator<int>{in},{} };  //{}초기화자 리스트 //클래스도 이렇게 되는것처럼해보자.
//	cout << "읽은정수는-" << v.size() << endl;
//
//
//	// 2번 찾기실력
//	//const auto [min,max]=minmax_element(v.begin(),v.end())
//	//pair<vector<int>::iterator,vector<int>::iterator> [min,max]=minmax_element(v.begin(),v.end())
//	//auto p = minmax_element(v.begin(), v.end());
//
//	const auto [min, max] = minmax_element(v.begin(), v.end());
//	cout << *min << ' ' << *max;
//	cout << endl;
//
//
//	//3번 
//	long long sum = 0;
//	for (int n : v)
//		sum += n;
//	cout << "평균- " << (long long)((double)sum / v.size()) << endl;
//
//	//4번
//	/*정렬하면
//		1 2 3 4 5 5 6 7 8 이렇게됨*/
//		//set(중복안됨)에 넣어서 set이 거부하는곳을 찾는다.
//
//		//4-1 sort로 한다.
//		//sort(v.begin(), v.end());
//		///*for(int i=0;i<v.size()-1;++i)
//		//	if (v[i] == v[i + 1]) {
//		//		cout << "같은 값-" << v[i] << endl;
//		//		break;
//		//	}*/
//		//auto p = adjacent_find(v.begin(), v.end());
//		//cout << "같은 값-" << *p << endl;
//
//		//4-2 set을 사용
//	//set<int> s;
//	//for (int n : v) {
//	//	/*auto [위치, 성공여부] = s.insert(n);
//	//	if (성공여부 == false){
//	//		cout << "중복된 값-" << n << endl;
//	//		break;
//
//	//	}*/
//	//	if (!s.insert(n).second) {
//	//		cout << "중복된 값-" << n << endl;
//	//		break;
//	//	}
//	//}
//
//	//5번
//	//in.seekg(ios::beg); ///초기위치로
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
//	/*for (const auto [숫자, 개수] : m)
//		cout << 숫자 << ' ' << 개수 << endl;*/
//
//	//unoderedMap 가장빨리 찾는다.O(1)-> 메모리를 희생
//
//
//}