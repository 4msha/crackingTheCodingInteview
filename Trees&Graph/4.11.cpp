#include <bits/stdc++.h>
using namespace std;

//getRandom Funtion in tree

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
    int size = 0;

    TreeNode(int val) : val(val), left(NULL), right(NULL), size(1){};
};

class Tree
{
public:
    TreeNode *root = NULL;
    Tree(TreeNode *ptr) : root(ptr){};
    int size() { return root == NULL ? 0 : root->size; };

    void insertInorder(int d, TreeNode *ptr)
    {
        if (d <= ptr->val)
        {
            if (ptr->left == NULL)
            {
                ptr->left = new TreeNode(d);
            }
            else
            {
                insertInorder(d, ptr->left);
            }
        }
        else
        {
            if (ptr->right == NULL)
            {
                ptr->right = new TreeNode(d);
            }
            else
            {
                insertInorder(d, ptr->right);
            }
        }
        ptr->size += 1;
    }

    TreeNode *getRandom()
    {
        if (root == NULL)
            return NULL;
        int size = root->size;
        int random = (int)(rand() * 1000) % size;
        //cout << "rand   " << random << "  " << size << endl;
        return getIthNode(root, random);
    }

    TreeNode *getIthNode(TreeNode *ptr, int n)
    {
        int leftSize = root->left ? 0 : root->left->size;
        if (leftSize > n)
        {
            return getIthNode(root->left, n);
        }
        else if (leftSize == n)
        {
            return ptr;
        }
        else
        {
            return getIthNode(root->right, n - leftSize - 1);
        }
    }
};

void printTree(TreeNode *root)
{
    if (root == NULL)
        return;
    printTree(root->left);
    cout << root->val << "   ";
    printTree(root->right);
}

int main()
{
    vector<int> vec{50, 60, 70, 20, 25, 15};
    TreeNode *root = new TreeNode(vec[0]);
    Tree *tree = new Tree(root);

    for (int i = 1; i < vec.size(); i++)
    {
        tree->insertInorder(vec[i], root);
    }
    printTree(root);
    cout << endl;
    cout << tree->getRandom()->val << endl;

    return 0;
}