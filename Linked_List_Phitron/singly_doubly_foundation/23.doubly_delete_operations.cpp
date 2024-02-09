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

void deleteTail(Node*& head, Node*& tail) {
    if (tail == NULL) return;

    Node* deleteNode = tail;
    tail = tail->prev;
    delete deleteNode;

    if (tail == NULL) {
        head = NULL;
        return;
    }

    tail->next = NULL;
}

void deleteHead(Node*& head, Node*& tail) {
    if (head == NULL) return;

    Node* deleteNode = head;
    head = head->next;
    delete deleteNode;

    if (head == NULL) {
        tail = NULL;
        return;
    }

    head->prev = NULL;
}

void deleteAt(Node*& head, Node*& tail, int pos) {
    if (pos >= size(head)) {
        cout << "Invalid" << endl;
        return;
    }
    if (pos == 0) {
        deleteHead(head, tail);
        return;
    }
    if (pos == size(head) - 1) {
        deleteTail(head, tail);
        return;
    }

    Node* tmp = head;
    for (int i = 0; i < pos - 1; i++) {
        tmp = tmp->next;
    }
    Node* deleteNode = tmp->next;
    tmp->next = tmp->next->next;
    tmp->next->prev = tmp;
    delete deleteNode;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    // insertAtTail(head, tail, 10);
    // insertAtTail(head, tail, 20);
    // insertAtTail(head, tail, 30);
    // insertAtTail(head, tail, 40);
    insertAtTail(head, tail, 50);
    // deleteAt(head, tail, 0);

    printForw(head);
    deleteTail(head, tail);
    printForw(head);



    return 0;
}
