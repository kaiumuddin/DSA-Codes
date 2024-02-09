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

bool containesDuplicates(Node* head) {
    int freq[100 + 1] = { 0 };

    for (Node* i = head;i != NULL; i = i->next) {
        freq[i->val]++;
        
        if (freq[i->val] > 1) {
            return true;
        }
    }

    return false;
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
    cout << containesDuplicates(head) << endl;

    return 0;
}