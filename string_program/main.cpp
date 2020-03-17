#include "custom_string.h"

using namespace std;

using namespace custom_string;

String generateItem()
{
    String item="test_string";
    return item;
}

int main()
{
    String s1="String example";
    cout << s1 << endl;
    String s2("str");
    cout << s2 << endl;
    String s3 = generateItem();
    cout << s3 << endl;
    String s4(s2);
    s3 = move(s2);
    cout<<s3 << endl;
    system("pause");
    return 0;
}
