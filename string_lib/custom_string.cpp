#include "custom_string.h"

namespace custom_string {

	String::String()
	{
		size = 0;
		str = new char[0];
	}

	String::String(const String& other)
	{
		size = other.size;
		str = new char[size+1];
		for (size_t j = 0; j < size; j++)
			str[j] = other[j];
		str[size] = '\0';
	}

	String::String(String&& other) noexcept
	{
		str = other.str;
		size = other.size;
		other.size = 0;
		other.str = nullptr;
	}

	String::String(const char* _str)
	{
		if (_str)
		{
			size = strlen(_str);
			str = new char[size + 1];
			for (size_t i = 0; i < size; i++)
				str[i] = _str[i];
			str[size] = '\0';
		}
		else
		{
			size = 0;
			str = new char[0];
		}
	}

	String::~String()
	{
		delete[] str;
	}
	size_t String::len() const
	{
		return size;
	}

	size_t String::strlen(const char* _str) const
	{
		size_t size = 0;
		while (*(_str++))
		{
			++size;
		}
		return size;
	}

	String& String::operator=(const String& other)
	{
		if (this != &other)
		{
			delete[] str;
			size = other.size;
			str = new char[size+1];
			for (size_t i = 0; i < size; i++)
				str[i] = other[i];
			str[size] = '\0';
		}
		return *this;
	}

	String& String::operator=(String&& other) noexcept
	{
		if (this != &other)
		{
			delete[] str;
			str = other.str;
			size = other.size;
			other.str = nullptr;
			other.size = 0;
		}
		return *this;
	}

	char String::operator[](size_t i) const
	{
		return str[i];
	}

	char& String::operator[](size_t i)
	{
		return str[i];
	}
}
