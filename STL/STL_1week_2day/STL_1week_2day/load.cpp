#include <iostream>
#include <random>
#include <fstream>
using namespace std;
int main()
{
	ifstream in("����1000��.txt");
	int n{};
	int i{ 0 };
	int min = INT_MIN;
	while (in >> n){
		cout << ++i << "-" << n << endl;
		if (n > min)
			min = n;
	}
	cout << "�ִ밪: " << min << '\n';
}