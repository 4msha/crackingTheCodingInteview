#include <bits/stdc++.h>
using namespace std;

void clearRow(vector<vector<int>> &mat, int n)
{

    for (int i = 0; i <= mat[0].size(); i++)
        mat[n][i] = 0;
}

void clearColumn(vector<vector<int>> &mat, int n)
{
    for (int i = 0; i <= mat.size(); i++)
        mat[i][n] = 0;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }

    bool row{false}, column{false};

    for (int i = 0; i < n; i++)
    {
        if (mat[i][0] == 0)
        {
            column = true;
            mat[i][0] = 1;
        }
    }

    for (int i = 0; i < m; i++)
    {
        if (mat[0][i] == 0)
        {
            row = true;
            mat[0][i] = 1;
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (mat[i][j] == 0)
            {
                mat[i][0] = 0;
                mat[0][j] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (mat[i][0] == 0)
        {
            clearRow(mat, i);
        }
    }

    for (int i = 0; i < m; i++)
    {
        if (mat[0][i] == 0)
        {
            clearColumn(mat, i);
        }
    }

    if (row)
        clearRow(mat, 0);
    if (column)
        clearColumn(mat, 0);

    return 0;
}