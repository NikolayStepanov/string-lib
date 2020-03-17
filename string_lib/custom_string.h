#ifndef STRING_H
#define STRING_H

#include <iostream>

namespace custom_string {
    class String
    {
        char* data = nullptr;
        unsigned int length = 0;

    public:
        String();
        String(const String& other);
        String(String&& other) noexcept;
        String(const char* c);
        ~String();
        unsigned int len() const;
        String& operator= (const String& other);
        String& operator= (String&& other) noexcept;
        char  operator[] (unsigned int j) const;
        char& operator[] (unsigned int j);
        friend std::ostream& operator<< (std::ostream& so, const String& s);

    };
}
#endif // STRING_H
