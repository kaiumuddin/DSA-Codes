#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node* next;
    Node* prev;

    Node(int val) {
        this->val = val;
        this->prev = NULL;
        this->next = NULL;
    }
};

void printForw(Node* head) {
    for (Node* i = head; i != NULL; i = i->next)
        cout << i->val << " ";
    cout << endl;
}

void printBack(Node* tail) {
    for (Node* i = tail; i != NULL; i = i->prev)
        cout << i->val << " ";
    cout << endl;
}

int size(Node* head) {
    int cnt = 0;
    while (head != NULL) {
        head = head->next;
        cnt++;
    }
    return cnt;
}

void insertAtHead(Node*& head, Node*& tail, int val) {
    Node* newNode = new Node(val);

    if (head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode;

    head = newNode;
}

void insertAtTail(Node*& head, Node*& tail, int val) {
    Node* newNode = new Node(val);

    if (tail == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    newNode->prev = tail;
    tail = tail->next;
}

void insertAt(Node*& head, Node*& tail, int pos, int val) {
    if (pos == 0) {
        insertAtHead(head, tail, val);
        return;
    }

    if (pos == size(head)) {
        insertAtTail(head, tail, val);
        return;
    }

    Node* tmp = head;
    Node* newNode = new Node(val);
    for (int i = 0; i < pos - 1; i++) {
        tmp = tmp->next;
    }

    newNode->next = tmp->next;
    newNode->prev = tmp;
    tmp->next = newNode;
    newNode->next->prev = newNode;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    insertAtTail(head, tail, 100);
    insertAtTail(head, tail, 102);
    printForw(head);
    printBack(tail);

    return 0;
}