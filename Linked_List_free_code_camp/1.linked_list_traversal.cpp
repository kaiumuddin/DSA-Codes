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

void printLinkedListIterative(Node* head) {
    Node* t = head;
    while (t) {
        cout << t->val << " ";
        t = t->next;
    }
}

void printLinkedListRecursive(Node* head) {
    if (head == NULL) return;

    cout << head->val << " ";
    printLinkedListRecursive(head->next);
}

int main() {

    Node* head =
        new Node(10,
            new Node(20,
                new Node(30,
                    new Node(40))));

    printLinkedListIterative(head);
    cout << endl;
    printLinkedListRecursive(head);


    return 0;
}