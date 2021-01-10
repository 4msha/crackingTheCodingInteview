#include <bits/stdc++.h>
using namespace std;

void permutation(map<char, int> &strMap, string prefix, int remainder, vector<string> &result)
{
    if (remainder == 0)
    {
        result.emplace_back(prefix);
        return;
    }

    for (auto &x : strMap)
    {
        if (x.second > 0)
        {
            char first = x.first;
            x.second -= 1;
            permutation(strMap, prefix + first, remainder - 1, result);
            x.second += 1;
        }
    }
}

map<char, int> createMap(string str)
{
    map<char, int> strMap;

    for (auto x : str)
    {
        strMap[x] += 1;
    }

    return strMap;
}
int main()
{
    string str;
    cin >> str;

    map<char, int> strMap = createMap(str);

    string prefix = "";

    vector<string> result;

    permutation(strMap, prefix, str.length(), result);

    for (auto &x : result)
    {
        cout << x << endl;
    }
    return 0;
}