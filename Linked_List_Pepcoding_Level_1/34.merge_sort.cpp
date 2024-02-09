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

    linked_list* merge_two_sorted_list(linked_list* a, linked_list* b) {
        Node* one = a->head;
        Node* two = b->head;

        linked_list* res = new linked_list();

        while (one != NULL && two != NULL) {
            if (one->data < two->data) {
                res->addLast(one->data);
                one = one->next;
            }
            else {
                res->addLast(two->data);
                two = two->next;
            }
        }

        while (one != NULL) {
            res->addLast(one->data);
            one = one->next;
        }

        while (two != NULL) {
            res->addLast(two->data);
            two = two->next;
        }

        return res;
    }

    Node* midNode(Node* head, Node* tail) {
        Node* f = head;
        Node* s = head;

        while (f != tail && f->next != tail) {
            f = f->next->next;
            s = s->next;
        }

        return s;
    }

    linked_list* mergeSort(Node* head, Node* tail) {
        if (head == tail) {
            linked_list* br = new linked_list();
            br->addLast(head->data);
            return br;
        }

        Node* mid = midNode(head, tail);
        linked_list* fsh = mergeSort(head, mid);
        linked_list* ssh = mergeSort(mid->next, tail);

        linked_list* cl = merge_two_sorted_list(fsh, ssh);
        return cl;

    }

};



int main() {
    linked_list* a = new linked_list();
    a->add_from_arr({ 10, 30, 20, 50, 40, 90, 70, 80, 60 });
    a->display();

    a = a->mergeSort(a->head, a->tail);
    a->display();

    return 0;
}