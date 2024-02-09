#include <bits/stdc++.h> 
/*
Following is the structure of Tree Node

class TreeNode
{
   public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }

};
*/

vector<int> postorderTraversal(TreeNode* root)
{
    if (root == NULL) return {};

    vector<int> l = postorderTraversal(root->left);
    vector<int> r = postorderTraversal(root->right);

    vector<int> mine;
    mine.insert(mine.end(), l.begin(), l.end());
    mine.insert(mine.end(), r.begin(), r.end());
    mine.insert(mine.end(), root->val);

    return mine;
}
