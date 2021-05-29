#include <bits/stdc++.h>
using namespace std;
#define M 26

//strings with no space
//using bitvector

bool solve(string s)
{
    bitset<M> bset;
    for (auto x : s)
    {
        int i = x - 'a';
        bset[i] = !bset[i];
    }

    int count = bset.count();

    if (s.length() & 1)
    {
        if (count == 1)
            return true;
        return false;
    }

    if (count == 0)
        return true;
    return false;
}

//using basic count of characters we can write a function using map or array but bitset is the most optimized approach

int main()
{
    string s;
    cin >> s;

    if (solve(s))
    {
        cout << "String " << s << " is a permutation of palindrome\n";
    }
    else
    {
        cout << "String " << s << " is not a permutation of palindrome\n";
    }

    return 0;
}