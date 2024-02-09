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

int sizeOfList(Node* head) {
    int s = 0;
    for (Node* i = head; i != NULL; i = i->next) {
        s++;
    }
    return s;
}


void printList(Node* head) {
    for (Node* i = head; i != NULL; i = i->next)
        cout << i->val << " ";
    cout << endl;
}

void middle(Node* head) {
    int n = sizeOfList(head);

    Node* tmp = head;
    for (int i = 0; i < (n / 2) - 1; i++) {
        tmp = tmp->next;
    }

    if (n % 2) {
        cout << tmp->next->val << " ";
    }
    else {
        cout << tmp->val << " ";
        cout << tmp->next->val << " ";
    }
}

int main() {
    Node* head = NULL;

    for (int x; cin >> x, x != -1;) {
        addLast(head, x);
    }

    // printList(head);
    middle(head);


    return 0;
}