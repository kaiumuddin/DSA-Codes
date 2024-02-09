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

    void removeFirst() {
        if (size == 0) {
            cout << "List is empty" << endl;
            return;
        }
        else if (size == 1) {
            head = tail = NULL;
            size--;
            return;
        }

        head = head->next;
        size--;
    }

    int getFirst() {
        if (size == 0) {
            return INT_MIN;
        }
        return head->data;
    }

    void removeDuplicates() {
        linked_list* res = new linked_list();

        while (this->size > 0) {
            int val = this->getFirst();
            this->removeFirst();

            if (res->size == 0 || res->tail->data != val) {
                res->addLast(val);
            }
        }

        this->head = res->head;
        this->tail = res->tail;
        this->size = res->size;
    }
};

int main() {
    linked_list* a = new linked_list();
    a->add_from_arr({ 10, 10, 20, 20, 20, 70, 70, 80, 90 });
    a->display();
    a->removeDuplicates();
    a->display();

    return 0;
}