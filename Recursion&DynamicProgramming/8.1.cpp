#include <bits/stdc++.h>
using namespace std;

int staircase(int n, int x[])
{
    if (n == 0)
    {
        return 1;
    }
    if (n < 0)
        return 0;

    if (x[n] != -1)
        return x[n];

    x[n] = staircase(n - 1, x) + staircase(n - 2, x) + staircase(n - 3, x);

    return x[n];
}

int main()
{
    int n;
    cin >> n;
    int x[n + 1];
    memset(x, -1, sizeof(x));
    cout << staircase(n, x) << endl;
    return 0;
}