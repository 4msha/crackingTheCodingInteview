#include <bits/stdc++.h>
using namespace std;

int *arr;
int n;

int magicIndex(int l, int r)
{
    if (r < l)
        return -1;

    int mid = l + (r - l) / 2;
    if (mid == arr[mid])
    {
        return mid;
    }

    int left = magicIndex(l, min(mid - 1, arr[mid]));
    if (left >= 0)
    {
        return left;
    }

    int right = magicIndex(max(mid + 1, arr[mid]), r);

    return right;
}

int main()
{
    cin >> n;
    arr = new int[n];

    for (int i{0}; i < n; i++)
    {
        cin >> arr[i];
    }

    int index = magicIndex(0, n - 1);

    cout << index << "   " << arr[index] << endl;

    delete[] arr;
    return 0;
}