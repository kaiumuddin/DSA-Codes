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

int maxLeaf = INT_MIN;
int minLeaf = INT_MAX;

void postorder(Node* root) {
    if(root == NULL) return;
    if (root->left == NULL && root->right == NULL) {
        maxLeaf = max(maxLeaf, root->val);
        minLeaf = min(minLeaf, root->val);
        return;
    }

    postorder(root->left);
    postorder(root->right);

}

int main()
{
    Node* root = input_tree();
    postorder(root);
    cout << maxLeaf << " " << minLeaf << endl;
}
