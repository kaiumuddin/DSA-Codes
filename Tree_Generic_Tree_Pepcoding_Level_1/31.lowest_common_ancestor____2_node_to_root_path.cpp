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

vector<int> nodeToRoot(Node* root, int data) {
    if (root->data == data) return { root->data };

    for (auto child : root->children) {
        vector<int> faith = nodeToRoot(child, data);
        if (faith.size() > 0) {
            faith.push_back(root->data);
            return faith;
        }
    }
    return {};
}

int lca(Node* root, int d1, int d2) {
    auto p1 = nodeToRoot(root, d1);
    auto p2 = nodeToRoot(root, d2);

    int i = p1.size() - 1;
    int j = p2.size() - 1;

    while (i >= 0 && j >= 0 && p1.at(i) == p2.at(j)) {
        i--;
        j--;
    }

    i++;
    j++;

    return p1.at(i);
}

int main() {
    vector<int> arr = { 10,20,50,-1, 60,-1,-1,30,70,-1,80,110,-1,120,-1,-1, 90,-1,-1,40,100,-1,-1,-1 };
    // vector<int> arr = { -10,-20,-50,-1, -60,-1,-1,-30,-70,-1,-80,-110,-1,-120,-1,-1, -90,-1,-1,-40,-100,-1,-1,-1 };
    // vector<int> arr = { 10,20,-1,30,-1,-1 };
    // vector<int> arr = { 10,20,-1,30,50,-1,60,-1,-1,40,-1,-1 };

    Node* root = create(arr);
    displayFolder(root);
    cout << endl;

    cout << lca(root, 60, 30) << endl;
    cout << lca(root, 70, 90) << endl;

    // displayFolder(root);
    return 0;
}