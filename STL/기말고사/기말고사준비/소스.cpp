//#include <iostream>
//#include <fstream>
//#include <string>
//#include <iterator>
//#include <vector>
//#include <algorithm>
//#include <set>
//#include <functional>
//
//using namespace std;
//
//bool comparWordLength(const string& a, const string& b) {
//	return a.size() < b.size();
//}
//
//
//int main()
//{
//	ifstream in{ "Frankenstein.txt" };
//	vector<string> v{ istream_iterator<string>{in},{} };
//
//	/*for (const auto& d : v)
//		cout << d << " " ;*/
//	cout << v.size() << endl;
//
//	size_t cnt = 0;
//	for (auto iter = v.begin(); iter != v.end()-1; ++iter) {
//		if (*iter == "i"&&*(iter+1)=="believe") {
//			cnt++;
//		}
//	}
//	cout << cnt << endl;
//
//	cout << v[0] << endl;
//	nth_element(v.begin(), v.begin() + 3, v.end(), [](const string& a, const string& b) {
//		return a.size() > b.size(); });
//	copy(v.begin(), v.begin() + 3, ostream_iterator<string>{cout,"\n"});
//
//
//	sort(v.begin(), v.end());
//	auto l=unique(v.begin(), v.end());
//	v.erase(l, v.end());
//
//
//	sort(v.begin(), v.end(), [](const string& a, const string& b){
//		return a.size() < b.size();
//		});
//	
//	stable_sort(v.begin(), v.end());
//	copy(v.begin(), v.end(), ostream_iterator<string>{cout, "\n"});
//	
//}