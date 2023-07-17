#include "custom_string.h"

namespace custom_string {

String::String()
{
    m_size = 0;
    m_str = nullptr;
}

String::String(const String& other)
{
    m_size = other.m_size;
    m_str = new char[m_size + 1];
    strlcpy(m_str, other.m_str, m_size + 1);
}

String::String(String&& other) noexcept
{
    m_str = other.m_str;
    m_size = other.m_size;
    other.m_size = 0;
    other.m_str = nullptr;
}

String::String(const char* str)
{
    if (str)
    {
        m_size = strlen(str);
        m_str = new char[m_size + 1];
        strlcpy(m_str, str, m_size + 1);
    }
    else
    {
        m_size = 0;
        m_str = nullptr;
    }
}

String::~String()
{
    delete[] m_str;
}

const char* String::c_str() const
{
    return m_str;
}

size_t String::len() const
{
    return m_size;
}

size_t String::strlen(const char* str) const
{
    size_t size = 0;
    while (*(str++))
    {
        size++;
    }
    return size;
}

char* strlcat(char* str, const char* other_str, size_t size)
{
    if (str == nullptr && other_str == nullptr)
    {
        return nullptr;
    }
    char* ptr = str + strlen(str);
    strlcpy(ptr, other_str, size);
    return str;
}

size_t strlcpy(char* str, const char* other_str, size_t size)
{
    if (str == nullptr && other_str == nullptr)
    {
        return 0;
    }
    size_t other_str_size = strlen(other_str);
    size_t tmp_count;
    size_t result_size;
    char* ptr = str;
    if (other_str_size < size)
    {
        tmp_count = other_str_size;
        result_size = other_str_size;
    }
    else
    {
        tmp_count = size - 1;
        result_size = size - 1;
    }
    while (tmp_count--)
    {
        *ptr = *other_str;
        ptr++;
        other_str++;
    }
    *ptr = '\0';
    return result_size;
}

String& String::operator = (const String& str)
{
    if (this != &str)
    {
        delete[] m_str;
        m_size = str.m_size;
        m_str = new char[m_size + 1];
        strlcpy(m_str, str.m_str, m_size + 1);
    }
    return *this;
}

String& String::operator = (String&& other) noexcept
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

String String::operator + (const String& str) {
    String new_string;
    size_t new_size = m_size + str.m_size;
    char* new_str = new char[new_size + 1];
    strlcpy(new_str, m_str, m_size + 1);
    strlcat(new_str, str.m_str, str.m_size + 1);
    new_string.m_str = new_str;
    new_string.m_size = new_size;
    return new_string;
}

String& String::operator += (const String& str)
{
    size_t new_size = m_size + str.m_size;
    char* new_str = new char[new_size + 1];
    strlcpy(new_str, m_str, m_size + 1);
    strlcat(new_str, str.m_str, str.m_size + 1);
    delete[] m_str;
    m_str = new_str;
    m_size = new_size;
    return *this;
}

String String::operator + (const char * str)
{
    String new_string;
    size_t size_str = strlen(str);
    size_t new_size = m_size + size_str;
    char* new_str = new char[new_size + 1];
    strlcpy(new_str, m_str, m_size + 1);
    strlcat(new_str, str, size_str + 1);
    new_string.m_str = new_str;
    new_string.m_size = new_size;
    return new_string;
}

String& String::operator = (const char* str){
    if (m_str != str)
    {
        delete[] m_str;
        m_size = strlen(str);
        m_str = new char[m_size + 1];
        strlcpy(m_str, str, m_size + 1);
    }
    return *this;
}

String& String::operator += (const char* str){
    size_t size_str = strlen(str);
    size_t new_size = m_size + size_str;
    char* new_str = new char[new_size + 1];
    strlcpy(new_str, m_str, m_size + 1);
    strlcat(new_str, str, new_size + 1);
    delete[] m_str;
    m_str = new_str;
    m_size = new_size;
    return *this;
}

char String::operator [] (size_t index) const
{
    return m_str[index];
}

char& String::operator [] (size_t index)
{
    return m_str[index];
}

bool String::operator < (const String& other){
    size_t len = min(m_size, other.m_size);
    for (size_t i = 0; i < len; i++)
    {
        char c = tolower(m_str[i]);
        char c_other = tolower(other[i]);
        if (c != c_other)
        {
            return c < c_other;
        }
    }
    return m_str < other.m_str;
}

bool String::operator > (const String& other)
{
    return !(*this < other);
}

String operator + (const char* str,const String& other)
{
    String new_string;
    size_t size_str = strlen(str);
    size_t new_size = size_str + other.m_size;
    char* new_str = new char[new_size + 1];
    strlcpy(new_str, str, size_str + 1);
    strlcat(new_str, other.m_str, other.m_size + 1);
    new_string.m_str = new_str;
    new_string.m_size = new_size;
    return new_string;
}

ostream& operator << (ostream& os, const String& other)
{
    os << other.m_str;
    return os;
}

istream& operator >> (istream& is, String& other)
{
    char input[MAXLEN];
    is.getline(input, MAXLEN);
    other = String(input);
    return is;
}

}
