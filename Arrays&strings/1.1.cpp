#include <bits/stdc++.h>
using namespace std;

//th question is if the charcters are from ascii code 128 chars or extended ascii 256 or unicode 143859 characters
// we will assume the character are from ascii 128

bool isUnique(string a)
{
    bool isPresent[128] = {false};

    for (auto x : a)
    {
        if (isPresent[x - 'a'])
        {
            return false;
        }
        isPresent[x - 'a'] = true;
    }
    return true;
}

//the other case when you can not use extra space we need to compare every character to every other chararcter O(n^2)

bool isUnique2(string a)
{

    for (int i{0}; i < a.length(); i++)
    {
        for (int j{i + 1}; j < a.length(); j++)
        {
            if (a[i] == a[j])
                return false;
        }
    }

    return true;
}

int main()
{
    string a;
    cin >> a;
    cout << "string " << a << " is ";
    if (isUnique(a))
        cout << "unique";
    else
        cout << "not unique";
    return 0;
}