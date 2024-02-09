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

void printList(Node* head) {
    for (auto i = head; i != NULL; i = i->next) cout << i->val << " ";
    cout << endl;
}

void hasCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    cout << slow->val << " " << fast->val << endl;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        cout << slow->val << " " << fast->val << endl;
        if (slow == fast) {
            cout << "Cycle Detected" << endl;
            return;
        }
    }
    cout << "No Cycle" << endl;
}

int main() {
    Node* d = new Node(50);
    Node* c = new Node(40, d);
    Node* b = new Node(30, c);
    Node* a = new Node(20, b);
    Node* head = new Node(10, a);

    d->next = head;

    // printList(head);
    hasCycle(head);

    return 0;
}