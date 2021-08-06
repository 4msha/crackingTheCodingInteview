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

void weaveList(list<int> &first, list<int> &second, list<int> prefix, vector<list<int>> &result)
{
    if (first.empty() || second.empty())
    {
        list<int> ft = prefix;
        for (auto x : first)
        {
            ft.emplace_back(x);
        }
        for (auto x : second)
        {
            ft.emplace_back(x);
        }

        result.emplace_back(ft);
        return;
    }

    int x = first.front();
    first.pop_front();
    prefix.emplace_back(x);
    weaveList(first, second, prefix, result);
    prefix.pop_back();
    first.emplace_front(x);

    x = second.front();
    second.pop_front();
    prefix.emplace_back(x);
    weaveList(first, second, prefix, result);
    prefix.pop_back();
    second.emplace_front(x);
}

vector<list<int>> createBSTSequence(Tree *root)
{
    vector<list<int>> result;
    if (root == NULL)
    {
        list<int> ft;
        result.emplace_back(ft);
        return result;
    }
    list<int> prefix;
    prefix.emplace_front(root->val);
    vector<list<int>> left = createBSTSequence(root->left);
    vector<list<int>> right = createBSTSequence(root->right);

    for (auto x : left)
    {
        for (auto y : right)
        {
            vector<list<int>> temp;
            weaveList(x, y, prefix, temp);
            for (auto z : temp)
            {
                result.emplace_back(z);
            }
        }
    }

    return result;
}

int main()
{
    int n;
    cout << "Enter the vector size\n";
    cin >> n;
    cout << " Now enter vector elements\n";
    vector<int> vec(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }

    Tree *root = createTree(vec);

    printTree(root);
    cout << endl;

    vector<list<int>> result = createBSTSequence(root);

    for (auto x : result)
    {
        for (auto y : x)
        {
            cout << y << "  ";
        }
        cout << endl;
    }
    return 0;
}