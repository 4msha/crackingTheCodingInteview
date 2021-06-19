#include <bits/stdc++.h>
using namespace std;

void solveOdd(vector<vector<int>> &res, int i, int j, int n, int num)
{
    if (i < 0 || i >= n || j < 0 || j >= n)
    {
        // cout << " hmmmm\n";
        return;
    }

    res[i][j] = num;
    if (num == pow(n, 2))
    {
        // cout << " hit\n";
        return;
    }
    int x, y;

    if (i - 1 >= 0 && j + 1 < n)
    {
        if (res[i - 1][j + 1] == 0)
        {
            //cout << "case 11\n";
            x = i - 1;
            y = j + 1;
        }
        else
        {
            //  cout << "case 12\n";
            x = i + 1;
            y = j;
        }
    }
    else if (i - 1 >= 0)
    {
        // cout << "case 2\n";
        x = i - 1;
        y = 0;
    }
    else if (j + 1 < n)
    {
        //cout << "case 3\n";
        x = n - 1;
        y = j + 1;
    }
    else
    {
        // cout << " thats it\n";
        x = i + 1;
        y = j;
    }
    //  cout << x << "  " << y << "  " << num << "  " << endl;
    solveOdd(res, x, y, n, num + 1);
}

void solveEven(vector<vector<int>> &res, int n)
{
    int i{0}, j{0}, x{n - 1}, y{n - 1};

    while (i < x && j < y)
    {
        int temp = res[i][j];
        res[i][j] = res[x][y];
        res[x][y] = temp;
        i++;
        j++;
        x--;
        y--;
    }

    i = 0;
    j = n - 1;
    x = n - 1;
    y = 0;

    while (i < x && j > y)
    {
        int temp = res[i][j];
        res[i][j] = res[x][y];
        res[x][y] = temp;
        x--;
        y++;
        j--;
        i++;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> res(n, vector<int>(n, 0));
    if (n & 1)
    {
        int j = n / 2;
        solveOdd(res, 0, j, n, 1);
    }
    else
    {
        int num = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                res[i][j] = num;
                num++;
            }
        }
        solveEven(res, n);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << res[i][j] << "   ";
        }
        cout << "\n";
    }

    return 0;
}