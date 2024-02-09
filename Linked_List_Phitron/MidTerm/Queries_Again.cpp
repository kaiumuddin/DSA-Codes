#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* prev;

    Node(int val) {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

int size(Node* head) {
    int count = 0;
    for (Node* i = head; i != NULL; i = i->next) {
        count++;
    }
    return count;
}

void printList(Node* head, Node* tail) {
    cout << "L -> ";
    for (Node* i = head; i != NULL; i = i->next)
        cout << i->val << " ";
    cout << endl;

    cout << "R -> ";
    for (Node* i = tail; i != NULL; i = i->prev)
        cout << i->val << " ";
    cout << endl;
}


void insertTail(Node*& head, Node*& tail, int val) {
    Node* newNode = new Node(val);

    if (head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void insertHead(Node*& head, Node*& tail, int val) {
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

void insertAt(Node*& head, Node*& tail, int pos, int val) {
    Node* tmp = head;
    for (int i = 0; i < pos - 1; i++) {
        tmp = tmp->next;
    }

    Node* newNode = new Node(val);
    newNode->next = tmp->next;
    newNode->prev = tmp;
    tmp->next->prev = newNode;
    tmp->next = newNode;

}

void inputList(Node*& head, Node* tail) {
    int q;
    cin >> q;
    while (q--) {
        int x, v;
        cin >> x >> v;

        if (x <0 || x > size(head)) {
            cout << "Invalid" << endl;
            continue;
        }
        else if (x == 0) {
            insertHead(head, tail, v);
        }
        else if (x == size(head)) {
            insertTail(head, tail, v);
        }
        else {
            insertAt(head, tail, x, v);
        }

        printList(head, tail);
    }
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    inputList(head, tail);

    return 0;
}