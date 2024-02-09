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

int _floor = INT_MIN;
int _ceil = INT_MAX;

void floorAndCeil(Node* node, int data) {
    if (node->data > data) {
        if (node->data < _ceil) {
            _ceil = node->data;
        }
    }
    if (node->data < data) {
        if (node->data > _floor) {
            _floor = node->data;
        }
    }

    for (auto child : node->children) {
        floorAndCeil(child, data);
    }
}


int main() {
    vector<int> arr = { 10,20,50,-1, 60,-1,-1,30,70,-1,80,110,-1,120,-1,-1, 90,-1,-1,40,100,-1,-1,-1 };
    // vector<int> arr = { -10,-20,-50,-1, -60,-1,-1,-30,-70,-1,-80,-110,-1,-120,-1,-1, -90,-1,-1,-40,-100,-1,-1,-1 };
    // vector<int> arr = { 10,20,-1,30,-1,-1 };
    // vector<int> arr = { 10,20,-1,30,50,-1,60,-1,-1,40,-1,-1 };

    Node* root = create(arr);
    displayFolder(root);
    cout << endl;

    floorAndCeil(root, 70);

    cout << "floor = " << _floor << endl;
    cout << "ceil = " << _ceil << endl;

    // displayFolder(root);
    return 0;
}