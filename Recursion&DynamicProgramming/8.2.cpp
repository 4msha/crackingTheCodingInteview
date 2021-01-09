#include <bits/stdc++.h>
using namespace std;

int n, m;
int **grid;

bool robotInGrid(int i, int j, vector<char> &path)
{
    if (i >= n || j >= m)
        return false;

    if (i == n - 1 && j == m - 1)
        return true;

    int r, d;

    if (j + 1 < m && grid[i][j + 1] != -1)
    {
        r = robotInGrid(i, j + 1, path);
        if (r)
        {
            path.emplace_back('r');
            return true;
        }
    }
    if (i + 1 < n && grid[i + 1][j] != -1)
    {
        d = robotInGrid(i + 1, j, path);
        if (d)
        {
            path.emplace_back('d');
            return true;
        }
    }

    grid[i][j] = -1;
    return false;
}

int main()
{
    cout << "enter demension of grid\n";
    cin >> n >> m;
    grid = new int *[n];
    for (int i = 0; i < n; ++i)
        grid[i] = new int[m];

    vector<char> path;

    if (robotInGrid(0, 0, path))
    {
        cout << "Theres a path which is\n";
        for (auto &x : path)
        {
            cout << x << " -> ";
        }
    }

    for (int i = 0; i < n; ++i)
        delete[] grid[i];
    delete[] grid;
    return 0;
}