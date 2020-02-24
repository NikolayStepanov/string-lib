#ifndef STRING_H
#define STRING_H

class String
{
    char *data;
    unsigned int length;

public:
    String();
    String (const String& s);
    String (const char* c);
    ~String ( );
    unsigned int len ( ) const;
    String& operator= (const String& s);
    char  operator[] (unsigned int j) const;
    char& operator[] (unsigned int j);
};

#endif // STRING_H
