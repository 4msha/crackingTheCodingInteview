#include <bits/stdc++.h>
using namespace std;

int *arr;
int n;

vector<vector<int>> power2(int n)
{
    vector<vector<int>> temp;
    if (n == 0)
    {
        vector<int> vec;
        temp.emplace_back(vec);
    }
    else
    {
        vector<vector<int>> help = power2(n - 1);
        for (auto x : help)
        {
            vector<int> y = x;
            y.emplace_back(arr[n - 1]);
            temp.emplace_back(y);
            temp.emplace_back(x);
        }
    }
    return temp;
}

void powerSet(vector<int> &power, int i, vector<vector<int>> &ans)
{
    if (i == 0)
    {
        ans.emplace_back(power);
        return;
    }

    powerSet(power, i - 1, ans);
    power.emplace_back(arr[i - 1]);
    powerSet(power, i - 1, ans);
    power.pop_back();
}

int main()
{
    cin >> n;

    arr = new int[n];

    for (int i{0}; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<vector<int>> ans;
    vector<int> power;

    powerSet(power, n, ans);

    cout << "Power Set is \n [";

    for (auto &x : ans)
    {
        cout << "[ ";
        for (auto &y : x)
        {
            cout << y << " , ";
        }
        cout << " ]\n";
    }

    cout << " ],";

    vector<vector<int>> ans2 = power2(n);

    cout << "\n----------------------------------------------------------------------------------------\n";

    for (auto &x : ans2)
    {
        cout << "[ ";
        for (auto &y : x)
        {
            cout << y << " , ";
        }
        cout << " ]\n";
    }

    cout << " ],";
    return 0;
}