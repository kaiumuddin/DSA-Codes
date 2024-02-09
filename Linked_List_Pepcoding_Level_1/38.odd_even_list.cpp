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

    void makeOddEven() {
        linked_list* odd = new linked_list();
        linked_list* even = new linked_list();

        while (this->size > 0) {
            int val = this->getFirst();
            this->removeFirst();

            if (val % 2 == 1) odd->addLast(val);
            else even->addLast(val);
        }

        if (even->size == 0) {
            this->head = odd->head;
            this->tail = odd->tail;
            this->size = odd->size;
        }
        else if (odd->size == 0) {
            this->head = even->head;
            this->tail = even->tail;
            this->size = even->size;
        }
        else if (odd->size > 0 && even->size > 0) {
            odd->tail->next = even->head;

            this->head = odd->head;
            this->tail = even->tail;
            this->size = odd->size + even->size;
        }
    }

};

int main() {
    linked_list* a = new linked_list();
    a->add_from_arr({ 1,2,3,4,5,6,7,8,9 });
    // a->add_from_arr({ 2,4,6,8,0 });
    // a->add_from_arr({ 1,3,5,7,9 });
    a->display();
    a->makeOddEven();
    a->display();

    return 0;
}