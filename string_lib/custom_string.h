#ifndef STRING_H
#define STRING_H

#define MAXLEN 256

#include <iostream>

namespace custom_string {

using namespace std;

class String
{
public:
    String();
    String(const char* _str);
    String(const String& other);
    String(String&& other) noexcept;
    ~String();

    const char* c_str() const;
    size_t len() const;
    size_t strlen(const char* _str) const;

    String& operator = (const String& other);
    String& operator = (String&& other) noexcept;
    String operator + (const String& other);
    String& operator += (const String& other);

    String operator + (const char* _str);
    String& operator = (const char* _str);
    String& operator += (const char* _str);

    char  operator [] (size_t index) const;
    char& operator [] (size_t index);
    bool operator < (const String& other);
    bool operator > (const String& other);

    friend String operator + (const char* _str, const String& other);
    friend ostream& operator << (ostream& os, const String& other);
    friend istream& operator >> (istream& is, String& other);

private:
    char* m_str = nullptr;
    size_t m_size = 0;
};
}
#endif // STRING_H
