#include <bits/stdc++.h>
using namespace std;

int multiply(int small, int big)
{
    if (small == 0)
        return 0;

    if (small == 1)
        return big;

    int s = small >> 2;
    int half = multiply(s, big);
    if (small % 2 == 0)
    {
        return 2 * half;
    }
    return 2 * half + big;
}
int main()
{
    int a, b;
    cin >> a >> b;

    int small = a < b ? a : b;
    int big = a < b ? b : a;
    cout << multiply(small, big) << endl;
}