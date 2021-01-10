#include <bits/stdc++.h>
using namespace std;

int coins(int n, int sum, vector<int> arr)
{
    if (sum == 0)
    {
        return 1;
    }
    if (n <= 0 || sum < 0)
    {
        return 0;
    }

    if (sum - arr[n - 1] >= 0)
    {
        //   cout << arr[n - 1] << " fuck\n";
        return (coins(n, sum - arr[n - 1], arr) + coins(n - 1, sum, arr));
    }
    //  cout << "fuck " << arr[n - 1] << endl;
    return coins(n - 1, sum, arr);
}
int main()
{

    vector<int> arr{1, 5, 10, 25};
    int n;
    cin >> n;

    cout << coins(4, n, arr) << endl;

    return 0;
}