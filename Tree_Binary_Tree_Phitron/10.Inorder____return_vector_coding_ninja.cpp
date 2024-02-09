#include <bits/stdc++.h> 
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
vector<int> getInOrderTraversal(TreeNode* root)
{
    if (root == NULL) return {};

    vector<int> l = getInOrderTraversal(root->left);
    vector<int> r = getInOrderTraversal(root->right);

    vector<int> mine;
    mine.insert(mine.end(), l.begin(), l.end());
    mine.insert(mine.end(), root->data);
    mine.insert(mine.end(), r.begin(), r.end());

    return mine;
}