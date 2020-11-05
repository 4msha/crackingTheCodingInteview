#include <bits/stdc++.h>
using namespace std;
#include "supportFunction.h"
#include "tree.h"

vector<int> returnRandomNeighbour(int n, int v)
{
    int x = (rand() % n) + 1;
    set<int> set;
    int count{0};
    for (int i{0}; count < x; i++)
    {
        int temp = rand() % n;
        if (temp != v)
        {
            set.insert(temp);
            count++;
        }
    }
    vector<int> vec;
    for (auto &t : set)
        vec.emplace_back(t);

    return vec;
}
map<int, vector<int>> createRandomGraph(int n)
{
    map<int, vector<int>> map;
    for (int i{0}; i < n; i++)
    {
        vector<int> vec = returnRandomNeighbour(n, i);
        map[i] = vec;
    }
    return map;
}

TreeNode *hero(vector<int> &vec, int l, int r)
{
    if (r <= l)
        return NULL;
    int mid = l + (r - l) / 2;
    TreeNode *root = new TreeNode(vec[mid]);
    root->left = hero(vec, l, mid);
    root->right = hero(vec, mid + 1, r);
    return root;
}
void createBST(vector<int> vec, TreeNode *root)
{
    root = hero(vec, 0, vec.size());
}

void display(TreeNode *root)
{
    if (root == NULL)
        return;
    display(root->left);
    cout << root->val << "    ";
    display(root->right);
}