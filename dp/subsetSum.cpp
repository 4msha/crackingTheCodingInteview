/*

Dyanamic Programming : Subset sum /subset sum count / Equal sum partition

*/

#include <bits/stdc++.h>
using namespace std;

//subset count return type should be integer
bool subsetSum(vector<int> &nums, int s, int n)
{
    if (s == 0)
    {
        //subset count   return 1;
        return true;
    }
    if (n == 0)
    {
        //subset cout   return 0;
        return false;
    }

    if (s >= nums[n - 1])
    {
        return (subsetSum(nums, s - nums[n - 1], n - 1) || subsetSum(nums, s, n - 1));
        //subset count
        // return (subsetSum(nums,s-nums[n-1],n-1) + subsetSum(nums,s,n-1));
    }

    return subsetSum(nums, s, n - 1);
}

int main()
{
    int n, s;
    cout << "enter no of elements\n";
    cin >> n;
    cout << "enter subset sum\n";
    cin >> s;
    cout << "enter the array \n";

    //in equal sum partition theres no s
    // s=accumulate(nums.begin(),nums.end(),0)/2;
    // if(s%2!=0)return false;
    // else return subsetSum(nums,s,n);

    vector<int> nums(n, 0);
    for (int i{0}; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << subsetSum(nums, s, n) << endl;
    return 0;
}