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

bool isSorted(Node* head) {
    Node* tmp = head;
    while (tmp->next != NULL) {
        if (tmp->val > tmp->next->val) {
            return false;
        }
        tmp = tmp->next;
    }
    return true;
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

    // printList(head);
    cout << isSorted(head) << endl;


    return 0;
}