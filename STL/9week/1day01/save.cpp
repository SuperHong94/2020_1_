#include <iostream>
#include <string>
#include <fstream>
#include <memory>
#include <functional>
#include <chrono>
#include <filesystem>
#include "save.h"
void save(std::string_view fname)
{
	size_t size = std::filesystem::file_size(fname);


	//char* p = new char[size]; //심하게 말하면 절대쓰지마라!
	/*std::unique_ptr<char, std::function<void(char*)>> p(new char[size],
		[](char* p) {
			delete[] p;
		});*/
	std::unique_ptr<char[]> p(new char[size]);


	std::ifstream in(fname, std::ios::binary);
	in.read(p.get(), size);

	std::ofstream out("2020 STL 강의 저장.txt", std::ios::binary | std::ios::app);
	auto tp = std::chrono::system_clock::now();  //어디서부터 얼마나? 1970년 1월1일(컴퓨터시간의 기원)
	auto ct = std::chrono::system_clock::to_time_t(tp);
	auto lt = localtime(&ct);  //9시간 차이나는 시간으로 바꿈
	out.imbue(std::locale("korean")); //imbue 쓸 수있는거 시간, 돈
	out << std::put_time(lt, "%c-(%A)") << std::endl;

	out.write(p.get(), size);

	/*std::unique_ptr<char, std::is_function<void(char*)>> p(new char[size], [](char* p) {delete[] p; });
	std::fstream in(fname);
	in.read(p.get(), size);
	std::ofstream out("2020 STL 화56rma 23 강의저장.txt", std::ios::binary | std::ios::app);
	auto tp = std::chrono::system_clock::now();
	auto ct = std::chrono::system_clock::to_time_t(tp);
	auto it = localtime(&ct);

	out.imbue(std::locale("korean"));

	out << std::endl << std::endl << std::endl;
	out << "--------------------------------" << std::endl;
	out << std::put_time(it, "%c-(%A)") << std::endl;
	out << "파일 크기-" << size << std::endl;
	out << "--------------------------------" << std::endl;
	out << std::endl;
	out.write(p, get(), size);*/
}