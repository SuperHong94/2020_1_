#include <iostream>
#include <string>
#include "String.h"
//#define ����
String::String()
{
#ifdef ����
	std::cout << "����Ʈ ������: ��ü-" << this << ",����-" << len << ",�޸�-" << static_cast<void*>(p) << std::endl;
#endif // ����

}

String::String(const char* s) //������
try :len{ strlen(s) }, p{ new char[len] }
{

#ifdef ����
	std::cout << "������(char*): ��ü-" << this << ", ����-" << len << ", �޸�-" << static_cast<void*>(p) << std::endl;
#endif // ����
	memcpy(p, s, len);

}
catch (const std::exception& e)
{
	std::cout << "String ����, �޸� ����-	" << e.what() << std::endl;
	throw e;
}

String::~String()
{
#ifdef ����
	std::cout << "�Ҹ���: ��ü-" << this << ", ����-" << len << ", �޸�-" << static_cast<void*>(p) << std::endl;
#endif
	if (p)
		delete[] p;
	len = 0;
}

String::String(const String& other)
try : len{ other.len }, p{ new char[len] } {
#ifdef ����
	std::cout << "���������: ��ü-" << this << ", ����-" << len << ", �޸�-" << static_cast<void*>(p) << std::endl;
#endif
	memcpy(p, other.p, len);
}
catch (std::exception& e) {
	std::cout << "String �������, �޸� ����-" << e.what() << std::endl;
	throw e;
}

String& String::operator=(const String& rhs)
try
{
	if (this != &rhs) {//�̰� ������
		len = rhs.len;
		p = new char[len];
		memcpy(p, rhs.p, len);
	}
#ifdef ����
	std::cout << "�Ҵ翬����: ��ü-" << this << ", ����-" << len << ", �޸�-" << static_cast<void*>(p) << std::endl;
#endif
	return *this;
}
catch (std::exception& e) {
	std::cout << "String �Ҵ翬����, �޸� ����-" << e.what() << std::endl;
}

String::String(String&& other) noexcept //noexcept��ߵǳ� �ٽú���
	:len{ other.len }, p{ other.p } //p=new char[len]�� �ƴϾ���
{
#ifdef ����
	std::cout << "�̵�������: ��ü-" << this << ", ����-" << len << ", �޸�-" << static_cast<void*>(p) << std::endl;
#endif
	other.len = 0;
	other.p = nullptr;
}

String& String::operator=(String&& rhs)noexcept
{
	if (this != &rhs) {
		if (p)//�̺κ� ���Ծ���
			delete p;
		len = rhs.len;
		p = rhs.p;
		rhs.len = 0;
#ifdef ����
		std::cout << "�̵��Ҵ翬����: ��ü-" << this << ", ����-" << len << ", �޸�-" << static_cast<void*>(p) << std::endl;
#endif
		rhs.p = nullptr;
	}
	return *this;
}

char& String::operator[](size_t idx)
{
	return p[idx];
}

char String::operator[](size_t idx)const {
	return p[idx];
}

size_t String::size() const
{
	return len;
}

std::string String::getString() const {
	return std::string(p, p + len);
}


std::ostream& operator<<(std::ostream& os, const String& s)
{
	/*for (int i = 0; i < s.len; ++i)
		os << s[i];*/
	os.write(s.p, s.len);
	return os;
}
std::istream& operator>>(std::istream& in, String& s)
{
	s = "";
	in >> std::ws;
	char ch = ' ';
	while (in.get(ch) && !isspace(ch))
		s += ch;

	/*char buffer[256];
	in >> buffer;
	s=String(buffer);*/

	return in;
}

bool String::operator==(const String& rhs)const noexcept {
	if (len == rhs.len) {
		for (int i = 0; i < len; ++i) {
			if (p[i] != rhs.p[i])
				return false;
		}
		return true;
	}
	return false;
}


//�ݺ��ڸ� ���� ��� �߰� 2020.4.25
String::iterator String::begin()
{
	return iterator(p);
}
String::iterator String::end()
{
	return iterator(p + len);
}

String::reverse_iterator String::rbegin()
{
	return reverse_iterator(p + len);
}

String::reverse_iterator String::rend()
{
	return reverse_iterator(p);
}


//20.5.4 �߰�
bool String::operator<(const String& rhs) const
{
	return getString() < rhs.getString();
}


String& String::operator+=(char c)
{

	char* temp = new char[len + 1];
	memcpy(temp, p, len);  //�����ӽð�ü�� �ֱ�
	temp[len] = c;
	len++;
	if (p)
		delete[] p;
	p = new char[len];
	memcpy(p, temp, len);
	delete[] temp;
	return *this;

}