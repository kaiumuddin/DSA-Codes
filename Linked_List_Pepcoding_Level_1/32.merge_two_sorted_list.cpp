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

linked_list merge_two_sorted_list(linked_list a, linked_list b) {
    Node* one = a.head;
    Node* two = b.head;

    linked_list res;

    while (one != NULL && two != NULL) {
        if (one->data < two->data) {
            res.addLast(one->data);
            one = one->next;
        }
        else {
            res.addLast(two->data);
            two = two->next;
        }
    }

    while (one != NULL) {
        res.addLast(one->data);
        one = one->next;
    }

    while (two != NULL) {
        res.addLast(two->data);
        two = two->next;
    }

    return res;
}

int main() {
    linked_list a;
    a.add_from_arr({ 10,20,30,40,50 });
    a.display();

    linked_list b;
    b.add_from_arr({ 7,9,12,15,37,43,44,45,52,56 });
    b.display();

    // after merge : 7,9,10,12,15,20,30, 37,40,43,44,45,50,52,56

    linked_list final = merge_two_sorted_list(a, b);
    final.display();


    return 0;
}