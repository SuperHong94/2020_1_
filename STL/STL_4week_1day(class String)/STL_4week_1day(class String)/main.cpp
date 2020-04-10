#include <iostream>
#include <string>
#include "String.h"

int main()
{
	String a[]{ "corona","virus","hate" };
	for (int i = 0; i < sizeof(a) / sizeof(String); ++i) {
		for (int j = 0; j < a[i].size(); ++j)
			std::cout << a[i][j] << ' ';
		std::cout << '\n';
	}
	/*String a{"abc" };
	for (int i = 0; i < a.size(); ++i)
		std::cout << a[i] << ' ';*/
	//std::cout << a << std::endl;
	std::cout << '\n';
}