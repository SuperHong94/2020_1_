#pragma once

class String_iterator
{
private:
	char* p{ nullptr };
public:
	String_iterator(char* p) :p{ p } {};

	String_iterator& operator++() { p++; return *this; };
	String_iterator& operator--() { p--; return *this; };

	char& operator*() const { return *p; };
	bool operator!=(const String_iterator& rhs) const { return p != rhs.p; };
	bool operator==(const String_iterator& rhs) const { return p == rhs.p; };
	bool operator<(const String_iterator& rhs) const { return p < rhs.p; };
	bool operator>(const String_iterator& rhs) const { return p > rhs.p; };
	bool operator<=(const String_iterator& rhs) const { return p <= rhs.p; };
	bool operator>=(const String_iterator& rhs) const { return p >= rhs.p; };

	ptrdiff_t operator-(const String_iterator& rhs) const { return p - rhs.p; };
	String_iterator operator+(const ptrdiff_t rhs) const { return p + rhs; };
	String_iterator operator-(const ptrdiff_t rhs) const { return p - rhs; };
};

template<>
struct std::iterator_traits<String_iterator>
{
	using iterator_category = random_access_iterator_tag;
	using value_type = char;
	using difference_type = ptrdiff_t;
	using pointer = char*;
	using reference = char&;
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
	//비교연산자 추가
	bool operator==(const String& rhs)const noexcept;
	friend std::ostream& operator<<(std::ostream& os, const String& s);

	using iterator = String_iterator;
	iterator begin();
	iterator end();
};

