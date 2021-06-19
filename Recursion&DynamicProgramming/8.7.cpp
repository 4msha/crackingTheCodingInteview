#include <bits/stdc++.h>
using namespace std;

void permutation(int j, int n, string &str)
{

    // // Sort the string in lexicographically
    // // ascennding order
    // sort(str.begin(), str.end());

    // // Keep printing next permutation while there
    // // is next permutation
    // do {
    //    cout << str << endl;
    // } while (next_permutation(str.begin(), str.end()));
    if (j == n - 1)
    {
        cout << str << endl;
        return;
    }
    for (int i{j}; i < n; i++)
    {
        swap(str[j], str[i]);
        permutation(j + 1, n, str);
        swap(str[j], str[i]);
    }
}

/*
  building from permutationof first n-1 permutation
  p(a)=a;
  p(ab)=ab,ba;
  p(abc)=abc,cab,acb,cba,bac,bac
  
   ab  -- insert c at every possible postion
   ---->  cab, acb, abc..

*/

vector<string> permut1(string str)
{
    vector<string> per;
    if (str.length() == 0)
    {
        per.emplace_back("");
        return per;
    }

    char first = str[0];
    string rem = str.substr(1);

    vector<string> partial = permut1(rem);

    for (auto x : partial)
    {
        for (int i = 0; i <= x.length(); i++)
        {
            string temp = x.substr(0, i) + first + x.substr(i);
            //  cout << temp << endl;
            per.emplace_back(temp);
        }
    }

    return per;
}

/*
   Building from permutation of all n-1 character strings
   p(a)=a;
   p(b)=b;
   p(c)=c;
   p(ab)= a+p(b),  b+p(a) == ab, ba
   p(abc)= a+ p(bc), b+p(ac) , c+p(ab)= abc , acb, bac, bca, cab,cba
*/

void permut2(string prefix, string str, vector<string> &result)
{
    if (str.length() == 0)
    {
        result.emplace_back(prefix);
        return;
    }

    int n = str.length();

    for (int i = 0; i < n; i++)
    {
        string bef = str.substr(0, i);
        string aft = str.substr(i + 1);

        permut2(prefix + str[i], bef + aft, result);
    }
}

int main()
{
    string str;
    cin >> str;

    //permutation(0, str.length(), str);

    vector<string> ans = permut1(str);
    cout << "\n -----------------------------------------\n";
    //  cout << ans.size() << endl;
    for (auto x : ans)
    {
        cout << x << "    ";
    }

    vector<string> result;
    permut2("", str, result);
    cout << "\n -----------------------------------------\n";
    //  cout << ans.size() << endl;
    for (auto x : result)
    {
        cout << x << "    ";
    }

    return 0;
}