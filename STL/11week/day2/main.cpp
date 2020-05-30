/*
2020.5.29 금요일
알고리즘 복잡도란 무엇인지 알아본다.
컨테이너의 찾기 실력을 검증해본다.
->찾기 위해 필요한 비교함수의 호출횟수로 실력을 비교해야한다.


*/

/*
O(n)은 최대 n번까지 찾는다.


		O(n)  O(log n)  O(1)
1		1번       1      1
100     100       7      1  
10000   10000     13     1
1000000 1000000   30     1

*/


//#include <iostream>
//#include <random>
//#include <iterator>
//#include <vector>
//#include <set>
//#include  <chrono>
//#include <unordered_set>
//#include <algorithm>
//using namespace std;
//
////using NUM = const int//이거 왜안되지?
//
//const int NUM{ 10'000'000 };
//const int TNUM = 100'000;//찾을 정수의 개수?
//
//int tnum[TNUM];	//찾을 정수를 저장한다.
//
//
//default_random_engine dre;
//normal_distribution<> nd{0.0,1.0};    //[-5,5]
//
//int main()
//{
//	vector<int> v;
//	v.reserve(NUM);
//	for (int i = 0; i < NUM; ++i){
//		double d=nd(dre);  ////이값은 -5~+5 
//
//
//		d=std::clamp(d, -5.0, 5.0); //d를 -5.0에서 5.0으로 묶어줘
//		d += 5.0; //[0,10]
//		d *= 100'0000;  //[0,1000'0000];
//
//		v.push_back(d);
//	}
//	//벡터의 자료를 셋에 넣는다.
//	/*set<int> s{ v.begin(),v.end()};
//	unordered_set<int> us{ v.begin(),v.end() };*/
//
//	//이친구들도 1000만개만들자
//	multiset<int> s{ v.begin(),v.end() };  //삽입할때 가장 오래걸림
//	unordered_multiset<int> us{ v.begin(),v.end() };
//
//	cout <<"벡터의 원소 수"<< v.size() << endl;
//	cout <<"셋의 원소 수"<< s.size() << endl;
//	cout <<"언오더드세의 원소수"<< us.size() << endl;
//
//
//	//찾아야 할 정수를 생성한다.
//	uniform_int_distribution uid;
//	for (int& n : tnum)  //&를 붙여야지 
//		n = uid(dre);
//
//
//
//
//
//	//벡터에서 찾아본다.
//	{
//	//chrono::high_resolution_clock//고정밀도 클럭
//	auto start = chrono::steady_clock::now();   //한번 auto가 몬지 찾아보자
//	for (int n : tnum)   //조단위번
//		find(v.begin(), v.end(), n);//시작부터끝까지 n이 있는지 찾아줘!
//	/*auto stop = chrono::steady_clock::now();
//	auto elapsedTime=stop - start;
//	auto dc=chrono::duration_cast<chrono::milliseconds>(elapsedTime);*/
//	cout <<"벡터- "<< chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start).count() << "밀리초가 걸렸습니다." << endl;
//	}
//
//	//셋에서 찾아본다.
//	{
//		chrono::steady_clock::time_point start = chrono::steady_clock::now();
//		for (int n : tnum)
//			s.find(n);
//		cout<<"셋-" << chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now() - start).count() << "밀리초가 걸렸습니다." << endl;
//	}
//
//	//언오더드셋에서 찾아본다.
//	{
//		auto start = chrono::steady_clock::now();
//		for (int n : tnum)
//			us.find(n);
//		cout <<"언오더드셋-"<< chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now() - start).count() << "밀리초가 걸렸습니다." << endl;
//	}
//}

//0274



////회수가 얼마나 걸리니?
//#include <iostream>
//#include <random>
//#include <iterator>
//#include <vector>
//#include <set>
//#include  <chrono>
//#include <unordered_set>
//#include <algorithm>
//using namespace std;
//
////using NUM = const int//이거 왜안되지?
//
//const int NUM{ 1000 };
//const int TNUM = 1000;//찾을 객체의 개수?
//
//default_random_engine dre;
//normal_distribution<> nd{ 0.0,1.0 };    //[-5,5]
//int equalCnt = 0;
//int lessCnt{ 0 };
//class Test {
//
//	int n;
//public:
//	Test() = default;
//	Test(int n):n{n}{}
//
//	void setN(int num) { n = num; }
//
//
//	bool operator==(const Test& rhs) const{
//		equalCnt++;
//		return n == rhs.n;
//	}
//	bool operator<(const Test& rhs)const {
//		lessCnt++;
//		return n < rhs.n;
//	}
//
//
//};
//
//Test tnum[TNUM];	//찾을 Test를 저장한다.
//
//
//int main()
//{
//	vector<Test> v;
//	v.reserve(NUM);
//	for (int i = 0; i < NUM; ++i) {
//	
//		v.emplace_back(i);
//	}
//
//	cout << "벡터의 원소 수" << v.size() << endl;
//
//
//
//	//찾아야 할 정수를 생성한다.
//	uniform_int_distribution uid;
//	for (int i = 0; i < TNUM; ++i)
//		tnum[i] = v[i];
//
//
//
//
//	//벡터에서 찾아본다.
//	{
//		equalCnt = 0;
//		
//		for (const Test& n : tnum)   // 객체일때는 const와 &붙이는것을 고려해야한다.
//			find(v.begin(), v.end(), n);//시작부터끝까지 n이 있는지 찾아줘!  //몇번 비교하는지 횟수를 센다
//		cout << "==호출횟수 - " << equalCnt << endl;
//	}
//
//	multiset<Test> s{ v.begin(),v.end() };
//		//셋에서 찾아본다.     (if (!(a<b)&&!(b<a)) ->이거면 똑같다고 판단한다.
//	{
//		equalCnt = 0;
//		lessCnt = 0;
//		for (const Test& n : tnum)   // 객체일때는 const와 &붙이는것을 고려해야한다.
//			s.find( n);//시작부터끝까지 n이 있는지 찾아줘!  //몇번 비교하는지 횟수를 센다
//
//		cout << "<호출횟수 - " << lessCnt << endl;  //셋은이것을 안쓰는구나!
//	}
//
//}