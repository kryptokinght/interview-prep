#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    getline(cin, str);
    string::iterator it;
    for (it = str.end() - 1; it != str.begin() - 1; it--)
        cout << *it;
    cout << endl;
    cout << "size:" << str.size() << endl;
    return 0;
}