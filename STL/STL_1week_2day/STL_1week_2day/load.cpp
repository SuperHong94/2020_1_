#include <iostream>
#include <random>
#include <fstream>
using namespace std;
int main()
{
	ifstream in("정수1000개.txt");
	int n{};
	int i{ 0 };
	int min = INT_MIN;
	while (in >> n){
		cout << ++i << "-" << n << endl;
		if (n > min)
			min = n;
	}
	cout << "최대값: " << min << '\n';
}