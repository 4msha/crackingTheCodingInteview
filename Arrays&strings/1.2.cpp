#include <bits/stdc++.h>
using namespace std;

//1- we sort the strings and compare O(n logn)
//2- we count the no. of characters if their are same no of char in both string

bool isPermutation(string a, string b)
{
    if (a.length() != b.length())
        return false;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for (int i{0}; i < a.length(); i++)
    {
        if (a[i] != b[i])
            return false;
    }
    return true;
}

bool isPermutation2(string a, string b)
{
    if (a.length() != b.length())
        ;

    int temp[128] = {0};

    for (auto x : a)
    {
        temp[x - 'a'] += 1;
    }

    for (auto x : b)
    {
        temp[x - 'a'] -= 1;
        if (temp[x - 'a'] < 0)
            return false;
    }

    for (int i{0}; i < 128; i++)
    {
        if (temp[i] != 0)
            return false;
    }

    return true;
}

int main()
{
    string a, b;
    cin >> a >> b;

    if (isPermutation(a, b))
    {
        cout << a << " & " << b << " are permutation of eachother";
    }
    else
    {
        cout << a << " & " << b << " are not permutation of each other";
    }

    return 0;
}