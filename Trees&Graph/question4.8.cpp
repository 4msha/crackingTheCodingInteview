/*---------------------------------------------------------------------------------------------
                    Chapter-4    Trees And Graph 
    4.8) First common Ancestor: Design an algorithm to find first common ancestor of two nodes.
--------------------------------------------------------------------------------------------*/
#include <bits/stdc++.h>
using namespace std;

#include "supportFunction.h"

TreeNode *hero(vector<int> &vec, int l, int r)
{
    if (r <= l)
        return NULL;
    int mid = l + (r - l) / 2;
    cout << l << " " << r << "  " << mid << endl;
    TreeNode *root = new TreeNode(vec[mid]);
    root->left = hero(vec, l, mid);
    root->right = hero(vec, mid + 1, r);
    return root;
}

TreeNode *createBST(vector<int> vec)
{
    return hero(vec, 0, vec.size());
}

bool help(TreeNode *root, TreeNode *ptr, vector<TreeNode *> &v)
{
    if (root == NULL)
        return false;

    if (root == ptr)
        return true;

    v.emplace_back(root);

    bool l = help(root->left, ptr, v);
    if (l)
    {
        return true;
    }

    l = help(root->right, ptr, v);
    if (l)
        return true;

    v.pop_back();
    return false;
}

void display(TreeNode *root)
{
    if (root == NULL)
        return;
    display(root->left);
    cout << root->val << "    ";
    display(root->right);
}

TreeNode *findCommonAncestor(TreeNode *ptr1, TreeNode *ptr2, TreeNode *root)
{
    vector<TreeNode *> v1, v2;

    help(root, ptr1, v1);
    help(root, ptr2, v2);

    set<TreeNode *> sp;

    cout << "v1 :";

    for (auto x : v1)
    {
        cout << x->val << "  ";
    }
    cout << "\n";
    cout << "v2 :";
    for (auto x : v2)
    {
        cout << x->val << "  ";
    }
    cout << "\n";

    for (auto x : v1)
    {
        sp.insert(x);
    }

    for (int i = v2.size() - 1; i >= 0; i++)
    {
        if (sp.find(v2[i]) != sp.end())
        {
            cout << " in " << v2[i]->val << endl;
            return v2[i];
        }
    }

    return NULL;
}

int main()
{
    vector<int> vec{1, 2, 3, 4, 9, 8, 7, 6, 5, 13, 9};
    TreeNode *root = createBST(vec);
    cout << "Displaying Tree\n";
    display(root);
    cout << "\n";
    //find ancestor

    TreeNode *ans = findCommonAncestor(root->left->right, root->right, root);
    cout << root->left->right->val << "  " << root->right->val << endl;
    cout << " ans : " << ans->val << endl;

    return 0;
}
