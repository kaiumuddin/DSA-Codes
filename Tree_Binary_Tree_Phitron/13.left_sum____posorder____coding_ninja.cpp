#include <bits/stdc++.h> 
/*
    Tree Node class.

    class BinaryTreeNode
    {
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    }
*/


long long leftSum(BinaryTreeNode<int>* root)
{
    if (root == NULL) return 0;

    long long l = leftSum(root->left);
    long long r = leftSum(root->right);

    if (root->left)
        return root->left->data + l + r;

    return l + r;
}