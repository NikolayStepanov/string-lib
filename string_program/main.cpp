#include "custom_string.h"

#include <iostream>
#include <vector>
#include <algorithm>

using namespace custom_string;

int main()
{
    String s1 = "String1";
    cout << "s1 = " << s1 << endl;
    String s2("String2");
    cout << "s2 = " << s2 << endl;
    String s3 = s1 + s2;
    cout << "s3 = s1 + s2; s3 = " << s3 << endl;
    String s4 = s3 + s1;
    cout << "s4 = s3 + s1; s4 = " << s4 << endl;
    String s5 = s3 + s4;
    cout << "s5 = s3 + s4; s5 = " << s5 << endl;
    String s6 = s1;
    s6 += s1;
    cout << "s6 = s1; s6 += s1; s6 = " << s6 << endl;
    String s7 = s2;
    s7 += s2;
    cout << "s7 = s2; s7 += s2; s7 = " << s7 << endl;
    String s8(std::move(s7));
    cout << "String s8(move(s7); s8 = " << s8 << endl;

    cout << "Enter strings:" << endl;
    vector<String> strings;
    String input;
    while (cin >> input && input.len() != 0)
    {
        strings.emplace_back(input);
    }

    sort(strings.begin(), strings.end(), greater<>());

    cout << "Sorted strings in reverse order:" << endl;

    for (const String& str : strings)
    {
        cout << str << endl;
    }
    system("pause");
    return 0;
}
