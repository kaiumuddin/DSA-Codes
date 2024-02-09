#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void preorder(TreeNode<int>* root, vector<int>& ans, int level, int& maxLevel) {
    if (root == NULL) return;

    if (level > maxLevel) {
        ans.push_back(root->data);
        maxLevel = max(maxLevel, level);
    }

    preorder(root->left, ans, level + 1, maxLevel);
    preorder(root->right, ans, level + 1, maxLevel);
}


vector<int> getLeftView(TreeNode<int>* root)
{
    vector<int> ans = {};
    int maxLevel = 0;
    preorder(root, ans, 1, maxLevel);

    return ans;
}