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

Node* reverseIterative(Node* head) {
    Node* prev = NULL;
    Node* cur = head;
    Node* next = head->next;

    while (cur) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    return prev;
};

Node* reverseRecursive(Node* curr, Node* prev = NULL) {
    if (curr == NULL) return prev;

    Node* newHead = reverseRecursive(curr->next, curr); // faith

    curr->next = prev;

    return newHead;
};


int main() {

    Node* head =
        new Node(10,
            new Node(20,
                new Node(30,
                    new Node(40))));
    // head = new Node(10);

    // head = reverseIterative(head);
    // printLinkedListIterative(head);

    head = reverseRecursive(head);
    printLinkedListIterative(head);


    return 0;
}