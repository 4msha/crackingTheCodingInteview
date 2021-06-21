#include <bits/stdc++.h>
using namespace std;

map<string, int> mp;

int solve(string s, int i, int j, bool flag)
{

    if (i > j)
        return 0;
    if (i == j)
    {
        if (flag)
        {
            return s[i] == 'T';
        }
        return s[i] == 'F';
    }

    string key = to_string(i) + " " + to_string(j) + " " + to_string(flag);

    if (mp[key])
        return mp[key];

    int ans = 0;
    int rt, rf, lt, lf;

    for (int k = i + 1; k <= j - 1; k++)
    {
        if (flag)
        {
            if (s[k] == '|')
            {
                lt = solve(s, i, k - 1, true);
                lf = solve(s, i, k - 1, false);
                rt = solve(s, k + 1, j, true);
                rf = solve(s, k + 1, j, false);

                ans += lt * rf + rt * lf + lt * rt;
            }
            else if (s[k] == '&')
            {
                lt = solve(s, i, k - 1, true);
                rt = solve(s, k + 1, j, true);
                ans += lt * rt;
            }
            else
            {
                lt = solve(s, i, k - 1, true);
                lf = solve(s, i, k - 1, false);
                rt = solve(s, k + 1, j, true);
                rf = solve(s, k + 1, j, false);

                ans += rt * lf + rf * lt;
            }
        }
        else
        {
            if (s[k] == '|')
            {
                lf = solve(s, i, k - 1, false);
                rf = solve(s, k + 1, j, false);

                ans += lf * rf;
            }
            else if (s[k] == '&')
            {
                lt = solve(s, i, k - 1, true);
                lf = solve(s, i, k - 1, false);
                rt = solve(s, k + 1, j, true);
                rf = solve(s, k + 1, j, false);
                ans += lf * rt + rf * lt + lf * rf;
            }
            else
            {
                lt = solve(s, i, k - 1, true);
                lf = solve(s, i, k - 1, false);
                rt = solve(s, k + 1, j, true);
                rf = solve(s, k + 1, j, false);

                ans += rt * lt + rf * lf;
            }
        }
        k++;
    }

    return mp[key] = ans;
}

int main()
{
    string s;
    cin >> s;

    cout << solve(s, 0, s.length() - 1, true) << endl;

    return 0;
}