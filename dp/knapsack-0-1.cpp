/*

Dyanamic Programming : Knapsack 0-1

*/

#include <bits/stdc++.h>
using namespace std;

int knapsack01(vector<int> &weight, vector<int> &val, int w, int n)
{

    //recursive code
    // if(n==0){
    //     return 0;
    // }

    // if(w>=weight[n-1]){
    //     return max(val[n-1]+knapsack01(weight,val,w-weight[n-1],n-1) , knapsack01(weight,val,w,n-1));
    // }

    // return knapsack01(weight,val,w,n-1);

    //bottom up approach

    int dp[n + 1][w + 1];

    for (int i{0}; i <= n; i++)
    {
        for (int j{0}; j <= w; j++)
        {
            cout << i << "  " << j << "  ";
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (j >= weight[i - 1])
            {
                dp[i][j] = max((val[i - 1] + dp[i - 1][j - weight[i - 1]]), dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // for (int i{0}; i <= n; i++)
    // {
    //     for (int j{0}; j <= w; j++)
    //     {
    //         cout << dp[i][j] << "    ";
    //     }
    //     cout << endl;
    // }

    return dp[n][w];
}

int main()
{
    int w, n;
    cout << "enter no of elements\n";
    cin >> n;
    cout << "enter weightof knapsack\n";
    cin >> w;

    vector<int> weight(n, 0), val(n, 0);
    cout << "enter weigt array\n";

    for (int i{0}; i < n; i++)
    {
        cin >> weight[i];
    }

    cout << "enter value array\n";

    for (int i{0}; i < n; i++)
    {
        cin >> val[i];
    }

    cout << knapsack01(weight, val, w, n) << endl;
}