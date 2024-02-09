#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Node {
public:
    T val;
    Node* left;
    Node* right;

    Node(T val, Node* left = NULL, Node* right = NULL) {
        this->val = val;
        this->left = left;
        this->right = right;
    }
};

template <typename T>
vector<T> dfs(Node<T>* root) {
    if (root == NULL) return {};

    vector<T> result = { root->val };

    vector<T> l = dfs(root->left);
    result.insert(result.end(), l.begin(), l.end());

    vector<T> r = dfs(root->right);
    result.insert(result.end(), r.begin(), r.end());

    return result;
}

int main() {
    Node<double>* root =
        new Node<double>(10.2,
            new Node<double>(20,
                new Node<double>(40),
                new Node<double>(50)
            ),
            new Node<double>(30,
                new Node<double>(60),
                new Node<double>(70)
            )
        );

    vector<double> result = dfs(root);

    for (auto x : result) {
        cout << x << " ";
    }
}
