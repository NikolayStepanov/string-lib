#ifndef STRING_H
#define STRING_H

#include <iostream>

namespace custom_string {
class String
{
public:
    String();
    String(const String& other);
    String(String&& other) noexcept;
    String(const char* c);
    ~String();
    size_t len() const;
    size_t strlen(const char* _str) const;
    String& operator= (const String& other);
    String& operator= (String&& other) noexcept;
    String& operator+=(const String& other);
    char  operator[] (size_t i) const;
    char& operator[] (size_t i);
    const char* c_str() const;
    friend String operator+(const String& left_other, const String& right_other);
    friend std::ostream& operator<<(std::ostream& os, const String& str);

private:
    char* m_str = nullptr;
    size_t m_size = 0;
};
}
#endif // STRING_H
