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

void printList(Node* head) {
    for (auto i = head; i != NULL; i = i->next) cout << i->val << " ";
    cout << endl;
}

Node* reverseList(Node* head, Node* prev = NULL) {
    if (head == NULL) return prev;

    Node* newHead = reverseList(head->next, head);

    head->next = prev;
    return newHead;
}

void reverse(Node*& head, Node* curr) {
    if (curr->next == NULL) {
        head = curr;
        return;
    }
    reverse(head, curr->next);
    curr->next->next = curr;
    curr->next = NULL;
}

int main() {
    Node* head = new Node(10, new Node(20, new Node(30)));
    printList(head);
    // head = reverseList(head);
    reverse(head, head);
    printList(head);
    return 0;
}