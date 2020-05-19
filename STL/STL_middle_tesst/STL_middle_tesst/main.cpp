#include <iostream>
#include <fstream>
#include <string>	
#include <vector>
#include <filesystem>
#include <algorithm>
#include <numeric>
using namespace std;

string file("중간시험정수.txt");
int main()
{
	//size_t fsize=std::filesystem::file_size(file);
	ifstream in(file);
	if (!in) cout << "파일 열기 실패" << endl;
	int cnt = 0;
	string a;

	vector<int > v;
	int value = 0;
	v.reserve(20000);
	while (in) {
		in >> value;
		// << value << endl;
		cnt++;
		if (value != EOF)
			v.emplace_back(value);
	}
	cout << v.size() << endl;
	//v.resize(156782);
	//in.read((char*)v.data(), sizeof(int) * (156782));
	//cout << cnt - 1;
	//cout << cnt-1;
	//v.resize(15678);
	//in.read((char*)v.data(), sizeof(int) * (15678));
	//for (const auto& d : v)
	//	cout << d << endl;

	//cout << v.capacity();
	const auto [min, max] = minmax_element(begin(v), end(v));
	cout << *min << ' ' << *max << endl;

	long long result = 0;
	for (int i = 0; i < v.size() - 1; ++i)
		result += v[i];
	cout << result / v.size() - 1 << endl;
}