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

int linkedListSumIterative(Node* head) {
    int sum = 0;

    Node* curr = head;
    while (curr) {
        sum += curr->val;
        curr = curr->next;
    }
    return sum;
};

int linkedListSumRecursive(Node* head) {
    if (head == NULL) return 0;

    int faith = linkedListSumRecursive(head->next);

    return head->val + faith;
};


int main() {

    Node* head =
        new Node(10,
            new Node(20,
                new Node(30,
                    new Node(40))));

    cout << linkedListSumIterative(head) << endl;
    cout << linkedListSumRecursive(head) << endl;

    return 0;
}