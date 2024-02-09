#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int data, Node* left = NULL, Node* right = NULL) {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

class Pair {
public:
    Node* node;
    int state;
    Pair(Node* node, int state) {
        this->node = node;
        this->state = state;
    }
};

Node* create(vector<int> arr) {
    Node* root = new Node(arr[0], NULL, NULL);
    stack <Pair*> st;
    st.push(new Pair(root, 1));

    int idx = 0;
    while (st.size() > 0) {
        Pair* top = st.top();

        if (top->state == 1) {
            idx++;
            if (arr[idx] != -1)
            {
                top->node->left = new Node(arr[idx]);
                st.push(new Pair(top->node->left, 1));
            }
            else
            {
                top->node->left = NULL;
            }
            top->state++;
        }
        else if (top->state == 2) {
            idx++;
            if (arr[idx] != -1)
            {
                top->node->right = new Node(arr[idx]);
                st.push(new Pair(top->node->right, 1));
            }
            else
            {
                top->node->right = NULL;
            }
            top->state++;
        }
        else {
            st.pop();
        }
    }

    return root;
}

void displayFolder(Node* root, string space = "") {
    if (root == NULL) return;

    cout << space << root->data << endl;

    displayFolder(root->left, space + "|  ");
    displayFolder(root->right, space + "|  ");
}

int size(Node* root) {
    if (root == NULL) return 0;

    int ls = size(root->left);
    int rs = size(root->right);

    return 1 + ls + rs;
}

int sum(Node* root) {
    if (root == NULL) return 0;

    int ls = sum(root->left);
    int rs = sum(root->right);

    return root->data + ls + rs;
}

int maxi(Node* root) {
    if (root == NULL) return INT_MIN;

    int lmax = maxi(root->left);
    int rmax = maxi(root->right);

    return max(root->data, max(lmax, rmax));
}

int height(Node* root) {
    if (root == NULL) return -1;

    int l = height(root->left);
    int r = height(root->right);

    return 1 + max(l, r);
}

int main() {
    vector<int> arr = { 50,25,12,-1, -1, 37, 30 , -1, -1, -1, 75,62,-1, 70, -1, -1, 87, -1, -1 };
    // vector<int> arr = { 10,20,-1,-1,30,-1,-1 };
    Node* root = create(arr);
    displayFolder(root);
    cout << endl;

    cout << size(root) << endl;
    cout << sum(root) << endl;
    cout << maxi(root) << endl;
    cout << height(root) << endl;

    return 0;
}