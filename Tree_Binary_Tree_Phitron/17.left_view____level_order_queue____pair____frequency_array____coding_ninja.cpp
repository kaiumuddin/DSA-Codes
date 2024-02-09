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

vector<int> getLeftView(TreeNode<int>* root)
{
    if (root == NULL) return {};

    vector<int> ans;

    bool frq[3005] = { false };
    queue<pair<TreeNode<int>*, int>> q;

    q.push({ root, 1 });

    while (!q.empty()) {
        auto front = q.front();
        q.pop();

        auto node = front.first;
        auto level = front.second;

        if (frq[level] == false) {
            ans.push_back(node->data);
            frq[level] = true;
        }

        if (node->left) q.push({ node->left, level + 1 });
        if (node->right) q.push({ node->right, level + 1 });
    }

    return ans;
}