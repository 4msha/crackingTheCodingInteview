#include <bits/stdc++.h>
using namespace std;

void permutation(int j, int n, string &str)
{

    // // Sort the string in lexicographically
    // // ascennding order
    // sort(str.begin(), str.end());

    // // Keep printing next permutation while there
    // // is next permutation
    // do {
    //    cout << str << endl;
    // } while (next_permutation(str.begin(), str.end()));
    if (j == n - 1)
    {
        cout << str << endl;
        return;
    }
    for (int i{j}; i < n; i++)
    {
        swap(str[j], str[i]);
        if (str[i] != str[j] || i == j)
        {
            permutation(j + 1, n, str);
        }
        swap(str[j], str[i]);
    }
}

int main()
{
    string str;
    cin >> str;

    permutation(0, str.length(), str);
}