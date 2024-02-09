#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int val, Node* next = NULL) {
        this->val = val;
        this->next = next;
    }
};

void print_v(vector<int> values) {
    for (auto e : values) {
        cout << e << " ";
    }
    cout << endl;
}

bool linkedListFindIterative(Node* head, int target) {
    Node* t = head;

    while (t) {
        if (t->val == target) {
            return true;
        }
        t = t->next;
    }

    return false;
};

bool linkedListFindRecursive(Node* head, int target) {
    if (head == NULL) return false;

    bool faith = linkedListFindRecursive(head->next, target);

    return head->val == target || faith;
};


int main() {

    Node* head =
        new Node(10,
            new Node(20,
                new Node(30,
                    new Node(40))));

    cout << linkedListFindIterative(head, 20) << endl;
    cout << linkedListFindIterative(head, 80) << endl;
    cout << linkedListFindRecursive(head, 20) << endl;
    cout << linkedListFindRecursive(head, 80) << endl;

    return 0;
}