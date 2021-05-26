#include <bits/stdc++.h>
using namespace std;

string urlify(string a)
{
    int index;

    for (int i = a.length() - 1; i >= 0; i--)
    {
        if (a[i] != ' ')
        {
            index = i;
            break;
        }
    }
    // cout << index << endl;
    for (int i = a.length() - 1; i >= 0;)
    {
        if (a[index] == ' ')
        {
            a[i] = '0';
            a[i - 1] = '2';
            a[i - 2] = '%';
            i = i - 3;
            index--;
        }
        else
        {
            a[i] = a[index];
            index--;
            i--;
        }
        //cout << i << "  " << index << "  " << a[index] << "  " << a << endl;
    }

    return a;
}

int main()
{
    string a;
    getline(cin, a);
    cout << urlify(a) << endl;
    return 0;
}