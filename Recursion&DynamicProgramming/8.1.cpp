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

int staircasedp(int n)
{

    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    int dp[n + 1];

    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    int x[n + 1];
    memset(x, -1, sizeof(x));
    cout << staircase(n, x) << endl;
    cout << staircasedp(n) << endl;
    return 0;
}