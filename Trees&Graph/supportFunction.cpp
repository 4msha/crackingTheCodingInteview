#include <bits/stdc++.h>
using namespace std;
#include "supportFunction.h"

vector<int> returnRandomNeighbour(int n, int v)
{
    int x = (rand() % n) + 1;
    set<int> set;
    int count{0};
    for (int i{0}; count < x; i++)
    {
        int temp = rand() % n;
        if (temp != v)
        {
            set.insert(temp);
            count++;
        }
    }
    vector<int> vec;
    for (auto &t : set)
        vec.emplace_back(t);

    return vec;
}
map<int, vector<int>> createRandomGraph(int n)
{
    map<int, vector<int>> map;
    for (int i{0}; i < n; i++)
    {
        vector<int> vec = returnRandomNeighbour(n, i);
        map[i] = vec;
    }
    return map;
}