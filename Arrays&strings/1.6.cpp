#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s, ans;
    cin >> s;
    for (int i = 0; i < s.length();)
    {
        char temp = s[i++];
        int count{1};
        while (s[i] == temp)
        {
            i++;
            count++;
        }
        ans += temp + to_string(count);
    }

    cout << ans << "\n";
    return 0;
}