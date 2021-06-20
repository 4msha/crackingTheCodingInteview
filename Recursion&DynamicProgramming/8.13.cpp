#include <bits/stdc++.h>
using namespace std;

struct box
{
    int h, l, b;
};

void solve(vector<box> &vec, int mxl, int mxb, int mxh, int &mx, int n, int temp)
{
    if (n == 0)
    {
        mx = max(mx, temp);
        return;
    }

    if (vec[n - 1].l < mxl && vec[n - 1].b < mxb && vec[n - 1].h < mxh)
    {
        solve(vec, vec[n - 1].l, vec[n - 1].b, vec[n - 1].h, mx, n - 1, temp + vec[n - 1].h);
    }

    solve(vec, mxl, mxb, mxh, mx, n - 1, temp);
}

int main()
{
    int n;
    cin >> n;
    vector<box> vec(n);

    for (int i{0}; i < n; i++)
    {
        cin >> vec[i].l >> vec[i].b >> vec[i].h;
    }

    int mx{0};
    solve(vec, INT_MAX, INT_MAX, INT_MAX, mx, n, 0);

    cout << mx << endl;
    return 0;
}