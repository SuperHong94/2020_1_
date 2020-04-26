#pragma once
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
};

