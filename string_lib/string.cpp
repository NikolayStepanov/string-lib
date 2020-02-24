#include "string.h"

String::String()
{
    length = 0;
    data   = new char[0];
}

String::String(const String &s)
{
    length = s.len();
    data   = new char[length];
    for (unsigned int j=0; j < length; j++)
        data[j] = s[j];
}

String::String(const char *c)
{
    if (c)
    {
        unsigned int n = 0;
        while (c[n] != '\0') n++;
        length = n;
        data   = new char[n];
        for (unsigned int j=0; j < n; j++)
            data[j] = c[j];
    } else
    {
        length = 0;
        data   = new char[0];
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

String &String::operator=(const String &s)
{
    if(this == &s)
        return *this;

    delete data;
    length = s.len();
    data   = new char[length];
    for (unsigned int j=0; j < length; j++)
        data[j] = s[j];

    return *this;
}

char String::operator[](unsigned int j) const
{
    if (j >= length)
        throw 1;

    return data[j];
}

char &String::operator[](unsigned int j)
{
    if (j >= length)
        throw 1;

    return data[j];
}
