#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int  data;
    vector<Node*> children;

    Node(int data) {
        this->data = data;
    }
};

Node* create(vector<int> arr) {
    Node* root = NULL;
    stack<Node*> st;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == -1) {
            st.pop();
        }
        else {
            Node* t = new Node(arr[i]);

            if (st.size() > 0) {
                st.top()->children.push_back(t);
            }
            else {
                root = t;
            }
            st.push(t);
        }
    }
    return root;
}

void displayEuler(Node* root) {
    if (root == NULL) return;

    cout << root->data << " -> ";
    for (auto child : root->children) {
        cout << child->data << ", ";
    }
    cout << endl;
    for (auto child : root->children) {
        displayEuler(child);
    }
}

void displayFolder(Node* root, string space = "") {
    if (root == NULL) return;

    cout << space << root->data << endl;

    for (auto child : root->children) {
        displayFolder(child, space + "|  ");
    }
}

Node* predecessor = NULL;
Node* successor = NULL;
int state = 0;
void travel(Node* node, int data) {
    if (state == 0) {
        if (node->data == data) {
            state = 1;
        }
        else {
            predecessor = node;
        }
    }
    else if (state == 1) {
        successor = node;
        state = 2;
    }

    for (auto child : node->children) {
        travel(child, data);
    }
}


int main() {
    // vector<int> arr = { 10,20,50,-1, 60,-1,-1,30,70,-1,80,110,-1,120,-1,-1, 90,-1,-1,40,100,-1,-1,-1 };
    // vector<int> arr = { -10,-20,-50,-1, -60,-1,-1,-30,-70,-1,-80,-110,-1,-120,-1,-1, -90,-1,-1,-40,-100,-1,-1,-1 };
    vector<int> arr = { 10,20,-1,30,-1,-1 };
    // vector<int> arr = { 10,20,-1,30,50,-1,60,-1,-1,40,-1,-1 };

    Node* root = create(arr);
    displayFolder(root);
    cout << endl;

    travel(root, 20);

    cout << "Predecessor = " << predecessor->data << endl;
    cout << "Successor = " << successor->data << endl;

    // displayFolder(root);
    return 0;
}