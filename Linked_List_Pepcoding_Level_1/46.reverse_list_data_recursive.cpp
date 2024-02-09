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

    void reversePRHelper(Node* curr) {
        if (curr == NULL) return;
        reversePRHelper(curr->next);

        if (curr != tail) {
            curr->next->next = curr;
        }
    }

    void reversePR() {
        reversePRHelper(head);
        head->next = NULL;
        swap(head, tail);
    }

};

int main() {
    linked_list* a = new linked_list();
    a->add_from_arr({ 1,2,3,4,5,6,7,8,9,10,11 });
    a->display();
    a->reversePR();
    a->display();

    return 0;
}