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
    Node* head = NULL;

    for (int x; cin >> x, x != -1;) {
        addLast(head, x);
    }

    printList(head);
    insertAt(head, 0, 5);
    printList(head);
    insertAt(head, 2, 15);
    printList(head);
    insertHead(head, 2);
    printList(head);


    return 0;
}