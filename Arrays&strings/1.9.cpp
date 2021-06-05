#include <bits/stdc++.h>
using namespace std;

bool isSubstring(string s1, string s2)
{
    ///whatever code
    return true;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    s1 += s1;
    if (isSubstring(s1, s2))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}