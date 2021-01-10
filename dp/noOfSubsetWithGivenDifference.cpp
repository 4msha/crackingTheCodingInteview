#include <bits/stdc++.h>
using namespace std;

int n, d;

int subsetSum(vector<int> &nums, int s, int n)
{
    // if (s == 0)
    // {
    //     //subset count   return 1;
    //     return 1;
    // }
    // if (n == 0)
    // {
    //     //subset cout   return 0;
    //     return 0;
    // }

    // if (s >= nums[n - 1])
    // {
    //     //  return (subsetSum(nums, s - nums[n - 1], n - 1) || subsetSum(nums, s, n - 1));
    //     //subset count
    //     return (subsetSum(nums, s - nums[n - 1], n - 1) + subsetSum(nums, s, n - 1));
    // }

    // return subsetSum(nums, s, n - 1);

    int dp[n + 1][s + 1];
    memset(dp, 0, sizeof(dp));

    for (int i{1}; i <= n; i++)
    {
        for (int j{1}; j <= s; j++)
        {
            if (j >= nums[i - 1])
            {
                dp[i][j] = max((nums[i - 1] + dp[i - 1][j - nums[i - 1]]), dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    for (int i{0}; i <= n; i++)
    {
        for (int j{0}; j <= s; j++)
        {
            cout << dp[i][j] << "  ";
        }
        cout << endl;
    }

    return dp[n][s];
}

int main()
{
    cin >> n >> d;
    vector<int> nums(n, 0);

    for (int i{0}; i < n; i++)
    {
        cin >> nums[i];
    }

    int sum = accumulate(nums.begin(), nums.end(), 0);
    int s = (sum + d) / 2;

    // if ((sum + d) % 2 != 0)
    // {
    //     cout << "Not Exists\n";
    // }<

    cout << s << "  " << n << endl;

    cout << subsetSum(nums, s, nums.size()) << endl;

    return 0;
}
