/*---------------------------------------------------------------------------------------------
                    Chapter-4    Trees And Graph 
    4.8) First common Ancestor: Design an algorithm to find first common ancestor of two nodes.
--------------------------------------------------------------------------------------------*/
#include <bits/stdc++.h>
using namespace std;

#include "supportFunction.h"

int main()
{
    vector<int> vec{1, 2, 3, 4, 9, 8, 7, 6, 5, 13, 9};
    TreeNode *root;
    createBST(vec, root);
    cout << "Displaying Tree\n";
    display(root);
    //find ancestor

    return 0;
}
