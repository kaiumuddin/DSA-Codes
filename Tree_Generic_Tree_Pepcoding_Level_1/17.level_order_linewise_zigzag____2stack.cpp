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

void levelOrderLineWiseZigzag(Node* root) {
    // stack<Node*> ms;
    auto ms = stack<Node*>();
    ms.push(root);

    auto cs = stack<Node*>();
    int level = 1;

    while (ms.size() > 0) {
        auto curr = ms.top();
        ms.pop();
        cout << curr->data << " ";

        if (level % 2 == 1) {
            for (int i = 0; i < curr->children.size(); i++) {
                cs.push(curr->children[i]);
            }
        }
        else {
            for (int i = curr->children.size() - 1; i >= 0; i--) {
                cs.push(curr->children[i]);
            }
        }

        if (ms.size() == 0) {
            ms = cs;
            cs = stack<Node*>();
            level++;
            cout << endl;
        }
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
    levelOrderLineWiseZigzag(root);
    return 0;
}

// remove print add (rpa)