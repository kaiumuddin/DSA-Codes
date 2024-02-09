#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int data, Node* next = NULL) {
        this->data = data;
        this->next = next;
    }
    Node() {}
};

class linked_list
{
public:
    Node* head;
    Node* tail;
    int size = 0;

public:
    linked_list() {
        head = NULL;
        tail = NULL;
    }
    void addFirst(int val) {
        head = new Node(val, head);

        if (size == 0) {
            tail = head;
        }
        size++;
    }

    void addLast(int val) {
        if (size == 0) {
            head = tail = new Node(val);
        }
        else {
            tail->next = new Node(val);
            tail = tail->next;
        }
        size++;
    }

    void display() {
        if (size == 0) {
            cout << "No Element to display" << endl;
            return;
        }
        for (Node* t = head; t != NULL; t = t->next) {
            cout << t->data << " ";
        }
        cout << endl;
    }

    void add_from_arr(vector<int> arr) {
        for (auto e : arr) {
            addLast(e);
        }
    }
};

int findIntersection(linked_list* one, linked_list* two) {
    Node* t1 = one->head;
    Node* t2 = two->head;

    int delta = abs(one->size - two->size);

    if (one->size > two->size) {
        for (int i = 0; i < delta; i++) {
            t1 = t1->next;
        }
    }
    else {
        for (int i = 0; i < delta; i++) {
            t2 = t2->next;
        }
    }

    while (t1->data != t2->data) {
        t1 = t1->next;
        t2 = t2->next;
    }

    return t1->data;
}

int main() {
    linked_list* a = new linked_list();
    a->add_from_arr({ 5,6,7,8,9,11,12,60,70,80,90,100 });
    linked_list* b = new linked_list();
    b->add_from_arr({ 10,20,30,40,50, 60, 70,80,90,100 });

    int d = findIntersection(a, b);
    cout << d << endl;

    return 0;
}