#include <bits/stdc++.h>
using namespace std;

bool getPath(vector<vector<int>> grid, int r, int c, vector<string> &path, map<string, bool> &visited)
{
    if (r < 0 || c < 0 || grid[r][c] == -1)
    {
        return false;
    }

    if (r == 0 && c == 0)
        return true;

    string key = to_string(r) + " " + to_string(c);

    if (visited[key])
        return visited[key];

    if (getPath(grid, r - 1, c, path, visited) || getPath(grid, r, c - 1, path, visited))
    {
        path.emplace_back(key);
        return visited[key] = true;
    }

    return visited[key] = false;
}

// bool robotInGrid(int i, int j, vector<char> &path)
// {
//     if (i >= n || j >= m)
//         return false;

//     if (i == n - 1 && j == m - 1)
//         return true;

//     int r, d;

//     if (j + 1 < m && grid[i][j + 1] != -1)
//     {
//         r = robotInGrid(i, j + 1, path);
//         if (r)
//         {
//             path.emplace_back('r');
//             return true;
//         }
//     }
//     if (i + 1 < n && grid[i + 1][j] != -1)
//     {
//         d = robotInGrid(i + 1, j, path);
//         if (d)
//         {
//             path.emplace_back('d');
//             return true;
//         }
//     }

//     grid[i][j] = -1;
//     return false;
// }

int main()
{
    cout << "enter demension of grid\n";
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    map<string, bool> visited;
    vector<string> path1;
    path1.emplace_back("0 0");

    if (getPath(grid, n - 1, m - 1, path1, visited))
    {
        path1.emplace_back(to_string(n - 1) + " " + to_string(m - 1));
        for (auto x : path1)
        {
            cout << x << "  ->  ";
        }
        cout << endl;
    }

    return 0;
}