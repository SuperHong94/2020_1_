#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <array>
#include <vector>
#include <filesystem>
#include <algorithm>
#include <map>
using namespace std;

class Name {
	string first{};
	string last{};
public:
	Name() = default;
	Name(string f, string l) :first{ f }, last{ l }{}
	string& getFirst() {
		return first;
	}
	string getFirst() const {
		return first;
	}
	string getLast()const {
		return last;
	}
	void setLast(const string& name) {
		last = name;
	}
	void show()const {
		cout << first << " " << last << endl;
	}
};

string file1{ "고객1.txt" }, file2{ "고객2.txt" };
void makeData();

int main()
{
	//makeData();
	ifstream in(file1);
	if (!in) cout << "파일읽기 실패" << endl;
	//size_t fsize = filesystem::file_size(file1);
	vector<Name> v;
	v.reserve(10);
	string a;
	string b;
	//in.read((char*)v.data(), sizeof(Name) * 10000);
	for (int i = 0; i < 10000; ++i) {
		in >> a;
		in >> b;
		v.emplace_back(Name(a, b));
	}
	/*
	int searchCount = 0;
	for (const auto& d : v) {
		if (d.getLast() == "kim") {
			d.show();
			searchCount++;
		}
	}
	if (searchCount == 0)
		cout << "몾찾음" << endl;
	for (int i = 0; i < 10; ++i)
		v[i].show();*/
		/*sort(v.begin(), v.end(), [](const Name& a, const Name& b) {
			return a.getFirst() < b.getFirst();
			});
		for (const auto& d : v)
			d.show();*/

	map<string, Name> sum12;
	for (const auto& d : v)
		sum12.insert(make_pair(d.getLast(), d));
	ifstream in2(file2);
	vector<Name> v2;
	v2.reserve(2'0000);
	for (int i = 0; i < 20000; ++i)
	{
		in >> a;
		in >> b;
		v2.emplace_back(Name(a, b));
	}
	for (const auto& d : v2)
		sum12.insert(make_pair(d.getLast(), d));

	for (const auto& d : sum12)
	{
		cout << d.first<<'-';
		d.second.show();
	}

	int searchCount = 0;
	for (const auto& d : sum12) {
		if (d.second.getLast() == "kim") {
			d.second.show();
			searchCount++;
		}
	}
	if (searchCount == 0)
		cout << "몾찾음" << endl;
}
void makeData()
{
	ofstream out1(file1);
	ofstream out2(file2);
	default_random_engine dre;
	uniform_int_distribution<> uiNameLen(3, 12);
	uniform_int_distribution<> uiName('a', 'z');

	for (int i = 0; i < 1'0000; ++i) {
		string first;
		for (int i = 0; i < uiNameLen(dre); ++i)
			first += uiName(dre);
		string second;
		for (int i = 0; i < 3; ++i)
			second += uiName(dre);
		Name name(first, second);
		out1 << name.getFirst() << '\t' << name.getLast() << endl;
	}

	for (int i = 0; i < 2'0000; ++i) {
		string first;
		for (int i = 0; i < uiNameLen(dre); ++i)
			first += uiName(dre);
		string second;
		for (int i = 0; i < 3; ++i)
			second += uiName(dre);
		Name name(first, second);
		out2 << name.getFirst() << '\t' << name.getLast() << endl;
	}
}