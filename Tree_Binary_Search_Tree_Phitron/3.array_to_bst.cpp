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

Node* convert(int arr[], int n, int l, int r) {
    if (l > r) return NULL;

    int mid = (l + r) / 2;
    Node* root = new Node(arr[mid]);

    root->left = convert(arr, n, l, mid - 1);
    root->right = convert(arr, n, mid + 1, r);

    return root;
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

// void displayFolder(Node* root, string space = "", string pos = "") {
//     if (root == NULL) {
//         cout << space << pos << "null" << endl;
//         return;
//     };


//     cout << space << pos << root->val << endl;
//     displayFolder(root->right, space + "    |", "r'");
//     displayFolder(root->left, space + "    |", "l'");
// }

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    Node* root = convert(arr, n, 0, n - 1);
    displayFolder(root);
}
