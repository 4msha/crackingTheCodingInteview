/*---------------------------------------------------------------------------------------------
                    Chapter-4    Trees And Graph 
    4.2)   Minimal Tree: Given a sorted array(incre
    cout<asing order) array with unique integer elements, 
                         write an algorithm to create a binary tree search tree wit minimal height.

--------------------------------------------------------------------------------------------*/
#include <bits/stdc++.h>
using namespace std;
#include "tree.h"
#include "supportFunction.h"

void sol(TreeNode *root, int level, vector<forward_list<TreeNode *>> &ans)
{
    if (root == NULL)
        return;
    if (level == ans.size())
    {
        forward_list<TreeNode *> list;
        list.push_front(root);
        ans.emplace_back(list);
    }
    else
    {
        ans[level].push_front(root);
    }

    sol(root->left, level + 1, ans);
    sol(root->right, level + 1, ans);
}

void solBFS(TreeNode *root, vector<forward_list<TreeNode *>> &ans)
{
    forward_list<TreeNode *> current;
    current.push_front(root);
    ans.emplace_back(current);

    for (auto i = current.begin(); i != current.end(); i++)
    {
        forward_list<TreeNode *> parents = current;
        forward_list<TreeNode *> current;
        for (auto &t : parents)
        {
            if (t->left != NULL)
                current.push_front(t->left);
            if (t->right != NULL)
                current.push_front(t->right);
        }
        ans.emplace_back(current);
    }
}

int main()
{
    vector<int> vec{1, 2, 3, 4, 5, 6, 12, 1, 6, 5, 3, 2};
    //create a sample tree
    TreeNode *root;
    createBST(vec, root);
    cout << "Displaying Tree\n";
    display(root);

    vector<forward_list<TreeNode *>> ans;

    sol(root, 0, ans);

    cout << "Printing linked List by level\n";
    for (auto &x : ans)
    {
        auto itr = x.begin();
        while (itr != x.end())
        {
            auto p = *(itr);
            cout << p->val << "   ";
            itr++;
        }
        cout << endl;
    }

    return 0;
}
