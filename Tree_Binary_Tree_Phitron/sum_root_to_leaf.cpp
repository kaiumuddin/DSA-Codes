#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node* left;
    Node* right;
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* input_tree() {
    int val;
    cin >> val;

    Node* root;
    if (val == -1)
        root = NULL;
    else
        root = new Node(val);

    queue<Node*> q;
    if (root)
        q.push(root);

    while (!q.empty()) {
        Node* parent = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;

        Node* left;
        Node* right;
        if (l == -1) left = NULL;
        else left = new Node(l);

        if (r == -1) right = NULL;
        else right = new Node(r);

        parent->left = left;
        parent->right = right;

        if (parent->left) q.push(parent->left);
        if (parent->right) q.push(parent->right);
    }

    return root;
}

int sum = 0;
void preorder(Node* root, int pathSum = 0) {
    if (root == NULL) return;
    if (root->left == NULL && root->right == NULL) {
        pathSum += root->val;
        sum += pathSum;
        return;
    }

    preorder(root->left, pathSum + root->val * 10);
    preorder(root->right, pathSum + root->val * 10);
}

int main()
{
    Node* root = input_tree();
    preorder(root);
    cout << sum << endl;
}
