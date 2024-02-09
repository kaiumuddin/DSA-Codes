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

int maxHeight(Node* root) {
    if (root == NULL) return 0;

    int l = maxHeight(root->left);
    int r = maxHeight(root->right);

    return max(l, r) + 1;
}

int totalNodes(Node* root) {
    if (root == NULL) return 0;
    return 1 + totalNodes(root->left) + totalNodes(root->right);
}


int main()
{
    Node* root = input_tree();
    int x;
    cin >> x;

    int tn = totalNodes(root);
    int mh = maxHeight(root);

    if (tn == pow(2, mh) - 1) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}
