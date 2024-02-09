#include <iostream>
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

    Node* getNodeAt(int idx) {
        Node* t = head;
        while (idx--) {
            t = t->next;
        }

        return t;
    }

    void reversDataIter() {
        int li = 0;
        int ri = size - 1;

        while (li < ri) {
            Node* left = getNodeAt(li);
            Node* right = getNodeAt(ri);

            swap(left->data, right->data);

            li++;
            ri--;
        }
    }

    void reversePointerIter() {
        Node* prev = NULL;
        Node* curr = head;

        while (curr) {
            Node* curr_next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = curr_next;
        }

        swap(head, tail);
    }
};


int main() {
    // string str;
    linked_list l;
    // while (true) {
    //     getline(cin, str);
    //     if (str[0] == 'q') {
    //         break;
    //     }
    //     if (str[0] == 'a') {
    //         string ss = str.substr(8, 2);
    //         int n = stoi(ss);
    //         l.addLast(n);
    //     }
    // }

    // while (true) {
    //     string s;
    //     int n;
    //     cin >> s >> n;
    //     if (s == "quit") {
    //         break;
    //     }
    //     else if (s == "addLast") {
    //         l.addLast(n);
    //     }
    // }

    l.addLast(0);
    l.addLast(10);
    l.addLast(20);
    l.addLast(30);
    l.addLast(40);
    l.addLast(50);
    l.display();
    // l.reversDataIter();
    l.reversePointerIter();
    l.display();

    return 0;

}