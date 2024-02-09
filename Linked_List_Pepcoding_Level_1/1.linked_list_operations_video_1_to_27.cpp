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

    void addFirst(int val) {
        // Node* t = new Node(val);
        // t->next = head;
        // head = t;

        head = new Node(val, head);

        if (size == 0) {
            tail = head;
        }
        size++;
    }

    void getFirst() {
        if (size == 0) {
            cout << "List is empty" << endl;
            return;
        }

        cout << head->data << endl;

    }

    void getLast() {
        if (size == 0) {
            cout << "List is empty" << endl;
            return;
        }

        cout << tail->data << endl;
    }

    void getAt(int idx) {
        if (size == 0) {
            cout << "List is empty" << endl;
            return;
        }
        else if (idx < 0 || idx >= size) {
            cout << "Invalid Arguments" << endl;
            return;
        }

        Node* t = head;
        while (idx--) {
            t = t->next;
        }

        cout << t->data << endl;
    }

    void addAt(int idx, int val) {
        Node* t = head;

        if (idx < 0 || idx > size) {
            cout << "Invalid Arguments" << endl;
            return;
        }
        else if (idx == 0) {
            addFirst(val);
        }
        else if (idx == size) {
            addLast(val);
        }
        else {
            Node* curr = head;
            for (int i = 0; i < idx - 1; i++) {
                curr = curr->next;
            }
            curr->next = new Node(val, curr->next);

            // Node* t = new Node(val);
            // t->next = curr->next;
            // curr->next = t;
        }
        size++;
    }

    void removeLast() {
        if (size == 0) {
            cout << "List is empty" << endl;
            return;
        }
        else if (size == 1) {
            head = tail = NULL;
            size--;
            return;
        }
        else {
            Node* curr = head;
            for (int i = 0; i < size - 2; i++) {
                curr = curr->next;
            }

            tail = curr;
            tail->next = NULL;
            size--;
        }
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

    void removeAt(int idx) {
        if (idx < 0 || idx >= size) {
            cout << "Invalid Argument" << endl;
            return;
        }
        else if (idx == 0) {
            removeFirst();
        }
        else if (idx == size - 1) {
            removeLast();
        }
        else {
            Node* curr = head;
            for (int i = 0; i < idx - 1; i++) {
                curr = curr->next;
            }
            curr->next = curr->next->next;
            size--;
        }

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
    // l.reversePointerIter();
    l.removeAt(3);
    l.display();

    return 0;

}