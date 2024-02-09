#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

void printList(Node* head) {
    for (Node* i = head; i != NULL; i = i->next)
        cout << i->val << " ";
    cout << endl;
}

void insertTail(Node*& head, Node*& tail, int val) {
    if (head == NULL) {
        head = new Node(val);
        tail = head;
        return;
    }

    tail->next = new Node(val);
    tail = tail->next;
}

void inputList(Node*& head, Node*& tail) {
    int x;
    while (true) {
        int x;
        cin >> x;
        if (x == -1) break;
        insertTail(head, tail, x);
    }
}

void reverseRec(Node*& head, Node* curr) {
    if (curr->next == NULL) {
        head = curr;
        return;
    }

    reverseRec(head, curr->next);

    curr->next->next = curr;
    curr->next = NULL;
}

bool isPalindrome(Node* head) {
    Node* newHead = NULL;
    Node* newTail = NULL;

    for (Node* i = head; i != NULL; i = i->next) {
        insertTail(newHead, newTail, i->val);
    }

    reverseRec(newHead, newHead);

    Node* i = head;
    Node* j = newHead;

    while (i) {
        if (i->val != j->val) return false;

        i = i->next;
        j = j->next;
    }

    return true;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    inputList(head, tail);

    bool ans = isPalindrome(head);
    if (ans) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}