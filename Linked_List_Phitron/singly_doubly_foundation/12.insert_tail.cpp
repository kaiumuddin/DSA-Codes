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

int sizeOfList(Node* head) {
    int s = 0;
    for (Node* i = head; i != NULL; i = i->next) {
        s++;
    }
    return s;
}


void addLast(Node*& head, int val) {
    if (head == NULL) {
        head = new Node(val);
        return;
    }

    Node* i = head;
    while (i->next != NULL) {
        i = i->next;
    }

    i->next = new Node(val);
}

void insertHead(Node*& head, int val) {
    head = new Node(val, head);
}

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

void insertAt(Node*& head, int pos, int val) {
    if (pos == 0) {
        head = new Node(val, head);
        return;
    }

    Node* tmp = head;
    for (int i = 0; i < pos - 1; i++) {
        tmp = tmp->next;
    }
    tmp->next = new Node(val, tmp->next);

}



void printList(Node* head) {
    for (Node* i = head; i != NULL; i = i->next)
        cout << i->val << " ";
    cout << endl;
}


int main() {
    Node* head = new Node(10);

    Node* a = new Node(20);
    Node* b = new Node(30);
    Node* c = new Node(40);
    Node* d = new Node(50);

    head->next = a;
    a->next = b;
    b->next = c;
    c->next = d;

    Node* tail = d;

    printList(head);
    insertTail(head, tail, 100);
    printList(head);

    return 0;
}