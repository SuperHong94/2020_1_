#pragma once

//String.h�� class String �տ� class String_Iterator �߰�
class String_Iterator {
	char* p{ nullptr };
public:
	String_Iterator(char* p) :p{ p } {};
	bool operator != (const String_Iterator& rhs)const {
		return p != rhs.p;
	}
	String_Iterator& operator++() {
		++p;
		return *this;
	}

	//char operator*() {  //�̰���
	//	return *p;
	//}
	char& operator*() const {  //�̰����� �ٲٴϱ� �ߵ˴ϴ�.
		return *p;
	}

	ptrdiff_t operator-(const String_Iterator rhs) const {
		return p - rhs.p;
	}

	bool operator<(const String_Iterator& rhs) const { return p < rhs.p; }
	bool operator>(const String_Iterator& rhs) const { return p < rhs.p; }
	bool operator<=(const String_Iterator& rhs) const { return p <= rhs.p; }
	bool operator>=(const String_Iterator& rhs) const { return p >= rhs.p; }
	bool operator==(const String_Iterator& rhs) const { return p == rhs.p; }
	String_Iterator operator+(ptrdiff_t rhs)const { return p + rhs; };
	String_Iterator operator-(ptrdiff_t rhs)const { return p - rhs; };
	String_Iterator& operator--() {--p; return *this; };
};

//String�� iterator_traits Ŭ������ " ���� �ݺ����̰� ���� �����ݺ����Դϴ�. " ��� �ڽ��� ������ ���
template<>
struct std::iterator_traits<String_Iterator> {
	using iterator_category = random_access_iterator_tag;
	using value_type = char;
	using difference_type = ptrdiff_t;
	using pointer = char*;
	using reference = char&;
};

class String_Reverse_Iterator {
	char* p{ nullptr };
public:
	String_Reverse_Iterator(char* p) :p{ p } {};
	bool operator!=(const String_Reverse_Iterator& rhs) const {
		return p != rhs.p;
	}
	String_Reverse_Iterator& operator++() {
		--p;
		return *this;
	}
	char operator*() {
		return *(p - 1);
	}
};


class String
{
	size_t len{ 0 };
	char* p{ nullptr };

public:
	String();
	String(const char* s);
	virtual ~String();
	String(const String& other);
	String& operator=(const String& rhs);
	String(String&& other)noexcept;
	String& operator=(String&& rhs)noexcept;
	char& operator[](size_t idx);
	char operator[](size_t idx) const;

	size_t size() const;
	std::string getString()const;
	//�񱳿����� �߰�
	bool operator==(const String& rhs)const noexcept;
	friend std::ostream& operator<<(std::ostream& os, const String& s);

	//�ݺ��ڸ� ���� ��� �߰� 2020.4.25
	using iterator = String_Iterator;
	using reverse_iterator = String_Reverse_Iterator;
	iterator begin();
	iterator end();
	reverse_iterator rbegin();
	reverse_iterator rend();


	//20.5.4 �߰�
	bool operator<(const String& rhs) const;
	String& operator+=(char c);
};

