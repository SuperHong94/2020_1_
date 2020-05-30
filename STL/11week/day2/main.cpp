/*
2020.5.29 �ݿ���
�˰��� ���⵵�� �������� �˾ƺ���.
�����̳��� ã�� �Ƿ��� �����غ���.
->ã�� ���� �ʿ��� ���Լ��� ȣ��Ƚ���� �Ƿ��� ���ؾ��Ѵ�.


*/

/*
O(n)�� �ִ� n������ ã�´�.


		O(n)  O(log n)  O(1)
1		1��       1      1
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
////using NUM = const int//�̰� �־ȵ���?
//
//const int NUM{ 10'000'000 };
//const int TNUM = 100'000;//ã�� ������ ����?
//
//int tnum[TNUM];	//ã�� ������ �����Ѵ�.
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
//		double d=nd(dre);  ////�̰��� -5~+5 
//
//
//		d=std::clamp(d, -5.0, 5.0); //d�� -5.0���� 5.0���� ������
//		d += 5.0; //[0,10]
//		d *= 100'0000;  //[0,1000'0000];
//
//		v.push_back(d);
//	}
//	//������ �ڷḦ �¿� �ִ´�.
//	/*set<int> s{ v.begin(),v.end()};
//	unordered_set<int> us{ v.begin(),v.end() };*/
//
//	//��ģ���鵵 1000����������
//	multiset<int> s{ v.begin(),v.end() };  //�����Ҷ� ���� �����ɸ�
//	unordered_multiset<int> us{ v.begin(),v.end() };
//
//	cout <<"������ ���� ��"<< v.size() << endl;
//	cout <<"���� ���� ��"<< s.size() << endl;
//	cout <<"������弼�� ���Ҽ�"<< us.size() << endl;
//
//
//	//ã�ƾ� �� ������ �����Ѵ�.
//	uniform_int_distribution uid;
//	for (int& n : tnum)  //&�� �ٿ����� 
//		n = uid(dre);
//
//
//
//
//
//	//���Ϳ��� ã�ƺ���.
//	{
//	//chrono::high_resolution_clock//�����е� Ŭ��
//	auto start = chrono::steady_clock::now();   //�ѹ� auto�� ���� ã�ƺ���
//	for (int n : tnum)   //��������
//		find(v.begin(), v.end(), n);//���ۺ��ͳ����� n�� �ִ��� ã����!
//	/*auto stop = chrono::steady_clock::now();
//	auto elapsedTime=stop - start;
//	auto dc=chrono::duration_cast<chrono::milliseconds>(elapsedTime);*/
//	cout <<"����- "<< chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start).count() << "�и��ʰ� �ɷȽ��ϴ�." << endl;
//	}
//
//	//�¿��� ã�ƺ���.
//	{
//		chrono::steady_clock::time_point start = chrono::steady_clock::now();
//		for (int n : tnum)
//			s.find(n);
//		cout<<"��-" << chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now() - start).count() << "�и��ʰ� �ɷȽ��ϴ�." << endl;
//	}
//
//	//�������¿��� ã�ƺ���.
//	{
//		auto start = chrono::steady_clock::now();
//		for (int n : tnum)
//			us.find(n);
//		cout <<"��������-"<< chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now() - start).count() << "�и��ʰ� �ɷȽ��ϴ�." << endl;
//	}
//}

//0274



////ȸ���� �󸶳� �ɸ���?
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
////using NUM = const int//�̰� �־ȵ���?
//
//const int NUM{ 1000 };
//const int TNUM = 1000;//ã�� ��ü�� ����?
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
//Test tnum[TNUM];	//ã�� Test�� �����Ѵ�.
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
//	cout << "������ ���� ��" << v.size() << endl;
//
//
//
//	//ã�ƾ� �� ������ �����Ѵ�.
//	uniform_int_distribution uid;
//	for (int i = 0; i < TNUM; ++i)
//		tnum[i] = v[i];
//
//
//
//
//	//���Ϳ��� ã�ƺ���.
//	{
//		equalCnt = 0;
//		
//		for (const Test& n : tnum)   // ��ü�϶��� const�� &���̴°��� ����ؾ��Ѵ�.
//			find(v.begin(), v.end(), n);//���ۺ��ͳ����� n�� �ִ��� ã����!  //��� ���ϴ��� Ƚ���� ����
//		cout << "==ȣ��Ƚ�� - " << equalCnt << endl;
//	}
//
//	multiset<Test> s{ v.begin(),v.end() };
//		//�¿��� ã�ƺ���.     (if (!(a<b)&&!(b<a)) ->�̰Ÿ� �Ȱ��ٰ� �Ǵ��Ѵ�.
//	{
//		equalCnt = 0;
//		lessCnt = 0;
//		for (const Test& n : tnum)   // ��ü�϶��� const�� &���̴°��� ����ؾ��Ѵ�.
//			s.find( n);//���ۺ��ͳ����� n�� �ִ��� ã����!  //��� ���ϴ��� Ƚ���� ����
//
//		cout << "<ȣ��Ƚ�� - " << lessCnt << endl;  //�����̰��� �Ⱦ��±���!
//	}
//
//}