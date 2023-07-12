#include "custom_string.h"

namespace custom_string {

String::String()
{
    m_size = 0;
    m_str = new char[0];
}

String::String(const String& other)
{
    m_size = other.m_size;
    m_str = new char[m_size+1];
    for (size_t i = 0; i < m_size; i++)
        m_str[i] = other[i];
    m_str[m_size] = '\0';
}

String::String(String&& other) noexcept
{
    m_str = other.m_str;
    m_size = other.m_size;
    other.m_size = 0;
    other.m_str = nullptr;
}

String::String(const char* _str)
{
    if (_str)
    {
        m_size = strlen(_str);
        m_str = new char[m_size + 1];
        for (size_t i = 0; i < m_size; i++)
            m_str[i] = _str[i];
        m_str[m_size] = '\0';
    }
    else
    {
        m_size = 0;
        m_str = new char[0];
    }
}

String::~String()
{
    delete[] m_str;
}
size_t String::len() const
{
    return m_size;
}

size_t String::strlen(const char* _str) const
{
    size_t size = 0;
    while (*(_str++))
    {
        size++;
    }
    return size;
}

String& String::operator=(const String& other)
{
    if (this != &other)
    {
        delete[] m_str;
        m_size = other.m_size;
        m_str = new char[m_size+1];
        for (size_t i = 0; i < m_size; i++)
            m_str[i] = other[i];
        m_str[m_size] = '\0';
    }
    return *this;
}

String& String::operator=(String&& other) noexcept
{
    if (this != &other)
    {
        delete[] m_str;
        m_str = other.m_str;
        m_size = other.m_size;
        other.m_str = nullptr;
        other.m_size = 0;
    }
    return *this;
}

String& String::operator+=(const String& other)
{
    size_t newSize = m_size + other.m_size;
    char* newStr = new char[newSize + 1];
    for (size_t i = 0; i < m_size; i++)
        newStr[i] = m_str[i];
    for (size_t i = m_size; i < newSize; i++)
        newStr[i] = other[i];
    newStr[newSize]='\0';
    delete[] m_str;
    m_str = newStr;
    m_size = newSize;
    return *this;
}

char String::operator[](size_t index) const
{
    return m_str[index];
}

char& String::operator[](size_t index)
{
    return m_str[index];
}

String operator+(const String& left_other, const String& right_other) {
    String newString(left_other);
    newString += right_other;
    return newString;
}

std::ostream& operator<<(std::ostream& os, const String& other)
{
    os << other.m_str;
    return os;
}

}
