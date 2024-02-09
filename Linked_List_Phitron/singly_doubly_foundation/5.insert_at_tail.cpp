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

void print_list(Node* head) {
    Node* t = head;

    cout << "List : ";
    while (t) {
        cout << t->val << " ";
        t = t->next;
    }
    cout << endl;
}

void insert_at_tail(Node*& head, int v) {
    Node* newNode = new Node(v);

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* tmp = head;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }

    tmp->next = newNode;
}

void insert_at_head(Node*& head, int v) {
    Node* newNode = new Node(v);
    newNode->next = head;
    head = newNode;
}

void insert_at_position(Node*& head, int pos, int v) {
    Node* newNode = new Node(v);

    if (pos == 0) {
        insert_at_head(head, v);
        return;
    }

    Node* tmp = head;
    for (int i = 0; i < pos - 1; i++) {
        tmp = tmp->next;
        if (tmp == NULL) {
            cout << "Invalid position" << endl;
            return;
        }
    }
    newNode->next = tmp->next;
    tmp->next = newNode;
}

void delete_head(Node*& head) {
    if (head == NULL) return;

    Node* deleteNode = head;
    head = head->next;
    delete deleteNode;
}

void delete_from_position(Node*& head, int pos) {

    if (pos == 0) {
        delete_head(head);
        return;
    }

    Node* tmp = head;
    for (int i = 0; i < pos - 1; i++) {
        tmp = tmp->next;
        if (tmp == NULL) {
            cout << "Invalid position" << endl;
            return;
        }
    }
    if (tmp->next == NULL) {
        cout << "Invalid position" << endl;
        return;
    }
    Node* deleteNode = tmp->next;
    tmp->next = deleteNode->next;
    delete(deleteNode);
}

int main() {
    Node* head = NULL;

    // while (true) {
    //     printf("Option 0: Exit\n");
    //     printf("Option 1: Print Linked List\n");
    //     printf("Option 2: Insert at Tail\n");
    //     printf("Option 3: Insert at any position\n");

    //     int op; cin >> op;

    //     if (op == 1) {
    //         cout << "Please enter a value: ";
    //         int v; cin >> v;
    //         insert_at_tail(head, v);
    //     }
    //     else if (op == 2) {
    //         print_list(head);
    //     }
    //     else if (op == 3) {
    //         cout << "Please enter Pos and Value: ";
    //         int pos, v;
    //         cin >> pos >> v;

    //         insert_at_position(head, pos, v);
    //     }
    //     else {
    //         break;
    //     }

    //     cout << endl << endl;
    // }

    // insert_at_tail(head, 0);
    // insert_at_tail(head, 10);
    // insert_at_tail(head, 20);
    // insert_at_tail(head, 30);
    // insert_at_tail(head, 40);
    // insert_at_tail(head, 50);
    print_list(head);
    // delete_from_position(head, 1);
    delete_head(head);
    delete_head(head);
    delete_head(head);

    print_list(head);


    return 0;
}