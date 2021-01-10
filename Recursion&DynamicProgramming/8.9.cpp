#include <bits/stdc++.h>
using namespace std;

void parens(int l, int r, string temp, vector<string> &result)
{
    //  cout << l << "  " << r << endl;
    if (l == 0 && r == 0)
    {
        result.emplace_back(temp);
        return;
    }

    if (l == r)
    {
        parens(l - 1, r, temp + "(", result);
    }
    else
    {
        if (l != 0)
        {
            parens(l - 1, r, temp + "(", result);
        }

        if (r != 0)
        {
            parens(l, r - 1, temp + ")", result);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<string> result;

    parens(n, n, "", result);

    for (auto &x : result)
    {
        cout << x << endl;
    }

    return 0;
}