
/************************************************************

    Following is the TreeNode class structure:

    template <typename T>

    class TreeNode {
    public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;
        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include <bits/stdc++.h> 
vector<int> reverseLevelOrder(TreeNode<int>* root) {
    if (root == NULL) return {};

    vector<int> ans;
    queue<TreeNode<int>*> q;
    q.push(root);

    while (!q.empty()) {
        auto front = q.front();
        q.pop();

        ans.push_back(front->val);

        if (front->left) q.push(front->left);
        if (front->right) q.push(front->right);
    }

    reverse(ans.begin(), ans.end());
    return ans;
}