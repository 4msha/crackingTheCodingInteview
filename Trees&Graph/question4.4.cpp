/*---------------------------------------------------------------------------------------------
                    Chapter-4    Trees And Graph 
    4.4) Check Balanced: Implement a function to check if s binary tree is balanced.For the purpose
                        of this question ,a tree is balanced if difference between the height of left
                        and right subtree is not greater than 1.

--------------------------------------------------------------------------------------------*/
#include <bits/stdc++.h>
using namespace std;

#include "supportFunction.h"

int helper(TreeNode *root)
{
    if (root == NULL)
        return -1;
    int l = helper(root->left);
    int r = helper(root->right);
    if (l == INT_MIN || r == INT_MIN)
        return INT_MIN;
    if (abs(l - r) > 1)
        return INT_MIN;
    return max(l, r);
}

bool isBalanced(TreeNode *root)
{
    if (helper(root) != INT_MIN)
        return true;
    return false;
}

int main()
{
    vector<int> vec{1, 2, 3, 4, 9, 8, 7, 6, 5, 13, 9};
    TreeNode *root;
    createBST(vec, root);
    cout << "Displaying Tree\n";
    display(root);
    //since the tree is a BST so isBalanced must return true
    if (isBalanced(root))
        cout << "Tree is Balances\n";
    else
        cout << "Tree is Not Balanced\n";
    return 0;
}
