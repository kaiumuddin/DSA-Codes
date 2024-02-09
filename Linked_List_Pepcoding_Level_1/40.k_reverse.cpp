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

    void addFirst(int val) {
        head = new Node(val, head);

        if (size == 0) {
            tail = head;
        }
        size++;
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

    void kReverse(int k) {
        linked_list* prev = NULL;

        while (this->size > 0) {
            linked_list* curr = new linked_list();

            if (this->size > k) {
                for (int i = 0; i < k; i++) {
                    int val = this->getFirst();
                    this->removeFirst();
                    curr->addFirst(val);
                }
            }
            else {
                int s = this->size;
                for (int i = 0; i < s; i++) {
                    int val = this->getFirst();
                    this->removeFirst();
                    curr->addLast(val);
                }
            }


            if (prev == NULL) {
                prev = curr;
            }
            else {
                prev->tail->next = curr->head;
                prev->tail = curr->tail;
                prev->size += curr->size;
            }
        }

        this->head = prev->head;
        this->tail = prev->tail;
        this->size = prev->size;
    }

};

int main() {
    linked_list* a = new linked_list();
    a->add_from_arr({ 1,2,3,4,5,6,7,8,9,10,11 });
    // a->add_from_arr({ 2,4,6,8,0 });
    // a->add_from_arr({ 1,3,5,7,9 });
    a->display();
    a->kReverse(3);
    a->display();

    return 0;
}