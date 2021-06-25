/*---------------------------------------------------------------------------------------------
                    Chapter-4    Trees And Graph 
    4.6) Successor: Write an algorithm to find the next ndoe (i.e,in-order succession) of a given
                    node in a binary tree.You may assume that each node has a link to its parent.
--------------------------------------------------------------------------------------------*/
#include <bits/stdc++.h>
using namespace std;

#include "supportFunction.h"

class Tree
{
public:
    int val;
    Tree *left;
    Tree *right;
    Tree *parent;

public:
    Tree(int ival) : val(ival), left(NULL), right(NULL), parent(NULL) {}
};

Tree *hero(vector<int> &vec, int l, int r, Tree *parent)
{
    if (r <= l)
        return NULL;
    int mid = l + (r - l) / 2;
    cout << mid << endl;
    Tree *root = new Tree(vec[mid]);
    cout << root->val << endl;
    root->parent = parent;
    root->left = hero(vec, l, mid, root);
    root->right = hero(vec, mid + 1, r, root);
    return root;
}

Tree *createBST(vector<int> vec)
{
    return hero(vec, 0, vec.size(), NULL);
    // cout << "  bst  " << root->val;
}

Tree *findNextNode(Tree *root)
{
    if (root == NULL)
        return NULL;
    if (root->left == NULL)
        return root;
    return findNextNode(root->left);
}

void display(Tree *root)
{
    if (root == NULL)
        return;
    display(root->left);
    cout << root->val << "    ";
    display(root->right);
}

Tree *randomNode(Tree *root, int &count)
{
    if (root == NULL)
        return NULL;
    if (!count)
        return root;
    count--;
    Tree *l = randomNode(root->left, count);
    if (l != NULL)
        return l;
    count--;
    Tree *r = randomNode(root->right, count);
    return r;
}

int main()
{
    vector<int> vec{1, 2, 3, 4, 9, 8, 7, 6, 5, 13, 9};
    Tree *root;
    root = createBST(vec);
    cout << "Displaying Tree\n";
    cout << root->val << endl;
    display(root);
    // next node is the left most child of right child
    // int random = (rand() % vec.size());
    // Tree *temp = randomNode(root, random);

    Tree *ans = findNextNode(root->right->right);

    cout << "Next Node of " << root->val << " is " << ans->val << endl;

    return 0;
}
