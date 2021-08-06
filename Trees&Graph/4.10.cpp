#include <bits/stdc++.h>
using namespace std;

//bst sequesnce

class Tree
{
public:
    int val;
    Tree *left;
    Tree *right;

public:
    Tree(int ival) : val(ival), left(NULL), right(NULL) {}
};

Tree *insertTree(Tree *root, int val)
{
    Tree *temp = root, *temp2 = NULL;

    while (temp != NULL)
    {
        temp2 = temp;
        if (temp->val > val)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    return temp2;
}

Tree *createTree(vector<int> &vec)
{
    Tree *root = new Tree(vec[0]);
    Tree *temp;
    for (int i = 1; i < vec.size(); i++)
    {
        temp = insertTree(root, vec[i]);
        Tree *ptr = new Tree(vec[i]);
        if (vec[i] > temp->val)
        {
            temp->right = ptr;
        }
        else
        {
            temp->left = ptr;
        }
    }
    return root;
}

void printTree(Tree *root)
{
    if (root == NULL)
        return;
    printTree(root->left);
    cout << root->val << "   ";
    printTree(root->right);
}

int main()
{

    return 0;
}