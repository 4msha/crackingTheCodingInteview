/*---------------------------------------------------------------------------------------------
                    Chapter-4    Trees And Graph 
    4.5) Validate BST: Implement a function to check if a binary tree is Binary Search Tree.
--------------------------------------------------------------------------------------------*/
#include <bits/stdc++.h>
using namespace std;

#include "supportFunction.h"

bool checkBST(TreeNode *root, int min, int max)
{
    if (root == NULL)
        return true;
    if (root->val < min || root->val > max)
        return false;

    bool l = checkBST(root->left, min, root->val);
    if (!l)
        return false;
    bool r = checkBST(root->right, root->val, max);
    if (!r)
        return false;
    return true;
}

int main()
{
    vector<int> vec{1, 2, 3, 4, 9, 8, 7, 6, 5, 13, 9};
    TreeNode *root;
    createBST(vec, root);
    cout << "Displaying Tree\n";
    display(root);
    //since the tree is a BST so isBalanced must return true
    if (checkBST(root, INT_MIN, INT_MAX))
        cout << "Tree is a BST\n";
    else
        cout << "Tree is Not BST\n";
    return 0;
}
