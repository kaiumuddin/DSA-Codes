#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        bool isOriginal;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int nodeLevel(TreeNode<int>* root, int searchedValue)
{
    if (root == NULL) return 0;

    if (root->val == searchedValue) return 1;

    int l = nodeLevel(root->left, searchedValue);
    int r = nodeLevel(root->right, searchedValue);

    if (l != 0) return l + 1;
    if (r != 0) return r + 1;
    return 0;
}
