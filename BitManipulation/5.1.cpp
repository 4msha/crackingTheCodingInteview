#include <bits/stdc++.h>
using namespace std;

//insertion on m in n

int insert(int n, int m, int i, int j)
{
    int maski = (1 << i) - 1;  //00001111
    int maskj = ~0 << (j + 1); // 1110000
    int mask = maskj | maski;  // 111000001111

    // cout << setbase(10) << maskj << "    " << maski << "    " << (maskj & maski) << endl;

    int n_cleared = n & mask;
    int m_shifted = m << i;

    return n_cleared | m_shifted;
}

int main()
{
    cout << insert(1024, 19, 2, 6);
    return 0;
}