#include <bits/stdc++.h> 
/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T val;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
vector<int> getLevelOrder(BinaryTreeNode<int>* root)
{
    if (root == NULL)
        return {};

    vector<int> ans;
    queue<BinaryTreeNode<int>*> q;

    q.push(root);

    while (!q.empty()) {
        auto front = q.front();
        q.pop();

        ans.push_back(front->val);

        if (front->left) q.push(front->left);
        if (front->right) q.push(front->right);
    }

    return ans;
}