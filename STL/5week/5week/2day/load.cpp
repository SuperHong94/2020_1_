//#include <iostream>
//#include <fstream>
//#include <random>
//#include <vector>
//using namespace std;
//
//int main()
//{
//	/*ofstream out("정수 만개");
//	default_random_engine dre;
//	uniform_int_distribution<> uid(0, 10'0000);
//	int num = 0;
//	for (int i = 0; i < 1'0000; ++i) {
//		int a = uid(dre);
//		out << a<<" ";
//		if (a >= 0 && a < 1'0000)
//			num+=1;
//		if (i % 10 == 9){
//			out << endl;
//		}
//	}
//	cout << num << endl;*/
//
//
//	ifstream in("정수 만개");
//	vector<int> v;
//	v.reserve(1'0000);
//	int value;
//	while (in >> value)
//		v.emplace_back(value);
//	
//	int num = count_if(v.begin(), v.end(), [](int i) {
//		return i >= 0 && i < 1'0000;
//		});
//	cout << num << endl;
//	
//	
//
//}