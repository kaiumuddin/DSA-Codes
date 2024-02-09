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

void level_order(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);

    while (q.size() > 0) {
        auto front = q.front();
        q.pop();

        cout << front->val << " ";

        if (front->left) q.push(front->left);
        if (front->right) q.push(front->right);
    }
}

void displayFolder(Node* root, string space = "", string pos = "") {
    if (root == NULL) {
        cout << space << pos << "null" << endl;
        return;
    };

    displayFolder(root->right, space + "|   ", "r'");
    cout << space << pos << root->val << endl;
    displayFolder(root->left, space + "|   ", "l'");

}


void insert(Node*& root, int x) {
    if (root == NULL) {
        root = new Node(x);
        return;
    }
    if (x < root->val) {
        if (root->left == NULL) {
            root->left = new Node(x);
        }
        else {
            insert(root->left, x);
        }
    }
    else {
        if (root->right == NULL) {
            root->right = new Node(x);
        }
        else {
            insert(root->right, x);
        }
    }
}

bool search(Node* root, int x) {
    if (root == NULL)   return false;
    if (root->val == x) return true;

    if (x < root->val)
        return search(root->left, x);
    if (x > root->val)
        return search(root->right, x);
}

int main()
{
    Node* root = input_tree();
    insert(root, 13);
    insert(root, 32);
    displayFolder(root);
    cout << search(root, 22) << endl;
}
