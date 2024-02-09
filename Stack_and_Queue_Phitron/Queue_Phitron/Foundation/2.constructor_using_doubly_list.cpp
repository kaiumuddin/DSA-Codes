#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* prev;
    Node(int val, Node* next = NULL, Node* prev = NULL) {
        this->val = val;
        this->next = next;
        this->prev = prev;
    }
};

class myQueue {
public:
    Node* head = NULL;
    Node* tail = NULL;
    int sz = 0;

    void push(int val) {
        sz++;
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = tail->next;
    }

    void pop() {
        sz--;
        Node* deleteNode = head;
        head = head->next;
        if (head == NULL) {
            tail = NULL;
            delete deleteNode;
            return;
        }
        head->prev = NULL;
        delete deleteNode;
    }

    int front() {
        return head->val;
    }
    int size() {
        return sz;
    }
    bool empty() {
        return sz == 0;
    }
};

int main() {
    myQueue q;
    q.push(10);
    q.push(20);
    q.push(40);
    q.push(30);
    while (q.size()) {
        cout << q.front() << endl;
        q.pop();
    }
    cout << q.size() << endl;
    return 0;
}