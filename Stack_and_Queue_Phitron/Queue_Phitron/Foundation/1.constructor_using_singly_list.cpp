#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node(int val, Node* next = NULL) {
        this->val = val;
        this->next = next;
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
        tail = tail->next;

    }

    void pop() {
        sz--;
        Node* deleteNode = head;
        head = head->next;
        delete deleteNode;

        if (head == NULL) {
            tail = NULL;
        }
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
    q.push(30);
    while (q.size()) {
        cout << q.front() << endl;
        q.pop();
    }
    return 0;
}