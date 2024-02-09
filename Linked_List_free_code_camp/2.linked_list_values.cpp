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

vector<int> linkedListValuesIterative(Node* head) {
    vector<int> values;

    Node* curr = head;
    while (curr) {
        values.push_back(curr->val);
        curr = curr->next;
    }
    return values;
};

vector<int> linkedListValuesRecursive(Node* head) {
    if (head == NULL) return {};

    vector<int> faith = linkedListValuesRecursive(head->next);

    vector<int> values;
    values.push_back(head->val);
    values.insert(values.end(), faith.begin(), faith.end());

    return values;
};


int main() {

    Node* head =
        new Node(10,
            new Node(20,
                new Node(30,
                    new Node(40))));

    vector<int> values = linkedListValuesIterative(head);
    print_v(values);
    values = linkedListValuesRecursive(head);
    print_v(values);

    return 0;
}