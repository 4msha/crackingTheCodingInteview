#include <bits/stdc++.h>
using namespace std;

//#include "tree.h"

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

public:
    TreeNode(int ival) : val(ival), left(NULL), right(NULL) {}
};

map<int, vector<int>> createRandomGraph(int n);

void createBST(vector<int> vec, TreeNode *root);

void display(TreeNode *root);
