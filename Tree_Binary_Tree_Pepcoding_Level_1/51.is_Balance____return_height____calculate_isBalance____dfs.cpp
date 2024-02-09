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


bool isBalance = true;
int height(Node* root) {
    if (root == NULL) return 0;

    int lh = height(root->left);
    int rh = height(root->right);

    int gap = abs(lh - rh);
    if (gap > 1) isBalance = false;

    return max(lh, rh) + 1;
}

int main() {
    vector<int> arr = { 50,25,12,-1, -1, 37, 30 , -1, -1, -1, 75,62,-1, 70, -1, -1, 87, -1, -1 };
    // vector<int> arr = { 10,20,-1,-1,30,-1,-1 };
    Node* root = create(arr);
    displayFolder(root);
    cout << endl;

    height(root);
    cout << isBalance << endl;

    return 0;
}