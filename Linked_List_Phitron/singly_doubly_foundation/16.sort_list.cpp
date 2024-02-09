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

void insertTail(Node*& head, Node*& tail, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

void printList(Node* head) {
    for (Node* i = head; i != NULL; i = i->next)
        cout << i->val << " ";
    cout << endl;
}

void printListRecursive(Node* n) {
    if (n == NULL) return;
    printListRecursive(n->next);
    cout << n->val << " ";
}

void sortList(Node*& head) {
    for (Node* i = head; i->next != NULL; i = i->next) {
        for (Node* j = i->next; j != NULL; j = j->next) {
            if (i->val > j->val) {
                swap(i->val, j->val);
            }
        }
    }
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    int val;
    while (true) {
        cin >> val;
        if (val == -1) break;
        insertTail(head, tail, val);
    }

    printList(head);
    sortList(head);
    printList(head);

    return 0;
}