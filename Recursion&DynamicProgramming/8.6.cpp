#include <bits/stdc++.h>
using namespace std;

//tower class implementation

// class Tower
// {
// private:
//     stack<int> disks;
//     int index;

// public:
//     Tower(int i) : index(i)
//     {
//     }

//     void add(int i)
//     {
//         if (!disks.empty())
//             disks.push(i);
//     }

//     void moveToTower(Tower &i)
//     {
//         int top = disks.top();
//         i.add(top);
//         disks.pop();
//     }

//     void towerOfhanoi(int n, Tower destination, Tower buffer)
//     {
//         if (n > 0)
//         {
//             towerOfhanoi(n - 1, buffer, destination);
//             moveToTower(destination);
//            // Tower initial = this;
//             buffer.towerOfhanoi(n - 1, destination, initial);
//         }
//     }
// };

map<string, vector<string>> mp;

vector<string> towerOfHanoi(int n, int i, int mid, int f)
{
    vector<string> vec;
    if (n == 1)
    {
        string temp = to_string(i) + " -> " + to_string(f);
        vec.emplace_back(temp);
        cout << i << " -> " << f << endl;
        return vec;
    }
    string key = to_string(n) + " " + to_string(i) + " " + to_string(mid) + " " + to_string(f);

    if (mp.find(key) != mp.end())
    {
        // cout << "hit\n";
        return mp[key];
    }

    vector<string> v = towerOfHanoi(n - 1, i, f, mid);
    string temp = to_string(i) + " -> " + to_string(f);
    v.emplace_back(temp);
    cout << i << " -> " << f << endl;
    vector<string> x = towerOfHanoi(n - 1, mid, i, f);
    v.insert(v.end(), x.begin(), x.end());

    return mp[key] = v;
}

int main()
{
    int n;
    cin >> n;

    vector<string> ans = towerOfHanoi(n, 1, 2, 3);
    cout << "\n-------------------------------------------------------\n";
    for (auto x : ans)
    {
        cout << x << endl;
    }

    // for (auto x : mp)
    // {
    //     cout << x.first << "    ";
    //     for (auto y : x.second)
    //     {
    //         cout << y << "   ";
    //     }
    //     cout << "\n";
    // }
}