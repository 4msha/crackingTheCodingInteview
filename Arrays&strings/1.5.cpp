#include <bits/stdc++.h>
using namespace std;

bool isReplacement(string s1, string s2)
{
    bool flag{false};
    for (int i{0}; i < s1.length(); i++)
    {
        if (s1[i] != s2[i])
        {
            if (flag)
                return false;
            flag = true;
        }
    }
    return true;
}

bool isEditable(string s1, string s2)
{
    bool flag;
    int i = 0, j = 0;

    while (i < s1.size())
    {
        if (s1[i] != s2[j])
        {
            if (flag)
                return false;
            flag = true;
            j--;
        }
        j++;
        i++;
    }
    return true;
}

bool solve(string s1, string s2)
{
    if (s1.size() == s2.size())
    {
        return isReplacement(s1, s2);
    }
    if (s1.size() > s2.size())
        return isEditable(s1, s2);

    return isEditable(s2, s1);
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << solve(s1, s2) << endl;
    return 0;
}