#include "custom_string.h"

namespace custom_string {

	String::String()
	{
		length = 0;
		data = new char[0];
	}

	String::String(const String& other)
	{
		length = other.len();
		data = new char[length];
		for (unsigned int j = 0; j < length; j++)
			data[j] = other[j];
	}

	String::String(String&& other) noexcept
	{
		data = other.data;
		length = other.length;
		other.length = 0;
		other.data = nullptr;
	}

	String::String(const char* c)
	{
		if (c)
		{
			unsigned int n = 0;
			while (c[n] != '\0') n++;
			length = n;
			data = new char[n];
			for (unsigned int j = 0; j < n; j++)
				data[j] = c[j];
		}
		else
		{
			length = 0;
			data = new char[0];
		}
	}

	String::~String()
	{
		delete[] data;
	}

	unsigned int String::len() const
	{
		return length;
	}

	String& String::operator=(const String& other)
	{
		if (this == &other)
			return *this;

		delete data;
		length = other.len();
		data = new char[length];
		for (unsigned int j = 0; j < length; j++)
			data[j] = other[j];

		return *this;
	}

	String& String::operator=(String&& other) noexcept
	{
		if (this != &other) {
			delete[] data;
			data = other.data;
			length = other.length;
			other.data = nullptr;
			other.length = 0;
		}
		return *this;
	}

	char String::operator[](unsigned int j) const
	{
		return data[j];
	}

	char& String::operator[](unsigned int j)
	{
		return data[j];
	}

	std::ostream& operator<<(std::ostream& so, const String& str)
	{
		for (int i = 0; i < str.len(); i++)
			so << str[i];
		return so;
	}
}
