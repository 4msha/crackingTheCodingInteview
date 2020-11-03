/*---------------------------------------------------------------------------------------------
                    Chapter-4    Trees And Graph 
    4.2)   Minimal Tree: Given a sorted array(increasing order) array with unique integer elements, 
                         write an algorithm to create a binary tree search tree wit minimal height.

--------------------------------------------------------------------------------------------*/
#include <bits/stdc++.h>
using namespace std;

class Tree
{
public:
    int val;
    Tree *right;
    Tree *left;

    Tree(int x) : val(x), right(NULL), left(NULL) {}
};

Tree *hero(vector<int> &vec, int l, int r)
{
    if (r <= l)
        return NULL;
    int mid = l + (r - l) / 2;
    Tree *root = new Tree(vec[mid]);
    root->left = hero(vec, l, mid);
    root->right = hero(vec, mid + 1, r);
    return root;
}
Tree *createBST(vector<int> &vec)
{
    return hero(vec, 0, vec.size());
}

void display(Tree *root)
{
    if (root == NULL)
        return;
    display(root->left);
    cout << root->val << "    ";
    display(root->right);
}

void calculateHeight(int temp, Tree *root, int &height)
{
    if (root == NULL)
    {
        height = max(height, temp);
        return;
    }

    calculateHeight(temp + 1, root->left, height);
    calculateHeight(temp + 1, root->right, height);
}
int main()
{
    vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Tree *temp = createBST(vec);
    display(temp);
    int height{INT_MIN};
    calculateHeight(0, temp, height);
    cout << "\nHeight of Tree is " << height << " rooted at " << temp->val << endl;
    return 0;
}
