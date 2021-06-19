#include <bits/stdc++.h>
using namespace std;

// void parens(int l, int r, string temp, vector<string> &result)
// {
//     //  cout << l << "  " << r << endl;
//     if (l == 0 && r == 0)
//     {
//         cout << " hehe  " << temp << endl;
//         result.emplace_back(temp);
//         return;
//     }

//     if (l > 0)
//     {
//         parens(l - 1, r, temp + "(", result);
//     }
//     else
//     {
//         if (l > 0)
//         {
//             parens(l - 1, r, temp + "(", result);
//         }

//         if (r > l)
//         {
//             parens(l, r - 1, temp + ")", result);
//         }
//     }
// }

void solve(int n, int l, int r, string temp, vector<string> &ans)
{

    if (l == n && r == n)
    {
        ans.emplace_back(temp);
        return;
    }

    if (l < n)
    {
        solve(n, l + 1, r, temp + "(", ans);
    }

    if (r < l)
    {
        solve(n, l, r + 1, temp + ")", ans);
    }
}

int main()
{
    int n;
    cin >> n;
    // vector<string> result;

    // parens(n, n, "", result);

    // for (auto x : result)
    // {
    //     cout << x << endl;
    // }

    vector<string> ans;

    solve(n, 0, 0, "", ans);

    cout << " \n -----------------------------------------------------------\n";

    for (auto x : ans)
    {
        cout << x << "   ";
    }
    cout << endl;

    return 0;
}