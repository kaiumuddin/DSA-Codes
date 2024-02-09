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

    Node* left;
    bool isPalindromeHelper(Node* right) {
        if (right == NULL) return true;
        bool res = isPalindromeHelper(right->next);

        if (res == false) {
            return false;
        }
        else if (left->data != right->data) {
            return false;
        }
        else {
            left = left->next;
            return true;
        };
    }

    void isPalindrome() {
        left = head;
        cout << isPalindromeHelper(head) << endl;
    }

};

int main() {
    linked_list* a = new linked_list();
    a->add_from_arr({ 1,2,1 });
    a->display();
    a->isPalindrome();
    // a->display();

    return 0;
}