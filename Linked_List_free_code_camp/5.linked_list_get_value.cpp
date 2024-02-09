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

void print_v(vector<int> values) {
    for (auto e : values) {
        cout << e << " ";
    }
    cout << endl;
}

int getNodeValue(Node* head, int index) {
    Node* t = head;

    while (t && index--) {
        t = t->next;
    }

    return t->val;
};

int getNodeValueRecursive(Node* head, int index) {
    if (head == NULL) return -1;
    if (index == 0) return head->val;

    int faith = getNodeValueRecursive(head->next, index - 1);

    return faith;
};


int main() {

    Node* head =
        new Node(10,
            new Node(20,
                new Node(30,
                    new Node(40))));

    cout << getNodeValue(head, 2) << endl;
    cout << getNodeValueRecursive(head, 2) << endl;

    return 0;
}