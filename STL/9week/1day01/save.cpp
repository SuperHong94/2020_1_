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


	//char* p = new char[size]; //���ϰ� ���ϸ� ���뾲������!
	/*std::unique_ptr<char, std::function<void(char*)>> p(new char[size],
		[](char* p) {
			delete[] p;
		});*/
	std::unique_ptr<char[]> p(new char[size]);


	std::ifstream in(fname, std::ios::binary);
	in.read(p.get(), size);

	std::ofstream out("2020 STL ���� ����.txt", std::ios::binary | std::ios::app);
	auto tp = std::chrono::system_clock::now();  //��𼭺��� �󸶳�? 1970�� 1��1��(��ǻ�ͽð��� ���)
	auto ct = std::chrono::system_clock::to_time_t(tp);
	auto lt = localtime(&ct);  //9�ð� ���̳��� �ð����� �ٲ�
	out.imbue(std::locale("korean")); //imbue �� ���ִ°� �ð�, ��
	out << std::put_time(lt, "%c-(%A)") << std::endl;

	out.write(p.get(), size);

	/*std::unique_ptr<char, std::is_function<void(char*)>> p(new char[size], [](char* p) {delete[] p; });
	std::fstream in(fname);
	in.read(p.get(), size);
	std::ofstream out("2020 STL ȭ56rma 23 ��������.txt", std::ios::binary | std::ios::app);
	auto tp = std::chrono::system_clock::now();
	auto ct = std::chrono::system_clock::to_time_t(tp);
	auto it = localtime(&ct);

	out.imbue(std::locale("korean"));

	out << std::endl << std::endl << std::endl;
	out << "--------------------------------" << std::endl;
	out << std::put_time(it, "%c-(%A)") << std::endl;
	out << "���� ũ��-" << size << std::endl;
	out << "--------------------------------" << std::endl;
	out << std::endl;
	out.write(p, get(), size);*/
}