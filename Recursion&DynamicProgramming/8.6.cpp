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

void towerOfHanoi(int n, int i, int mid, int f)
{
    if (n == 1)
    {
        cout << i << " -> " << f << endl;
        return;
    }

    towerOfHanoi(n - 1, i, f, mid);
    cout << i << " -> " << f << endl;
    towerOfHanoi(n - 1, mid, i, f);
}

int main()
{
    int n;
    cin >> n;

    towerOfHanoi(n, 1, 2, 3);
}