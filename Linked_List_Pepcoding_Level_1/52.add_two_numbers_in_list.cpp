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

int addTwoListHelper(Node* one, int pv1, Node* two, int pv2, linked_list* res) {
    if (one == NULL && two == NULL) {
        return 0; // carry
    }

    int data = 0;

    if (pv1 > pv2) {
        int oc = addTwoListHelper(one->next, pv1 - 1, two, pv2, res);
        data = one->data + oc;
    }
    else if (pv1 < pv2) {
        int oc = addTwoListHelper(one, pv1, two->next, pv2 - 1, res);
        data = two->data + oc;
    }
    else {
        int oc = addTwoListHelper(one->next, pv1 - 1, two->next, pv2 - 1, res);
        data = one->data + two->data + oc;
    }

    int nd = data % 10;
    int nc = data / 10;

    res->addFirst(nd);
    return nc;
}

linked_list* addTwoList(linked_list* one, linked_list* two) {
    linked_list* res = new linked_list();
    int oc = addTwoListHelper(one->head, one->size, two->head, two->size, res);
    if (oc > 0) {
        res->addFirst(oc);
    }
    return res;
}

int main() {
    linked_list* a = new linked_list();
    a->add_from_arr({ 9,9,9 });
    linked_list* b = new linked_list();
    b->add_from_arr({ 1 });

    // a + b = 9831

    linked_list* addedList = addTwoList(a, b);
    addedList->display();


    return 0;
}