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

void level_order(Node* root) {
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* front = q.front();
        q.pop();
        cout << front->val << " ";

        if (front->left) q.push(front->left);
        if (front->right) q.push(front->right);
    }
}

int main() {
    Node* root = new Node(10);
    Node* a = new Node(20);
    Node* b = new Node(30);
    Node* c = new Node(40);
    Node* h = new Node(90);
    Node* d = new Node(50);
    Node* e = new Node(60);
    Node* i = new Node(100);
    Node* f = new Node(70);
    Node* g = new Node(80);

    root->left = a;
    root->right = b;
    a->left = c;
    a->right = h;
    c->right = e;
    b->right = d;
    d->left = f;
    d->right = g;
    h->right = i;

    level_order(root);

    return 0;
}