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

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    inputList(head, tail);

    return 0;
}