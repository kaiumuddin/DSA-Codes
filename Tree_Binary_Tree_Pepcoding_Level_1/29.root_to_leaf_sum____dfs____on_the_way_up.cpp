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


void displayFolder(Node* root, string space = "", string pos = "") {
    if (root == NULL) {
        cout << space << pos << "n" << endl;
        return;
    };
    displayFolder(root->right, space + "    |", "r'");
    cout << space << pos << root->data << endl;
    displayFolder(root->left, space + "    |", "l'");
}

void rootToLeafSum(Node* root, string path, int sum, int low, int high) {
    if (root->left == NULL && root->right == NULL) {
        sum += root->data;

        if (sum >= low && sum <= high) {
            cout << path + to_string(root->data) << endl;
        }
        return;
    }

    rootToLeafSum(root->left, path + to_string(root->data) + " ", sum + root->data, low, high);
    rootToLeafSum(root->right, path + to_string(root->data) + " ", sum + root->data, low, high);
}

int main() {
    // vector<int> arr = { 50,25, 12,-1, -1, 37, 30 , -1, -1, -1, 75,62,-1, 70, -1, -1, 87, -1, -1 };
    vector<int> arr = { 50,25, 12,-1, -1, 37, 30 , -1, -1, 40,-1,-1, 75,62,60,-1,-1, 70, -1, -1, 87, -1, -1 };
    // vector<int> arr = { 10,20,-1,-1,30,-1,-1 };
    Node* root = create(arr);
    displayFolder(root);
    cout << endl;

    rootToLeafSum(root, "", 0, 150, 250);

    return 0;
}