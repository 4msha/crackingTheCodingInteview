#ifndef _TreeNode_H_
#define _TreeNode_H_

#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

public:
    TreeNode(int ival) : val(ival), left(NULL), right(NULL) {}

    void calculateHeight(int temp, TreeNode *root, int &height)
    {
        if (root == NULL)
        {
            height = max(height, temp);
            return;
        }

        calculateHeight(temp + 1, root->left, height);
        calculateHeight(temp + 1, root->right, height);
    }
};

#endif